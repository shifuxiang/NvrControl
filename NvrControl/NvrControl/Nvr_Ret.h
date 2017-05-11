#ifndef NVR_RET_H
#define NVR_RET_H

#define NVR_SUCCESS                                                                 0				////成功值

///数据库模块
#define DB_CONNECTED_ERROR															420500001				///	连接数据库失败
#define DB_DISCONNECTED_ERROR														420500002				///	断开数据库连接失败
#define DB_COMMAND_QUERY_ERROR														420500003				///	发送数据库查询命令失败

///nvr 模块
#define URL_NVRLOGIN_ERROR															420200001				////登录nvr失败
#define URL_NVRLOGOUT_ERROR															420200002				////登出nvr失败
#define URL_NVRIPCANNOTPING_ERROR													420200003				////nvrIP地址ping不通


///ipc 模块
#define URL_IPCCONTROL_SETIPCINFO_ERROR												420300001				////设置ipc信息失败
#define URL_IPCCONTROL_GETIPCINFO_ERROR												420300002				////获取ipc信息失败
#define URL_IPCCONTROL_GETIPCRESOLURATIO_ERROR										420300003				////获取ipc所支持的分辨率信息失败

///download 模块
#define URL_DOWNLOADCONTROL_SETDOWNLOADSPEED_ERROR									420100001				////设置高速下载失败
#define URL_DOWNLOADCONTROL_DOWNLOADNUM_ERROR										420100002				////设置并发下载的数量，当当前并发下载的数量超过18时，停止该次下载
#define URL_DOWNLOADCONTROL_DOWNLOADBYTIME_ERROR									420100003				////调用sdk按时间下载的函数失败
#define URL_DOWNLOADCONTROL_AVAILABLESPACETOOLITTLE_ERROR							420100004				////当前目录剩余空间过小
#define URL_DOWNLOADCONTROL_STARTTIME_ERROR											420100005				////开始下载时间晚于当前时间
#define URL_DOWNLOADCONTROL_ENDTIME_ERROR											420100006				////结束下载时间晚于当前时间	

///timecontrol 模块
#define URL_TIMECONTROL_GETSYSTEMTIME_ERROR											420400001				////获取NVR系统时间失败
#define URL_TIMECONTROL_SETSYSTEMTIME_ERROR											420400002				////设置NVR系统时间失败
#endif  