#ifndef _OPEN_API_SDK_H_
#define _OPEN_API_SDK_H_

#ifdef  __cplusplus
extern "C"{
#endif


#ifndef STATIC
#define STATIC                  static
#endif

#ifndef CONST
#define CONST                   const
#endif

#ifndef EXTERN
#define EXTERN                  extern
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif

/* 标准函数调用约定 Standard function calling convention */
#if defined(_WIN32) || defined(WIN32)
    /* Windows 平台 Windows platform */
#define STDCALL __stdcall

#ifdef OPEN_API_DLL_EXPORTS
#define OPEN_API __declspec(dllexport)
#else
#define OPEN_API __declspec(dllimport)
#endif

#elif defined(__GNUC__) || defined(__GNUG__)
    /* GNU GCC 编译器 GNU GCC compiler */
#if defined(__i386__) || defined(__i386)
#define STDCALL __attribute__((stdcall))
#else
#define STDCALL
#endif
#define OPEN_API __attribute__((visibility("default")))

#else
    /* 其他编译器 Other compilers */
#define STDCALL
#define OPEN_API
#endif


#ifndef UCHAR_DEF
#define UCHAR_DEF
    typedef unsigned char           UCHAR;
#endif

#ifndef CHAR_DEF
#define CHAR_DEF
    typedef char                    CHAR;
#endif

#ifndef BYTE_DEF
#define BYTE_DEF
    typedef unsigned char           BYTE;
#endif

#ifndef UINT16_DEF
#define UINT16_DEF
    typedef unsigned short          UINT16;
#endif

#ifndef UINT_DEF
#define UINT_DEF
    typedef unsigned int            UINT32;
#endif

#ifndef INT16_DEF
#define INT16_DEF
    typedef  short                  INT16;
#endif

#ifndef INT32_DEF
#define INT32_DEF
    typedef  int                    INT32;
#endif

#ifndef LPVOID_DEF
#define LPVOID_DEF
    typedef void*                   LPVOID;
#endif

#ifndef VOID
#ifndef VOID_DEF
#define VOID_DEF
    typedef void                    VOID;
#endif
#endif

#ifndef INT64_DEF
#define INT64_DEF
    typedef long long               INT64;
#endif

#ifndef BOOL_DEF
#define BOOL_DEF
#ifndef __OBJC__
    typedef int                 BOOL;
#else
#import<objc/objc.h>
#endif
#endif

#ifndef FLOAT
#ifndef VOID_FLOAT
#define VOID_FLOAT
    typedef float                   FLOAT;
#endif
#endif

#ifndef DOUBLE
#ifndef DOUBLE_DEF
#define DOUBLE_DEF
    typedef double                   DOUBLE;
#endif
#endif

#ifndef FALSE
#define FALSE                   0
#endif

#ifndef TRUE
#define TRUE                    1
#endif

#ifndef WIN32
    typedef LPVOID                 HWND;
#endif

#define OPENAPI_TYPE                        1           /* 调用CommonSDK时需传入SDK类型，在此提前声明好 */

#define OPENAPI_LEN_0                       0
#define OPENAPI_LEN_100                     100

/* 通用长度 Common length */
#define OPENAPI_LEN_32                      32
#define OPENAPI_LEN_64                      64
#define OPENAPI_LEN_128                     128
#define OPENAPI_LEN_132                     132
#define OPENAPI_LEN_256                     256
#define OPENAPI_LEN_260                     260
#define OPENAPI_LEN_512                     512

#define OPENAPI_MAX_PRESET_NUM                   255         /* 预置位最大数  Maximum number of presets */

// ==================== 枚举定义 Enumeration Definitions ====================

/* 错误码范围 600000-604999 */
typedef enum tagOpenAPIErrCode
{
    OPENAPI_E_SUCCEED                               = 0,                                /* 成功 Success */

    /* 起始错误码 */
    OPENAPI_E_START                                 = 600000,                           /* SDK错误码开始标记，无实际意义 SDK error code start marker, no practical meaning */

    OPENAPI_E_NOT_SUPPORT                           = OPENAPI_E_START + 1,              /* 不支持功能 Function not supported */

    /* 通用错误码 */
    OPENAPI_E_NO_INIT                               = OPENAPI_E_START + 2,              /* 未初始化 Not initialized */
    OPENAPI_E_INVALID_PARAMETER                     = OPENAPI_E_START + 3,              /* 无效参数 Invalid parameter */
    /* 认证相关 */
    OPENAPI_E_TOKEN_AUTHENTICATION_FAILED           = OPENAPI_E_START + 4,              /* accessToken不正确 accessToken incorrect */
    OPENAPI_E_TOKEN_AUTHENTICATION_EXPIRED          = OPENAPI_E_START + 5,              /* accessToken过期,重新获取accessToken accessToken expired, reacquire accessToken */
    OPENAPI_E_ACCOUNT_ERROR                         = OPENAPI_E_START + 6,              /* appId与secretKey不匹配 appId and secretKey do not match */
    /* 用户相关 */
    OPENAPI_E_NO_USER                               = OPENAPI_E_START + 7,              /* 用户不存在 User does not exist*/
    OPENAPI_E_USER_WRONG_PASSWD                     = OPENAPI_E_START + 8,              /* 用户密码错误 User password error */
    OPENAPI_E_USER_SELOG_IP_LOCKED                  = OPENAPI_E_START + 9,              /* 用户安全登录锁定 User security logon lock*/
    OPENAPI_E_NOT_PERMISSION                        = OPENAPI_E_START + 10,             /* 用户无权限 User has no permission */
    /* 资源设备相关 */
    OPENAPI_E_NORESULT                              = OPENAPI_E_START + 11,             /* 结果为空 No Result */
    OPENAPI_E_NO_RESOURCE                           = OPENAPI_E_START + 12,             /* 资源不存在 Resource not found. */
    OPENAPI_E_ADD_DEVICE_ERROR                      = OPENAPI_E_START + 13,             /* 添加设备失败 Add device error */
    OPENAPI_E_DEVICE_NOT_EXIST                      = OPENAPI_E_START + 14,             /* 设备不存在 Device does not exist*/
    OPENAPI_E_SERIAL_NO_EXIST                       = OPENAPI_E_START + 15,             /* 设备序列号不存在 Device serial number does not exist */
    OPENAPI_E_CHANNEL_OFFLINE                       = OPENAPI_E_START + 16,             /* 通道离线 Channel offline */
    /* 内存指针相关 */
    OPENAPI_E_NO_MEMORY                             = OPENAPI_E_START + 17,             /* 内存申请失败 Memory allocation failed */
    OPENAPI_E_NULL_POINT                            = OPENAPI_E_START + 18,             /* 指针转换失败 Pointer conversion failed */
    /* 网络连接/Json相关 */
    OPENAPI_E_RUN_TIME_ERROR                        = OPENAPI_E_START + 19,             /* 获取系统时间错误 Get system time error */
    OPENAPI_E_TUNNEL_CONNECT_FAILED                 = OPENAPI_E_START + 20,             /* 连接TUNNEL失败 Connect TUNNEL Failed*/
    OPENAPI_E_CURL_ERROR                            = OPENAPI_E_START + 21,             /* curl网络交互错误 curl network interaction error */
    OPENAPI_E_JSON_CREATE_ERROR                     = OPENAPI_E_START + 22,             /* json节点创建失败 json node creation failed */
    OPENAPI_E_JSON_RSP_ERROR                        = OPENAPI_E_START + 23,             /* 解析json响应信息失败 Parse json response failed */
    OPENAPI_E_LAPI_RETURN_ERROR                     = OPENAPI_E_START + 24,             /* LAPI返回的错误码不为0  LAPI return errocode */

    OPENAPI_E_INSERT_ERROR                          = OPENAPI_E_START + 25,             /* 插入数据失败 Insert failed */
    OPENAPI_E_CLOUD_VIDEO_NONE                      = OPENAPI_E_START + 26,             /* 无云存储录像 No cloud storage recording */
    OPENAPI_E_CHECK_PORT_ERROR                      = OPENAPI_E_START + 27,             /* 探测端口失败 Port detection failed */
    OPENAPI_E_SERVER_INTERNAL_ERROR                 = OPENAPI_E_START + 29,             /* 服务器内部错误 Server internal error */

    /***********************媒体获取URL和控制块查找模块-错误码-100个-开始****包括实况、回放、下载、语音对讲****************************************/
    OPENAPI_E_PLAYER_INIT_ERROR                     = OPENAPI_E_START + 600,            /* 播放器初始化失败 Player initialization failed */
    OPENAPI_E_LIVE_GET_URL_ERROR                    = OPENAPI_E_START + 601,            /* 获取实况播放URL失败 Failed to get live playback URL */
    OPENAPI_E_LIVE_START_ERROR                      = OPENAPI_E_START + 602,            /* 媒体库启动实况失败 Media library failed to start live stream */
    OPENAPI_E_LIVE_STOP_ERROR                       = OPENAPI_E_START + 603,            /* 媒体库停止实况失败 Media library failed to stop live stream */
    OPENAPI_E_VOD_TIME_ERROR                        = OPENAPI_E_START + 604,            /* 结束时间不能小于开始时间 End time cannot be earlier than start time */
    OPENAPI_E_VOD_QUERY_ERROR                       = OPENAPI_E_START + 605,            /* 查录像返回失败 Video query failed */
    OPENAPI_E_VOD_GET_URL_ERROR                     = OPENAPI_E_START + 606,            /* 获取回放播放URL失败 Failed to get playback URL */
    OPENAPI_E_VOD_START_ERROR                       = OPENAPI_E_START + 607,            /* 媒体库开始回放失败 Media library failed to start playback */
    OPENAPI_E_VOD_STOP_ERROR                        = OPENAPI_E_START + 608,            /* 媒体库停止回放失败 Media library failed to stop playback */
    OPENAPI_E_VOD_CONTROL_ERROR                     = OPENAPI_E_START + 609,            /* 媒体库回放控制失败 Media library playback control failed */
    OPENAPI_E_AUDIO_GET_URL_ERROR                   = OPENAPI_E_START + 610,            /* 获取语音对讲URL失败 Failed to get audio intercom URL */
    OPENAPI_E_AUDIO_START_ERROR                     = OPENAPI_E_START + 611,            /* 媒体库开启语音对讲失败 Media library failed to start audio intercom */
    OPENAPI_E_AUDIO_STOP_ERROR                      = OPENAPI_E_START + 612,            /* 媒体库停止语音对讲失败 Media library failed to stop audio intercom */
    OPENAPI_E_PLAY_CB_NOTEXIST                      = OPENAPI_E_START + 613,            /* 播放控制块不存在 Play control block does not exist */
    OPENAPI_E_PLAY_CB_ADDERROR                      = OPENAPI_E_START + 614,            /* 添加控制块失败 Add control block error */
    OPENAPI_E_PLAY_CB_DELERROR                      = OPENAPI_E_START + 615,            /* 删除控制块失败 Delete control block error */
    OPENAPI_E_TALK_GET_URL_ERROR                    = OPENAPI_E_START + 616,            /* 获取语音对讲URL失败 Get Talk URL Failed */
    OPENAPI_E_CAPTURE_NO_SUPPORT_FORMAT             = OPENAPI_E_START + 617,            /* 抓拍格式不支持 Snapshot format does not support */
    OPENAPI_E_CAPTURE_NO_ENOUGH_CAPACITY            = OPENAPI_E_START + 618,            /* 硬盘空间不足 Insufficient hard disk space */
    OPENAPI_E_CAPTURE_NO_DECODED_PICTURE            = OPENAPI_E_START + 619,            /* 没有解码过的图片可供抓拍 Undecoded pictures can be captured */
    OPENAPI_E_CAPTURE_SINGLE_FAILED                 = OPENAPI_E_START + 620,            /* 单次抓拍操作失败 Single snap operation failed */

    /***********************媒体库模块-错误码-2099个-开始****包括实况、回放、下载、语音对讲****************************************/
    OPENAPI_E_MEDIA_START                           = OPENAPI_E_START + 800,            /* SDK错误码开始标记，无实际意义 SDK error code start marker, no practical meaning */
    OPENAPI_E_COMMON_NO_INIT                        = OPENAPI_E_MEDIA_START + 1,        /* 未初始化 Not initialized */
    OPENAPI_E_COMMON_NO_MEMORY                      = OPENAPI_E_MEDIA_START + 2,        /* 内存分配失败 Memory allocation failed */
    OPENAPI_E_COMMON_NOT_SUPPORT                    = OPENAPI_E_MEDIA_START + 3,        /* 不支持功能 Function not supported */
    OPENAPI_E_COMMON_NVALID_PARAMETER               = OPENAPI_E_MEDIA_START + 4,        /* 参数不正确 Parameter incorrect */
    OPENAPI_E_COMMON_PASSWORD_UPDATE_FAIL           = OPENAPI_E_MEDIA_START + 5,        /* 更新密码失败 Password update failed */

    /* 媒体相关错误码 - 通用错误码 */
    OPENAPI_E_MEDIA_FAIL                            = OPENAPI_E_MEDIA_START + 100,      /* 执行失败 Execute failed */
    OPENAPI_E_MEDIA_INVALID_PARAM                   = OPENAPI_E_MEDIA_START + 101,      /* 参数非法 Invalid parameter */
    OPENAPI_E_MEDIA_NULL_PTR                        = OPENAPI_E_MEDIA_START + 102,      /* 指针为空 Pointer is null */
    OPENAPI_E_MEDIA_NO_MEMORY                       = OPENAPI_E_MEDIA_START + 103,      /* 系统内存不足 System memory insufficient */
    OPENAPI_E_MEDIA_PORT_INVALID                    = OPENAPI_E_MEDIA_START + 104,      /* 非法通道号 Invalid channel number */
    OPENAPI_E_MEDIA_NOT_SUPPORT                     = OPENAPI_E_MEDIA_START + 105,      /* 功能不支持 Function not supported */
    OPENAPI_E_MEDIA_UNSUPPORT_FMT                   = OPENAPI_E_MEDIA_START + 106,      /* 不支持的格式 Unsupported format */
    OPENAPI_E_MEDIA_GET_MORE_DATA                   = OPENAPI_E_MEDIA_START + 107,      /* 需要继续获取拼好的帧 Need to continue getting assembled frames */
    OPENAPI_E_MEDIA_SYS_FAIL                        = OPENAPI_E_MEDIA_START + 108,      /* 系统方法调用失败 System method call failed */
    OPENAPI_E_MEDIA_CREATE_THREAD_FAIL              = OPENAPI_E_MEDIA_START + 109,      /* 线程创建失败 Thread creation failed */
    OPENAPI_E_MEDIA_LOAD_DLL_FAILED                 = OPENAPI_E_MEDIA_START + 110,      /* 加载动态库失败 Dynamic library loading failed */
    OPENAPI_E_MEDIA_STREAM_IN_STARTING              = OPENAPI_E_MEDIA_START + 111,      /* 异步启流中 Stream starting asynchronously */
    OPENAPI_E_MEDIA_GPU_DECODE_NOT_ENABLE           = OPENAPI_E_MEDIA_START + 112,      /* 未使能硬解 Hardware decoding not enabled */
    OPENAPI_E_MEDIA_WND_IS_NOT_VISIBLE              = OPENAPI_E_MEDIA_START + 113,      /* 窗口不可见 Window is not visible */
    OPENAPI_E_MEDIA_STREAM_ALREADY_START            = OPENAPI_E_MEDIA_START + 114,      /* 已启动码流 Stream already started */
    OPENAPI_E_MEDIA_RECORD_ALREADY_START            = OPENAPI_E_MEDIA_START + 115,      /* 已启动录像 Recording already started */
    OPENAPI_E_MEDIA_FILE_ALREADY_PLAY               = OPENAPI_E_MEDIA_START + 116,      /* 已启动文件播放 File playback already started */
    OPENAPI_E_MEDIA_NOT_GET_STREAM_INFO             = OPENAPI_E_MEDIA_START + 117,      /* 未获取到流信息 Stream information not obtained */
    OPENAPI_E_MEDIA_GET_PORT_RES_FAIL               = OPENAPI_E_MEDIA_START + 118,      /* 获取播放通道资源失败 Failed to get playback channel resources */
    OPENAPI_E_MEDIA_RES_NOT_EXIST                   = OPENAPI_E_MEDIA_START + 119,      /* 资源不存在 Resource does not exist */
    OPENAPI_E_MEDIA_LOG_CLOSE                       = OPENAPI_E_MEDIA_START + 120,      /* 已停止打印日志 Logging has been stopped */

    /* 运行过程上报 */
    OPENAPI_E_MEDIA_AUDIO_EXIST                     = OPENAPI_E_MEDIA_START + 189,      /* 码流中存在音频 Audio exists in stream */
    OPENAPI_E_MEDIA_VIDEO_EXIST                     = OPENAPI_E_MEDIA_START + 190,      /* 码流中存在视频 Video exists in stream */
    OPENAPI_E_MEDIA_PLAYBACK_FINISH                 = OPENAPI_E_MEDIA_START + 191,      /* 回放结束（从RTP解析） Playback finished (from RTP parsing) */
    OPENAPI_E_MEDIA_FIRSTFRAME_FINISH               = OPENAPI_E_MEDIA_START + 192,      /* 首帧解码完成 First frame decoding completed */
    OPENAPI_E_MEDIA_VIDEO_NET_STUCK                 = OPENAPI_E_MEDIA_START + 193,      /* 检测到网络卡顿 Network congestion detected */
    OPENAPI_E_MEDIA_MERGE_FINISH                    = OPENAPI_E_MEDIA_START + 194,      /* 文件合并完成 File merge completed */
    OPENAPI_E_MEDIA_DROP_CACHED_FRAMES              = OPENAPI_E_MEDIA_START + 195,      /* 缓存过多，主动丢包 Too much cache, actively dropping packets */

    /* 音频模块错误码 */
    OPENAPI_E_MEDIA_MIC_NOT_EXIST                   = OPENAPI_E_MEDIA_START + 316,      /* 麦克风不存在 Microphone does not exist */
    OPENAPI_E_MEDIA_MIXER_OPEN_DEV_FAIL             = OPENAPI_E_MEDIA_START + 317,      /* 打开混音器输入设备失败 Failed to open mixer input device */
    OPENAPI_E_MEDIA_MIXER_GET_DEV_INFO_FAIL         = OPENAPI_E_MEDIA_START + 318,      /* 获取混音器输入设备信息失败 Failed to get mixer input device information */
    OPENAPI_E_MEDIA_MIXER_GET_LINE_INFO_FAIL        = OPENAPI_E_MEDIA_START + 319,      /* 获取指定的首个音频线路信息失败 Failed to get specified first audio line information */
    OPENAPI_E_MEDIA_MIXER_GET_LINE_CONTROL_FAIL     = OPENAPI_E_MEDIA_START + 320,      /* 获取波形音频输入混音器音频标识失败 Failed to get waveform audio input mixer audio identifier */
    OPENAPI_E_MEDIA_MIXER_SET_CONTROL_DETAIL_FAIL   = OPENAPI_E_MEDIA_START + 321,      /* 设置控制信息失败 Failed to set control information */
    OPENAPI_E_MEDIA_MIXER_GET_CONTROL_DETAIL_FAIL   = OPENAPI_E_MEDIA_START + 322,      /* Mixer获取控制信息失败 Mixer failed to get control information */
    OPENAPI_E_MEDIA_CAP_DEVICE_CREATE_FAIL          = OPENAPI_E_MEDIA_START + 323,      /* 音频捕获设备对象创建失败 Audio capture device object creation failed */
    OPENAPI_E_MEDIA_CAP_BUFFER_CREATE_FAIL          = OPENAPI_E_MEDIA_START + 324,      /* 音频捕获缓存创建失败 Audio capture buffer creation failed */
    OPENAPI_E_MEDIA_SET_NOTIFY_POSITION_FAIL        = OPENAPI_E_MEDIA_START + 325,      /* 音频捕获设置通知位置失败 Audio capture set notification position failed */
    OPENAPI_E_MEDIA_CAPTURE_FAIL                    = OPENAPI_E_MEDIA_START + 326,      /* 音频采集实例内部错误 Audio capture instance internal error */
    OPENAPI_E_MEDIA_MCM_SPEAKER_NOT_EXIST           = OPENAPI_E_MEDIA_START + 327,      /* 扬声器不存在 Speaker does not exist */
    OPENAPI_E_MEDIA_MCM_SPEAKER_MORE_THAN_ONE       = OPENAPI_E_MEDIA_START + 328,      /* 扬声器超过一个 More than one speaker exists */

    OPENAPI_E_MEDIA_CREATE_DEV_FAIL                 = OPENAPI_E_MEDIA_START + 381,      /* 音频播放实例创建失败 Audio playback instance creation failed */
    OPENAPI_E_MEDIA_PLAY_DEVICE_CREATE_FAIL         = OPENAPI_E_MEDIA_START + 382,      /* 音频播放设备初始化失败 Audio playback device initialization failed */
    OPENAPI_E_MEDIA_SET_COORPERATIVA_LEVEL_FAIL     = OPENAPI_E_MEDIA_START + 383,      /* 音频播放设备初始化设置失败 Audio playback device initialization setting failed */
    OPENAPI_E_MEDIA_PLAYER_FAIL                     = OPENAPI_E_MEDIA_START + 384,      /* 音频播放实例内部错误 Audio playback instance internal error */
    OPENAPI_E_MEDIA_GET_PLAY_VOLUME_FAIL            = OPENAPI_E_MEDIA_START + 385,      /* 获取音频播放音量失败 Failed to get audio playback volume */
    OPENAPI_E_MEDIA_SET_PLAY_VOLUME_FAIL            = OPENAPI_E_MEDIA_START + 386,      /* 设置音频播放音量失败 Failed to set audio playback volume */
    OPENAPI_E_MEDIA_LOCK_FAIL                       = OPENAPI_E_MEDIA_START + 387,      /* 音频锁定缓冲区资源失败 Audio lock buffer resources failed */
    OPENAPI_E_MEDIA_UNLOCK_FAIL                     = OPENAPI_E_MEDIA_START + 388,      /* 音频解锁缓冲区资源失败 Audio unlock buffer resources failed */
    OPENAPI_E_MEDIA_LOOP_PLAY_FAIL                  = OPENAPI_E_MEDIA_START + 389,      /* 循环播放音频失败 Loop audio playback failed */
    OPENAPI_E_MEDIA_INPUT_DATA_ZERO                 = OPENAPI_E_MEDIA_START + 390,      /* 音频输入数据长度为0 Audio input data length is 0 */
    OPENAPI_E_MEDIA_POINTER_INVALID                 = OPENAPI_E_MEDIA_START + 391,      /* 音频句柄指针非法 Audio handle pointer invalid */
    OPENAPI_E_MEDIA_GET_PLAY_POSITION_FAIL          = OPENAPI_E_MEDIA_START + 392,      /* 获取音频播放位置失败 Failed to get audio playback position */
    OPENAPI_E_MEDIA_SET_PLAY_POSITION_FAIL          = OPENAPI_E_MEDIA_START + 393,      /* 设置音频播放位置失败 Failed to set audio playback position */
    OPENAPI_E_MEDIA_PLAY_BUFFER_HIGH_LEVEL          = OPENAPI_E_MEDIA_START + 394,      /* 音频播放缓冲区高水位 Audio playback buffer high water level */
    OPENAPI_E_MEDIA_PLAY_BUFFER_LOW_LEVEL           = OPENAPI_E_MEDIA_START + 395,      /* 音频播放缓冲区低水位 Audio playback buffer low water level */

    /* 文件播放错误码 */
    OPENAPI_E_MEDIA_GET_PIC_HW_FAIL                 = OPENAPI_E_MEDIA_START + 445,      /* 获取图像宽高失败 Failed to get image width and height */
    OPENAPI_E_MEDIA_DECODER_OUTPUT_FAIL             = OPENAPI_E_MEDIA_START + 446,      /* 解码输出设置失败 Decoder output setting failed */
    OPENAPI_E_MEDIA_FILESRC_END                     = OPENAPI_E_MEDIA_START + 447,      /* 文件读取结束 File reading ended */
    OPENAPI_E_MEDIA_FILESRC_NOT_OPEN                = OPENAPI_E_MEDIA_START + 448,      /* 文件没有打开 File not opened */
    OPENAPI_E_MEDIA_FILESRC_READ_FAIL               = OPENAPI_E_MEDIA_START + 449,      /* 读文件失败 File reading failed */
    OPENAPI_E_MEDIA_FILESRC_DESTROY                 = OPENAPI_E_MEDIA_START + 450,      /* 文件损坏 File corrupted */
    OPENAPI_E_MEDIA_FILESRC_CLOSE_FAIL              = OPENAPI_E_MEDIA_START + 451,      /* 关闭文件失败 File closing failed */
    OPENAPI_E_MEDIA_FILESRC_OPEN_FAIL               = OPENAPI_E_MEDIA_START + 452,      /* 打开文件操作失败 File opening operation failed */
    OPENAPI_E_MEDIA_FILESRC_INDEX_FAIL              = OPENAPI_E_MEDIA_START + 453,      /* 文件索引失败 File indexing failed */
    OPENAPI_E_MEDIA_FILESRC_FSEEK_FAIL              = OPENAPI_E_MEDIA_START + 454,      /* 文件跳播失败 File skip playback failed */
    OPENAPI_E_MEDIA_FILESRC_FAIL_TO_BUILD_INDEX     = OPENAPI_E_MEDIA_START + 455,      /* 文件索引创建失败 File index creation failed */
    OPENAPI_E_MEDIA_FILESRC_FILE_READ_HEAD          = OPENAPI_E_MEDIA_START + 456,      /* 读取到文件开始 Read to file beginning */
    OPENAPI_E_MEDIA_FILESRC_PAYLOAD_INVALID         = OPENAPI_E_MEDIA_START + 457,      /* 不支持录制的负载格式 Unsupported payload format for recording */
    OPENAPI_E_MEDIA_FILESRC_CODEC_INVALID           = OPENAPI_E_MEDIA_START + 458,      /* 不支持录制的编码格式 Unsupported codec format for recording */
    OPENAPI_E_MEDIA_FILESRC_WRITE_FRAME_FAIL        = OPENAPI_E_MEDIA_START + 459,      /* 录制视频帧错误 Video frame recording error */
    OPENAPI_E_MEDIA_FILESRC_WRITE_AUDIO_FAIL        = OPENAPI_E_MEDIA_START + 460,      /* 录制音频帧错误 Audio frame recording error */
    OPENAPI_E_MEDIA_FILESRC_SET_PLAYTIME_FAIL       = OPENAPI_E_MEDIA_START + 461,      /* 设置跳转位置失败 Failed to set jump position */
    OPENAPI_E_MEDIA_FILESRC_UNKNOWN_STREAM_TYPE     = OPENAPI_E_MEDIA_START + 462,      /* 文件中存在无效码流格式 Invalid stream format exists in file */
    OPENAPI_E_MEDIA_FILE_SPELL_FAIL                 = OPENAPI_E_MEDIA_START + 463,      /* 拼帧失败 Frame assembly failed */
    OPENAPI_E_MEDIA_PACKET_OVERSIZE                 = OPENAPI_E_MEDIA_START + 464,      /* 数据包过大 Packet too large */
    OPENAPI_E_MEDIA_FILE_JUMP_OVER_LEN              = OPENAPI_E_MEDIA_START + 465,      /* 跳播无效 Skip playback invalid */
    OPENAPI_E_MEDIA_FILE_PAUSE                      = OPENAPI_E_MEDIA_START + 466,      /* 文件处于暂停状态 File is paused */
    OPENAPI_E_MEDIA_FILE_STEP_READ_COMPLETE         = OPENAPI_E_MEDIA_START + 467,      /* 单帧播放结束 Single frame playback ended */
    OPENAPI_E_MEDIA_FILE_FRAMERATE_INVALID          = OPENAPI_E_MEDIA_START + 468,      /* 文件帧率不正确 File frame rate incorrect */
    OPENAPI_E_MEDIA_FILE_PATH_FIND_FAILED           = OPENAPI_E_MEDIA_START + 469,      /* 查找文件路径失败 Failed to find file path */
    OPENAPI_E_MEDIA_FILE_READ_TOO_FAST              = OPENAPI_E_MEDIA_START + 470,      /* 文件读取过快，需减慢读取 File reading too fast, need to slow down */
    OPENAPI_E_MEDIA_FILE_READ_TOO_SLOW              = OPENAPI_E_MEDIA_START + 471,      /* 文件读取过慢，需加快读取 File reading too slow, need to speed up */
    OPENAPI_E_MEDIA_FILE_JUMP_NOW                   = OPENAPI_E_MEDIA_START + 472,      /* 当前文件正在跳转 Current file is jumping */
    OPENAPI_E_MEDIA_FILESRC_HAVE_OPEN               = OPENAPI_E_MEDIA_START + 473,      /* 文件已经打开 File already opened */
    OPENAPI_E_MEDIA_HD_CAPACITY_NOT_ENOUGH          = OPENAPI_E_MEDIA_START + 474,      /* 硬盘空间不足，达到下限（100M）Hard disk space insufficient, reached lower limit (100M) */
    OPENAPI_E_MEDIA_HD_CAPACITY_NOT_ENOUGH_MAX      = OPENAPI_E_MEDIA_START + 475,      /* 硬盘空间不足，达到上报阈值（500M）Hard disk space insufficient, reached reporting threshold (500M) */
    OPENAPI_E_MEDIA_HD_GETDISKSPACE_FAIL            = OPENAPI_E_MEDIA_START + 476,      /* 获取磁盘剩余空间失败 Failed to get disk remaining space */
    OPENAPI_E_MEDIA_VIDEO_RECORD_PART               = OPENAPI_E_MEDIA_START + 477,      /* 录像已分段 Recording has been segmented */
    OPENAPI_E_MEDIA_UCODE_NOT_SUPPORT_BACK          = OPENAPI_E_MEDIA_START + 478,      /* UCODE 文件不支持倒放 UCODE file does not support reverse playback */
    OPENAPI_E_MEDIA_FILE_ENCRYPED                   = OPENAPI_E_MEDIA_START + 479,      /* 文件加密需要输入秘钥 File is encrypted, need to input key */
    OPENAPI_E_MEDIA_RESOLUTION_CHANGE               = OPENAPI_E_MEDIA_START + 480,      /* 媒体流分辨率发生变化 Media stream resolution changed */
    OPENAPI_E_MEDIA_TOO_LARGE                       = OPENAPI_E_MEDIA_START + 481,      /* 设置录像大小超过限制(10-4000M) Set recording size exceeds limit (10-4000M) */
    OPENAPI_E_MEDIA_TOTALTIME_FAIL                  = OPENAPI_E_MEDIA_START + 482,      /* 获取文件时长失败 Failed to get file duration */

    /* 画图元数据 */
    OPENAPI_E_MEDIA_INIT_CREATEDATA_FAIL            = OPENAPI_E_MEDIA_START + 572,      /* 创建绘图整体数据结构失败 Failed to create drawing overall data structure */
    OPENAPI_E_MEDIA_DRAW_NO_GRAPHICS                = OPENAPI_E_MEDIA_START + 573,      /* 未获得绘图器 Drawing device not obtained */
    OPENAPI_E_MEDIA_DRAW_CREATEDIBSECTION_FAIL      = OPENAPI_E_MEDIA_START + 574,      /* 创建与设备无关的位图失败 Failed to create device-independent bitmap */
    OPENAPI_E_MEDIA_CONVERSION_NO_YUVMEMORY         = OPENAPI_E_MEDIA_START + 575,      /* 未获得转YUV可用内存空间 No available YUV conversion memory */
    OPENAPI_E_MEDIA_CONVERSION_OUT_PICTURE          = OPENAPI_E_MEDIA_START + 576,      /* 超过源图片区域 Exceeded source image area */
    OPENAPI_E_MEDIA_IVA_DATA_LEN_INVALID            = OPENAPI_E_MEDIA_START + 577,      /* 画图数据长度不合法 Drawing data length invalid */
    OPENAPI_E_MEDIA_IVA_DATA_POINTER_INVALID        = OPENAPI_E_MEDIA_START + 578,      /* 画图数据指针非法 Drawing data pointer invalid */
    OPENAPI_E_MEDIA_DRAW_LINE_FAIL                  = OPENAPI_E_MEDIA_START + 579,      /* GDI PLUS画线失败 GDI PLUS line drawing failed */
    OPENAPI_E_MEDIA_DRAW_POLYGON_FAIL               = OPENAPI_E_MEDIA_START + 580,      /* GDI PLUS画多边形失败 GDI PLUS polygon drawing failed */
    OPENAPI_E_MEDIA_DRAW_LABEL_LINE_FAIL            = OPENAPI_E_MEDIA_START + 581,      /* GDI PLUS画方向标志线失败 GDI PLUS direction marker line drawing failed */
    OPENAPI_E_MEDIA_DRAW_RECT_LABEL_LINE_FAIL       = OPENAPI_E_MEDIA_START + 582,      /* GDI PLUS画矩形方向标志线失败 GDI PLUS rectangle direction marker line drawing failed */
    OPENAPI_E_MEDIA_DRAW_FISHEYE_WND_FAIL           = OPENAPI_E_MEDIA_START + 583,      /* 根据坐标点绘制窗口边框失败 Failed to draw window border based on coordinate points */

    /* 四目全景PTZ */
    OPENAPI_E_MEDIA_PTZ_RESOUCE_FAIL                = OPENAPI_E_MEDIA_START + 701,      /* 四目全景 ptz资源错误 Four-eye panoramic PTZ resource error */
    OPENAPI_E_MEDIA_PTZ_STREAM_EXIST                = OPENAPI_E_MEDIA_START + 702,      /* 四目全景 ptz流信息存在 Four-eye panoramic PTZ stream information exists */
    OPENAPI_E_MEDIA_PTZ_STREAM_NOT_EXIST            = OPENAPI_E_MEDIA_START + 703,      /* 四目全景 ptz流信息不存在 Four-eye panoramic PTZ stream information does not exist */
    OPENAPI_E_MEDIA_PTZ_GET_WNDID_FROM_POINT_FAIL   = OPENAPI_E_MEDIA_START + 704,      /* 通过点坐标找PTZ窗口号失败 Failed to find PTZ window ID from point coordinates */
    OPENAPI_E_MEDIA_PTZ_NUM_INVALID                 = OPENAPI_E_MEDIA_START + 705,      /* PTZ图像数量非法 Invalid PTZ image count */
    OPENAPI_E_MEDIA_PTZ_POINTER_INVALID             = OPENAPI_E_MEDIA_START + 706,      /* PTZ指针非法 Invalid PTZ pointer */
    OPENAPI_E_MEDIA_PTZ_CREATE_RES_FAIL             = OPENAPI_E_MEDIA_START + 707,      /* PTZ创建图像处理对象失败 PTZ failed to create image processing object */
    OPENAPI_E_MEDIA_PTZ_IMAGE_STITCH_FAIL           = OPENAPI_E_MEDIA_START + 708,      /* PTZ图像拼接失败 PTZ image stitching failed */
    OPENAPI_E_MEDIA_PTZ_IMAGE_PROCESS_FAIL          = OPENAPI_E_MEDIA_START + 709,      /* PTZ图像处理失败 PTZ image processing failed */
    OPENAPI_E_MEDIA_PTZ_RESULT_DATA_LEN_INVALID     = OPENAPI_E_MEDIA_START + 710,      /* PTZ规则信息长度非法 Invalid PTZ rule information length */
    OPENAPI_E_MEDIA_PTZ_NOT_STITCH_MODE             = OPENAPI_E_MEDIA_START + 711,      /* 非PTZ拼接模式 Not PTZ stitching mode */

    /* 鱼眼矫正 */
    OPENAPI_E_MEDIA_FISHEYE_RESOUCE_FAIL            = OPENAPI_E_MEDIA_START + 828,      /* 鱼眼资源错误 Fisheye resource error */
    OPENAPI_E_MEDIA_FISHEYE_GET_WNDID_FROM_POINT_FAIL = OPENAPI_E_MEDIA_START + 829,    /* 通过点坐标查找鱼眼PTZ窗口号失败 Failed to find fisheye PTZ window ID from point coordinates */
    OPENAPI_E_MEDIA_FISHEYE_ADJUST_NOT_NEED         = OPENAPI_E_MEDIA_START + 830,      /* 无需进行鱼眼矫正 No need for fisheye correction */
    OPENAPI_E_MEDIA_FISHEYE_ADJUST_FAIL             = OPENAPI_E_MEDIA_START + 831,      /* 鱼眼矫正失败 Fisheye correction failed */
    OPENAPI_E_MEDIA_FISHEYE_STREAM_EXIST            = OPENAPI_E_MEDIA_START + 832,      /* 鱼眼流信息存在，仅用于上报 Fisheye stream information exists, for reporting only */
    OPENAPI_E_MEDIA_FISHEYE_STREAM_NOT_EXIST        = OPENAPI_E_MEDIA_START + 833,      /* 鱼眼流信息不存在，仅用于上报 Fisheye stream information does not exist, for reporting only */
    OPENAPI_E_MEDIA_FISHEYE_MODE_INVALID            = OPENAPI_E_MEDIA_START + 834,      /* 非法鱼眼模式（非ptz、安装模式） Invalid fisheye mode (not PTZ, installation mode) */
    OPENAPI_E_MEDIA_FISHEYE_POINTER_INVALID         = OPENAPI_E_MEDIA_START + 835,      /* 非法鱼眼数据指针 Invalid fisheye data pointer */
    OPENAPI_E_MEDIA_FISHEYE_PTZ_MODE_INVALID        = OPENAPI_E_MEDIA_START + 836,      /* 非法鱼眼ptz模式 Invalid fisheye PTZ mode */
    OPENAPI_E_MEDIA_FISHEYE_FIX_MODE_INVALID        = OPENAPI_E_MEDIA_START + 837,      /* 非法鱼眼安装模式 Invalid fisheye installation mode */

    /* POS信息 */
    OPENAPI_E_MEDIA_POS_STREAM_EXIST                = OPENAPI_E_MEDIA_START + 957,      /* 码流中存在POS信息 POS information exists in stream */
    OPENAPI_E_MEDIA_POS_STREAM_NOT_EXIST            = OPENAPI_E_MEDIA_START + 958,      /* 码流中不存在POS信息 POS information does not exist in stream */

    /* 流模块错误码 */
    OPENAPI_E_MEDIA_URL_NOT_STANDARD                = OPENAPI_E_MEDIA_START + 1084,     /* URL不标准 URL not standard */
    OPENAPI_E_MEDIA_URL_NO_USER                     = OPENAPI_E_MEDIA_START + 1085,     /* URL未携带用户名 URL does not carry username */
    OPENAPI_E_MEDIA_URL_NO_PASSWORD                 = OPENAPI_E_MEDIA_START + 1086,     /* URL未携带密码 URL does not carry password */
    OPENAPI_E_MEDIA_NEED_AUTH                       = OPENAPI_E_MEDIA_START + 1087,     /* 需传入用户名&密码进行鉴权 Need to pass username & password for authentication */
    OPENAPI_E_MEDIA_AUTH_TYPE_UNKNOWN               = OPENAPI_E_MEDIA_START + 1088,     /* 鉴权类型未知 Unknown authentication type */
    OPENAPI_E_MEDIA_AUTH_FAIL                       = OPENAPI_E_MEDIA_START + 1089,     /* 鉴权失败 Authentication failed */
    OPENAPI_E_MEDIA_RTSP_MSG_PARSE_FAIL             = OPENAPI_E_MEDIA_START + 1090,     /* RTSP消息解析失败 RTSP message parsing failed */
    OPENAPI_E_MEDIA_NET_FAIL                        = OPENAPI_E_MEDIA_START + 1091,     /* 网络错误 Network error */
    OPENAPI_E_MEDIA_NET_TIMEOUT                     = OPENAPI_E_MEDIA_START + 1092,     /* 网络超时 Network timeout */
    OPENAPI_E_MEDIA_INTERACTION_ERROR               = OPENAPI_E_MEDIA_START + 1093,     /* 流交互错误 Stream interaction error */
    OPENAPI_E_MEDIA_DEVICE_ERROR                    = OPENAPI_E_MEDIA_START + 1094,     /* 设备内部错误 Device internal error */
    OPENAPI_E_MEDIA_STREAM_ASYNC_SUCCEED            = OPENAPI_E_MEDIA_START + 1095,     /* 异步启流成功 Asynchronous stream start succeeded */
    OPENAPI_E_MEDIA_ADDRESSINUSE                    = OPENAPI_E_MEDIA_START + 1096,     /* 网络端口被占用 Network port in use */
    OPENAPI_E_MEDIA_MEDIA_UNREADY                   = OPENAPI_E_MEDIA_START + 1097,     /* 媒体流未就绪 Media stream not ready */
    OPENAPI_E_MEDIA_HLS_NO_M3U8                     = OPENAPI_E_MEDIA_START + 1098,     /* 云存储回放未设置M3U8数据 Cloud storage playback not set M3U8 data */
    OPENAPI_E_MEDIA_HLS_NODE_NOT_EXIST              = OPENAPI_E_MEDIA_START + 1099,     /* 云存储回放未查询到指定播放节点 Cloud storage playback did not find specified playback node */
    OPENAPI_E_MEDIA_FLV_PARSE_FAIL                  = OPENAPI_E_MEDIA_START + 1100,     /* FLV格式解析失败 FLV format parsing failed */
    OPENAPI_E_MEDIA_RTMP_CONNECT_FAIL               = OPENAPI_E_MEDIA_START + 1101,     /* RTMP 连接失败 RTMP connection failed */

    OPENAPI_E_MEDIA_STREAM_NUM_FULL                 = OPENAPI_E_MEDIA_START + 1149,     /* 流数量已满 Stream count full */
    OPENAPI_E_MEDIA_STREAM_PLAY_COMPLETE            = OPENAPI_E_MEDIA_START + 1150,     /* 流播放完成 Stream playback completed */
    OPENAPI_E_MEDIA_STREAM_THIRD_STOP               = OPENAPI_E_MEDIA_START + 1151,     /* 第三方停止流 Third party stopped stream */
    OPENAPI_E_MEDIA_STREAM_UPDATE                   = OPENAPI_E_MEDIA_START + 1152,     /* 码流类型更新 Stream type updated */
    OPENAPI_E_MEDIA_STREAM_STOP                     = OPENAPI_E_MEDIA_START + 1153,     /* 服务器国标流停止 Server GB stream stopped */
    OPENAPI_E_MEDIA_STREAM_DEV_SLEEP                = OPENAPI_E_MEDIA_START + 1154,     /* 设备已休眠 Device is sleeping */
    OPENAPI_E_MEDIA_STREAM_TYPE_MAIN                = OPENAPI_E_MEDIA_START + 1155,     /* 当前流是主流 Current stream is main stream */
    OPENAPI_E_MEDIA_STREAM_TYPE_SUB                 = OPENAPI_E_MEDIA_START + 1156,     /* 当前流是辅流 Current stream is sub stream */
    OPENAPI_E_MEDIA_STREAM_TYPE_THIRD               = OPENAPI_E_MEDIA_START + 1157,     /* 当前流是第三流 Current stream is third stream */
    OPENAPI_E_MEDIA_STREAM_OVER_ABILITY             = OPENAPI_E_MEDIA_START + 1158,     /* 服务器流规格满 Server stream specification full */
    OPENAPI_E_MEDIA_STREAM_NOT_FOUND_RECORD         = OPENAPI_E_MEDIA_START + 1159,     /* 回放未查询到录像 Playback did not find recording */
    OPENAPI_E_MEDIA_STREAM_PLAY_ABNORMAL            = OPENAPI_E_MEDIA_START + 1160,     /* 播放失败 Playback failed */
    OPENAPI_E_MEDIA_HLS_DOWNLOAD_FINISH             = OPENAPI_E_MEDIA_START + 1161,     /* 云存储回放：内部下载任务完成 Cloud storage playback: internal download task completed */
    OPENAPI_E_MEDIA_HLS_DOWNLOAD_FAILED             = OPENAPI_E_MEDIA_START + 1162,     /* 云存储回放：内部下载出错 Cloud storage playback: internal download error */
    OPENAPI_E_MEDIA_HLS_PARSE_DOMAIN_FAIL           = OPENAPI_E_MEDIA_START + 1163,     /* 云存储回放：解析M3U8内部域名出错 Cloud storage playback: parsing M3U8 internal domain error */
    OPENAPI_E_MEDIA_HLS_NETWORK_POOR                = OPENAPI_E_MEDIA_START + 1164,     /* 云存储回放：网络较差 Cloud storage playback: poor network */
    OPENAPI_E_MEDIA_HLS_PLAY_FINISH                 = OPENAPI_E_MEDIA_START + 1165,     /* 云存储回放：播放完成 Cloud storage playback: playback completed */
    OPENAPI_E_MEDIA_RTMP_INIT_FAIL                  = OPENAPI_E_MEDIA_START + 1166,     /* RTMP初始化失败 RTMP initialization failed */

    /* 截图错误码 */
    OPENAPI_E_MEDIA_SNAP_FINISH                     = OPENAPI_E_MEDIA_START + 1213,     /* 截图结束 Screenshot finished */
    OPENAPI_E_MEDIA_JPEG_ENC_FAIL                   = OPENAPI_E_MEDIA_START + 1214,     /* JPEG编码失败 JPEG encoding failed */
    OPENAPI_E_MEDIA_CREATE_ENCODER_FAIL             = OPENAPI_E_MEDIA_START + 1215,     /* 创建编码器失败 Encoder creation failed */
    OPENAPI_E_MEDIA_SNAP_NOT_GET_DATA               = OPENAPI_E_MEDIA_START + 1216,     /* 未获取到图像数据 Image data not obtained */
    OPENAPI_E_MEDIA_MAX                             = OPENAPI_E_START       + 2899      /* 媒体模块错误码最大值 Media module error code maximum value */

}OPENAPI_ERR_CODE;

/**
* @enum tagOpenAPILogLevel
* @brief 日志级别 Log level
* @attention 无 None
*/
typedef enum tagOpenAPILogLevel
{
    OPENAPI_LOG_LEVEL_CLOSE    = 0,            /* 关闭日志，不输出任何日志信息 Close log, no log output */
    OPENAPI_LOG_LEVEL_FATAL    = 1,            /* 只记录致命错误日志，系统无法继续运行的严重错误 Only log FATAL level, critical errors that prevent system from running */
    OPENAPI_LOG_LEVEL_ERROR    = 2,            /* 记录错误日志，包括FATAL和ERROR级别的错误 Log ERROR level, including FATAL and ERROR messages */
    OPENAPI_LOG_LEVEL_WARN     = 3,            /* 记录警告日志，包括FATAL、ERROR和WARN级别的信息 Log WARN level, including FATAL, ERROR and WARN messages */
    OPENAPI_LOG_LEVEL_INFO     = 4,            /* 记录一般信息日志，包括FATAL、ERROR、WARN和INFO级别的信息 Log INFO level, including FATAL, ERROR, WARN and INFO messages */
    OPENAPI_LOG_LEVEL_DEBUG    = 5,            /* 记录调试日志，包含所有级别的日志信息，用于开发调试 Log DEBUG level, all level messages for development debugging */
    OPENAPI_LOG_LEVEL_INVALID  = 0xff          /* 无效的日志级别值 Invalid log level value */
}OPENAPI_LOG_LEVEL_E;

/**
* @enum tagOpenAPIConfigKey
* @brief 配置键 Configuration key
* @attention 无 None
*/
typedef enum tagOpenAPIConfigKey
{
    CONFIG_LOG_LEVEL     = 1,            /* 日志级别 参考 OPENAPI_LOG_LEVEL_E Log level, see OPENAPI_LOG_LEVEL_E */
    CONFIG_NET_TIMEOUT   = 2,            /* 网络交互超时时间,单位秒,当前默认5秒 范围(0,30] Network interaction timeout, in seconds, default is 5 seconds Range(0,30] */
    CONFIG_INVALID       = 0xff          /* 无效值 Invalid value */
}OPENAPI_CONFIG_KEY;

/**
* @enum tagOpenAPIStreamQuality
* @brief 视频流质量 Video stream quality
* @attention 无 None
 */
typedef enum tagOpenAPIStreamQuality
{
    OPENAPI_STREAM_QUALITY_HD            = 0,                /* 高清 High definition */
    OPENAPI_STREAM_QUALITY_SD            = 1,                /* 标清 Standard definition */
    OPENAPI_STREAM_QUALITY_SMOOTH        = 2,                /* 流畅 Smooth */
    OPENAPI_STREAM_QUALITY_INVALID       = 0xff              /* 无效值 Invalid value */
}OPENAPI_STREAM_QUALITY_E;

/**
* @enum tagOpenAPIStreamType
* @brief 流类型 Stream type
* @attention 无 None
 */
typedef enum tagOpenAPIStreamType
{
    OPENAPI_STREAM_TYPE_LOCAL            = 0,                /* 本地录像 Local record */
    OPENAPI_STREAM_TYPE_CLOUD            = 1,                /* 云存录像 Cloud record */
    OPENAPI_STREAM_TYPE_INVALID          = 0xff              /* 无效值 Invalid value */
}OPENAPI_STREAM_TYPE_E;

/**
* @enum tagOpenAPITransportProtocol
* @brief 视频传输协议 Video transport protocol
* @attention 无 None
 */
typedef enum tagOpenAPITransportProtocol
{
    OPENAPI_PROTOCOL_RTP_TCP            = 0,                /* TCP */
    OPENAPI_PROTOCOL_RTP_UDP            = 1,                /* UDP */
    OPENAPI_PROTOCOL_INVALID            = 0xff              /* 无效值 Invalid value */
}OPENAPI_PROTOCOL_E;

/**
* @enum tagOpenAPIFileFormate
* @brief 文件格式类型 File format types
* @attention 无 None
*/
typedef enum tagOpenAPIFileFormate
{
    OPENAPI_FILE_FORMATE_MP4                           = 0,        /* MP4格式视频+音频文件，由API指定 MP4 format video+audio file, specified by API */
    OPENAPI_FILE_FORMATE_TS                            = 1,        /* TS格式视频+音频文件，由API指定 TS format video+audio file, specified by API */
    OPENAPI_FILE_FORMATE_FMP4                          = 2,        /* FMP4格式视频+音频文件 FMP4 format video+audio file */
    OPENAPI_FILE_FORMATE_MP4_ADD_TIME                  = 3,        /* MP4格式视频+音频文件，自动添加系统时间到文件名 MP4 format video+audio file, automatically add system time to filename */
    OPENAPI_FILE_FORMATE_TS_ADD_TIME                   = 4,        /* TS格式视频+音频文件，自动添加系统时间到文件名 TS format video+audio file, automatically add system time to filename */
    OPENAPI_FILE_FORMATE_AUDIO_TS                      = 5,        /* TS格式音频文件(单声道音频)，由API指定 TS format audio file (mono audio), specified by API */
    OPENAPI_FILE_FORMATE_AUDIO_MP4                     = 6,        /* MP4格式音频文件(单声道音频)，由API指定 MP4 format audio file (mono audio), specified by API */
    OPENAPI_FILE_FORMATE_AUDIO_TS_ADD_TIME             = 7,        /* TS格式音频文件(单声道音频)，自动添加系统时间到文件名 TS format audio file (mono audio), automatically add system time to filename */
    OPENAPI_FILE_FORMATE_AUDIO_MP4_ADD_TIME            = 8,        /* MP4格式音频文件(单声道音频)，自动添加系统时间到文件名 MP4 format audio file (mono audio), automatically add system time to filename */
    OPENAPI_FILE_FORMATE_MP4_ADD_RCD_TIME              = 9,        /* MP4格式视频+音频文件，自动添加录像时间到文件名 MP4 format video+audio file, automatically add recording time to filename */
    OPENAPI_FILE_FORMATE_TS_ADD_RCD_TIME               = 10,       /* TS格式视频+音频文件，自动添加录像时间到文件名 TS format video+audio file, automatically add recording time to filename */
    OPENAPI_FILE_FORMATE_AUDIO_MP4_ADD_RCD_TIME        = 11,       /* MP4格式音频文件(单声道音频)，自动添加录像时间到文件名 MP4 format audio file (mono audio), automatically add recording time to filename */
    OPENAPI_FILE_FORMATE_AUDIO_TS_ADD_RCD_TIME         = 12,       /* TS格式音频文件(单声道音频)，自动添加录像时间到文件名 TS format audio file (mono audio), automatically add recording time to filename */
    OPENAPI_FILE_FORMATE_VIDEO_MP4_ADD_RCD_TIME        = 13,       /* MP4格式视频文件(单声道音频)，自动添加录像时间到文件名 MP4 format video file (mono audio), automatically add recording time to filename */
    OPENAPI_FILE_FORMATE_VIDEO_TS_ADD_RCD_TIME         = 14,       /* TS格式视频文件(单声道音频)，自动添加录像时间到文件名 TS format video file (mono audio), automatically add recording time to filename */
    OPENAPI_FILE_FORMATE_AVI                           = 15,       /* AVI格式视频+音频文件，由API指定 AVI format video+audio file, specified by API */
    OPENAPI_FILE_FORMATE_AVI_ADD_TIME                  = 16,       /* AVI格式视频+音频文件，自动添加系统时间到文件名 AVI format video+audio file, automatically add system time to filename */
    OPENAPI_FILE_FORMATE_AUDIO_AVI                     = 17,       /* AVI格式音频文件(单声道音频)，由API指定 AVI format audio file (mono audio), specified by API */
    OPENAPI_FILE_FORMATE_AUDIO_AVI_ADD_TIME            = 18,       /* AVI格式音频文件(单声道音频)，自动添加系统时间到文件名 AVI format audio file (mono audio), automatically add system time to filename */
    OPENAPI_FILE_FORMATE_AVI_ADD_RCD_TIME              = 19,       /* AVI格式视频+音频文件，自动添加录像时间到文件名 AVI format video+audio file, automatically add recording time to filename */
    OPENAPI_FILE_FORMATE_AUDIO_AVI_ADD_RCD_TIME        = 20,       /* AVI格式音频文件(单声道音频)，自动添加录像时间到文件名 AVI format audio file (mono audio), automatically add recording time to filename */
    OPENAPI_FILE_FORMATE_VIDEO_AVI_ADD_RCD_TIME        = 21,       /* AVI格式视频文件(单声道音频)，自动添加录像时间到文件名 AVI format video file (mono audio), automatically add recording time to filename */
    OPENAPI_FILE_FORMATE_HIK_PRIVATE                   = 22,       /* 海康私有格式 Hikvision private format */
    OPENAPI_FILE_FORMATE_DAHUA_PRIVATE                 = 23,       /* 大华私有格式 Dahua private format */
    OPENAPI_FILE_FORMATE_MOBOTIX_PRIVATE               = 24,       /* Mobotix私有格式 Mobotix private format */
    OPENAPI_FILE_FORMATE_SVAC_PRIVATE                  = 25,       /* SVAC私有格式 SVAC private format */
    OPENAPI_FILE_FORMATE_INVALID                       = 0xff      /* 无效值 Invalid value */
}OPENAPI_FILE_FORMATE_E;

/**
* @enum tagOpenAPIPictureFormat
* @brief 图片格式枚举定义 Picture format enumeration definition
* @attention 无 None
 */
typedef enum tagOpenAPIPictureFormat
{
    OPENAPI_PICTURE_BMP     = 0,                  /* 图片格式为bmp格式 Picture format is bmp */
    OPENAPI_PICTURE_JPG     = 1,                  /* 图片格式为jpg格式 Picture format is jpg */
    OPENAPI_PICTURE_INVALID = 0xff                /* 无效值 Invalid value */
}OPENAPI_PICTURE_FORMAT_E;

/**
* @enum tagOpenAPIVideoFrameType
* @brief 视频帧类型枚举定义 Video frame type enumeration definition
* @attention 无 None
 */
typedef enum tagOpenAPIVideoFrameType
{
    OPENAPI_VIDEO_FRAME_I       = 0,               /* I帧 I-frame */
    OPENAPI_VIDEO_FRAME_P       = 1,               /* P帧 P-frame */
    OPENAPI_VIDEO_FRAME_B       = 2,               /* B帧 B-frame */
    OPENAPI_VIDEO_FRAME_INVALID = 0xff             /* 无效值 Invalid value */
}OPENAPI_VIDEO_FRAME_TYPE_E;

/**
* @enum tagOpenAPIWaveFormatInfo
* @brief 解码后音频格式 Wave format info
* @attention 无  None
*/
typedef enum tagOpenAPIWaveFormatInfo
{
    OPENAPI_WAVE_FORMAT_PCM8M16        = 0,        /* PCM,8K采样率,单声道,16位采样 PCM,8k sampling rate,16 bit sampling*/
    OPENAPI_WAVE_FORMAT_PCM16M16       = 1,        /* PCM,16K采样率,单声道,16位采样 PCM,16k sampling rate,16 bit sampling*/
    OPENAPI_WAVE_FORMAT_PCM441M16      = 2,        /* PCM,44.1K采样率,单声道,16位采样 PCM,44.1k sampling rate,16 bit sampling*/
    OPENAPI_WAVE_FORMAT_PCM11025M16    = 3,        /* PCM,11.025K采样率,单声道,16位采样 PCM,11.025k sampling rate,16 bit sampling*/
    OPENAPI_WAVE_FORMAT_PCM8_RIGHT     = 4,        /* PCM，8K采样率，右声道 PCM,8k sampling rate,right channel*/
    OPENAPI_WAVE_FORMAT_PCM_NORMAL     = 5,        /* PCM，通用模式 PCM,general mode*/
    OPENAPI_WAVE_FORMAT_PCM48000M16    = 6,        /* PCM，48.0K采样率，单声道（M），16位采样 PCM,48.0k sampling rate,single track,16 bit sampling*/
    OPENAPI_WAVE_FORMAT_UNKNOWN        = 7         /* 未知 Unknown */
}OPENAPI_WAVE_FORMAT_INFO_E;

/**
* @enum tagOpenAPIEventType
* @brief 事件类型 Event type enumeration
* @attention 无 None
*/
typedef enum tagOpenAPIEventType
{
    OPENAPI_EVENT_TYPE_NETWORK             = 0,        /* 网络事件 Network event */
    OPENAPI_EVENT_TYPE_MEDIA               = 1,        /* 媒体事件 Media event */
    OPENAPI_EVENT_TYPE_ALARM               = 2,        /* 告警事件 Alarm event */
    OPENAPI_EVENT_TYPE_INVALID             = 0xff      /* 无效值 Invalid value */
}OPENAPI_EVENT_TYPE_E;

/**
* @enum tagOpenAPIAlarmEventType
* @brief 智能分析告警事件类型 Intelligent analysis Alarm Event Type
* @attention 无 None
*/
/* 注：告警事件类型枚举已删除，类型信息通过 OPENAPI_EVENT_INFO_S.szMsgType 字符串透传 */

/* 注：事件子类型已改为字符串形式(szMsgType)，不再使用枚举，以直接透传云平台msgType */

/**
* @enum tagOpenAPIStreamDataCBType
* @brief 码流数据回调类型 Stream Data Callback Type
* @attention 参考UMS设计，支持原始码流/拼帧后/解码后三种回调
*/
typedef enum tagOpenAPIStreamDataCBType
{
    OPENAPI_STREAM_CB_TYPE_SOURCE  = 1,   /* 原始码流回调（RTP包） Source stream callback */
    OPENAPI_STREAM_CB_TYPE_PARSE   = 2,   /* 拼帧后回调（NAL单元/ES流） Parsed stream callback */
    OPENAPI_STREAM_CB_TYPE_DECODE  = 3,   /* 解码后回调（YUV帧） Decoded stream callback */
    OPENAPI_STREAM_CB_TYPE_INVALID = 0xff /* 无效值 Invalid value */
}OPENAPI_STREAM_DATA_CB_TYPE_E;

/**
* @enum tagOpenAPIVideoEncodeType
* @brief 视频编码类型 Video Encode Type
* @attention 无 None
*/
typedef enum tagOpenAPIVideoEncodeType
{
    OPENAPI_VIDEO_ENCODE_H264      = 0,   /* H.264编码 H.264 encoding */
    OPENAPI_VIDEO_ENCODE_H265      = 1,   /* H.265编码 H.265 encoding */
    OPENAPI_VIDEO_ENCODE_INVALID   = 0xff /* 无效值 Invalid value */
}OPENAPI_VIDEO_ENCODE_TYPE_E;

/**
* @enum tagOpenAPIAudioEncodeType
* @brief 音频编码类型 Audio Encode Type
* @attention 无 None
*/
typedef enum tagOpenAPIAudioEncodeType
{
    OPENAPI_AUDIO_ENCODE_PCM8M     = 0,    /* PCM，8K采样率 */
    OPENAPI_AUDIO_ENCODE_PCM16M    = 1,    /* PCM，16K采样率 */
    OPENAPI_AUDIO_ENCODE_G711U8M   = 2,    /* G711U，8K采样率 */
    OPENAPI_AUDIO_ENCODE_G711U16M  = 3,    /* G711U，16K采样率 */
    OPENAPI_AUDIO_ENCODE_G711A8M   = 4,    /* G711A，8K采样率 */
    OPENAPI_AUDIO_ENCODE_G711A16M  = 5,    /* G711A，16K采样率 */
    OPENAPI_AUDIO_ENCODE_AAC8M     = 6,    /* AAC，8K采样率 */
    OPENAPI_AUDIO_ENCODE_AAC16M    = 7,    /* AAC，16K采样率 */
    OPENAPI_AUDIO_ENCODE_AAC32M    = 8,    /* AAC，32K采样率 */
    OPENAPI_AUDIO_ENCODE_AAC48M    = 9,    /* AAC，48K采样率 */
    OPENAPI_AUDIO_ENCODE_MP2       = 10,   /* MP2 */
    OPENAPI_AUDIO_ENCODE_SVAC      = 11,   /* SVAC Audio 16位采样率 */
    OPENAPI_AUDIO_ENCODE_NULL      = 12    /* 无音频 */
}OPENAPI_AUDIO_ENCODE_TYPE_E;

/**
* @enum tagOpenAPIMediaEventType
* @brief 媒体事件类型 Media event type enumeration
* @attention 无 None
*/
typedef enum tagOpenAPIMediaEventType
{
    OPENAPI_MEDIA_EVENT_TYPE_RECORD_VIDEO        = 0,        /* 本地录像过程中上报运行信息 Record video event notification */
    OPENAPI_MEDIA_EVENT_TYPE_MEDIA_PROCESS       = 1,        /* 视频媒体处理过程中的上报运行信息 Media processing event notification */
    OPENAPI_MEDIA_EVENT_TYPE_MEDIA_VOICE         = 2,        /* 语音业务过程中上报运行信息 Voice communication event notification */
    OPENAPI_MEDIA_EVENT_TYPE_STREAM              = 3,        /* 网络流过程中上报运行信息 Stream event notification */
    OPENAPI_MEDIA_EVENT_TYPE_SNATCH              = 4,        /* 截图过程中的上报运行信息 Snapshot event notification */
    OPENAPI_MEDIA_EVENT_TYPE_INVALID             = 0xff      /* 无效值 Invalid value */
}OPENAPI_MEDIA_EVENT_TYPE_E;

/**
* @enum tagOpenAPINetworkEventType
* @brief 网络事件类型 Network event type enumeration
* @attention 无 None
*/
typedef enum tagOpenAPINetworkEventType
{
    OPENAPI_NETWORK_EVENT_TYPE_HEARTBEAT_TIMEOUT   = 0,        /* 多次未收到心跳回复 Heartbeat timeout */
    OPENAPI_NETWORK_EVENT_TYPE_INVALID             = 0xff      /* 无效值 Invalid value */
}OPENAPI_NETWORK_EVENT_TYPE_E;

/**
* @enum tagOpenAPIPlayControl
* @brief 播放控制命令枚举定义 Playback control commands enumeration definition
* @attention 无 None
 */
typedef enum tagOpenAPIPlayControl
{
    OPENAPI_PLAY_CTRL_PAUSE                      = 1,        /* 暂停命令 Pause command */
    OPENAPI_PLAY_CTRL_RESUME                     = 2,        /* 恢复命令 Resume command */
    OPENAPI_PLAY_CTRL_GETPLAYTIME                = 3,        /* 获取播放时间 Get play time */
    OPENAPI_PLAY_CTRL_SETPLAYTIME                = 4,        /* 设置播放时间 Set play time */
    OPENAPI_PLAY_CTRL_GETPLAYSPEED               = 5,        /* 获取播放速度 Get play speed */
    OPENAPI_PLAY_CTRL_SETPLAYSPEED               = 6,        /* 设置播放速度 Set play speed */
    OPENAPI_PLAY_CTRL_INVALID                    = 0xff      /* 无效值 Invalid value */
}OPENAPI_VOD_PLAY_CTRL_E;

/**
* @enum tagOpenAPIVodPlayStatus
* @brief 播放和下载状态枚举定义 Playback and download status enumeration definition
* @attention 无 None
 */
typedef enum tagOpenAPIVodPlayStatus
{
    OPENAPI_PLAY_STATUS_QUARTER_FORWARD          = 0,            /* 1/4前进速度 1/4 forward speed */
    OPENAPI_PLAY_STATUS_HALF_FORWARD             = 1,            /* 1/2前进速度 1/2 forward speed */
    OPENAPI_PLAY_STATUS_1_FORWARD                = 2,            /* 正常前进速度 Normal forward speed */
    OPENAPI_PLAY_STATUS_2_FORWARD                = 3,            /* 2倍前进速度 2x forward speed */
    OPENAPI_PLAY_STATUS_4_FORWARD                = 4,            /* 4倍前进速度 4x forward speed */
    OPENAPI_PLAY_STATUS_8_FORWARD                = 5,            /* 8倍前进速度 8x forward speed */
    OPENAPI_PLAY_STATUS_16_FORWARD               = 6,            /* 16倍前进速度 16x forward speed */
    OPENAPI_PLAY_STATUS_16_BACKWARD              = 7,            /* 16倍后退速度 16x backward speed */
    OPENAPI_PLAY_STATUS_8_BACKWARD               = 8,            /* 8倍后退速度 8x backward speed */
    OPENAPI_PLAY_STATUS_4_BACKWARD               = 9,            /* 4倍后退速度 4x backward speed */
    OPENAPI_PLAY_STATUS_2_BACKWARD               = 10,           /* 2倍后退速度 2x backward speed */
    OPENAPI_PLAY_STATUS_1_BACKWARD               = 11,           /* 正常后退速度 Normal backward speed */
    OPENAPI_PLAY_STATUS_HALF_BACKWARD            = 12,           /* 1/2后退速度 1/2 backward speed */
    OPENAPI_PLAY_STATUS_QUARTER_BACKWARD         = 13,           /* 1/4后退速度 1/4 backward speed */
    OPENAPI_PLAY_STATUS_2_FORWARD_IFRAME         = 14,           /* 2倍前进速度(I帧) 2x forward speed (I-frame) */
    OPENAPI_PLAY_STATUS_4_FORWARD_IFRAME         = 15,           /* 4倍前进速度(I帧) 4x forward speed (I-frame) */
    OPENAPI_PLAY_STATUS_8_FORWARD_IFRAME         = 16,           /* 8倍前进速度(I帧) 8x forward speed (I-frame) */
    OPENAPI_PLAY_STATUS_16_FORWARD_IFRAME        = 17,           /* 16倍前进速度(I帧) 16x forward speed (I-frame) */
    OPENAPI_PLAY_STATUS_2_BACKWARD_IFRAME        = 18,           /* 2倍后退速度(I帧) 2x backward speed (I-frame) */
    OPENAPI_PLAY_STATUS_4_BACKWARD_IFRAME        = 19,           /* 4倍后退速度(I帧) 4x backward speed (I-frame) */
    OPENAPI_PLAY_STATUS_8_BACKWARD_IFRAME        = 20,           /* 8倍后退速度(I帧) 8x backward speed (I-frame) */
    OPENAPI_PLAY_STATUS_16_BACKWARD_IFRAME       = 21,           /* 16倍后退速度(I帧) 16x backward speed (I-frame) */
    OPENAPI_PLAY_STATUS_INTELLIGENT_FORWARD      = 22,           /* 智能播放 Intelligent forward */
    OPENAPI_PLAY_STATUS_1_FRAME_FORWARD          = 23,           /* 单帧前进 One frame forward */
    OPENAPI_PLAY_STATUS_I_FRAME_BACKWARD         = 24,           /* 单帧(I帧)后退 One frame backward (I-frame)  */
    OPENAPI_PLAY_STATUS_40_FORWARD               = 25,           /* 40倍速前进播放度 40x forward speed */
    OPENAPI_PLAY_STATUS_32_FORWARD_IFRAME        = 26,           /* 32倍速抽帧前进播放 Play forward at 32x speed with keyframe stepping */
    OPENAPI_PLAY_STATUS_32_BACKWARD_IFRAME       = 27,           /* 32倍速抽帧后退播放 Play backward at 32x speed with keyframe stepping */
    OPENAPI_PLAY_STATUS_64_FORWARD_IFRAME        = 28,           /* 64倍速抽帧前进播放 Play forward at 64x speed with keyframe stepping */
    OPENAPI_PLAY_STATUS_64_BACKWARD_IFRAME       = 29,           /* 64倍速抽帧后退播放 Play backward at 64x speed with keyframe stepping */
    OPENAPI_PLAY_STATUS_128_FORWARD_IFRAME       = 30,           /* 128倍速抽帧前进播放 Play forward at 128x speed with keyframe stepping */
    OPENAPI_PLAY_STATUS_128_BACKWARD_IFRAME      = 31,           /* 128倍速抽帧后退播放 Play backward at 128x speed with keyframe stepping */
    OPENAPI_PLAY_STATUS_256_FORWARD_IFRAME       = 32,           /* 256倍速抽帧前进播放 Play forward at 256x speed with keyframe stepping */
    OPENAPI_PLAY_STATUS_256_BACKWARD_IFRAME      = 33,           /* 256倍速抽帧后退播放 Play backward at 256x speed with keyframe stepping */
    OPENAPI_PLAY_STATUS_32_FORWARD               = 34,           /* 32倍前进速度 32x forward speed */
    OPENAPI_PLAY_STATUS_32_BACKWARD              = 35,           /* 32倍后退速度 32x backward speed */
    OPENAPI_PLAY_STATUS_FORWORD_TOP_SPEED        = 36,           /* 全速发流，用于下载功能 Maximum forward speed */
    OPENAPI_PLAY_STATUS_ONEEIGHTH_FORWARD        = 37,           /* 1/8前进速度 1/8 forward speed */
    OPENAPI_PLAY_STATUS_THREE_QUARTERS_FORWARD   = 38,           /* 3/4前进速度 3/4 forward speed */
    OPENAPI_PLAY_STATUS_FIVE_FOURTHS_FORWARD     = 39,           /* 5/4前进速度 5/4 forward speed */
    OPENAPI_PLAY_STATUS_ONE_AND_HALF_FORWARD     = 40,           /* 3/2前进速度 3/2 forward speed */
    OPENAPI_PLAY_STATUS_64_FORWARD               = 41,           /* 64倍前进速度 64x forward speed */
    OPENAPI_PLAY_STATUS_SUPER_FAST_FORWARD       = 42,           /* 超快前进 Super fast forward */
    OPENAPI_PLAY_STATUS_AUTO_STEP_FORWARD        = 43,           /* 连续单步前进 Auto step forward */
    OPENAPI_PLAY_STATUS_AUTO_STEP_BACKWARD       = 44,           /* 连续单步后退 Auto step backward */
    OPENAPI_PLAY_STATUS_INVALID                  = 0xff          /* 无效值 Invalid value */
}OPENAPI_VOD_PLAY_STATUS_E;

/**
* @enum tagOpenAPIVideoRawType
* @brief 解码后回调数据类型 Raw video data type
* @attention 无
 */
 typedef enum tagOpenAPIVideoRawType
 {
     OPENAPI_VIDEO_RAW_YUV420    = 0,           /* YV12原始数据格式，默认 YV12 raw data format, default */
     OPENAPI_VIDEO_RAW_NV12      = 1,           /* NV12原始数据格式 NV12 raw data format */
     OPENAPI_VIDEO_RAW_DXVA2_VLD = 2,           /* DXVA2 VLD原始数据格式 DXVA2 VLD raw data format */
     OPENAPI_VIDEO_RAW_D3D11     = 3,           /* D3D11原始数据格式 D3D11 raw data format */
     OPENAPI_VIDEO_RAW_DRM       = 4,           /* DRM原始数据格式 DRM raw data format */
     OPENAPI_VIDEO_RAW_RGBA      = 5,           /* RGBA原始数据格式 RGBA raw data format */
     OPENAPI_VIDEO_RAW_INVALID   = 0xff         /* 无效值 Invalid value */
 }OPENAPI_VIDEO_RAW_TYPE_E;


/**
* @enum tagOpenAPIDeviceType
* @brief 设备类型 Device type
* @attention 无 None
 */
 typedef enum tagOpenAPIDeviceType
 {
     OPENAPI_DEVICE_TYPE_UNKNOWN   = -1,          /* 未知设备 Unknown device */
     OPENAPI_DEVICE_TYPE_IPC       = 0,           /* IPC */
     OPENAPI_DEVICE_TYPE_NVR       = 1,           /* NVR */
     OPENAPI_DEVICE_TYPE_VMS       = 2,           /* VMS */
     OPENAPI_DEVICE_TYPE_DVR       = 3,           /* DVR */
     OPENAPI_DEVICE_TYPE_EC        = 4,           /* EC编码器 */
     OPENAPI_DEVICE_TYPE_DC        = 5,           /* DC解码器 */
     OPENAPI_DEVICE_TYPE_PTS       = 6,           /* 门禁 */
     OPENAPI_DEVICE_TYPE_RADAR     = 13,          /* 雷达设备 Radar device */
     OPENAPI_DEVICE_TYPE_INVALID   = 0xff         /* 无效值 Invalid value */
 }OPENAPI_DEVICE_TYPE_E;

 /**
* @enum tagOpenAPIStatus
* @brief 在线状态
* @attention 无 None
 */
 typedef enum tagOpenAPIStatus
 {
     OPENAPI_STATUS_OFFLINE    = 0,           /* 离线 Offline */
     OPENAPI_STATUS_ONLINE     = 1,           /* 在线 Online */
     OPENAPI_STATUS_INVALID    = 0xff         /* 无效值 Invalid value */
 }OPENAPI_STATUS_E;

 /**
* @enum tagOpenAPISharedType
* @brief 共享设备类型 Shared device type
* @attention 无 None
 */
 typedef enum tagOpenAPISharedType
 {
     OPENAPI_SHARED_TYPE_NONE              = 0,           /* 非共享 Not shared */
     OPENAPI_SHARED_TYPE_ORGANIZATION      = 1,           /* 组织共享 Shared by organization */
     OPENAPI_SHARED_TYPE_DEVICE            = 2,           /* 设备共享 Shared by device */
     OPENAPI_SHARED_TYPE_INVALID           = 0xff         /* 无效值 Invalid value */
 }OPENAPI_SHARED_TYPE_E;

 /**
 * @enum tagOpenAPIPtzCmdEnum
 * @brief 云台命令 枚举定义 PTZ commands Enumeration definition
 * @attention 无 None
 */
typedef enum tagOpenAPIPtzCmdEnum
{
    OPENAPI_PTZ_IRISCLOSE_STOP       =0x0101,        /* 光圈关停止  Iris close stop */
    OPENAPI_PTZ_IRISCLOSE            =0x0102,        /* 光圈关  Iris close */
    OPENAPI_PTZ_IRISOPEN_STOP        =0x0103,        /* 光圈开停止  Iris open stop */
    OPENAPI_PTZ_IRISOPEN             =0x0104,        /* 光圈开  Iris open */

    OPENAPI_PTZ_FOCUSNEAR_STOP       =0x0201,        /* 近聚集停止  Focus near stop */
    OPENAPI_PTZ_FOCUSNEAR            =0x0202,        /* 近聚集  Focus near */
    OPENAPI_PTZ_FOCUSFAR_STOP        =0x0203,        /* 远聚集停止  Focus far stop */
    OPENAPI_PTZ_FOCUSFAR             =0x0204,        /* 远聚集  Focus far */

    OPENAPI_PTZ_ZOOMTELE_STOP        = 0x0301,       /* 放大停止  Zoom in stop */
    OPENAPI_PTZ_ZOOMTELE             = 0x0302,       /* 放大  Zoom in */
    OPENAPI_PTZ_ZOOMWIDE_STOP        = 0x0303,       /* 缩小停止  Zoom out stop */
    OPENAPI_PTZ_ZOOMWIDE             = 0x0304,       /* 缩小  Zoom out */

    OPENAPI_PTZ_TILTUP               = 0x0402,       /* 向上  Tilt up */
    OPENAPI_PTZ_TILTDOWN             = 0x0404,       /* 向下  Tilt down */
    OPENAPI_PTZ_PANRIGHT             = 0x0502,       /* 向右  Pan right */
    OPENAPI_PTZ_PANLEFT              = 0x0504,       /* 向左  Pan left */
    OPENAPI_PTZ_LEFTUP               = 0x0702,       /* 左上  Move up left */
    OPENAPI_PTZ_LEFTDOWN             = 0x0704,       /* 左下  Move down left */
    OPENAPI_PTZ_RIGHTUP              = 0x0802,       /* 右上  Move up right */
    OPENAPI_PTZ_RIGHTDOWN            = 0x0804,       /* 右下  Move down right */

    OPENAPI_PTZ_ALLSTOP              = 0x0901,       /* 全停命令字  All-stop command word */

    OPENAPI_PTZ_BRUSHON              = 0x0A01,        /* 雨刷开  Wiper on */
    OPENAPI_PTZ_BRUSHOFF             = 0x0A02,        /* 雨刷关  Wiper off */
    OPENAPI_PTZ_BRUSHAUTO            = 0x0A03,        /* 自动雨刷  Auto wiper */

    OPENAPI_PTZ_LIGHTON              = 0x0B01,        /* 灯开  Lamp on */
    OPENAPI_PTZ_LIGHTOFF             = 0x0B02,        /* 灯关  Lamp off */

    OPENAPI_PTZ_HEATON               = 0x0C01,        /* 加热开  Heater on */
    OPENAPI_PTZ_HEATOFF              = 0x0C02,        /* 加热关  Heater off */

    OPENAPI_PTZ_INFRAREDON           = 0x0D01,        /* 红外开  IR on */
    OPENAPI_PTZ_INFRAREDOFF          = 0x0D02,        /* 红外关  IR off */

    OPENAPI_PTZ_PRESET_CRUISE_START  = 0x1001,        /* 云台按预置位巡航  PTZ preset cruise start */
    OPENAPI_PTZ_PRESET_CRUISE_STOP   = 0x1002,        /* 云台按预置位巡航关闭  PTZ preset cruise stop */

    OPENAPI_PTZ_SNOW_REMOVAL_START   = 0x1301,        /* 触发除雪模式  Trigger snow removal mode */
    OPENAPI_PTZ_SNOW_REMOVAL_STOP    = 0x1302,        /* 停止除雪模式  Stop snow removal mode */

    OPENAPI_PTZ_FAN_START            = 0x1401,        /* 开启风扇  Start fan */
    OPENAPI_PTZ_FAN_STOP             = 0x1402,        /* 停止风扇  Stop fan */
    OPENAPI_PTZ_LOCK_ON              = 0x1403,        /* 云台锁定开启  PTZ lock on */
    OPENAPI_PTZ_LOCK_OFF             = 0x1404,        /* 云台锁定关闭  PTZ lock off */

    OPENAPI_PTZ_SELF_CHECKING        = 0x1801,        /* 恢复球机云台默认物理参数配置或云台自检  Restore default PTZ physical parameters or self-check */
    OPENAPI_PTZ_INVALID              = 0xffff         /* 无效值 Invalid value */

} OPENAPI_PTZ_E;

/**
 * @enum tagOpenAPIAudioVoiceType
 * @brief 音频编码格式枚举定义 Audio encoding format enumeration definition
 * @attention 无 None
 */
typedef enum tagOpenAPIAudioVoiceType
{
    OPENAPI_AUDIO_VOICE_G711U   = 0,            /* 音频符合G.711U律标准 Audio complies with G.711 U-law standard */
    OPENAPI_AUDIO_VOICE_MP2     = 1,            /* 音频符合MP2编码标准 Audio complies with MP2 encoding standard */
    OPENAPI_AUDIO_VOICE_AAC     = 2,            /* 音频符合AAC编码标准 Audio complies with AAC encoding standard */
    OPENAPI_AUDIO_VOICE_G711A   = 3,            /* 音频符合G.711A律标准 Audio complies with G.711 A-law standard */
    OPENAPI_AUDIO_VOICE_PCMA    = 4,            /* 音频符合PCMA律标准 Audio complies with PCMA law standard */
    OPENAPI_AUDIO_VOICE_INVALID = 0xff          /* 无效值 Invalid value */
}OPENAPI_AUDIO_VOICE_TYPE_E;

/**
 * @enum tagOpenAPIConnectMode
 * @brief 连接模式枚举定义
 * @attention 无 None
 */
typedef enum tagOpenAPIConnectMode
{
    OPENAPI_HOLE_PUNCHING_THEN_FORWARD    = 0,            /* 打洞->转发(串行)  Hole punching then forward (serial) */
    OPENAPI_HOLE_PUNCHING_AND_FORWARD     = 1,            /* 打洞+转发(并行)，默认方式  Hole punching and forward (parallel), default mode */
    OPENAPI_HOLE_PUNCHING_ONLY            = 2,            /* 打洞  Hole punching only */
    OPENAPI_FORWARD_ONLY                  = 3,            /* 转发  Forward only */
    OPENAPI_CONNECT_MODE_INVALID          = 0xff          /* 无效值 Invalid value */
}OPENAPI_CONNECT_MODE_E;

/**
 * @enum tagOpenAPIPictureFluency
 * @brief 图像播放流畅性 Picture fluency
 * @attention 无
*/
typedef enum tagOpenAPIPictureFluency
{
    OPENAPI_PICTURE_REAL                 = 0,                /* 实时性优先 Real-time first */
    OPENAPI_PICTURE_FLUENCY              = 1,                /* 流畅性优先 Fluency first */
    OPENAPI_PICTURE_BALANCE              = 2,                /* 均衡 Balance */
    OPENAPI_PICTURE_USER_DEFINED         = 3,                /* 自定义-缓冲帧数可配 Custom-defined - configurable buffer frames */
    OPENAPI_PICTURE_NETADJUST            = 4,                /* 网络抖动自适应模式  Network jitter adaptive mode */
    OPENAPI_PICTURE_FLUENCY_INVALID      = 0xff              /* 无效值 Invalid value */
}OPENAPI_PICTURE_FLUENCY_E;

/**
* @enum tagOpenAPINetAdjustKey
* @brief 网络卡顿自适应参数键值 Network stuck adaptive parameter key
* @attention
*          1) 卡顿检测模块注：只有超过卡顿检测阈值的时长才会被累加进卡顿累计时间 Stuck detection module: Only duration exceeding the stuck detection threshold will be added to the total stuck time
*/
typedef enum tagOpenAPINetAdjustKey
{
    OPENAPI_NETADJUST_KEY_DELAYLIMIT     = 0,                /* 延时大小上限，单位second，默认5s Delay upper limit, unit: second, default: 5s */
    OPENAPI_NETADJUST_KEY_SPEEDLIMIT     = 1,                /* 播放加速上限，默认200% Playback speed upper limit, default: 200% */
    OPENAPI_NETADJUST_KEY_UNKNOWN
}OPENAPI_NETADJUST_KEY_E;

/**
* @enum tagOpenAPINetStuckKey
* @brief 网络卡顿参数键值 Network stuck parameter key
* @attention
*          1) 卡顿检测阈值：持续该时长未收到视频帧，才判断作为卡顿，单位：ms； Stuck detection threshold: Duration without receiving video frames to be considered stuck, unit: ms;
*          2) 严重卡顿检测阈值：当持续该时长未接收到视频帧时，会直接上报卡顿事件，单位：ms；Severe stuck detection threshold: Duration without receiving video frames to directly report stuck event, unit: ms;
*          3) 频繁卡顿检测阈值：在检测周期内，超过卡顿检测阈值的卡顿时长累计超过该值时，会上报卡顿事件，单位：ms；Frequent stuck detection threshold: In detection period, total stuck time exceeding this value will report stuck event, unit: ms.
*/
typedef enum tagOpenAPINetStuckKey
{
    OPENAPI_NETSTUCK_KEY_BOTTOM_LIMIT    = 0,                /* 卡顿检测阈值 Stuck detection threshold */
    OPENAPI_NETSTUCK_KEY_TOP_LIMIT       = 1,                /* 严重卡顿检测阈值 Severe stuck detection threshold */
    OPENAPI_NETSTUCK_KEY_SUM_LIMIT       = 2,                /* 频繁卡顿检测阈值 Frequent stuck detection threshold */
    OPENAPI_NETSTUCK_KEY_UNKNOWN
}OPENAPI_NETSTUCK_KEY_E;

/**
 * @enum tagOpenAPIPtzMode
 * @brief PTZ模式枚举（鱼眼矫正模式） PTZ mode enumeration (fisheye correction mode)
 * @attention 无 None
 */
typedef enum tagOpenAPIPtzMode
{
    OPENAPI_PTZ_MODE_ORIGINAL          = 0,   /* 原始图像（关闭矫正） Original image (correction disabled) */
    OPENAPI_PTZ_MODE_180               = 1,   /* 2×180度模式 2x180 degree mode */
    OPENAPI_PTZ_MODE_360_1PTZ          = 2,   /* 360度+1PTZ模式 360 degree + 1PTZ mode */
    OPENAPI_PTZ_MODE_360_6PTZ          = 3,   /* 360度+6PTZ模式 360 degree + 6PTZ mode */
    OPENAPI_PTZ_MODE_FISH_3PTZ         = 4,   /* 鱼眼+3PTZ模式 Fisheye + 3PTZ mode */
    OPENAPI_PTZ_MODE_FISH_MID_ON_4PTZ  = 5,   /* 鱼眼在中间且显示+4PTZ Fisheye in middle and display + 4PTZ */
    OPENAPI_PTZ_MODE_FISH_MID_OFF_4PTZ = 6,   /* 鱼眼在中间不显示+4PTZ Fisheye in middle not display + 4PTZ */
    OPENAPI_PTZ_MODE_FISH_LEFT_4PTZ    = 7,   /* 鱼眼左边+4PTZ Fisheye left + 4PTZ */
    OPENAPI_PTZ_MODE_FISH_8PTZ         = 8,   /* 鱼眼+8PTZ Fisheye + 8PTZ */
    OPENAPI_PTZ_MODE_PANORAMA          = 9,   /* 全景模式 Panorama mode */
    OPENAPI_PTZ_MODE_PR_3PTZ           = 10,  /* 全景+3PTZ Panorama + 3PTZ */
    OPENAPI_PTZ_MODE_PR_4PTZ           = 11,  /* 全景+4PTZ Panorama + 4PTZ */
    OPENAPI_PTZ_MODE_PR_8PTZ           = 12,  /* 全景+8PTZ Panorama + 8PTZ */
    OPENAPI_PTZ_MODE_1PTZ              = 13,  /* 1PTZ模式 1PTZ mode */
    OPENAPI_PTZ_MODE_NOPR_4PTZ         = 14,  /* 4PTZ，无鱼眼或全景 4PTZ, no fisheye or panorama */
    OPENAPI_PTZ_MODE_INVALID           = 0xff /* 无效值 Invalid value */
}OPENAPI_PTZ_MODE_E;

/**
 * @enum tagOpenAPIFixMode
 * @brief 安装模式枚举 Installation mode enumeration
 * @attention 无 None
 */
typedef enum tagOpenAPIFixMode
{
    OPENAPI_FIX_MODE_TOP_INSTALLATION    = 0,  /* 顶部安装（吸顶） Top installation (ceiling) */
    OPENAPI_FIX_MODE_BOTTOM_INSTALLATION = 1,  /* 底部安装（桌面） Bottom installation (desktop) */
    OPENAPI_FIX_MODE_SIDE_INSTALLATION   = 2,  /* 侧面安装（壁装） Side installation (wall) */
    OPENAPI_FIX_MODE_INVALID             = 0xff /* 无效值 Invalid value */
}OPENAPI_FIX_MODE_E;

/**
 * @enum tagOpenAPIVideoCBType
 * @brief 视频回调数据来源类型 Video callback data source type
 * @attention 无 None
 */
typedef enum tagOpenAPIVideoCBType
{
    OPENAPI_VIDEO_CB_DEFAULT        = 0,  /* 解码后数据回调（矫正前原始帧） Decoded data callback (original frame before correction) */
    OPENAPI_VIDEO_CB_PROCESSED_DATA = 1,  /* 鱼眼矫正后数据回调 Fisheye corrected data callback */
    OPENAPI_VIDEO_CB_MAX
}OPENAPI_VIDEO_CB_TYPE_E;

// ==================== 结构体定义 Structure Definitions ====================

/**
* @struct tagOpenAPIStreamDataCB
* @brief 流数据回调信息 Stream data callback information
* @attention 无 None
 */
typedef struct tagOpenAPIStreamDataCB
{
    BOOL        bDecode;                /* 是否需要显示 Enable display */
    LPVOID      lpVideoDataCB;          /* 解码后视频回调函数 Video data callback function */
    LPVOID      lpAudioDataCB;          /* 解码后音频回调函数 Audio data callback function */
    LPVOID      lpUserData;             /* 用户数据 User data */
    BYTE        byRes[100];             /* 保留字段 Reserved field */
}OPENAPI_STREAM_DATA_CB_S, *LPOPENAPI_STREAM_DATA_CB_S;

/**
* @struct tagOpenAPIParseVideoData
* @brief 拼帧后视频流数据信息 Parsed Video Data Information
* @attention 对应Common SDK的COMMON_PARSE_VIDEO_DATA_S，输出H.264/H.265 NAL单元
*/
typedef struct tagOpenAPIParseVideoData
{
    LPVOID                      lpData;             /* 数据指针（NAL单元） Data pointer (NAL unit) */
    INT32                       dwDataLen;          /* 数据长度 Data length */
    OPENAPI_VIDEO_ENCODE_TYPE_E enEncodeType;       /* 编码类型：H264/H265 Encode type */
    INT32                       dwFrameType;        /* 帧类型：0=I帧, 1=P帧, 2=B帧 Frame type */
    INT64                       ullTimeStamp;       /* 时间戳（毫秒） Timestamp (ms) */
    INT32                       dwWidth;            /* 视频宽度 Video width */
    INT32                       dwHeight;           /* 视频高度 Video height */
    INT32                       dwFrameRate;        /* 帧率 Frame rate */
    BYTE                        byRes[32];          /* 保留 Reserved */
}OPENAPI_PARSE_VIDEO_DATA_S, *LPOPENAPI_PARSE_VIDEO_DATA_S;

/**
* @struct tagOpenAPIStreamDataCBEx
* @brief 扩展码流数据回调信息（兼容多种码流类型） Extended Stream Data Callback Information
* @attention 参考UMS的UMSSDK_STREAM_DATA_CB_S设计
*/
typedef struct tagOpenAPIStreamDataCBEx
{
    OPENAPI_STREAM_DATA_CB_TYPE_E   enCBType;         /* 码流回调类型 Stream callback type */
    BOOL                            bDecode;          /* 是否需要显示 Enable display */
    LPVOID                          lpVideoDataCB;    /* 视频回调函数指针 Video callback function pointer */
    LPVOID                          lpAudioDataCB;    /* 音频回调函数指针 Audio callback function pointer */
    LPVOID                          lpUserData;       /* 用户数据 User data */
    BYTE                            byRes[64];        /* 保留字段 Reserved field */
}OPENAPI_STREAM_DATA_CB_EX_S, *LPOPENAPI_STREAM_DATA_CB_EX_S;

/**
* @struct tagOpenAPIStreamInfo
* @brief 媒体流信息 Media Stream Information
* @attention 无 None
*/
typedef struct tagOpenAPIStreamInfo
{
    INT32                       dwBitRate;            /* 码率 Bit rate */
    INT32                       dwRecvPktNum;         /* 总包数 Total packet number */
    INT32                       dwLostPktNum;         /* 丢包数 Lost packet number */
    INT32                       dwFrameRate;          /* 帧率 Frame rate */
    INT32                       dwWidth;              /* 视频宽 Video width */
    INT32                       dwHeight;             /* 视频高 Video height */
    OPENAPI_VIDEO_ENCODE_TYPE_E enVideoEncodeType;    /* 视频编码格式 Video encode type */
    OPENAPI_AUDIO_ENCODE_TYPE_E enAudioEncodeType;    /* 音频编码格式 Audio encode type */
    BYTE                        byRes[32];            /* 保留字段 Reserved field */
}OPENAPI_STREAM_INFO_S, *LPOPENAPI_STREAM_INFO_S;

/**
* @struct tagOpenAPIPictureData
* @brief 图像数据结构体定义 存放解码后图像数据的指针和长度等信息 Picture data structure definition, for preview image data pointers and statistical information
* @attention 无 None
 */
typedef struct tagOpenAPIPictureData
{
    BYTE                     *pucData[4];                 /* YV12格式数据，pucData[0]:Y平面指针，pucData[1]:U平面指针，pucData[2]:V平面指针 YV12 format data, pucData[0]: Y plane pointer, pucData[1]: U plane pointer, pucData[2]: V plane pointer */
    INT32                    dwLineSize[4];               /* ulLineSize[0]:Y平面每行跨距, ulLineSize[1]:U平面每行跨距, ulLineSize[2]:V平面每行跨距 ulLineSize[0]: Y plane line size, ulLineSize[1]: U plane line size, ulLineSize[2]: V plane line size */
    INT32                    dwPicHeight;                 /* 图片高度 Picture height */
    INT32                    dwPicWidth;                  /* 图片宽度 Picture width */
    INT32                    dwFrameRate;                 /* 帧率 Frame rate */
    INT64                    tRenderTime;                 /* 用于渲染的时间数据 Rendering timestamp */
    OPENAPI_VIDEO_RAW_TYPE_E enDataType;                  /* 解码后数据格式 Raw data format */
    BYTE                     byRes[36];                   /* 保留字段 Reserved field */
}OPENAPI_PICTURE_DATA_S, *LPOPENAPI_PICTURE_DATA_S;

/**
* @struct tagOpenAPIWaveData
* @brief 音频数据 结构体定义 存放解码后音频数据的指针和长度等信息 Audio data structure definition - stores pointers and length information of decoded audio data.
* @attention 无 None
 */
typedef struct tagOpenAPIWaveData
{
    CHAR                       *pcData;                      /* 音频数据指针 Audio data pointer */
    INT32                      dwDataLen;                    /* 音频数据长度 Audio data length */
    OPENAPI_WAVE_FORMAT_INFO_E enWaveFormat;                 /* 解码后音频格式 Audio format */
    BYTE                       byRes[32];                    /* 保留字段 Reserved field */
}OPENAPI_WAVE_DATA_S, *LPOPENAPI_WAVE_DATA_S;

/**
* @struct tagOpenAPIRealPlayInfo
* @brief 实时预览参数结构定义 Live preview parameters structure definition
* @attention 无 None
 */
typedef struct tagOpenAPIRealPlayInfo
{
    INT32                      dwChannelID;                 /* 通道ID Channel ID */
    OPENAPI_PROTOCOL_E         enProtocol;                  /* 视频传输协议 Video transport protocol */
    OPENAPI_STREAM_QUALITY_E   enQuality;                   /* 视频质量 Video quality */
    LPVOID                     hPlayWnd;                    /* 播放窗口句柄，不需要显示时可设为NULL Play window handle, NULL if no display needed */
    CHAR                       *pcURL;                      /* 外部传入的流URL，非空时跳过内部URL获取 External stream URL. When non-NULL, skip internal URL acquisition */
    BYTE                       byRes[104];                  /* 保留字段 Reserved field */
}OPENAPI_REALPLAY_S, *LPOPENAPI_REALPLAY_S;

/**
* @struct tagOpenAPIPlayBackInfo
* @brief 回放结构定义 Playback structure definition
* @attention 无 None
 */
typedef struct tagOpenAPIPlayBackInfo
{
    INT32                        dwChannelID;               /* 通道ID Channel ID */
    OPENAPI_STREAM_QUALITY_E     enQuality;                 /* 视频质量 Video quality */
    OPENAPI_PROTOCOL_E           enProtocol;                /* 视频传输协议，在enStreamType=OPENAPI_STREAM_TYPE_LOCAL时有效 Video transport protocol, valid when enStreamType=OPENAPI_STREAM_TYPE_LOCAL */
    OPENAPI_VOD_PLAY_STATUS_E    enSpeed;                   /* 播放速度，在enStreamType=OPENAPI_STREAM_TYPE_LOCAL时有效 Play speed, valid when enStreamType=OPENAPI_STREAM_TYPE_LOCAL */
    LPVOID                       hPlayWnd;                  /* 播放窗口句柄，不需要显示时可设为NULL Play window handle, NULL if no display needed */
    INT64                        tStartPlayTime;            /* 开始时间(单位:秒 UTC时间) Start time (unit: seconds UTC time) */
    INT64                        tEndPlayTime;              /* 结束时间(单位:秒 UTC时间) End time (unit: seconds UTC time) */
    CHAR                         *pcURL;                    /* 外部传入的流URL，非空时跳过内部URL获取 External stream URL. When non-NULL, skip internal URL acquisition */
    OPENAPI_STREAM_TYPE_E        enStreamType;              /* 流类型，0=本地录像(默认)，1=云存录像 Stream type, 0=local record (default), 1=cloud record */
    BYTE                         byRes[204];                /* 保留字段 Reserved field */
}OPENAPI_PLAYBACK_S, *LPOPENAPI_PLAYBACK_S;

/**
* @struct tagOpenAPIHlsPlayBackInfo
* @brief HLS回放参数结构体 HLS playback parameter structure
* @attention 无 None
 */
typedef struct tagOpenAPIHlsPlayBackInfo
{
    CHAR                         *pcM3u8;                   /* 设置要播放的录像段的m3u8信息，填NULL为缺省，延后设置 Set the m3u8 info of the recording segment to be played, fill NULL for default, set later */
    INT64                        tiSeekTime;                /* 要播放的时间点（单位：s），填0为缺省 Playback time point (unit: s), fill 0 for default */
    INT64                        tiEndTime;                 /* 播放终止时间点（单位：s），填0为缺省 Playback end time point (unit: s), fill 0 for default */
}OPENAPI_HLS_PLAYBACK_S, *LPOPENAPI_HLS_PLAYBACK_S;

/**
* @struct tagOpenAPIDownloadInfo
* @brief 下载结构定义 Download structure definition
* @attention 无 None
 */
typedef struct tagOpenAPIDownloadInfo
{
    INT32                        dwChannelID;               /* 通道ID Channel ID */
    OPENAPI_PROTOCOL_E           enProtocol;                /* 视频传输协议 Video transport protocol */
    OPENAPI_STREAM_QUALITY_E     enQuality;                 /* 视频质量 Video quality */
    OPENAPI_VOD_PLAY_STATUS_E    enSpeed;                   /* 播放速度 Play speed */
    OPENAPI_FILE_FORMATE_E       enFileFormat;              /* 录像文件格式 Recording file format */
    CHAR                         *pcFileName;               /* 录像文件存放路径，包括文件名（不带后缀名） Recording file path, including file name and extension */
    INT64                        tStartPlayTime;            /* 开始时间(单位:秒 UTC时间) Start time (unit: seconds UTC time) */
    INT64                        tEndPlayTime;              /* 结束时间(单位:秒 UTC时间) End time (unit: seconds UTC time) */
    CHAR                         *pcURL;                    /* 外部传入的流URL，非空时跳过内部URL获取 External stream URL. When non-NULL, skip internal URL acquisition */
    OPENAPI_STREAM_TYPE_E        enStreamType;              /* 流类型，0=本地录像(默认)，1=云存录像 Stream type, 0=local record (default), 1=cloud record */
    BYTE                         byRes[204];                /* 保留字段 Reserved field */
}OPENAPI_DOWNLOAD_S, *LPOPENAPI_DOWNLOAD_S;

/**
* @struct tagstOpenAPIMediaEventInfo
* @brief 媒体事件信息 Media event information
* @attention 无 None
 */
typedef struct tagstOpenAPIMediaEventInfo
{
    OPENAPI_MEDIA_EVENT_TYPE_E  enMediaEventType;              /* 事件类型 Event type */
    OPENAPI_ERR_CODE            enErrCode;                     /* 错误码 Error code */
    INT64                       tPlayBackTime;                 /* 回放绝对时间（单位: s），UTC时间戳 Playback absolute time (unit: seconds UTC time) */
    CHAR                        szFilePath[OPENAPI_LEN_256];   /* 字符串参数 File path string */
    LPVOID                      lpPlayHandle;                  /* 播放句柄 Play handle */
    BYTE                        byRes[128];                    /* 保留字段 Reserved field */
}OPENAPI_MEDIA_EVENT_INFO_S, *LPOPENAPI_MEDIA_EVENT_INFO_S;

/**
* @struct tagstOpenAPINetworkEventInfo
* @brief 网络事件信息 Network event information
* @attention 无 None
 */
typedef struct tagstOpenAPINetworkEventInfo
{
    OPENAPI_NETWORK_EVENT_TYPE_E  enNetworkEventType;          /* 事件类型 Event type */
    INT32                         dwDeviceId;                  /* 设备ID Device ID */
    BYTE                          byRes[128];                  /* 保留字段 Reserved field */
}OPENAPI_NETWORK_EVENT_INFO_S, *LPOPENAPI_NETWORK_EVENT_INFO_S;

/**
* @struct tagstOpenAPIEventInfo
* @brief 事件信息 Event information
* @attention 结构体修改说明：去掉union，stMediaInfo/stNetworkInfo改为独立字段；新增szMsgType字符串和lpEventData用于告警事件的扩展数据；byRes从116缩减为48
*
* szMsgType与lpEventData的映射关系 Mapping between szMsgType and lpEventData:
*   szMsgType="device_alarm"          -> lpEventData转为 LPOPENAPI_DEVICE_ALARM_INFO_S
*   szMsgType="acs_event"             -> lpEventData转为 LPOPENAPI_ACS_EVENT_INFO_S
*   szMsgType="face_capture"          -> lpEventData转为 LPOPENAPI_FACE_CAPTURE_INFO_S
*   szMsgType="vehicle_capture"       -> lpEventData转为 LPOPENAPI_VEHICLE_CAPTURE_INFO_S
*   szMsgType="idcard_comparison"     -> lpEventData转为 LPOPENAPI_IDCARD_COMPARISON_INFO_S
*   szMsgType="face_comparison"       -> lpEventData转为 LPOPENAPI_FACE_COMPARISON_INFO_S
*   szMsgType="people_counting"       -> lpEventData转为 LPOPENAPI_PEOPLE_COUNTING_INFO_S
*   szMsgType="safety_suite_detection"-> lpEventData转为 LPOPENAPI_SAFETY_SUITE_INFO_S
*   szMsgType="behavior_recognition"  -> lpEventData转为 LPOPENAPI_BEHAVIOR_RECOGNITION_INFO_S
*   szMsgType="fast_move_recognition" -> lpEventData转为 LPOPENAPI_FAST_MOVE_INFO_S
*   szMsgType="smoke_fire_detection"  -> lpEventData转为 LPOPENAPI_SMOKE_FIRE_INFO_S
*   szMsgType="temperature_detection" -> lpEventData转为 LPOPENAPI_TEMPERATURE_INFO_S
*   szMsgType="device_onoffline"      -> lpEventData转为 LPOPENAPI_DEVICE_ONOFFLINE_INFO_S
*   szMsgType="channel_onoffline"     -> lpEventData转为 LPOPENAPI_CHANNEL_ONOFFLINE_INFO_S
*   szMsgType="vehicle_comparison"    -> lpEventData转为 LPOPENAPI_VEHICLE_COMPARISON_INFO_S
*   szMsgType="person_health"         -> lpEventData转为 LPOPENAPI_PERSON_HEALTH_INFO_S
*   szMsgType="mixed_target_detection"-> lpEventData转为 LPOPENAPI_MIXED_TARGET_INFO_S
*   szMsgType="people_exist_detection"-> lpEventData转为 LPOPENAPI_PEOPLE_EXIST_INFO_S
*   szMsgType="people_exist_alarm_info"-> lpEventData转为 LPOPENAPI_PEOPLE_EXIST_ALARM_INFO_S
*   szMsgType="person_verification"   -> lpEventData转为 LPOPENAPI_PERSON_VERIFICATION_INFO_S
*   szMsgType="float_person_update"   -> lpEventData转为 LPOPENAPI_FLOAT_PERSON_UPDATE_INFO_S
*   szMsgType="float_person_vertification"-> lpEventData转为 LPOPENAPI_FLOAT_PERSON_VERIFICATION_INFO_S
*   szMsgType="motion_alarm"          -> lpEventData转为 LPOPENAPI_DEVICE_ALARM_INFO_S (与device_alarm同结构)
*/
typedef struct tagstOpenAPIEventInfo
{
    OPENAPI_EVENT_TYPE_E            enEventType;               /* 事件类型 Event type */
    OPENAPI_MEDIA_EVENT_INFO_S      stMediaInfo;               /* 媒体信息，在enEventType=OPENAPI_EVENT_TYPE_MEDIA时有效 Media information, valid when enEventType=OPENAPI_EVENT_TYPE_MEDIA */
    OPENAPI_NETWORK_EVENT_INFO_S    stNetworkInfo;             /* 网络信息，在enEventType=OPENAPI_EVENT_TYPE_NETWORK时有效 Network information, valid when enEventType=OPENAPI_EVENT_TYPE_NETWORK */
    CHAR                            szMsgType[64];             /* 消息类型字符串，对应云平台msgType；在enEventType=OPENAPI_EVENT_TYPE_ALARM时有效；根据此值将lpEventData转为对应的专有结构体指针(详见结构体头部映射表) Message type string corresponding to cloud platform msgType; valid when enEventType=OPENAPI_EVENT_TYPE_ALARM; cast lpEventData to the corresponding specific struct pointer based on this value (see mapping table at struct header) */
    LPVOID                          lpEventData;               /* 指向各类型的专有结构指针，在enEventType=OPENAPI_EVENT_TYPE_ALARM时有效；由SDK内部分配和释放，仅在回调期间有效；根据szMsgType值转为对应结构体指针(详见结构体头部映射表) Pointer to type-specific data, valid when enEventType=OPENAPI_EVENT_TYPE_ALARM; managed by SDK internally, valid only during callback; cast to the corresponding struct pointer based on szMsgType value (see mapping table at struct header) */
    BYTE                            byRes[48];                 /* 保留字段 Reserved field */
}OPENAPI_EVENT_INFO_S, *LPOPENAPI_EVENT_INFO_S;

/* 告警专有结构相关常量 Alarm specific structure constants */
#define OPENAPI_MAX_PIC_NUM              8           /* 最大图片数量 Maximum picture number */
#define OPENAPI_MAX_FACE_NUM             8           /* 最大人脸数量 Maximum face number */
#define OPENAPI_MAX_VEHICLE_NUM          8           /* 最大车辆数量 Maximum vehicle number */
#define OPENAPI_MAX_FIRE_CHANNEL_NUM     8           /* 最大烟火通道数量 Maximum fire channel number */
#define OPENAPI_MAX_ONOFFLINE_CHANNEL_NUM 64         /* 最大上下线通道数量 Maximum onoffline channel number */
#define OPENAPI_MAX_MIXED_TARGET_NUM     8           /* 最大混合目标数量 Maximum mixed target number */
#define OPENAPI_MAX_ALARM_TYPE_NUM       10          /* 最大告警类型数量 Maximum alarm type number */

/**
* @struct tagOpenAPIPictureItem
* @brief 图片项 Picture item
* @attention 无 None
*/
typedef struct tagOpenAPIPictureItem
{
    INT32                       dwIndex;                        /* 图片索引 Picture index */
    CHAR                        szUrl[OPENAPI_LEN_512];        /* 图片URL Picture URL */
    BYTE                        byRes[16];                      /* 保留字段 Reserved field */
}OPENAPI_PICTURE_ITEM_S, *LPOPENAPI_PICTURE_ITEM_S;

/**
* @struct tagOpenAPIRect
* @brief 区域坐标 Rectangle coordinates (x/y/width/height format)
* @attention 与宇视云平台协议定义一致，坐标为万分比[0-10000]
*            Consistent with EzCloud protocol, coordinates are in ten-thousandths [0-10000]
*/
typedef struct tagOpenAPIRect
{
    INT32                       dwX;                            /* 左上角横坐标万分比[0-10000] X coordinate of top-left corner [0-10000] */
    INT32                       dwY;                            /* 左上角纵坐标万分比[0-10000] Y coordinate of top-left corner [0-10000] */
    INT32                       dwWidth;                        /* 宽度万分比[0-10000] Width [0-10000] */
    INT32                       dwHeight;                       /* 高度万分比[0-10000] Height [0-10000] */
    BYTE                        byRes[16];                      /* 保留字段 Reserved field */
}OPENAPI_RECT_S, *LPOPENAPI_RECT_S;

/**
* @struct tagOpenAPIFaceAttribute
* @brief 人脸属性 Face attribute
* @attention 无 None
*/
typedef struct tagOpenAPIFaceAttribute
{
    CHAR                        szGender[OPENAPI_LEN_32];      /* 性别 male/female Gender */
    INT32                       dwAgeRange;                     /* 年龄段 0-未知 1- juvenile(0~6) 2- youth(7~17) 3- young(18~40) 4- middle(41~60) 5- old(61~100) Age range */
    INT32                       dwGlassesFlag;                  /* 是否戴眼镜 0-否 1-是 Glasses flag: 0-no, 1-yes */
    INT32                       dwGlassesStyle;                 /* 眼镜类型 0-未知 1-无框 2-半框 3-全框 Glasses style */
    INT32                       dwMaskFlag;                     /* 是否戴口罩 0-否 1-是 Mask flag: 0-no, 1-yes */
    INT32                       dwHatFlag;                      /* 是否戴帽子 0-否 1-是 Hat flag: 0-no, 1-yes */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_FACE_ATTRIBUTE_S, *LPOPENAPI_FACE_ATTRIBUTE_S;

/**
* @struct tagOpenAPIFaceItem
* @brief 人脸单项 Face capture item
* @attention 无 None
*/
typedef struct tagOpenAPIFaceItem
{
    INT32                       dwId;                           /* 人脸ID Face ID */
    INT32                       dwConfidence;                   /* 置信度 Confidence */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    CHAR                        szFacePicUrl[OPENAPI_LEN_512];  /* 人脸图URL Face picture URL */
    OPENAPI_RECT_S              stFaceRect;                     /* 人脸区域坐标 Face rectangle */
    OPENAPI_FACE_ATTRIBUTE_S    stFaceAttribute;                /* 人脸属性 Face attribute */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_FACE_ITEM_S, *LPOPENAPI_FACE_ITEM_S;

/**
* @struct tagOpenAPIFaceCaptureInfo
* @brief 人脸抓拍消息专有结构 Face capture message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIFaceCaptureInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    INT32                       dwFaceCount;                    /* 人脸数量 Face count */
    OPENAPI_FACE_ITEM_S         astFaceList[OPENAPI_MAX_FACE_NUM]; /* 人脸列表 Face list */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_FACE_CAPTURE_INFO_S, *LPOPENAPI_FACE_CAPTURE_INFO_S;

/**
* @struct tagOpenAPIVehicleInfo
* @brief 车辆信息 Vehicle information
* @attention 无 None
*/
typedef struct tagOpenAPIVehicleInfo
{
    INT32                       dwVehicleType;                  /* 车辆类型 0-未知 1-客车 2-货车 3-轿车 4-面包车 5-小货车 6-行人 7-非机动车 8-三轮车 9-SUV 10-MPV 11-面包车(小) 12-皮卡车 Vehicle type */
    INT32                       dwVehicleColor;                 /* 车辆颜色 0-未知 1-白色 2-银色 3-灰色 4-黑色 5-红色 6-深蓝 7-蓝色 8-黄色 9-绿色 10-棕色 11-粉色 12-紫色 13-深灰 Vehicle color */
    INT32                       dwSpeed;                        /* 速度 Speed */
    INT32                       dwSpeedUnit;                    /* 速度单位 0-公里/小时(km/h) 1-英里/小时(mph) Speed unit */
    INT32                       dwSpeedType;                    /* 速度类型 0-未知 1-瞬时速度 2-平均速度 3-限速 Speed type */
    CHAR                        szVehicleBrand[OPENAPI_LEN_64]; /* 车辆品牌 Vehicle brand */
    INT32                       dwImageDirection;               /* 车辆方向 0-未知 1-由内向外 2-由外向内 3-其他 Image direction */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_VEHICLE_INFO_S, *LPOPENAPI_VEHICLE_INFO_S;

/**
* @struct tagOpenAPIVehicleItem
* @brief 车辆单项 Vehicle capture item
* @attention 无 None
*/
typedef struct tagOpenAPIVehicleItem
{
    INT32                       dwId;                           /* 车辆ID Vehicle ID */
    INT32                       dwConfidence;                   /* 置信度 Confidence */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    CHAR                        szVehiclePicUrl[OPENAPI_LEN_512]; /* 车辆图URL Vehicle picture URL */
    CHAR                        szPlatePicUrl[OPENAPI_LEN_512]; /* 车牌图URL Plate picture URL */
    OPENAPI_RECT_S              stVehicleRect;                  /* 车辆区域坐标 Vehicle rectangle */
    OPENAPI_VEHICLE_INFO_S      stVehicleInfo;                  /* 车辆信息 Vehicle information */
    CHAR                        szLicensePlate[OPENAPI_LEN_64]; /* 车牌号 License plate */
    INT32                       dwPlateColor;                   /* 车牌颜色 0-未知 1-蓝色 2-黄色 3-白色 4-黑色 5-绿色 Plate color */
    INT32                       dwPlateType;                    /* 车牌类型 0-未知 1-蓝牌(小型车) 2-黄牌(大型车) 3-白牌(军警车) 4-黑牌(港澳车) 5-绿牌(新能源车) Plate type */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_VEHICLE_ITEM_S, *LPOPENAPI_VEHICLE_ITEM_S;

/**
* @struct tagOpenAPIPersonItem
* @brief 人员单项 Person capture item
* @attention 无 None
*/
typedef struct tagOpenAPIPersonItem
{
    INT32                       dwId;                           /* 人员ID Person ID */
    INT32                       dwConfidence;                   /* 置信度 Confidence */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    CHAR                        szPersonPicUrl[OPENAPI_LEN_512];/* 人员图URL Person picture URL */
    OPENAPI_RECT_S              stPersonRect;                   /* 人员区域坐标 Person rectangle */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_PERSON_ITEM_S, *LPOPENAPI_PERSON_ITEM_S;

/**
* @struct tagOpenAPINonMotorInfo
* @brief 非机动车信息 Non-motor vehicle information
* @attention 无 None
*/
typedef struct tagOpenAPINonMotorInfo
{
    INT32                       dwNonMotorType;                 /* 非机动车类型 0-未知 1-自行车 2-三轮车 3-电动自行车 4-摩托车 Non-motor type */
    INT32                       dwColor;                        /* 颜色 0-未知 1-白色 2-银色 3-灰色 4-黑色 5-红色 6-深蓝 7-蓝色 8-黄色 9-绿色 10-棕色 11-粉色 12-紫色 13-深灰 Color */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_NON_MOTOR_INFO_S, *LPOPENAPI_NON_MOTOR_INFO_S;

/**
* @struct tagOpenAPINonMotorItem
* @brief 非机动车单项 Non-motor vehicle capture item
* @attention 无 None
*/
typedef struct tagOpenAPINonMotorItem
{
    INT32                       dwId;                           /* 非机动车ID Non-motor ID */
    INT32                       dwConfidence;                   /* 置信度 Confidence */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    CHAR                        szNonMotorPicUrl[OPENAPI_LEN_512];/* 非机动车图URL Non-motor picture URL */
    OPENAPI_RECT_S              stNonMotorRect;                 /* 非机动车区域坐标 Non-motor rectangle */
    OPENAPI_NON_MOTOR_INFO_S    stNonMotorInfo;                 /* 非机动车信息 Non-motor information */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_NON_MOTOR_ITEM_S, *LPOPENAPI_NON_MOTOR_ITEM_S;

/**
* @struct tagOpenAPIVehicleCaptureInfo
* @brief 车辆抓拍消息专有结构 Vehicle capture message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIVehicleCaptureInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    INT32                       dwVehicleCount;                 /* 车辆数量 Vehicle count */
    OPENAPI_VEHICLE_ITEM_S      astVehicleList[OPENAPI_MAX_VEHICLE_NUM]; /* 车辆列表 Vehicle list */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_VEHICLE_CAPTURE_INFO_S, *LPOPENAPI_VEHICLE_CAPTURE_INFO_S;

/**
* @enum tagOpenAPIACSVerifyMode
* @brief 门禁核验模式 Access control verify mode enumeration
* @attention 无 None
*/
typedef enum tagOpenAPIACSVerifyMode
{
    OPENAPI_ACS_VERIFY_CARD                 = 1,    /* 刷卡 Card */
    OPENAPI_ACS_VERIFY_FACE                 = 2,    /* 人脸 Face */
    OPENAPI_ACS_VERIFY_CARD_FACE            = 3,    /* 刷卡+人脸 Card + Face */
    OPENAPI_ACS_VERIFY_IDCARD_FACE          = 4,    /* 人证对比 ID card + Face */
    OPENAPI_ACS_VERIFY_PASSWORD             = 5,    /* 密码 Password */
    OPENAPI_ACS_VERIFY_FINGERPRINT          = 6,    /* 指纹 Fingerprint */
    OPENAPI_ACS_VERIFY_PALM_VEIN            = 7,    /* 掌静脉 Palm vein */
    OPENAPI_ACS_VERIFY_FINGERPRINT_FACE     = 8,    /* 指纹+人脸 Fingerprint + Face */
    OPENAPI_ACS_VERIFY_CARD_PASSWORD        = 9,    /* 刷卡+密码 Card + Password */
    OPENAPI_ACS_VERIFY_INVALID              = 0xff  /* 无效值 Invalid value */
}OPENAPI_ACS_VERIFY_MODE_E;

/**
* @struct tagOpenAPIACSEventInfo
* @brief 门禁事件专有结构 ACS event specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIACSEventInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szEventId[OPENAPI_LEN_64];      /* 事件ID Event ID */
    CHAR                        szChannelName[OPENAPI_LEN_128]; /* 通道名称 Channel name */
    INT32                       dwCardReaderKind;               /* 读卡器类型 0-未知 1-IC卡读卡器 2-身份证读卡器 3-二维码读卡器 4-指纹读卡器 5-人脸读卡器 6-掌静脉读卡器 Card reader kind */
    CHAR                        szCardNo[OPENAPI_LEN_64];       /* 卡号 Card number */
    CHAR                        szPersonNo[OPENAPI_LEN_64];     /* 人员编号 Person number */
    OPENAPI_ACS_VERIFY_MODE_E   enVerifyMode;                   /* 核验模式 Verify mode */
    CHAR                        szFacePicUrl[OPENAPI_LEN_512];  /* 人脸图URL Face picture URL */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    OPENAPI_RECT_S              stFaceRect;                     /* 人脸区域坐标 Face rectangle */
    FLOAT                       fBodyMaxTemperature;            /* 人体最高温度 Body max temperature */
    FLOAT                       fBodyTemperature;               /* 人体温度 Body temperature */
    FLOAT                       fCurrTemperature;               /* 当前温度 Current temperature */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_ACS_EVENT_INFO_S, *LPOPENAPI_ACS_EVENT_INFO_S;

/**
* @struct tagOpenAPIDeviceAlarmInfo
* @brief 设备告警消息专有结构 Device alarm message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIDeviceAlarmInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szAlarmId[OPENAPI_LEN_64];      /* 告警ID Alarm ID */
    INT32                       dwAlarmType;                    /* 告警类型码 Alarm type code */
    CHAR                        szAlarmTypeString[OPENAPI_LEN_64]; /* 告警类型字符串 Alarm type string */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    CHAR                        szAlarmName[OPENAPI_LEN_128];   /* 告警名称 Alarm name */
    INT32                       dwPicCount;                     /* 图片数量 Picture count */
    OPENAPI_PICTURE_ITEM_S      astPictureList[OPENAPI_MAX_PIC_NUM]; /* 图片列表 Picture list */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_DEVICE_ALARM_INFO_S, *LPOPENAPI_DEVICE_ALARM_INFO_S;

/**
* @struct tagOpenAPIAlarmQueryCond
* @brief 历史告警查询条件 History alarm query conditions
* @attention 无 None
*/
typedef struct tagOpenAPIAlarmQueryCond
{
    INT64                       tStartTime;                     /* 开始时间(UTC时间戳) Start time (UTC timestamp) */
    INT64                       tEndTime;                       /* 结束时间(UTC时间戳) End time (UTC timestamp) */
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelNo;                    /* 通道号 Channel ID */
    CHAR                        szAlarmTypeString[OPENAPI_LEN_256]; /* 告警类型字符串，逗号分隔 Alarm type string, comma separated */
    INT32                       dwAlarmTypeNum;                 /* 告警类型数量，0表示不使用alarmType数组 Alarm type count, 0 means not using alarmType array */
    INT32                       adwAlarmType[OPENAPI_MAX_ALARM_TYPE_NUM]; /* 告警类型码数组 Alarm type code array */
    INT32                       dwPageStart;                    /* 分页起始页，默认从0开始 Page start, default 0 */
    INT32                       dwPageSize;                     /* 分页大小，默认10，最大100 Page size, default 10, max 100 */
    BYTE                        byRes[56];                      /* 保留字段 Reserved field */
}OPENAPI_ALARM_QUERY_COND_S, *LPOPENAPI_ALARM_QUERY_COND_S;

/**
* @struct tagOpenAPIAlarmQueryInfo
* @brief 历史告警信息项 History alarm information item
* @attention 无 None
*/
typedef struct tagOpenAPIAlarmQueryInfo
{
    CHAR                        szAlarmId[OPENAPI_LEN_64];      /* 告警ID Alarm ID */
    INT32                       dwAlarmType;                    /* 告警类型码 Alarm type code */
    CHAR                        szAlarmTypeString[OPENAPI_LEN_64]; /* 告警类型字符串 Alarm type string */
    INT64                       tAlarmTime;                     /* 告警时间(UTC时间戳) Alarm time (UTC timestamp) */
    CHAR                        szAlarmName[OPENAPI_LEN_128];   /* 告警设备名称 Alarm device name */
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelNo;                    /* 通道号 Channel ID */
    CHAR                        szPicUrl[OPENAPI_LEN_512];      /* 告警图片URL Alarm picture URL */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_ALARM_QUERY_INFO_S, *LPOPENAPI_ALARM_QUERY_INFO_S;

/**
* @struct tagOpenAPIAlarmQueryResult
* @brief 历史告警查询结果 History alarm query result
* @attention 无 None
*/
typedef struct tagOpenAPIAlarmQueryResult
{
    INT32                       dwTotal;                        /* 总记录数 Total count */
    INT32                       dwAlarmCount;                   /* 本次查询返回的告警数量 Alarm count returned */
    LPOPENAPI_ALARM_QUERY_INFO_S pstAlarmInfo;                  /* 告警信息数组指针（由调用方分配内存）Alarm info array pointer (allocated by caller) */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_ALARM_QUERY_RESULT_S, *LPOPENAPI_ALARM_QUERY_RESULT_S;

/**
* @struct tagOpenAPIIdCardInfo
* @brief 身份证信息 ID card information
* @attention 无 None
*/
typedef struct tagOpenAPIIdCardInfo
{
    CHAR                        szName[OPENAPI_LEN_64];        /* 姓名 Name */
    CHAR                        szGender[OPENAPI_LEN_32];      /* 性别 Gender */
    CHAR                        szBirth[OPENAPI_LEN_32];       /* 出生日期 Birth date */
    CHAR                        szAddr[OPENAPI_LEN_256];       /* 地址 Address */
    CHAR                        szIdCardNo[OPENAPI_LEN_64];    /* 身份证号 ID card number */
    CHAR                        szIssuingAuthority[OPENAPI_LEN_128]; /* 签发机关 Issuing authority */
    CHAR                        szStartDate[OPENAPI_LEN_32];   /* 有效期开始 Start date */
    CHAR                        szEndDate[OPENAPI_LEN_32];     /* 有效期结束 End date */
    INT32                       dwIsLongTermEffective;          /* 是否长期有效 0-否 1-是 Long term effective: 0-no, 1-yes */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_IDCARD_INFO_S, *LPOPENAPI_IDCARD_INFO_S;

/**
* @struct tagOpenAPIIdCardComparisonInfo
* @brief 人证对比事件专有结构 ID card comparison event specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIIdCardComparisonInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    INT32                       dwEventType;                    /* 事件类型 1-人证对比 Event type */
    INT32                       dwCurrentEvent;                 /* 当前事件 1-人证对比认证 Current event */
    CHAR                        szPicUrl[OPENAPI_LEN_512];      /* 抓拍图片URL Capture picture URL */
    CHAR                        szIdCardPicUrl[OPENAPI_LEN_512]; /* 身份证图片URL ID card picture URL */
    OPENAPI_IDCARD_INFO_S       stIdCardInfo;                   /* 身份证信息 ID card information */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_IDCARD_COMPARISON_INFO_S, *LPOPENAPI_IDCARD_COMPARISON_INFO_S;

/**
* @struct tagOpenAPIFaceComparisonPersonInfo
* @brief 人脸比对人员信息 Face comparison person information
* @attention 无 None
*/
typedef struct tagOpenAPIFaceComparisonPersonInfo
{
    CHAR                        szName[OPENAPI_LEN_64];        /* 姓名 Name */
    CHAR                        szGender[OPENAPI_LEN_32];      /* 性别 Gender */
    CHAR                        szBirth[OPENAPI_LEN_32];       /* 出生日期 Birth date */
    INT32                       dwCertificateType;              /* 证件类型 0-身份证 1-护照 2-军官证 3-驾驶证 4-其他 Certificate type */
    CHAR                        szCertificateNo[OPENAPI_LEN_64]; /* 证件号 Certificate number */
    CHAR                        szPersonPicUrl[OPENAPI_LEN_512]; /* 人员图片URL Person picture URL */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_FACE_COMPARISON_PERSON_S, *LPOPENAPI_FACE_COMPARISON_PERSON_S;

/**
* @struct tagOpenAPIFaceComparisonFaceInfo
* @brief 人脸比对的人脸信息 Face comparison face information
* @attention 无 None
*/
typedef struct tagOpenAPIFaceComparisonFaceInfo
{
    INT32                       dwFaceTime;                     /* 人脸时间 Face time */
    INT32                       dwContrastStatus;               /* 比对状态 1-比对成功 Contrast status: 1-success */
    CHAR                        szFacePicUrl[OPENAPI_LEN_512];  /* 人脸图URL Face picture URL */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    OPENAPI_RECT_S              stFaceRect;                     /* 人脸区域坐标 Face rectangle */
    INT32                       dwSimilarity;                   /* 相似度 Similarity */
    OPENAPI_FACE_COMPARISON_PERSON_S stPerson;                  /* 人员信息 Person information */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_FACE_COMPARISON_FACE_S, *LPOPENAPI_FACE_COMPARISON_FACE_S;

/**
* @struct tagOpenAPIFaceComparisonInfo
* @brief 边缘人脸比对消息专有结构 Face comparison message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIFaceComparisonInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    OPENAPI_FACE_COMPARISON_FACE_S stFace;                      /* 人脸信息 Face information */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_FACE_COMPARISON_INFO_S, *LPOPENAPI_FACE_COMPARISON_INFO_S;

/**
* @struct tagOpenAPIPeopleCountingInfo
* @brief 人数统计消息专有结构 People counting message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIPeopleCountingInfo
{
    CHAR                        szId[OPENAPI_LEN_64];           /* 记录ID Record ID */
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT32                       dwEnterNum;                     /* 进入人数 Enter number */
    INT32                       dwLeaveNum;                     /* 离开人数 Leave number */
    INT32                       dwStayNum;                      /* 滞留人数 Stay number */
    INT32                       dwByWayNum;                     /* 经过人数 By way number */
    INT32                       dwTotalEnterNum;                /* 累计进入人数 Total enter number */
    INT32                       dwTotalLeaveNum;                /* 累计离开人数 Total leave number */
    INT32                       dwTotalByWayNum;                /* 累计经过人数 Total by way number */
    INT64                       tMessageTime;                   /* 消息时间(UTC) Message time (UTC) */
    INT64                       tStartTime;                     /* 开始时间(UTC) Start time (UTC) */
    INT64                       tEndTime;                       /* 结束时间(UTC) End time (UTC) */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_PEOPLE_COUNTING_INFO_S, *LPOPENAPI_PEOPLE_COUNTING_INFO_S;

/**
* @struct tagOpenAPISafetySuiteTargetInfo
* @brief 工服工帽检测目标信息 Safety suite detection target information
* @attention 无 None
*/
typedef struct tagOpenAPISafetySuiteTargetInfo
{
    CHAR                        szRecognitionType[OPENAPI_LEN_64]; /* 识别类型 Recognition type */
    CHAR                        szPicUrl[OPENAPI_LEN_512];      /* 目标图片URL Target picture URL */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_SAFETY_SUITE_TARGET_S, *LPOPENAPI_SAFETY_SUITE_TARGET_S;

/**
* @struct tagOpenAPISafetySuiteInfo
* @brief 工服工帽检测事件专有结构 Safety suite detection event specific structure
* @attention 无 None
*/
typedef struct tagOpenAPISafetySuiteInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    OPENAPI_SAFETY_SUITE_TARGET_S stTarget;                      /* 目标信息 Target information */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_SAFETY_SUITE_INFO_S, *LPOPENAPI_SAFETY_SUITE_INFO_S;

/**
* @struct tagOpenAPIBehaviorRecognitionInfo
* @brief 行为识别事件专有结构 Behavior recognition event specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIBehaviorRecognitionInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    OPENAPI_SAFETY_SUITE_TARGET_S stTarget;                      /* 目标信息 Target information */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_BEHAVIOR_RECOGNITION_INFO_S, *LPOPENAPI_BEHAVIOR_RECOGNITION_INFO_S;

/**
* @struct tagOpenAPIFastMoveInfo
* @brief 快速移动检测事件专有结构 Fast move recognition event specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIFastMoveInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    OPENAPI_SAFETY_SUITE_TARGET_S stTarget;                      /* 目标信息 Target information */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_FAST_MOVE_INFO_S, *LPOPENAPI_FAST_MOVE_INFO_S;

/**
* @struct tagOpenAPIFirePointInfo
* @brief 火点信息 Fire point information
* @attention 无 None
*/
typedef struct tagOpenAPIFirePointInfo
{
    INT32                       dwId;                           /* 火点ID Fire point ID */
    INT32                       dwPointCount;                   /* 点数量 Point count */
    OPENAPI_RECT_S              stPointList[OPENAPI_MAX_PIC_NUM]; /* 火点坐标列表 Fire point coordinate list */
    BYTE                        byRes[16];                      /* 保留字段 Reserved field */
}OPENAPI_FIRE_POINT_INFO_S, *LPOPENAPI_FIRE_POINT_INFO_S;

/**
* @struct tagOpenAPIFireChannelInfo
* @brief 烟火通道信息 Fire channel information
* @attention 无 None
*/
typedef struct tagOpenAPIFireChannelInfo
{
    INT32                       dwChannelNo;                    /* 通道号 Channel number */
    FLOAT                       fLensView;                      /* 镜头视角 Lens view angle */
    INT32                       dwFirePointCount;               /* 火点数量 Fire point count */
    OPENAPI_FIRE_POINT_INFO_S   astFirePointList[OPENAPI_MAX_FIRE_CHANNEL_NUM]; /* 火点列表 Fire point list */
    BYTE                        byRes[16];                      /* 保留字段 Reserved field */
}OPENAPI_FIRE_CHANNEL_INFO_S, *LPOPENAPI_FIRE_CHANNEL_INFO_S;

/**
* @struct tagOpenAPIAbsoluteHighInfo
* @brief 绝对高度信息 Absolute high information
* @attention 无 None
*/
typedef struct tagOpenAPIAbsoluteHighInfo
{
    FLOAT                       fElevation;                     /* 海拔高度 Elevation */
    FLOAT                       fAzimuth;                       /* 方位角 Azimuth */
    BYTE                        byRes[16];                      /* 保留字段 Reserved field */
}OPENAPI_ABSOLUTE_HIGH_S, *LPOPENAPI_ABSOLUTE_HIGH_S;

/**
* @struct tagOpenAPISmokeFireInfo
* @brief 烟火检测事件专有结构 Smoke fire detection event specific structure
* @attention 无 None
*/
typedef struct tagOpenAPISmokeFireInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    CHAR                        szVisibleLightUrl[OPENAPI_LEN_512]; /* 可见光图片URL Visible light picture URL */
    CHAR                        szFirePicUrl[OPENAPI_LEN_512];  /* 火点图片URL Fire picture URL */
    CHAR                        szThermalUrl[OPENAPI_LEN_512];  /* 热成像图片URL Thermal picture URL */
    OPENAPI_ABSOLUTE_HIGH_S     stAbsoluteHigh;                 /* 绝对高度信息 Absolute high information */
    INT32                       dwFireChannelCount;             /* 烟火通道数量 Fire channel count */
    OPENAPI_FIRE_CHANNEL_INFO_S astFireChannelList[OPENAPI_MAX_FIRE_CHANNEL_NUM]; /* 烟火通道列表 Fire channel list */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_SMOKE_FIRE_INFO_S, *LPOPENAPI_SMOKE_FIRE_INFO_S;

/**
* @struct tagOpenAPITemperatureInfo
* @brief 温度检测事件专有结构 Temperature detection event specific structure
* @attention 无 None
*/
typedef struct tagOpenAPITemperatureInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    INT32                       dwRuleType;                     /* 规则类型 1-温度规则 Rule type */
    INT32                       dwAlarmCondition;               /* 告警条件 0-未知 1-高于阈值 2-低于阈值 Alarm condition */
    FLOAT                       fThreshold;                     /* 阈值 Threshold */
    INT32                       dwValueType;                    /* 值类型 1-摄氏度 Value type */
    FLOAT                       fAlarmValue;                    /* 告警值 Alarm value */
    CHAR                        szVisibleLightUrl[OPENAPI_LEN_512]; /* 可见光图片URL Visible light picture URL */
    CHAR                        szThermalUrl[OPENAPI_LEN_512];  /* 热成像图片URL Thermal picture URL */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_TEMPERATURE_INFO_S, *LPOPENAPI_TEMPERATURE_INFO_S;

/**
* @struct tagOpenAPIDeviceOnofflineInfo
* @brief 设备上下线消息专有结构 Device onoffline message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIDeviceOnofflineInfo
{
    CHAR                        szDeviceName[OPENAPI_LEN_128];  /* 设备名称 Device name */
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    CHAR                        szOnofflineType[OPENAPI_LEN_32]; /* 上下线类型 online/offline Onoffline type */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_DEVICE_ONOFFLINE_INFO_S, *LPOPENAPI_DEVICE_ONOFFLINE_INFO_S;

/**
* @struct tagOpenAPIChannelOnofflineItem
* @brief 通道上下线单项 Channel onoffline item
* @attention 无 None
*/
typedef struct tagOpenAPIChannelOnofflineItem
{
    INT32                       dwChannelNo;                    /* 通道号 Channel number */
    CHAR                        szChannelName[OPENAPI_LEN_128]; /* 通道名称 Channel name */
    CHAR                        szOnofflineType[OPENAPI_LEN_32]; /* 上下线类型 online/offline Onoffline type */
    BYTE                        byRes[16];                      /* 保留字段 Reserved field */
}OPENAPI_CHANNEL_ONOFFLINE_ITEM_S, *LPOPENAPI_CHANNEL_ONOFFLINE_ITEM_S;

/**
* @struct tagOpenAPIChannelOnofflineInfo
* @brief 通道上下线消息专有结构 Channel onoffline message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIChannelOnofflineInfo
{
    CHAR                        szDeviceName[OPENAPI_LEN_128];  /* 设备名称 Device name */
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    INT32                       dwChannelCount;                 /* 通道数量 Channel count */
    OPENAPI_CHANNEL_ONOFFLINE_ITEM_S astChannelList[OPENAPI_MAX_ONOFFLINE_CHANNEL_NUM]; /* 通道列表 Channel list */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_CHANNEL_ONOFFLINE_INFO_S, *LPOPENAPI_CHANNEL_ONOFFLINE_INFO_S;

/**
* @struct tagOpenAPIVehicleComparisonPlateInfo
* @brief 车辆比对车牌信息 Vehicle comparison plate information
* @attention 无 None
*/
typedef struct tagOpenAPIVehicleComparisonPlateInfo
{
    CHAR                        szPlateNo[OPENAPI_LEN_64];      /* 车牌号 Plate number */
    INT32                       dwPlateType;                    /* 车牌类型 0-未知 1-蓝牌(小型车) 2-黄牌(大型车) 3-白牌(军警车) 4-黑牌(港澳车) 5-绿牌(新能源车) Plate type */
    INT32                       dwPlateColor;                   /* 车牌颜色 0-未知 1-蓝色 2-黄色 3-白色 4-黑色 5-绿色 Plate color */
    BYTE                        byRes[16];                      /* 保留字段 Reserved field */
}OPENAPI_VEHICLE_COMPARISON_PLATE_S, *LPOPENAPI_VEHICLE_COMPARISON_PLATE_S;

/**
* @struct tagOpenAPIVehicleComparisonVehicleInfo
* @brief 车辆比对的车辆信息 Vehicle comparison vehicle information
* @attention 无 None
*/
typedef struct tagOpenAPIVehicleComparisonVehicleInfo
{
    INT32                       dwVehicleTime;                  /* 车辆时间 Vehicle time */
    INT32                       dwContrastStatus;               /* 比对状态 0-未比对 1-比对成功 2-比对失败 Contrast status: 0-not compared, 1-success, 2-failed */
    CHAR                        szVehiclePicUrl[OPENAPI_LEN_512]; /* 车辆图URL Vehicle picture URL */
    CHAR                        szPlatePicUrl[OPENAPI_LEN_512]; /* 车牌图URL Plate picture URL */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    INT32                       dwVehicleType;                  /* 车辆类型 0-未知 1-客车 2-货车 3-轿车 4-面包车 5-小货车 6-行人 7-非机动车 8-三轮车 9-SUV 10-MPV 11-面包车(小) 12-皮卡车 Vehicle type */
    INT32                       dwVehicleColor;                 /* 车辆颜色 0-未知 1-白色 2-银色 3-灰色 4-黑色 5-红色 6-深蓝 7-蓝色 8-黄色 9-绿色 10-棕色 11-粉色 12-紫色 13-深灰 Vehicle color */
    OPENAPI_VEHICLE_COMPARISON_PLATE_S stPlate;                  /* 车牌信息 Plate information */
    BYTE                        byRes[32];                      /* 保留字段 Reserved field */
}OPENAPI_VEHICLE_COMPARISON_VEHICLE_S, *LPOPENAPI_VEHICLE_COMPARISON_VEHICLE_S;

/**
* @struct tagOpenAPIVehicleComparisonInfo
* @brief 边缘车辆比对消息专有结构 Vehicle comparison message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIVehicleComparisonInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    OPENAPI_VEHICLE_COMPARISON_VEHICLE_S stVehicle;              /* 车辆信息 Vehicle information */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_VEHICLE_COMPARISON_INFO_S, *LPOPENAPI_VEHICLE_COMPARISON_INFO_S;

/**
* @struct tagOpenAPIPersonHealthInfo
* @brief 人体康养数据消息专有结构 Person health message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIPersonHealthInfo
{
    CHAR                        szId[OPENAPI_LEN_64];           /* 记录ID Record ID */
    CHAR                        szDeviceName[OPENAPI_LEN_128];  /* 设备名称 Device name */
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT32                       dwHasPeople;                    /* 是否有人 0-否 1-是 Has people: 0-no, 1-yes */
    INT32                       dwHasMove;                      /* 是否有移动 0-否 1-是 Has move: 0-no, 1-yes */
    FLOAT                       fBreathFreqAverage;             /* 呼吸频率平均值 Breath frequency average */
    FLOAT                       fHeartFreqAverage;              /* 心率频率平均值 Heart frequency average */
    FLOAT                       fBreathFreqStd;                 /* 呼吸频率标准差 Breath frequency standard deviation */
    FLOAT                       fHeartFreqStd;                  /* 心率频率标准差 Heart frequency standard deviation */
    FLOAT                       fBreathAmpDiff;                 /* 呼吸幅度差 Breath amplitude difference */
    FLOAT                       fHeartAmpDiff;                  /* 心率幅度差 Heart amplitude difference */
    FLOAT                       fBreathAmpAverage;              /* 呼吸幅度平均值 Breath amplitude average */
    FLOAT                       fHeartAmpAverage;               /* 心率幅度平均值 Heart amplitude average */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    FLOAT                       fMeanIBI;                       /* 平均心跳间期 Mean IBI */
    FLOAT                       fRmSSD;                         /* 相邻RR间期差值的均方根 RMSSD */
    FLOAT                       fSDRR;                          /* RR间期标准差 SDRR */
    FLOAT                       fPNN50;                         /* 相邻RR间期差值>50ms的比例 PNN50 */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_PERSON_HEALTH_INFO_S, *LPOPENAPI_PERSON_HEALTH_INFO_S;

/**
* @struct tagOpenAPIMixedTargetInfo
* @brief 混合目标检测事件专有结构 Mixed target detection event specific structure
* @attention 包含faceList、personList、nonMotorVehicleList、vehicleList四类目标
*/
typedef struct tagOpenAPIMixedTargetInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    INT32                       dwFaceCount;                    /* 人脸数量 Face count */
    OPENAPI_FACE_ITEM_S         astFaceList[OPENAPI_MAX_MIXED_TARGET_NUM]; /* 人脸列表 Face list */
    INT32                       dwPersonCount;                  /* 人员数量 Person count */
    OPENAPI_PERSON_ITEM_S       astPersonList[OPENAPI_MAX_MIXED_TARGET_NUM]; /* 人员列表 Person list */
    INT32                       dwNonMotorVehicleCount;         /* 非机动车数量 Non-motor vehicle count */
    OPENAPI_NON_MOTOR_ITEM_S    astNonMotorVehicleList[OPENAPI_MAX_MIXED_TARGET_NUM]; /* 非机动车列表 Non-motor vehicle list */
    INT32                       dwVehicleCount;                 /* 车辆数量 Vehicle count */
    OPENAPI_VEHICLE_ITEM_S      astVehicleList[OPENAPI_MAX_MIXED_TARGET_NUM]; /* 车辆列表 Vehicle list */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_MIXED_TARGET_INFO_S, *LPOPENAPI_MIXED_TARGET_INFO_S;

/**
* @struct tagOpenAPIPeopleExistInfo
* @brief 人员存在变更事件专有结构 People exist detection event specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIPeopleExistInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    INT32                       dwPeopleExisted;                /* 人员是否存在 0-否 1-是 People existed: 0-no, 1-yes */
    INT32                       dwAreaId;                       /* 区域ID Area ID */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_PEOPLE_EXIST_INFO_S, *LPOPENAPI_PEOPLE_EXIST_INFO_S;

/**
* @struct tagOpenAPIPeopleExistRuleInfo
* @brief 人员存在规则信息 People exist rule information
* @attention 无 None
*/
typedef struct tagOpenAPIPeopleExistRuleInfo
{
    INT32                       dwAreaId;                       /* 区域ID Area ID */
    INT32                       dwEnable;                       /* 是否启用 0-否 1-是 Enable: 0-no, 1-yes */
    INT32                       dwTriggerTime;                  /* 触发时间 Trigger time */
    INT32                       dwTimeUnit;                     /* 时间单位 1-秒 2-分钟 3-小时 Time unit */
    BYTE                        byRes[16];                      /* 保留字段 Reserved field */
}OPENAPI_PEOPLE_EXIST_RULE_S, *LPOPENAPI_PEOPLE_EXIST_RULE_S;

/**
* @struct tagOpenAPIPeopleExistAlarmInfo
* @brief 人员存在报警信息专有结构 People exist alarm info specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIPeopleExistAlarmInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szRelationId[OPENAPI_LEN_64];   /* 关联ID Relation ID */
    OPENAPI_PEOPLE_EXIST_RULE_S stPeopleExistRule;              /* 人员存在规则 People exist rule */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_PEOPLE_EXIST_ALARM_INFO_S, *LPOPENAPI_PEOPLE_EXIST_ALARM_INFO_S;

/**
* @struct tagOpenAPIPersonVerificationInfo
* @brief 过人记录专有结构 Person verification specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIPersonVerificationInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    INT32                       dwIdentityType;                 /* 身份类型 0-身份证 1-其他 Identity type */
    CHAR                        szCardNo[OPENAPI_LEN_64];       /* 卡号 Card number */
    CHAR                        szPersonName[OPENAPI_LEN_64];   /* 人员姓名 Person name */
    CHAR                        szPersonNo[OPENAPI_LEN_64];     /* 人员编号 Person number */
    INT32                       dwVerifyMode;                   /* 核验模式 参见OPENAPI_ACS_VERIFY_MODE_E Verify mode, see OPENAPI_ACS_VERIFY_MODE_E */
    FLOAT                       fBodyTemperature;               /* 体温 Body temperature */
    CHAR                        szFacePicUrl[OPENAPI_LEN_512];  /* 人脸图URL Face picture URL */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_PERSON_VERIFICATION_INFO_S, *LPOPENAPI_PERSON_VERIFICATION_INFO_S;

/**
* @struct tagOpenAPIFloatPersonInfo
* @brief 流动人员信息 Float person information
* @attention 无 None
*/
typedef struct tagOpenAPIFloatPersonInfo
{
    CHAR                        szGmsfhm[OPENAPI_LEN_64];      /* 公民身份号码 Citizen ID number */
    CHAR                        szXm[OPENAPI_LEN_64];          /* 姓名 Name */
    CHAR                        szCym[OPENAPI_LEN_64];         /* 曾用名 Former name */
    CHAR                        szXb[OPENAPI_LEN_32];          /* 性别 Gender */
    CHAR                        szMz[OPENAPI_LEN_32];          /* 民族 Nation */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_FLOAT_PERSON_INFO_S, *LPOPENAPI_FLOAT_PERSON_INFO_S;

/**
* @struct tagOpenAPIFloatPersonUpdateInfo
* @brief 流动人员信息更新消息专有结构 Float person update message specific structure
* @attention 无 None
*/
typedef struct tagOpenAPIFloatPersonUpdateInfo
{
    CHAR                        szPersonNo[OPENAPI_LEN_64];     /* 人员编号 Person number */
    INT32                       dwOperationType;                /* 操作类型 1-新增 2-修改 3-删除 Operation type */
    OPENAPI_FLOAT_PERSON_INFO_S stFloatPersonInfo;              /* 流动人员信息 Float person information */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_FLOAT_PERSON_UPDATE_INFO_S, *LPOPENAPI_FLOAT_PERSON_UPDATE_INFO_S;

/**
* @struct tagOpenAPIFloatPersonVerificationInfo
* @brief 流动人员核验消息专有结构 Float person verification message specific structure
* @attention 结合门禁事件消息和流动人员信息
*/
typedef struct tagOpenAPIFloatPersonVerificationInfo
{
    CHAR                        szDeviceSerial[OPENAPI_LEN_64]; /* 设备序列号 Device serial number */
    INT32                       dwChannelID;                    /* 通道号 Channel ID */
    INT64                       tEventTime;                     /* 事件时间(UTC) Event time (UTC) */
    CHAR                        szEventId[OPENAPI_LEN_64];      /* 事件ID Event ID */
    CHAR                        szChannelName[OPENAPI_LEN_128]; /* 通道名称 Channel name */
    INT32                       dwCardReaderKind;               /* 读卡器类型 0-未知 1-IC卡读卡器 2-身份证读卡器 3-二维码读卡器 4-指纹读卡器 5-人脸读卡器 6-掌静脉读卡器 Card reader kind */
    CHAR                        szCardNo[OPENAPI_LEN_64];       /* 卡号 Card number */
    CHAR                        szPersonNo[OPENAPI_LEN_64];     /* 人员编号 Person number */
    OPENAPI_ACS_VERIFY_MODE_E   enVerifyMode;                   /* 核验模式 Verify mode */
    CHAR                        szFacePicUrl[OPENAPI_LEN_512];  /* 人脸图URL Face picture URL */
    CHAR                        szBkgPicUrl[OPENAPI_LEN_512];   /* 背景图URL Background picture URL */
    OPENAPI_FLOAT_PERSON_INFO_S stFloatPersonInfo;              /* 流动人员信息 Float person information */
    BYTE                        byRes[64];                      /* 保留字段 Reserved field */
}OPENAPI_FLOAT_PERSON_VERIFICATION_INFO_S, *LPOPENAPI_FLOAT_PERSON_VERIFICATION_INFO_S;

/**
* @struct tagOpenAPIAudioSampleParamType
* @brief 音频参数 Audio sample parameters
* @attention 无 None
*/
typedef struct tagOpenAPIVoiceTalkInfo
{
    INT32                         dwChannelID;      /* 通道ID Channel ID */
    INT32                         dwSampleRate;     /* 采样率 Sample rate */
    OPENAPI_AUDIO_VOICE_TYPE_E    enVoiceType;      /* 音频编码格式 Audio encoding format */
    CHAR                          *pcURL;           /* 外部传入的流URL，非空时跳过内部URL获取 External stream URL. When non-NULL, skip internal URL acquisition */
    BYTE                          byRes[112];       /* 保留字段 Reserved field */
}OPENAPI_VOICE_TALK_INFO_S, *LPOPENAPI_VOICE_TALK_INFO_S;

/**
* @struct tagOpenAPIDeviceChannelInfo
* @brief 设备通道信息
* @attention 无 None
 */
typedef struct tagOpenAPIDeviceChannelInfo
{
    INT32                    dwChannelID;                                        /* 通道ID Channel ID */
    OPENAPI_STATUS_E         enChannelStatus;                                    /* 通道状态 Channel status */
    CHAR                     szDeviceSerial[OPENAPI_LEN_32];                     /* 设备序列号 Device serial number */
    CHAR                     szChannelName[OPENAPI_LEN_256];                     /* 通道名称 Channel name */
    BYTE                     byRes[256];                                         /* 保留字段 Reserved field */
}OPENAPI_DEVICE_CHANNEL_INFO_S, *LPOPENAPI_DEVICE_CHANNEL_INFO_S;

/**
* @struct tagOpenAPIDeviceChannelList
* @brief 设备通道列表 Device channel list
* @attention 无 None
 */
typedef struct tagOpenAPIDeviceChannelList
{
    INT32                                 dwTotal;              /* 总记录数 Total count */
    LPOPENAPI_DEVICE_CHANNEL_INFO_S       pstDeviceChannelInfo; /* 设备通道信息 Device channel information */
    BYTE                                  byRes[116];           /* 保留字段 Reserved field */
}OPENAPI_DEVICE_CHANNEL_LIST_S, *LPOPENAPI_DEVICE_CHANNEL_LIST_S;

/**
* @struct tagOpenAPIDeviceInfo
* @brief 设备信息 Device information
* @attention 无 None
 */
typedef struct tagOpenAPIDeviceInfo
{
    CHAR                     szDeviceSerial[OPENAPI_LEN_32];                     /* 设备序列号 Device serial number */
    CHAR                     szDeviceName[OPENAPI_LEN_256];                      /* 设备名称 Device name */
    CHAR                     szDeviceModel[OPENAPI_LEN_256];                     /* 设备型号 Device model */
    CHAR                     szDeviceVersion[OPENAPI_LEN_128];                   /* 设备版本 Device version */
    OPENAPI_DEVICE_TYPE_E    enDeviceType;                                       /* 设备类型 Device type */
    OPENAPI_STATUS_E         enDeviceStatus;                                     /* 设备状态 Device status */
    OPENAPI_SHARED_TYPE_E    enSharedType;                                       /* 共享类型 Share type */
    INT64                    tLatestOnlineTime;                                  /* 最近上线时间（单位: s），UTC时间戳 Latest online time (unit: seconds UTC time) */
    BYTE                     byRes[108];                                         /* 保留字段 Reserved field */
}OPENAPI_DEVICE_INFO_S, *LPOPENAPI_DEVICE_INFO_S;

/**
* @struct tagOpenAPIDeviceList
* @brief 设备列表 Device List
* @attention 无 None
 */
typedef struct tagOpenAPIDeviceList
{
    INT32                         dwTotal;       /* 总记录数 Total count */
    LPOPENAPI_DEVICE_INFO_S       pstDeviceInfo; /* 设备信息 Device information */
    BYTE                          byRes[116];    /* 保留字段 Reserved field */
}OPENAPI_DEVICE_LIST_S, *LPOPENAPI_DEVICE_LIST_S;

/**
* @struct tagOpenAPIQueryConditions
* @brief 查询条件 Query conditions
* @attention 无 None
 */
typedef struct tagOpenAPIQueryConditions
{
    INT32                        dwLimit;        /* 每次查询的数量 每次最多查询100个 本地录像IPC设备分页查询时使用，非必选字段，不传查所有 Number of entries per query; maximum 100. Used for local video recording search on IPC devices. Empty query all. Optional field. */
    INT32                        dwOffset;       /* 从当前序号开始查询 序号从0开始  本地录像IPC设备分页查询时使用，非必选字段 Starting sequence number for the query; sequence starts from 0. Used for local video recording search on IPC devices. Optional field.*/
    INT32                        dwChannelID;    /* 通道ID Channel ID */
    OPENAPI_STREAM_QUALITY_E     enQuality;      /* 视频质量 Video quality */
    OPENAPI_STREAM_TYPE_E        enStreamType;   /* 流类型 Stream type */
    INT64                        tStartTime;     /* 开始时间(单位:秒 UTC时间) Start time (unit: seconds UTC time) */
    INT64                        tEndTime;       /* 结束时间（单位: s），UTC时间戳 查询时间跨度不能超过一天 End time End time (unit: seconds UTC time) The time span of the query must not exceed one day.*/
    BYTE                         byRes[92];      /* 保留字段 Reserved field */
}OPENAPI_QUERY_CONDITIONS_S, *LPOPENAPI_QUERY_CONDITIONS_S;

/**
* @struct tagOpenAPIQueryResult
* @brief 分页查询结果
* @attention 无 None
 */
typedef struct tagOpenAPIQueryResult
{
    INT32                        dwTotal;        /* 总共的录像个数 Total count */
    INT32                        dwOffset;       /* 本次查询从第几个开始查询 Offset from beginning */
    INT32                        dwNums;         /* 查询到的录像文件个数 Number of records queried */
    BYTE                         byRes[36];      /* 保留字段 Reserved field */
}OPENAPI_PAGED_QUERY_RESULT_S, *LPOPENAPI_PAGED_QUERY_RESULT_S;

/**
* @struct tagOpenAPIRecordInfo
* @brief 录像信息 Record information
* @attention 无 None
 */
typedef struct tagOpenAPIRecordInfo
{
    INT64                      tStartTime;       /* 开始时间(单位:秒 UTC时间) Start time (unit: seconds UTC time) */
    INT64                      tEndTime;         /* 结束时间(单位:秒 UTC时间) End time (unit: seconds UTC time) */
    BYTE                       byRes[32];        /* 保留字段 Reserved field */
}OPENAPI_RECORD_INFO_S, *LPOPENAPI_RECORD_INFO_S;

/**
 * @struct tagstOpenAPIPtzPreset
 * @brief 云台预置位信息 结构体定义 PTZ preset information Structure definition
 * @attention 无 None
 */
typedef struct tagstOpenAPIPtzPreset
{
    INT32   dwPresetID;                                 /* 预置位ID  Preset ID */
    CHAR    szPresetName[OPENAPI_LEN_128];              /* 预置位名称  Preset name */
    BYTE    byRes[512];                                 /* 保留字段   */
}OPENAPI_PTZ_PRESET_S, *LPOPENAPI_PTZ_PRESET_S;

/**
 * @struct tagstOpenAPIPtzAllPresets
 * @brief 所有云台预置位 结构体定义 All PTZ presets Structure definition
 * @attention 无 None
 */
typedef struct tagstOpenAPIPtzAllPresets
{
    INT32                   dwSize;                                 /* 预置位总数  Total number of presets */
    OPENAPI_PTZ_PRESET_S    astPreset[OPENAPI_MAX_PRESET_NUM];      /* 预置位信息结构体  Structure of preset information */
    BYTE                    byRes[512];                             /* 保留字段   */
}OPENAPI_PTZ_ALLPRESETS_S, *LPOPENAPI_PTZ_ALLPRESETS_S;


// ==================== 函数定义 Function Definitions ====================

/**
 * SDK 初始化
* @param[IN] szCloudUrl    云服务URL Cloud service URL
* @param[IN] szAppId       云账号AppId Cloud Account AppId
* @param[IN] szSecretKey   云账号SecretKey Cloud Account SecretKey
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 线程安全，支持多线程 Thread-safe, supports multi-threading
*/
OPEN_API BOOL STDCALL OpenAPI_Init(IN CONST CHAR* szCloudUrl, IN CONST CHAR *szAppId, IN CONST CHAR *szSecretKey);


/**
 * SDK 初始化
* @param[IN] szCloudUrl    云服务URL Cloud service URL
* @param[IN] accessToken   云账号AppId szSecretKey 生成的accessToken
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 线程安全，支持多线程 Thread-safe, supports multi-threading
*/
OPEN_API BOOL STDCALL OpenAPI_InitByToken(IN CONST CHAR* szCloudUrl, IN CONST CHAR *accessToken);

/**
 * SDK 清理
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 线程安全，支持多线程 Thread-safe, supports multi-threading
*/
OPEN_API BOOL STDCALL OpenAPI_Cleanup();

/**
 * SDK 版本
* @return SDK版本字符串 SDK version string
* @note 
*/
OPEN_API CONST CHAR* STDCALL OpenAPI_GetSdkVersion();

/** 
 * 全局配置信息
* @param[IN] iKey    配置键 Configuration key
* @param[IN] iValue  配置值 Configuration value
 */
OPEN_API BOOL STDCALL OpenAPI_SetConfigInfo(IN OPENAPI_CONFIG_KEY iKey, IN CONST INT32 dwValue);

/**
* 获取错误码
* @return 错误码 Last error code
* @note 当接口失败时调用此函数获取详细错误信息 Call this function when interface fails to get detailed error information
*/
OPEN_API INT32 STDCALL OpenAPI_GetLastError();

/**
 * 获取设备列表
* @param[IN] dwPageIndex           分页起始页，默认从0开始 Page index, default 0
* @param[IN] dwPageSize            默认为10，最大为100 Default 10, maximum 100
* @param[OUT] pstDeviceList         设备列表 Device list
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
*/
OPEN_API BOOL STDCALL OpenAPI_GetDeviceList(IN INT32 dwPageIndex,
                                            IN INT32 dwPageSize,
                                            OUT LPOPENAPI_DEVICE_LIST_S pstDeviceList);

/**
 * 获取设备通道信息
* @param[IN] dwPageIndex             分页起始页，默认从0开始 Page index, default 0
* @param[IN] dwPageSize              默认为10，最大为100 Default 10, maximum 100
* @param[IN] szDevSerial             设备序列号，空字符串获取所有设备 Device serial number, empty string gets all devices
* @param[OUT] pstDeviceChannelList    设备通道列表 Device channel list
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
*/
OPEN_API BOOL STDCALL OpenAPI_GetDeviceChannelList(IN INT32 dwPageIndex,
                                                  IN INT32 dwPageSize,
                                                  IN CHAR* szDevSerial,
                                                  OUT LPOPENAPI_DEVICE_CHANNEL_LIST_S pstDeviceChannelList);

/**
 * 开始设备连接
* @param[IN] szDevSerial         设备序列号 Device serial number
* @param[OUT] pdwDeviceId        设备ID Device ID
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
 */
OPEN_API BOOL STDCALL OpenAPI_StartDeviceConnect(IN CONST CHAR* szDevSerial, OUT INT32* pdwDeviceId);

/**
 * 断开设备连接
* @param[IN] dwDeviceId        设备ID Device ID
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
 */
OPEN_API BOOL STDCALL OpenAPI_StopDeviceConnect(IN CONST INT32 dwDeviceId);

/**
 * 设置连接模式
* @param[IN] dwConnectMode  连接模式，参考 OPENAPI_CONNECT_MODE_E，默认OPENAPI_HOLE_PUNCHING_AND_FORWARD Connection mode, refer to OPENAPI_CONNECT_MODE_E, default is OPENAPI_HOLE_PUNCHING_AND_FORWARD.
* @note 
 */
OPEN_API BOOL STDCALL OpenAPI_SetConnectMode(INT32 dwConnectMode);

/**
* 解码后视频流数据回调函数的指针类型  Type of pointer to callback function for decoded video stream data 
* @param [IN] lpPlayHandle      当前的实况播放句柄 Current live playing handle
* @param [IN] pstPictureData    存放解码后视频流数据信息缓冲区指针 Pointer to buffer that stores decoded video stream data
* @param [IN] lpUserParam       用户设置参数 User set param
* @return 无. None.
* @note
* -     1、用户应及时处理输出的视频流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理 When user handles decoded video stream data, ensure timely processing to avoid blocking player functions；
* -     2、pPictureData->ulDataType指明解码后的数据格式，需根据所述格式进行数据处理 The pPictureData->ulDataType indicates the raw data format, which may vary by device；
* -     3、默认解码后视频数据是yv12格式。排列顺序“Y0-Y1-......”，“U0-U1-......”，“V0-V1-......”By default, video stream data is in YV12 format, with Y0-Y1-... U0-U1-... V0-V1-...
*/
typedef VOID (STDCALL* OpenAPI_DECODE_VIDEO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                              IN CONST OPENAPI_PICTURE_DATA_S *pstPictureData,
                                                              IN LPVOID lpUserParam);

/**
* 解码后音频流数据回调函数的指针类型  Type of pointer to callback function for decoded audio stream data 
* @param [IN] lpPlayHandle   当前的实况播放句柄 Current live playing handle
* @param [IN] pstWaveData    存放解码后音频流数据信息缓冲区指针 Pointer to buffer that stores decoded audio stream data
* @param [IN] lpUserParam    用户设置参数 User set param
* @return 无. None.
* @note
* -     用户应及时处理输出的音频流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理.
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef VOID (STDCALL* OpenAPI_DECODE_AUDIO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                              IN CONST OPENAPI_WAVE_DATA_S *pstWaveData,
                                                              IN LPVOID lpUserParam);

/**
* 原始码流数据回调（RTP级别，未拼帧）
* @param [IN] lpPlayHandle      播放句柄 Play handle
* @param [IN] pucBuffer         数据缓冲区指针 Data buffer pointer
* @param [IN] dwBufSize         缓冲区大小 Buffer size
* @param [IN] dwMediaDataType   媒体数据类型 Media data type
* @param [IN] lpUserParam       用户参数 User param
* @return 无 None.
* @note 此回调输出的数据为RTP级别原始码流，未进行拼帧处理
*/
typedef VOID (STDCALL *OpenAPI_SOURCE_DATA_CALLBACK_PF)(
    IN LPVOID        lpPlayHandle,
    IN CONST BYTE    *pucBuffer,
    IN INT32         dwBufSize,
    IN INT32         dwMediaDataType,
    IN LPVOID        lpUserParam
);

/**
* 拼帧后视频流数据回调（NAL单元/Elementary Stream）
* @param [IN] lpPlayHandle         播放句柄 Play handle
* @param [IN] pstParseVideoData    拼帧后视频数据 Parsed video data
* @param [IN] lpUserParam          用户参数 User param
* @return 无 None.
* @note 此回调输出的数据即为H.264/H.265 NAL单元，可直接保存或送入解码器
*/
typedef VOID (STDCALL *OpenAPI_PARSE_VIDEO_DATA_CALLBACK_PF)(
    IN LPVOID lpPlayHandle,
    IN CONST OPENAPI_PARSE_VIDEO_DATA_S *pstParseVideoData,
    IN LPVOID lpUserParam
);

/**
* 拼帧后音频流数据回调 Parsed audio stream data callback
* @param [IN] lpPlayHandle         播放句柄 Play handle
* @param [IN] pcData               音频数据指针 Audio data pointer
* @param [IN] dwDataLen             数据长度 Data length
* @param [IN] enAudioEncodeType    音频编码类型 Audio encode type
* @param [IN] lpUserParam          用户参数 User param
* @return 无 None.
*/
typedef VOID (STDCALL *OpenAPI_PARSE_AUDIO_DATA_CALLBACK_PF)(
    IN LPVOID lpPlayHandle,
    IN CONST CHAR  *pcData,
    IN INT32  dwDataLen,
    IN INT32  dwAudioEncodeType,
    IN LPVOID lpUserParam
);

/**
* 事件回调函数的指针类型 
* @param [IN] pstEventInfo              事件信息 Event information
* @param [IN] lpUserData                用户数据 User data
* @return 无 None.
* @note 
*/
typedef VOID (STDCALL *OpenAPI_MESSAGE_CALLBACK_PF)(IN LPOPENAPI_EVENT_INFO_S pstEventInfo);

/**
 * 设置消息回调
* @param [IN] cbMessageCallBack     消息回调函数指针 Message callback function pointer
* @param [IN] lpUserData            用户数据 User data
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
*/
OPEN_API BOOL STDCALL OpenAPI_SetMessageCallBack(IN OpenAPI_MESSAGE_CALLBACK_PF cbMessageCallBack);

/**
* 订阅告警事件 Subscribe alarm events
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 调用此接口后，SDK将启动告警拉取线程，通过OpenAPI_SetMessageCallBack设置的回调接收告警事件。
*       需先调用OpenAPI_Init初始化SDK，否则返回FALSE。
*       重复订阅不会重复启动线程（返回TRUE）。
*       告警事件类型通过消息回调中 OPENAPI_EVENT_INFO_S.szMsgType 字符串字段获取。
*/
OPEN_API BOOL STDCALL OpenAPI_SubscribeAlarm();

/**
* 取消订阅告警事件 Unsubscribe alarm events
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 调用此接口后，SDK将停止告警拉取线程，不再接收告警事件。
*       若未订阅告警（线程未运行），调用此接口返回TRUE。
*       需先调用OpenAPI_Init初始化SDK，否则返回FALSE。
*/
OPEN_API BOOL STDCALL OpenAPI_UnSubscribeAlarm();

/**
* 历史告警查询
* @param[IN]  pstQueryCond     查询条件指针 Query conditions pointer
* @param[OUT] pstQueryResult   查询结果指针 Query result pointer
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note
*       - 只能查询7天以内的告警，且起止时间间隔不超过24小时
*       - alarmTypeString为可选字段，空字符串表示查询所有告警类型
*       - pstQueryResult->pstAlarmInfo 需由调用方提前分配内存
*       - 返回的 dwAlarmCount 不超过 pstQueryResult 中分配的数组大小
*/
OPEN_API BOOL STDCALL OpenAPI_QueryAlarmHistory(IN LPOPENAPI_ALARM_QUERY_COND_S pstQueryCond,
                                                OUT LPOPENAPI_ALARM_QUERY_RESULT_S pstQueryResult);

/**
* @brief 配置HLS缓存参数
* @param[IN] pcCachePath    缓存路径，NULL表示使用默认路径 Cache path, NULL for default
* @param[IN] dwCacheLimit   缓存大小限制（单位：MB），0表示使用默认值 Cache size limit in MB, 0 for default
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 云存储回放时，需先调用OpenAPI_ConfigHls配置HLS缓存，起流后可通过OpenAPI_UpdateHlsParam更新参数
*/
OPEN_API BOOL STDCALL OpenAPI_ConfigHls(IN CONST CHAR *pcCachePath, IN INT32 dwCacheLimit);

/**
* @brief 更新HLS播放参数
* @param[IN] lpPlayHandle     启流句柄 Play handle
* @param[IN] pstHlsParam      HLS回放参数 HLS playback parameters
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 云存储回放时，需先调用OpenAPI_ConfigHls配置HLS缓存，起流后可通过OpenAPI_UpdateHlsParam更新参数
*/
OPEN_API BOOL STDCALL OpenAPI_UpdateHlsParam(IN LPVOID lpPlayHandle, IN LPOPENAPI_HLS_PLAYBACK_S pstHlsParam);

/**
 * 开始实时预览
* @param[IN] dwDeviceId        设备ID Device ID
* @param[IN] pstPreviewInfo    预览参数 Preview parameters
* @param[IN] lpStreamDataCB    流数据回调函数指针，可设为NULL Stream data callback function pointer, can be NULL
* @return 句柄值，0表示失败，正数值表示成功 Handle value, 0 for failure, positive value for success
* @note 
 */
OPEN_API LPVOID STDCALL OpenAPI_StartRealPlay(IN INT32 dwDeviceId, 
                                              IN LPOPENAPI_REALPLAY_S pstPreviewInfo,
                                              IN LPOPENAPI_STREAM_DATA_CB_S lpStreamDataCB);

/**
* 开始实时预览（扩展版，支持多种码流回调）
* @param[IN] dwDeviceId          设备ID Device ID
* @param[IN] pstPreviewInfo      预览参数 Preview parameters
* @param[IN] lpStreamDataCBEx    扩展码流回调参数 Extended stream callback parameters
* @return 句柄值，0表示失败，正数值表示成功 Handle value, 0 for failure, positive value for success
* @note 与OpenAPI_StartRealPlay的区别：
*       - 支持原始码流/拼帧后/解码后三种回调类型
*       - 通过enCBType指定回调类型，lpVideoDataCB根据类型强转使用
*       - 当enCBType=PARSE时，lpVideoDataCB强转为OpenAPI_PARSE_VIDEO_DATA_CALLBACK_PF
*         输出H.264/H.265 NAL单元（Elementary Stream）
*/
OPEN_API LPVOID STDCALL OpenAPI_StartRealPlayEx(IN INT32 dwDeviceId,
                                                 IN LPOPENAPI_REALPLAY_S pstPreviewInfo,
                                                 IN LPOPENAPI_STREAM_DATA_CB_EX_S lpStreamDataCBEx);

/** 
 * 停止实时预览
* @param[IN] lpPlayHandle        播放句柄 Play handle
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 对应OpenAPI_StartRealPlay Corresponds to OpenAPI_StartRealPlay
 */
OPEN_API BOOL STDCALL OpenAPI_StopRealPlay(IN LPVOID lpPlayHandle);


/**
* 控制播放状态  Control recording playback status.
* @param [IN]     lpPlayHandle     启流句柄 Play handle
* @param [IN]     dwControlCode    播放控制命令 参考枚举： OPENAPI_VOD_PLAY_CTRL_E，Control command, refer to OPENAPI_VOD_PLAY_CTRL_E
* @param [INOUT]  lpBuffer         指向输入/输出参数的指针, 播放速度参考枚举 OPENAPI_VOD_PLAY_STATUS_E ,播放时间参数为时间戳（单位秒） Input/output buffer pointer, for speed refer to OPENAPI_VOD_PLAY_STATUS_E, time unit is seconds
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 暂停/恢复时，lpBuffer为NULL When pausing/resuming, lpBuffer is NULL
 */
OPEN_API BOOL STDCALL OpenAPI_PlayControl( IN LPVOID lpPlayHandle, 
                                           IN INT32 dwControlCode, 
                                           INOUT LPVOID lpBuffer);

/**
* 查询录像
* @param [IN] dwDeviceId             设备ID Device ID
* @param [IN] pstQueryConditions     查询条件 Query conditions
* @param [OUT] pstPagedResultInfo    分页查询结果信息 Paged query result information
* @return 句柄值，0表示失败，正数值表示成功 Handle value, 0 for failure, positive value for success
* @note 
 *         1. 查询成功后，调用OpenAPI_FindNextRecord并传入返回的句柄获取详细文件信息。 After successful query, call OpenAPI_FindNextRecord with the returned handle to get detailed file information.
 *         2. 查询完成后，调用OpenAPI_FindClose并传入返回的句柄释放资源。 After query, call OpenAPI_FindClose with the returned handle to release resources.
 */
OPEN_API LPVOID STDCALL OpenAPI_FindRecord(IN INT32 dwDeviceId,
                                           IN LPOPENAPI_QUERY_CONDITIONS_S pstQueryConditions,
                                           OUT LPOPENAPI_PAGED_QUERY_RESULT_S pstPagedResultInfo);

/**
* 逐个获取查找到的录像信息  Obtain the information of found files one by one.
* @param [IN]  lpFindHandle      文件查找句柄，OpenAPI_FindRecord接口调用成功时的返回值 File search handle
* @param [OUT] pstRecordInfo       保存文件信息的指针 Pointer to save file information
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
OPEN_API BOOL STDCALL OpenAPI_FindNextRecord(IN LPVOID lpFindHandle,
                                             OUT LPOPENAPI_RECORD_INFO_S pstRecordInfo);

/**
* 关闭文件查找,释放资源  Close file search and release resources
* @param [IN] lpFindHandle  文件查找句柄，OpenAPI_FindRecord接口调用成功时的返回值 File search handle
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note
*/
OPEN_API BOOL STDCALL OpenAPI_FindClose(IN LPVOID lpFindHandle);

/**
 * 开始按时间回放
* @param [IN] dwDeviceId        设备ID Device ID
* @param [IN] pstPlayBackCond   按时间回放结构指针 Time-based playback structure pointer
* @param[IN] lpStreamDataCB     流数据回调函数指针，可设为NULL Stream data callback function pointer, can be NULL
* @return 句柄值，0表示失败，正数值表示成功 Handle value, 0 for failure, positive value for success
* @note 云存储回放时，需先调用OpenAPI_ConfigHls配置HLS缓存，起流后可通过OpenAPI_UpdateHlsParam更新参数
 */
OPEN_API LPVOID STDCALL OpenAPI_StartPlayBack(IN INT32 dwDeviceId,
                                              IN LPOPENAPI_PLAYBACK_S pstPlayBackInfo,
                                              IN LPOPENAPI_STREAM_DATA_CB_S lpStreamDataCB);

/**
* 开始按时间回放（扩展版，支持多种码流回调）
* @param [IN] dwDeviceId        设备ID Device ID
* @param [IN] pstPlayBackInfo   按时间回放结构指针 Time-based playback structure pointer
* @param [IN] lpStreamDataCBEx  扩展码流回调参数 Extended stream callback parameters
* @return 句柄值，0表示失败，正数值表示成功 Handle value, 0 for failure, positive value for success
* @note 与OpenAPI_StartPlayBack的区别：
*       - 支持原始码流/拼帧后/解码后三种回调类型
*       - 通过enCBType指定回调类型，lpVideoDataCB根据类型强转使用
*       - 当enCBType=PARSE时，lpVideoDataCB强转为OpenAPI_PARSE_VIDEO_DATA_CALLBACK_PF
*         输出H.264/H.265 NAL单元（Elementary Stream）
*       - 云存储回放时，需先调用OpenAPI_ConfigHls配置HLS缓存，起流后可通过OpenAPI_UpdateHlsParam更新参数
*/
OPEN_API LPVOID STDCALL OpenAPI_StartPlayBackEx(IN INT32 dwDeviceId,
                                                IN LPOPENAPI_PLAYBACK_S pstPlayBackInfo,
                                                IN LPOPENAPI_STREAM_DATA_CB_EX_S lpStreamDataCBEx);

/**
* 停止回放  Stop playback
* @param [IN] lpPlayHandle  启流句柄 Playback handle
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note
*/
OPEN_API BOOL STDCALL OpenAPI_StopPlayBack(IN LPVOID lpPlayHandle);

/**
 * 开始下载
* @param [IN] dwDeviceId        设备ID Device ID
* @param [IN] pstDownloadInfo   录像下载结构指针 Record download structure pointer
* @return 句柄值，0表示失败，正数值表示成功 Handle value, 0 for failure, positive value for success
* @note 云存储下载时，需先调用OpenAPI_ConfigHls配置HLS缓存
 */
OPEN_API LPVOID STDCALL OpenAPI_StartDownload(IN INT32 dwDeviceId,
                                              IN LPOPENAPI_DOWNLOAD_S pstDownloadInfo);

/**
 * 停止下载
* @param [IN] lpPlayHandle  下载句柄,OpenAPI_StartDownload的返回值 Download handle,Return value of OpenAPI_StartDownload
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
 */
OPEN_API BOOL STDCALL OpenAPI_StopDownload(IN LPVOID lpPlayHandle);

/**
* 开启语音对讲
* @param [IN]  dwDeviceId               设备ID Device ID
* @param [IN]  pstVoiceTalkInfo         对讲信息 Voice Talk Info
* @param [IN]  cbPlayDataCallBack       音频数据 Audio data
* @param [IN]  lpUserData               用户数据 User data
* @return 句柄值，0表示失败 Handle value, 0 for failure
* @note
*/
OPEN_API LPVOID STDCALL OpenAPI_StartVoiceTalk(IN INT32 dwDeviceId,
                                               IN LPOPENAPI_VOICE_TALK_INFO_S pstVoiceTalkInfo,
                                               IN OpenAPI_DECODE_AUDIO_DATA_CALLBACK_PF cbPlayDataCallBack,
                                               IN LPVOID lpUserData);

/**
* 输入语音数据
* @param [IN] lpPlayHandle              对讲句柄,OpenAPI_StartDownload的返回值 Conversation handle,Return value of OpenAPI_StartInputVoiceSrv
* @param [IN] lpDataBuf                 语音数据缓冲区地址 Voice data buffer address
* @param [IN] dwDataLen                 语音数据长度 Voice data length
* @param [IN] pstVoiceParam             语音参数 Voice parameters
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
 */
OPEN_API BOOL STDCALL OpenAPI_InputVoiceData(IN LPVOID lpPlayHandle,
                                             IN LPVOID lpDataBuf,
                                             IN INT32 dwDataLen);

/**
* 关闭语音对讲
* @param [IN]  lpPlayHandle   对讲句柄 Conversation handle
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
 */
OPEN_API BOOL STDCALL OpenAPI_StopVoiceTalk(IN LPVOID lpPlayHandle);

/**
* 开启声音
* @param [IN]  lpPlayHandle   预览句柄  PlayHandle
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
*/
OPEN_API BOOL STDCALL OpenAPI_OpenSound(IN LPVOID lpPlayHandle);

/**
* 关闭声音
* @param [IN]  lpPlayHandle   预览句柄  PlayHandle
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 
*/
OPEN_API BOOL STDCALL OpenAPI_CloseSound(IN LPVOID lpPlayHandle);

/**
* 开始本地录像  Local recording
* @param [IN]  lpPlayHandle         预览句柄 Preview handle
* @param [IN]  pszSaveFileName      保存录像的文件名（包括文件绝对路径） File name for saving video recording (including absolute file path)
* @param [IN]  dwFormat             文件格式，见# OPENAPI_FILE_FORMATE_E File format, see # OPENAPI_FILE_FORMATE_E 
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note
*/
OPEN_API BOOL STDCALL OpenAPI_SaveRealData(IN LPVOID lpPlayHandle, 
                                           IN CHAR *pszSaveFileName,
                                           IN INT32   dwFormat);

/**
* 停止本地录像 Stop local recording
* @param [IN]  lpPlayHandle     预览句柄 Preview handle
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note
*/
OPEN_API BOOL STDCALL OpenAPI_StopSaveRealData(IN LPVOID lpPlayHandle);

/**
* 预览抓拍  Live view snapshot
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [IN]  pszFileName      保存图像的文件名（包括文件绝对路径） File name for saving image (including absolute file path)
* @param [IN]  dwCaptureMode    保存图像格式,参见# OPENAPI_PICTURE_FORMAT_E   Image saving format, see # OPENAPI_PICTURE_FORMAT_E
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 文件名中可以不携带抓拍格式的后缀名 File format suffix is not required in the file name
*/
OPEN_API BOOL STDCALL OpenAPI_CapturePicture(IN LPVOID lpPlayHandle, 
                                             IN CHAR *pszFileName, 
                                             IN INT32 dwCaptureMode);

/**
* 获取媒体流信息 Get media stream information
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [OUT] pstStreamInfo    流信息 Stream Info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 无 None
*/
OPEN_API BOOL STDCALL OpenAPI_GetStreamInfo(IN LPVOID lpPlayHandle, OUT LPOPENAPI_STREAM_INFO_S pstStreamInfo);

/**
* 设置播放图像流畅性或实时性 Set the fluency or real-time performance of image playback
* @param [IN] lpPlayHandle         预览\回放句柄 Preview\playback handle
* @param [IN] dwFluency            图像播放流畅性优先类型,参见枚举# OPENAPI_PICTURE_FLUENCY_E Image playback fluency priority type, see # OPENAPI_PICTURE_FLUENCY_E
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
OPEN_API BOOL STDCALL OpenAPI_SetPictureFluency(IN LPVOID lpPlayHandle,IN INT32 dwFluency);

/**
* 设置网络卡顿自适应参数 Set network stuck adaptive parameters
* @param [IN] lpPlayHandle         预览\回放句柄 Preview\playback handle
* @param [IN] dwKey                参数键值,参见枚举# OPENAPI_NETADJUST_KEY_E Parameter key value, see enumeration # OPENAPI_NETADJUST_KEY_E
* @param [IN] dwValue              参数值 Parameter value
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*          1) 该接口仅在通过OpenAPI_SetPictureFluency设置了OPENAPI_PICTURE_NETADJUST后才可用。
*/
OPEN_API BOOL STDCALL OpenAPI_SetNetAdjustParam(IN LPVOID lpPlayHandle, IN INT32 dwKey, IN INT32 dwValue);

/**
* 设置网络卡顿参数 Set network stuck parameters
* @param [IN] lpPlayHandle         预览\回放句柄 Preview\playback handle
* @param [IN] dwKey                参数键值,参见枚举# OPENAPI_NETSTUCK_KEY_E Parameter key value, see enumeration # OPENAPI_NETSTUCK_KEY_E
* @param [IN] dwValue              参数值 Parameter value
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*          1) 该接口仅在通过OpenAPI_SetPictureFluency设置了OPENAPI_PICTURE_NETADJUST后才可用。
*/
OPEN_API BOOL STDCALL OpenAPI_SetNetStuckParam(IN LPVOID lpPlayHandle, IN INT32 dwKey, IN INT32 dwValue);

/*************************************************************************/
/*                      云台控制/PTZ Control                            */
/*************************************************************************/

/**
* 云台控制 PTZ Control
* @param [IN]   dwDeviceId        设备ID Device ID
* @param [IN]   dwChannelID       通道ID Channel ID
* @param [IN]   enPtzCommand      云台命令，参见枚举# OPENAPI_PTZ_E  PtzCommand see enumeration # OPENAPI_PTZ_E
* @param [IN]   udwPtzSpeed       云台速度，范围1-9（9最快），非必填字段  Ptz Move Speed，range:1-9（9 is the fastest） This field can be empty.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
OPEN_API BOOL STDCALL OPENAPI_PTZControl(IN INT32 dwDeviceId, IN INT32 dwChannelID, IN OPENAPI_PTZ_E enPtzCommand, IN UINT32 udwPtzSpeed);

/**
* 添加预置位 Add Preset
* @param [IN]   dwDeviceId        设备ID Device ID
* @param [IN]   dwChannelID       通道ID Channel ID
* @param [IN]   pstPresetInfo     预置位信息  Preset Info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note NVR不支持 NVR is not supported
*/
OPEN_API BOOL STDCALL OPENAPI_SetPreset(IN INT32 dwDeviceId, IN INT32 dwChannelID, IN LPOPENAPI_PTZ_PRESET_S pstPresetInfo);

/**
* 查询预置位 PTZ Preset Query
* @param [IN]   dwDeviceId                  设备ID Device ID
* @param [IN]   dwChannelID                 通道ID Channel ID
* @param [OUT]  pstPresetList               预置位信息  Preset Info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
OPEN_API BOOL STDCALL OPENAPI_GetPresetList(IN INT32 dwDeviceId, IN INT32 dwChannelID, OUT LPOPENAPI_PTZ_ALLPRESETS_S pstPresetList);

/**
* 删除预置位 PTZ Preset Delete
* @param [IN]   dwDeviceId                  设备ID Device ID
* @param [IN]   dwChannelID                 通道ID Channel ID
* @param [IN]   udwPresetIndex              预置位编号，范围：1-255,  PresetIndex,range:1-255
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
OPEN_API BOOL STDCALL OPENAPI_DelPreset(IN INT32 dwDeviceId, IN INT32 dwChannelID, IN UINT32 udwPresetIndex);

/**
* 跳转预置位 PTZ Preset Goto
* @param [IN]   dwDeviceId                  设备ID Device ID
* @param [IN]   dwChannelID                 通道ID Channel ID
* @param [IN]   udwPresetIndex              预置位编号，范围：1-255,  PresetIndex,range:1-255
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
OPEN_API BOOL STDCALL OPENAPI_GotoPreset(IN INT32 dwDeviceId, IN INT32 dwChannelID, IN UINT32 udwPresetIndex);

/*************************************************************************/
/*                      鱼眼矫正/Fisheye Correction                      */
/*************************************************************************/

/**
* 设置PTZ模式和安装模式（开启鱼眼矫正）
* @param [IN] lpPlayHandle    播放句柄 Play handle
* @param [IN] ulPtzMode       PTZ模式，参考OPENAPI_PTZ_MODE_E PTZ mode, refer to OPENAPI_PTZ_MODE_E
* @param [IN] ulFixMode       安装模式，参考OPENAPI_FIX_MODE_E Installation mode, refer to OPENAPI_FIX_MODE_E
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 双条件触发机制：需同时满足bStartFisheye和bReportFisheyeStream Dual condition trigger: both bStartFisheye and bReportFisheyeStream must be satisfied
*/
OPEN_API BOOL STDCALL OpenAPI_SetPtzAndFixMode(IN LPVOID lpPlayHandle,
                                                IN UINT32 ulPtzMode,
                                                IN UINT32 ulFixMode);

/**
* 获取PTZ模式和安装模式
* @param [IN]  lpPlayHandle    播放句柄 Play handle
* @param [OUT] pulPtzMode      PTZ模式，参考OPENAPI_PTZ_MODE_E PTZ mode, refer to OPENAPI_PTZ_MODE_E
* @param [OUT] pulFixMode      安装模式，参考OPENAPI_FIX_MODE_E Installation mode, refer to OPENAPI_FIX_MODE_E
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
*/
OPEN_API BOOL STDCALL OpenAPI_GetPtzAndFixMode(IN LPVOID lpPlayHandle,
                                                OUT UINT32* pulPtzMode,
                                                OUT UINT32* pulFixMode);

/**
* 设置视频回调数据来源（矫正前/矫正后）
* @param [IN] lpPlayHandle    播放句柄 Play handle
* @param [IN] ulCBType        回调类型，参考OPENAPI_VIDEO_CB_TYPE_E Callback type, refer to OPENAPI_VIDEO_CB_TYPE_E
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
* @note 必须在OpenAPI_StartRealPlay后调用 Must be called after OpenAPI_StartRealPlay
*/
OPEN_API BOOL STDCALL OpenAPI_SetVideoCallBackMode(IN LPVOID lpPlayHandle,
                                                    IN UINT32 ulCBType);

/**
* 获取鱼眼参数（圆心坐标和半径）
* @param [IN]  lpPlayHandle     播放句柄 Play handle
* @param [OUT] pusCenterX       圆心X坐标（万分比[0,10000]） Center X coordinate (permyriad [0,10000])
* @param [OUT] pusCenterY       圆心Y坐标（万分比[0,10000]） Center Y coordinate (permyriad [0,10000])
* @param [OUT] pulRadius        半径 Radius
* @param [OUT] pulReserved      保留字段 Reserved field
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
*/
OPEN_API BOOL STDCALL OpenAPI_GetFishEyeParam(IN LPVOID lpPlayHandle,
                                               OUT UINT16* pusCenterX,
                                               OUT UINT16* pusCenterY,
                                               OUT UINT32* pulRadius,
                                               OUT UINT32* pulReserved);

/**
* 鼠标左键按下事件（鱼眼PTZ交互）
* @param [IN] lpPlayHandle    播放句柄 Play handle
* @param [IN] ulFlags         标志位 Flags
* @param [IN] pusPoint        点坐标（万分比[0,10000]） Point coordinates (permyriad [0,10000])
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
*/
OPEN_API BOOL STDCALL OpenAPI_OnLButtonDown(IN LPVOID lpPlayHandle,
                                             IN UINT32 ulFlags,
                                             IN CONST UINT16* pusPoint);

/**
* 鼠标左键弹起事件（鱼眼PTZ交互）
* @param [IN] lpPlayHandle    播放句柄 Play handle
* @param [IN] ulFlags         标志位 Flags
* @param [IN] pusPoint        点坐标（万分比[0,10000]） Point coordinates (permyriad [0,10000])
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
*/
OPEN_API BOOL STDCALL OpenAPI_OnLButtonUp(IN LPVOID lpPlayHandle,
                                           IN UINT32 ulFlags,
                                           IN CONST UINT16* pusPoint);

/**
* 鼠标移动事件（鱼眼PTZ交互）
* @param [IN] lpPlayHandle    播放句柄 Play handle
* @param [IN] ulFlags         标志位 Flags
* @param [IN] pusPoint        点坐标（万分比[0,10000]） Point coordinates (permyriad [0,10000])
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
*/
OPEN_API BOOL STDCALL OpenAPI_OnMouseMove(IN LPVOID lpPlayHandle,
                                           IN UINT32 ulFlags,
                                           IN CONST UINT16* pusPoint);

/**
* 鼠标滚轮事件（鱼眼PTZ交互）
* @param [IN] lpPlayHandle    播放句柄 Play handle
* @param [IN] ulFlags         标志位 Flags
* @param [IN] lDelta          滚轮值，正值表示向上滚动 Wheel value, positive for scrolling up
* @param [IN] pusPoint        点坐标（万分比[0,10000]） Point coordinates (permyriad [0,10000])
* @return TRUE表示成功, FALSE表示失败 TRUE for success, FALSE for failure
*/
OPEN_API BOOL STDCALL OpenAPI_OnMouseWheel(IN LPVOID lpPlayHandle,
                                            IN UINT32 ulFlags,
                                            IN INT32 lDelta,
                                            IN CONST UINT16* pusPoint);


#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */

#endif //_OPEN_API_SDK_H_ 