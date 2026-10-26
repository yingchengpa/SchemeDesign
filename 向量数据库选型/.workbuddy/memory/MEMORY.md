# 向量数据库选型 - 项目记忆

## 项目背景
- 宇视云项目，IPC/NVR 上报特征值存储到向量数据库
- 用户输入文本 → Embedding 向量化 → 向量检索匹配目标
- 当前使用 Tencent Cloud VectorDB，特征全存内存，成本过高
- 核心需求：内存/磁盘可互换方案，降低内存成本
- 海外部署是关键约束：Tencent VectorDB 磁盘索引海外不支持

## 技术选型结论（2026-09-28）
- 国内场景：Tencent VectorDB 开启磁盘索引（零迁移）
- 海外场景：阿里云 Milvus（DiskANN+RaBitQ，全托管，新加坡/法兰克福可用）
- 开源备选：Qdrant（内存管理最灵活，运维比 Milvus 简单）
- 不推荐：pgvector（无真正磁盘索引）、zvector（生态不足）

## 关键数据点
- 阿里云 Milvus DiskANN+RaBitQ：1亿768维 QPS=开源20倍+，P99=1/10，内存减29%，召回98%+
- 开源 Milvus DiskANN：100M向量内存从80-90GB降至12-16GB，节省61%-76%
- Qdrant TurboQuant 量化：8x-32x 内存节省，三层内存分级(pinned/cached/cold)
