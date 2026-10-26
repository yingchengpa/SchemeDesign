# 项目长期记忆 - 设备接口的压缩方案

## 项目背景
- 宇视云 IPC/NVR 设备与云端 WebSocket 通信压缩方案设计
- 现状：WebSocket 仅支持 opcode=0x1 文本帧（JSON），二进制需 Base64 导致 33% 膨胀
- 项目说明明确导向：需支持 CBOR 格式传输 + text 直接压缩后二进制传输

## 方案决策（V2.0）
- 主推：CBOR-Native + LZ4 压缩（cmd=1, opt1=enc=2, opt2=cmp=1）
- 过渡：CBOR-JSON + LZ4 压缩（cmd=1, opt1=enc=1, opt2=cmp=1）
- 降级：JSON 文本 + LZ4 压缩（cmd=1, opt1=enc=0, opt2=cmp=1）
- 预留：Protobuf（opt1=enc=3，远期备选）
- 演进路线：CBOR-Native(enc=2) → CBOR+CDDL schema(enc 不变，叠加 RFC 8610 schema 层) → Protobuf(enc=3，仅远期备选)
  - CBOR 自带 CDDL schema 语言，优先于 Protobuf；CDDL 不改编码，只加校验，与存量兼容
- enc 取值：0=JSON, 1=CBOR-JSON(JSON转CBOR，二进制仍Base64), 2=CBOR-Native(原生CBOR，二进制bstr消除Base64膨胀), 3=Protobuf
  - 关键区分：CBOR-JSON 未消除 Base64 膨胀（仅结构压缩）；CBOR-Native 才消除（二进制用 bstr）
- 协议头 4 字节：cmd / opt1 / opt2 / opt3（"命令字+参数字节"复用结构）
  - cmd=1 = LAPI_OVER_WS（LAPI 指令走 WS 二进制帧）：opt1=enc, opt2=cmp, opt3=子类型
  - 具体 LAPI 业务指令由 payload 内 LAPI cmd 字段区分，协议头不关心
  - 其他 cmd 值（2~255）保留
  - 命名用 opt1/2/3 而非 rsv1/2/3，避免与 WebSocket 帧头 RSV1/RSV2/RSV3 混淆
- 压缩时协议头后追加 4 字节原始长度（LZ4 Block 解压所需）
- CBOR 选用 tinycbor（C，嵌入式 ~10KB）；JSON 压缩选用 LZ4

## 文档约定
- 输出文档命名：原文件名后加 "-ai"（见《宇视云任务描述.md》）
- 文档结构遵循《PO需求文档模板.md》
- 开发文档字段描述格式：`Param | requirement | Type | Description | Example`（requirement: M=必填/O=可选）
- Type 取值：int / string / bool / float / array / object / byte
  - byte 为新增类型，表示二进制数据（图片/缩略图/证书等）
  - byte 在 enc=0/1 时为 Base64 string（膨胀33%），enc=2(CBOR-Native) 时为 CBOR bstr（无膨胀）
  - 开发文档统一用 byte 标注，协议层按 enc 自动选择承载方式
