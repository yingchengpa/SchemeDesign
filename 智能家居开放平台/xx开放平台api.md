# 介绍
客户需要使用我们的sdk和openapi 进行开发自己的app，对接方案组网如下
![局部截取_20260525_142511.png](http://106.54.161.137:4999/server/?s=/api/attachment/visitFile&sign=871c0084f935f277f7ebd6196d7bad6b)

# 流程图
![局部截取_20260525_144856.png](http://106.54.161.137:4999/server/?s=/api/attachment/visitFile&sign=9f1a56ab1dadd21ae4ebbb84421c12bd)

# 友商接口
- 积加：https://docs.a4x.io/#/zh-cn/app/product_overview
- 探鸽：https://tange-ai.feishu.cn/wiki/wikcnEnWxyIFeR6TIFHw4SLBntf
- 探鸽：https://app.apifox.com/project/1836098
- 萤石：https://open.ys7.com/cn/s/supportcenter

# 接入准备
** 每个区域都要单独申请**
AccessToken 获取：申请appid、secretKey。

# 提供接口

## openapi

### 账户模块

#### 1. 获取接入Access Token

POST `openapi/user/app/token/get`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| appId | string | 是 | - | 应用ID（Pattern: ^[0-9]{1,32}$） |  |
| secretKey | string | 是 | - | 秘钥（Pattern: ^[0-9A-Za-z_-]{1,128}$） |  |

**请求示例**
```json
{
    "appId": "string",
    "secretKey": "string"
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 | - | 数据信息 |  |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {}
}
```

#### 2. 创建子账号

POST `openapi/user/sub/account/create`

ContentType：`application/x-www-form-urlencoded`

**请求参数**

无

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 | - | 数据信息 |  |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {}
}
```

#### 3. 删除子账号

POST `openapi/user/sub/account/delete`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| accountId | string | 否 | - | 子账号ID |  |

**请求示例**
```json
{
    "accountId": "string"
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 | - | 数据信息 |  |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {}
}
```

#### 4. 获取子账户Access Token

POST `openapi/user/sub/account/token/get`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| accountId | string | 否 | - | 子账号ID |  |

**请求示例**
```json
{
    "accountId": "string"
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 | - | 数据信息 |  |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {}
}
```

### 云端设备模块

#### 1. 添加设备

POST `openapi/device/add`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| registerCode | string | 是 | - | 设备注册码（Pattern: ^[a-zA-Z0-9]{25}$） | FVS5Z9DZR52YPQJLILBSWCORB |
| deviceName | string | 是 | - | 设备名称（Pattern: ^([^<>]{0,64})$） | 164 |

**请求示例**
```json
{
    "registerCode": "FVS5Z9DZR52YPQJLILBSWCORB",
    "deviceName": "164"
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 |  | 数据信息 |  |
| &emsp;└ deviceSerial | string | 否 | - | 设备序列号 | 210235C3KNF203000168 |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {
        "deviceSerial": "210235C3KNF203000168"
    }
}
```

#### 2. 查询设备列表

POST `openapi/device/list`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| pageNo | int32 | 否 | - | 分页起始页，默认从1开始（Min: 1） | 1 |
| pageStart | int32 | 否 | - | 分页起始页，从0开始（Min: 0） | 0 |
| pageSize | int32 | 否 | - | 分页大小，默认为10，最大为100（Min: 1, Max: 100） | 10 |

**请求示例**
```json
{
    "pageNo": 1,
    "pageStart": 0,
    "pageSize": 10
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 |  | 数据信息 |  |
| &emsp;└ total | int32 | 否 | - | 总记录数 | 100 |
| &emsp;└ deviceList | array | 否 |  | 设备列表 |  |
| &emsp;&emsp;└ deviceSerial | string | 否 | - | 设备序列号 | 210235C3KNF203000168 |
| &emsp;&emsp;└ deviceName | string | 否 | - | 设备名称 | 164 |
| &emsp;&emsp;└ deviceModel | string | 否 | - | 设备型号 | NVR301-08S2-DT |
| &emsp;&emsp;└ deviceVersion | string | 否 | - | 设备版本 | ENVRV300R008B01D020SP15 |
| &emsp;&emsp;└ deviceType | int32 | 否 | - | 设备类型 | 1 |
| &emsp;&emsp;└ deviceTypeName | string | 否 | - | 设备类型对应名称 | NVR301-08S2-DT |
| &emsp;&emsp;└ deviceUserName | string | 否 | - | 设备用户名，多个用户用;分隔 | admin |
| &emsp;&emsp;└ status | int32 | 否 | - | 状态 | 1 |
| &emsp;&emsp;└ isShared | int32 | 否 | - | 是否是共享设备 | 0 |
| &emsp;&emsp;└ latestOnline | int64 | 否 | - | 最近上线时间 | 1731246781000 |
| &emsp;&emsp;└ addTime | int64 | 否 | - | 最近一次添加设备的时间 | 0 |
| &emsp;&emsp;└ supportMultiChannel | int32 | 否 | - | 是否支持多通道，0-不支持，1-支持 | 1 |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {
        "total": 100,
        "deviceList": [
            {
                "deviceSerial": "210235C3KNF203000168",
                "deviceName": "164",
                "deviceModel": "NVR301-08S2-DT",
                "deviceVersion": "ENVRV300R008B01D020SP15",
                "deviceType": 1,
                "deviceTypeName": "NVR301-08S2-DT",
                "deviceUserName": "admin",
                "status": 1,
                "isShared": 0,
                "latestOnline": 1731246781000,
                "addTime": 0,
                "supportMultiChannel": 1
            }
        ]
    }
}
```

#### 3. 解绑设备

POST `openapi/device/delete`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| deviceSerial | string | 是 | - | 设备序列号（Pattern: ^[a-zA-Z0-9]{20}$） | 210235C3KNF203000168 |

**请求示例**
```json
{
    "deviceSerial": "210235C3KNF203000168"
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 | - | 数据信息 |  |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {}
}
```

#### 4. 查询设备是否可升级

POST `openapi/device/version/update`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| deviceSerial | string | 是 | - | 设备序列号（Pattern: ^[a-zA-Z0-9]{20}$） |  |


**请求示例**
```json
{
    "deviceSerial": "string"
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 | - | 数据信息 |  |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {}
}
```

#### 5. 设备升级

POST `openapi/device/version/update`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| deviceSerial | string | 是 | - | 设备序列号（Pattern: ^[a-zA-Z0-9]{20}$） |  |

**请求示例**
```json
{
    "deviceSerial": "string"
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 | - | 数据信息 |  |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {}
}
```

#### 6. 升级进度查询

POST `openapi/device/version/status/get`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| deviceSerial | string | 是 | - | 设备序列号（Pattern: ^[a-zA-Z0-9]{20}$） |  |

**请求示例**
```json
{
    "deviceSerial": "string",
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 |  | 数据信息 |  |
| &emsp;└ progress | int32 | 否 | - | 升级进度百分比 | 0 |
| &emsp;└ status | int32 | 否 | - | 升级状态 0-正在升级，1-升级成功，2-升级失败，3-未升级，4-重启中，5-取消升级中 | 0 |
| &emsp;└ timeLeft | string | 否 | - | 云升级各状态的预计剩余耗时，单位：秒 |  |
| &emsp;└ cancelable | int32 | 否 | - | 是否可以取消升级，1表示可以取消，0表示不可以取消 | 0 |
| &emsp;└ deviceStatus | int32 | 否 | - | 设备上报的升级状态：0-初始化中，1-查询中，2-下载中，3-传输中，4-升级中，5-升级出错，8-升级完成 | 0 |
| &emsp;└ deviceProgress | int32 | 否 | - | 设备上报的各升级阶段的升级进度 | 0 |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {
        "progress": 0,
        "status": 0,
        "timeLeft": "string",
        "cancelable": 0,
        "deviceStatus": 0,
        "deviceProgress": 0
    }
}
```

#### 7. 查询设备状态（含wifi信号、电量、sd卡状态）

POST `openapi/device/status/get`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| deviceSerial | string | 是 | - | 设备序列号 | 210235C3KNF203000168 |

**请求示例**
```json
{
    "deviceSerial": "210235C3KNF203000168"
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 |  | 数据信息 |  |
| &emsp;└ status | int32 | 否 | - | 状态（0-离线，1-在线） | 1 |
| &emsp;└ wakeUpStatus | int32 | 否 | - | 唤醒状态（0-休眠，1-工作，2-关机） | 1 |
| &emsp;└ batteryStatus | int32 | 否 | - | 电池电量，0到100(%)，-1：设备没有上报或者设备不支持该状态 | 80 |
| &emsp;└ chargeStatus | int32 | 否 | - | 电池充电状态，0-非充电，1-充电中 | 1 |
| &emsp;└ simCardId | string | 否 | - | 4G卡号 | 89860012345678901234 |
| &emsp;└ simIntensity | int32 | 否 | - | 4G信号强度（0-100） | 85 |
| &emsp;└ wifiName | string | 否 | - | wifi名 | MyWiFi |
| &emsp;└ wifiIntensity | int32 | 否 | - | wifi信号强度（0-100） | 90 |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {
        "status": 1,
        "wakeUpStatus": 1,
        "batteryStatus": 80,
        "chargeStatus": 1,
        "simCardId": "89860012345678901234",
        "simIntensity": 85,
        "wifiName": "MyWiFi",
        "wifiIntensity": 90
    }
}
```

#### 8. 获取设备抓拍图片

POST `openapi/device/capture/get`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| deviceSerial | string | 是 | - | 设备序列号（Pattern: ^[a-zA-Z0-9]{20}$） |  |
| channelNo | int32 | 是 | - | 通道号（Min: 0） | 0 |
| captureMode | int32 | 否 | - | 抓图模式。0：覆盖模式（默认）；1：不覆盖模式（Min: 0, Max: 1） | 0 |

**请求示例**
```json
{
    "deviceSerial": "string",
    "channelNo": 0,
    "captureMode": 0
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 | - | 数据信息 |  |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {}
}
```

#### 9. 查询设备能力集

POST `openapi/device/capacity/get`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| deviceSerial | string | 是 | - | 设备序列号（Pattern: ^[a-zA-Z0-9]{20}$） | 210235C3KNF203000168 |

**请求示例**
```json
{
    "deviceSerial": "210235C3KNF203000168"
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 |  | 数据信息 |  |
| &emsp;└ supportPtz | int32 | 否 | - | 云台能力 | 1 |
| &emsp;└ supportTalk | int32 | 否 | - | 语音对讲能力 | 1 |
| &emsp;└ supportLive | int32 | 否 | - | RTSP实况能力（0-不支持，1-支持，2-快速RTSP） | 1 |
| &emsp;└ supportCdn | int32 | 否 | - | 设备云分发能力 | 1 |
| &emsp;└ supportCos | int32 | 否 | - | 云存储支持能力（0-不支持，1-支持） | 1 |
| &emsp;└ supportFaceRecognition | int32 | 否 | - | 人脸识别能力（0-不支持，1-支持） | 1 |
| &emsp;└ supportVehicleRecognition | int32 | 否 | - | 车辆识别能力（0-不支持，1-支持） | 0 |
| &emsp;└ supportWifi | int32 | 否 | - | Wifi支持能力（0-不支持，1-支持） | 1 |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {
        "supportPtz": 1,
        "supportTalk": 1,
        "supportLive": 1,
        "supportCdn": 1,
        "supportCos": 1,
        "supportFaceRecognition": 1,
        "supportVehicleRecognition": 0,
        "supportWifi": 1
    }
}
```

### 设备直连

#### 1. 透明通道

POST `openapi/device/api/invoke/{设备协议上的请求路径}`

通过透明通道直接与设备通信，请求路径为设备协议上的请求路径。

### 事件与云录像

#### 1. 查询云事件列表

POST `openapi/event/alarm/query`

#### 2. 按日历查询是否有云事件

#### 3. 查询云录像列表

#### 4. 设置消息上报

### 增值服务

#### 1. 查询套餐列表

#### 2. 查询套餐详情

#### 3. 查询设备开通的套餐列表

#### 4. 套餐生效

#### 5. 转移套餐

### 低功耗设备

#### 1. 唤醒设备

POST `openapi/device/wakeup`

ContentType：`application/json`

**请求参数（Body Parameter）**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| deviceSerial | string | 是 | - | 设备序列号 | 210235C3KNF203000168 |

**请求示例**
```json
{
    "deviceSerial": "210235C3KNF203000168",
}
```

**响应参数**

| 名称 | 类型 | 必填 | 最大长度 | 描述 | 示例值 |
| --- | --- | --- | --- | --- | --- |
| code | int32 | 否 | - | 状态码 | 0 |
| message | string | 否 | - | 状态描述 |  |
| data | object | 否 | - | 数据信息 |  |

**响应示例**
```json
{
    "code": 0,
    "message": "string",
    "data": {}
}
```
