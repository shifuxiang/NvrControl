#ifndef _SMS_RET_H
#define _SMS_RET_H

#define SMS_SUCCESS																	0	///	操作成功



#define SMS_PARAMETER_ERROR															1001	/// 输入参数错误

#define DB_CONNECTED_ERROR															1002	///	连接数据库失败
#define DB_DISCONNECTED_ERROR														1003	///	断开数据库连接失败
#define DB_COMMAND_QUERY_ERROR														1004	///	发送数据库查询命令失败



#define URI_COMMAND_PARSE_ERROR														1005	/// url发送的命令请求解析错误
#define URI_COMMAND_REQUEST_ERROR													1006	/// url发送的命令请求解析错误
//////////////////////////////////////////////////////////
///// 网页错误
#define URL_ADDRESS_ERROR															1007	/// URL地址错误
#define URL_ERROR_CODE_ERROR														1008	/// 没有指定的错误编码

#define DB_TABLE_INVALID_ERROR														1009	///	数据库表损坏错误
#define DB_READ_CONFIG_FILE_ERROR													1010	/// 读取数据库配置文件失败
#define DB_INIT_ERROR																1011	/// 读取初始化数据库对象失败


/// 配置管理 2000
#define URL_CONFIGCONTROLLER_NO_CONFIGTYPE_ERROR									2001				/// 没有此配置类型错误
#define URL_CONFIGCONTROLLER_NO_KEY_ERROR											2002				/// 没有此配置错误
#define URL_CONFIGCONTROLLER_KEY_VALUE_ERROR										2003				/// 配置值错误
#define URL_CONFIGCONTROLLER_GET_ERROR												2004				/// 获取配置错误
#define URL_CONFIGCONTROLLER_POST_ERROR												2005				/// 创建配置错误
#define URL_CONFIGCONTROLLER_PUT_ERROR												2006				/// 修改配置错误
#define URL_CONFIGCONTROLLER_DELETE_ERROR											2007				/// 删除配置错误
#define URL_CONFIGCONTROLLER_VALUE_ALREADY_EXIST_ERROR								2008				/// 配置值重复，路径配置相关
#define URL_CONFIGCONTROLLER_KEY_READONLY_ERROR										2009				/// 配置项为只读
#define URL_CONFIGCONTROLLER_SMS_CONFIG_FILE_NOT_EXIST_ERROR						2010				/// sms的配置文件不存在
#define URL_CONFIGCONTROLLER_SMS_CONFIG_FILE_INVALID_ERROR							2011				/// sms的配置文件无效

/// 用户管理 3000
#define URL_USERCONTROLLER_NO_USERID_ERROR											3001				/// 没有指定的ingestjob id
#define URL_USERCONTROLLER_USER_ALREADY_EXIST_ERROR									3002				/// 用户已经存在
#define URL_USERCONTROLLER_RIGHT_ERROR												3003				/// 权限错误
#define URL_USERCONTROLLER_NO_USER_ERROR											3004				/// 没有此用户错误
#define URL_USERCONTROLLER_PASSWORD_ERROR											3005				/// 用户密码错误
#define URL_USERCONTROLLER_PASSWORD_CONFIRM_ERROR									3006				/// 用户确认密码错误
#define URL_USERCONTROLLER_GET_ERROR												3007				/// 获取用户错误
#define URL_USERCONTROLLER_POST_ERROR												3008				/// 创建用户错误
#define URL_USERCONTROLLER_PUT_ERROR												3009				/// 修改用户错误
#define URL_USERCONTROLLER_DELETE_ERROR												3010				/// 删除用户错误

/// 片源管理 



/// 导入管理 4000
#define URL_INGESTCONTROLLER_NO_INGESTID_ERROR										4001				/// 没有指定的ingestjob id
#define URL_INGESTCONTROLLER_POST_INGEST_PATH_ERROR									4002				/// 导入路径错误，指定路径下没有cpl
#define URL_INGESTCONTROLLER_GET_ERROR												4003				/// 获取导入错误
#define URL_INGESTCONTROLLER_POST_ERROR												4004				/// 创建导入错误
#define URL_INGESTCONTROLLER_PUT_ERROR												4005				/// 修改导入错误
#define URL_INGESTCONTROLLER_DELETE_ERROR											4006				/// 删除导入错误
#define URL_INGESTCONTROLLER_DELETE_INGESTYING_ERROR								4007				/// 删除导入错误,导入任务正在进行
#define URL_INGESTCONTROLLER_PUT_CANCEL_NO_INESTING_ERROR							4008				/// 取消导入任务失败，此任务没有正在运行
#define URL_INGESTCONTROLLER_POST_CPL_ALREADY_EXIST_ERROR							4009				/// 创建导入错误,cpl已经存在
#define URL_INGESTCONTROLLER_FILELENZERO_ERROR										4010                /// 导入失败，文件长度为0
#define URL_INGESTCONTROLLER_SPACENOTENOUGH_ERROR									4011                /// 硬盘空间不不足

/// kdm管理 5000
#define URL_KDMCONTROLLER_NO_KDMID_ERROR											5001				/// 没有指定的kdm id
#define URL_KDMCONTROLLER_POST_KDM_PATH_ERROR										5002				/// 导入路径错误，指定路径下没有kdm文件
#define URL_KDMCONTROLLER_GET_ERROR													5003				/// 获取kdm错误
#define URL_KDMCONTROLLER_POST_ERROR												5004				/// 创建kdm错误
#define URL_KDMCONTROLLER_PUT_ERROR													5005				/// 修改kdm错误
#define URL_KDMCONTROLLER_DELETE_ERROR												5006				/// 删除kdm错误
#define URL_KDMCONTROLLER_POST_KDM_ALREADY_EXIST_ERROR								5007				/// 导入kdm错误 kdm文件已经存在
#define URL_KDMCONTROLLER_KDM_PARSE_ERROR											5008				/// kdm文件解析错误
#define URL_KDMCONTROLLER_KDM_MACHE_IMB_ERROR										5009				/// kdm文件匹配imb板卡错误
#define URL_KDMCONTROLLER_KDM_ACCESS_KDMFILE_ERROR									5010				/// kdm访问kdm文件错误

/// cpl管理 6000
#define URL_CPLCONTROLLER_NO_CPLID_ERROR											6001				/// 没有指定的cpl id
#define URL_CPLCONTROLLER_NO_REELID_ERROR											6002				/// 没有指定的reel id
#define URL_CPLCONTROLLER_NO_ASSETID_ERROR											6003				/// 没有指定的asset id
#define URL_CPLCONTROLLER_NO_ASSET_ERROR											6004				/// cpl没有asset资源文件
#define URL_CPLCONTROLLER_GET_ERROR													6005				/// 获取cpl错误
#define URL_CPLCONTROLLER_POST_ERROR												6006				/// 创建cpl错误
#define URL_CPLCONTROLLER_PUT_ERROR													6007				/// 修改cpl错误
#define URL_CPLCONTROLLER_DELETE_ERROR												6008				/// 删除cpl错误
#define URL_CPLCONTROLLER_DELETE_CPL_OCCUPIED_INUPCOMINGSCHEDULE_ERROR				6009				/// 删除cpl错误,cpl在将来的排期中被占用
#define URL_CPLCONTROLLER_DELETE_CPL_INPLAYINGSPL_ERROR								6010				/// 删除cpl错误,cpl 存在于正在放映的spl中
#define URL_CPLCONTROLLER_DELETE_INCHECKING_ERROR									6011				/// 删除cpl错误,cpl正在进行hash校验
#define URL_CPLCONTROLLER_PUT_CANCEL_NO_CHECKING_ERROR								6012				/// 取消cpl校验失败，此任务没有正在运行
#define URL_CPLCONTROLLER_NO_CPLUUID_ERROR											6013				/// 没有指定的cpl uuid
#define URL_CPLCONTROLLER_DELETE_CPL_OCCUPIED_INSPL_ERROR							6014				/// 删除cpl错误,cpl在spl中被占用
#define URL_CPLCONTROLLER_POST_CPL_ALREADY_EXIST_ERROR								6015				/// 创建cpl错误,cpl已经存在
#define URL_CPLCONTROLLER_POST_CPL_PARSE_SOURCE_ERROR								6016				/// 创建cpl错误,cpl解析片源错误
#define URL_CPLCONTROLLER_PUT_PAUSE_IN_INGESTING_ERROR								6017				/// 暂停cpl校验失败，此任务正在导入中
#define URL_CPLCONTROLLER_PUT_CANCEL_IN_INGESTING_ERROR								6018				/// 取消cpl校验失败，此任务正在导入中
#define URL_CPLCONTROLLER_PUT_CONTINUE_IN_OTHER_INGESTING_ERROR						6019				/// 继续cpl校验失败，其他导片任务正在进行
#define URL_CPLCONTROLLER_PUT_UPDATE_CPL_STORE_PATH_NO_CPL_ERROR					6020				/// 修改cpl存储路径失败，cpl不存在
#define URL_CPLCONTROLLER_PUT_UPDATE_CPL_STORE_PATH_CPL_PARSE_SOURCE_ERROR			6021				/// 修改cpl存储路径失败,cpl解析片源错误
#define URL_CPLCONTROLLER_CREATE_CPLINFO_PARAMETER_ERROR							6022				/// 创建cpl信息，参数错误
#define URL_CPLCONTROLLER_GET_ASSETINFOS_PARAMETER_ERROR							6023				/// 根据id获取reel信息错误
#define URL_CPLCONTROLLER_GET_ASSETINFOS_ERROR										6024				/// 根据id获取reel信息错误
#define URL_CPLCONTROLLER_GET_ASSETINFO_BYFILTER_PARAMETER_ERROR					6025				/// 根据过滤条件获取asset信息错误,参数错误
#define URL_CPLCONTROLLER_GET_ASSETINFO_BYFILTER_ERROR								6026				/// 根据过滤条件获取asset信息错误
#define URL_CPLCONTROLLER_GET_ASSETINFO_BYID_PARAMETER_ERROR						6027				/// 根据id获取asset信息错误,参数错误
#define URL_CPLCONTROLLER_GET_ASSETINFO_BYID_ERROR									6028				/// 根据id获取asset信息错误
#define URL_CPLCONTROLLER_GET_ASSETINFO_BYID_VALUE_NULL_ERROR						6029				/// 根据id获取asset信息获取到空值错误
#define URL_CPLCONTROLLER_GET_ASSETINFO_SUBTITLE_SUBS_ERROR							6030				/// 根据字幕子项asset信息错误
#define URL_CPLCONTROLLER_GET_REELS_PARAMETER_ERROR									6031				/// 根据过滤条件获取分本信息错误，参数错误
#define URL_CPLCONTROLLER_GET_REELS_ERROR											6032				/// 根据过滤条件获取分本信息错误
#define URL_CPLCONTROLLER_GET_REELINFO_BYFILTER_PARAMETER_ERROR						6033				/// 根据根据过滤条件获取分本信息错误,参数错误
#define URL_CPLCONTROLLER_GET_REELINFO_BYFILTER_ERROR								6034				///根据过滤条件获取分本信息错误
#define URL_CPLCONTROLLER_GET_REELINFO_BYID_PARAMETER_ERROR							6035				/// 根据id获取分本信息错误,参数错误
#define URL_CPLCONTROLLER_GET_REELINFO_BYID_ERROR									6036				/// 根据id获取分本信息错误
#define URL_CPLCONTROLLER_GET_CPLS_PARAMETER_ERROR									6037				/// 获取cpls信息错误，参数错误
#define URL_CPLCONTROLLER_GET_CPLS_ERROR											6038				/// 获取cpls信息错误
#define URL_CPLCONTROLLER_GET_CPLS_BYFILTER_PARAMETER_ERROR							6039				/// 根据过滤条件获取cpls信息错误，参数错误
#define URL_CPLCONTROLLER_GET_CPLS_BYFILTER_ERROR									6040				/// 根据过滤条件获取cpls信息错误
#define URL_CPLCONTROLLER_GET_CPLS_BYID_PARAMETER_ERROR								6041				/// 根据id获取cpl信息错误，参数错误
#define URL_CPLCONTROLLER_GET_CPLS_BYID_ERROR										6042				/// 根据id获取cpl信息错误
#define URL_CPLCONTROLLER_POST_PARSE_DCP_IN_FTP_ERROR								6043				/// 创建cpl错误,解析ftp服务器上的数字电影包失败
#define URL_CPLCONTROLLER_POST_FTP_DOWN_CPL_FILE_ERROR								6044				/// 创建cpl错误,下载ftp服务器上的数字电影包中的cpl文件失败
#define URL_CPLCONTROLLER_POST_FTP_DOWN_PKL_FILE_ERROR								6045				/// 创建cpl错误,下载ftp服务器上的数字电影包中的pkl文件失败
#define URL_CPLCONTROLLER_POST_FTP_DOWN_ASSETMAP_FILE_ERROR							6046				/// 创建cpl错误,下载ftp服务器上的数字电影包中的assetmap文件失败
#define URL_CPLCONTROLLER_POST_PARSE_DCP_IN_STORE_ERROR								6047				/// 创建cpl错误,解析存储设备上的数字电影包失败
#define URL_CPLCONTROLLER_POST_STORE_COPY_CPL_FILE_ERROR							6048				/// 创建cpl错误,拷贝存储上的数字电影包中的cpl文件失败
#define URL_CPLCONTROLLER_POST_STORE_COPY_PKL_FILE_ERROR							6049				/// 创建cpl错误,拷贝存储上上的数字电影包中的pkl文件失败
#define URL_CPLCONTROLLER_POST_STORE_COPY_ASSETMAP_FILE_ERROR						6050				/// 创建cpl错误,拷贝存储上上的数字电影包中的assetmap文件失败
#define URL_CPLCONTROLLER_CREATE_CPLINFO_FTPSERVER_INFO_NOT_INTEGRITY_ERROR			6051				/// 创建cpl信息失败，ftp信息不完整
#define URL_CPLCONTROLLER_SCAN_CPLINFO_FTPSERVER_INFO_NOT_INTEGRITY_BY_FTP_ERROR	6052				/// 扫描cpl信息失败，ftp信息不完整
#define URL_CPLCONTROLLER_SCAN_CPLINFO_PATH_INFO_NOT_INTEGRITY_BY_STORE_ERROR		6053				/// 扫描cpl信息失败，路径信息不完整
#define URL_CPLCONTROLLER_CPL_ACCESS_CPLFILE_ERROR									6054				/// cpl无法访问cpl文件错误
#define URL_CPLCONTROLLER_CPL_ACCESS_PKLFILE_ERROR									6055				/// cpl无法访问pkl文件错误
#define URL_CPLCONTROLLER_CPL_ACCESS_VIDEOFILE_ERROR								6056				/// cpl无法访问video文件错误
#define URL_CPLCONTROLLER_CPL_ACCESS_AUDIOFILE_ERROR								6057				/// cpl无法访问audio文件错误
#define URL_CPLCONTROLLER_CPL_NOTINTEGRITY_VIDEOFILE_ERROR							6058				/// cpl视频文件不完整错误
#define URL_CPLCONTROLLER_CPL_NOTINTEGRITY_AUDIOFILE_ERROR							6059				/// cpl音频文件不完整错误
#define URL_CPLCONTROLLER_CPL_ACCESS_SUBTITLEFILE_ERROR								6060				/// cpl无法访问字幕文件错误
#define URL_CPLCONTROLLER_CPL_ACCESS_SUB_SUBTITLEFILE_ERROR							6061				/// cpl无法访问子字幕文件错误
#define URL_CPLCONTROLLER_CPL_NOTINTEGRITY_SUBTITLEFILE_ERROR						6062				/// cpl字幕文件不完整错误
#define URL_CPLCONTROLLER_CPL_NOTINTEGRITY_SUB_SUBTITLEFILE_ERROR					6063				/// cpl子字幕文件不完整错误

#define URL_CPLCONTROLLER_GET_ASSETINFO_BYUUID_PARAMETER_ERROR            6064
#define URL_CPLCONTROLLER_NO_ASSETUUID_ERROR                               6065




/// cue管理 7000
#define URL_CUECONTROLLER_NO_CUEID_ERROR											7001				/// 没有指定的ingestjob id
#define URL_CUECONTROLLER_NO_CUEFILE_ERROR											7002				/// 没有指定的cue脚本文件
#define URL_CUECONTROLLER_CUEEXECUTE_ERROR											7003				/// cue脚本文件执行失败
#define URL_CUECONTROLLER_POST_INGEST_PATH_ERROR									7004				/// 导入路径错误，指定路径下没有cue脚本文件
#define URL_CUECONTROLLER_GET_ERROR													7005				/// 获取cue错误
#define URL_CUECONTROLLER_POST_ERROR												7006				/// 创建cue错误
#define URL_CUECONTROLLER_PUT_ERROR													7007				/// 修改cue错误
#define URL_CUECONTROLLER_DELETE_ERROR												7008				/// 删除cue错误

/// spl管理 8000
#define URL_SPLCONTROLLER_NO_SPLID_ERROR											8001				/// 没有指定的spl id
#define URL_SPLCONTROLLER_NO_CPL_ERROR												8002				/// 指定spl下没有cpl
#define URL_SPLCONTROLLER_GET_ERROR													8003				/// 获取spl错误
#define URL_SPLCONTROLLER_POST_ERROR												8004				/// 创建spl错误
#define URL_SPLCONTROLLER_PUT_ERROR													8005				/// 修改spl错误
#define URL_SPLCONTROLLER_DELETE_ERROR												8006				/// 删除spl错误
#define URL_SPLCONTROLLER_POST_SPLNAME_ALREADY_EXIST_ERROR							8007				/// 创建spl错误，存在同名spl
#define URL_SPLCONTROLLER_DELETE_SPL_OCCUPIED_INUPCOMINGSCHEDULE_ERROR				8008				/// 删除spl错误,cpl在schedule中被占用
#define URL_SPLCONTROLLER_DELETE_SPL_PLAYING_ERROR									8009				/// 删除spl错误,spl 正在被放映
#define URL_SPLCONTROLLER_PUT_SPL_PLAYING_ERROR										8010				/// 修改spl错误,spl 正在被放映
#define URL_SPLCONTROLLER_PUT_SPL_OCCUPIED_INUPCOMINGSCHEDULE_ERROR					8011				/// 修改spl错误,cpl在schedule中被占用
#define URL_SPLCONTROLLER_DELETE_SPLELEMENT_INUSINGSPL_ERROR						8012				/// 删除spl element错误,spl 正在被使用，放映中，或是 在未来的schedule中
#define URL_SPLCONTROLLER_POST_CPL_NOTEXIST_ERROR									8013				/// 创建spl错误 cpl不存在
#define URL_SPLCONTROLLER_POST_CPL_NOTLOCAL_ERROR									8014				/// 创建spl错误 cpl没有在本地存在（导入过程中、或导入失败）
/// gkm add 20141209
#define URL_SPLCONTROLLER_POST_SPLUUID_ALREADY_EXIST_ERROR							8015				/// 创建spl错误，spl uuid已经存在
#define URL_SPLCONTROLLER_POST_SPLNAME_NULL_ERROR									8016				/// 创建spl错误，spl名字为空
#define URL_SPLCONTROLLER_GET_SPLS_PARAMETER_ERROR									8017				/// 创建spl错误，参数错误
#define URL_SPLCONTROLLER_GET_SPLS_ERROR											8018				/// 获取spls信息错误
#define URL_SPLCONTROLLER_GET_SPL_BYFILTER_PARAMETER_ERROR							8019				/// 根据过滤条件获取spls信息错误,参数错误
#define URL_SPLCONTROLLER_GET_SPL_BYFILTER_ERROR									8020				/// 根据过滤条件获取spls信息错误
#define URL_SPLCONTROLLER_GET_SPL_BYID_PARAMETER_ERROR								8021				/// 根据id获取spl信息错误,参数错误
#define URL_SPLCONTROLLER_GET_SPL_BYID_ERROR										8022				/// 根据id获取spl信息错误
#define URL_SPLCONTROLLER_GET_SPL_ELEMENTS_PARAMETER_ERROR							8024				/// 获取spl元素信息错误,参数错误
#define URL_SPLCONTROLLER_GET_SPL_ELEMENTS_ERROR									8025				/// 获取spl元素信息错误
#define URL_SPLCONTROLLER_GET_SPL_ELEMENT_BYFILTER_PARAMETER_ERROR					8026				/// 根据过滤条件获取spl元素信息错误,参数错误
#define URL_SPLCONTROLLER_GET_SPL_ELEMENT_BYFILTER_ERROR							8027				/// 根据过滤条件获取spl元素信息错误
#define URL_SPLCONTROLLER_GET_SPL_ELEMENT_BYID_PARAMETER_ERROR						8028				/// 根据id获取spl元素信息错误,参数错误
#define URL_SPLCONTROLLER_GET_SPL_ELEMENT_BYID_ERROR								8029				/// 根据id获取spl元素信息错误
#define URL_SPLCONTROLLER_SPL_VERIFY_HAVE_CPL_INVALID_ERROR							8030				/// spl验证错误，含有无效的cpl
#define URL_SPLCONTROLLER_SPL_VERIFY_HAVE_CPL_VALID_AFTER_ERROR						8031				/// spl验证错误，含有将来有效的密文cpl
#define URL_SPLCONTROLLER_SPL_VERIFY_HAVE_CPL_NO_KDM_ERROR							8032				/// spl验证错误，含有无kdm的密文cpl
#define URL_SPLCONTROLLER_SPL_VERIFY_HAVE_CPL_NO_KDM_FILE_ERROR						8033				/// spl验证错误，含有无kdm文件的密文cpl
#define URL_SPLCONTROLLER_SPL_VERIFY_HAVE_CPL_NOT_INTEGRITY_ERROR					8034				/// spl验证错误，含有cpl关联文件不完整的cpl
#define URL_SPLCONTROLLER_POST_SPLUUID_FORMAT_ERROR									8035				/// 创建spl错误，spl uuid格式错误


/// schedule管理 9000
#define URL_SCHEDULECONTROLLER_NO_SCHEDULEID_ERROR									9001				/// 没有指定的schedule id
#define URL_SCHEDULECONTROLLER_POST_NO_SPLID_ERROR									9002				/// 创建schedule没有指定的splid
#define URL_SCHEDULECONTROLLER_POST_START_AT_ERROR									9003				/// 创建schedule开始播放时间错误
#define URL_SCHEDULECONTROLLER_GET_ERROR											9004				/// 获取schedule错误
#define URL_SCHEDULECONTROLLER_POST_ERROR											9005				/// 创建schedule错误
#define URL_SCHEDULECONTROLLER_PUT_ERROR											9006				/// 修改schedule错误
#define URL_SCHEDULECONTROLLER_DELETE_ERROR											9007				/// 删除schedule错误
#define URL_SCHEDULECONTROLLER_DELETE_RUNNING_ERROR									9008				/// 删除schedule错误 正在运行
#define URL_SCHEDULECONTROLLER_POST_PLAYNOW_INPLAYING_ERROR							9009				/// 创建立即播放的schedule错误,目前正在播放
#define URL_SCHEDULECONTROLLER_POST_STARTAT_ALREADY_EXIST_ERROR						9010				/// 创建schedule错误,开始时间已经存在
#define URL_SCHEDULECONTROLLER_PUT_RUNNING_ERROR									9011				/// 修改schedule错误 正在运行
#define URL_SCHEDULECONTROLLER_PUT_STARTAT_ALREADY_EXIST_ERROR						9012				/// 修改schedule错误,开始时间已经存在
#define URL_SCHEDULECONTROLLER_POST_SPL_INVALID_ERROR								9013				/// 创建schedule,spl无效
#define URL_SCHEDULECONTROLLER_POST_STARTAT_IN_PASS_ERROR							9014				/// 创建schedule错误,开始时间在过去
#define URL_SCHEDULECONTROLLER_PUT_STARTAT_IN_PASS_ERROR							9015				/// 修改schedule错误,开始时间在过去
#define URL_SCHEDULECONTROLLER_GET_SCHEDULE_BYID_PARAMETER_ERROR					9016				/// 根据id获取schedule信息错误,参数错误
#define URL_SCHEDULECONTROLLER_GET_SCHEDULE_BYID_ERROR								9017				/// 根据id获取schedule信息错误
#define URL_SCHEDULECONTROLLER_GET_SCHEDULE_BYFILTER_PARAMETER_ERROR				9018				/// 根据过滤条件获取schedule信息错误,参数错误
#define URL_SCHEDULECONTROLLER_GET_SCHEDULE_BYFILTER_ERROR							9019				/// 根据过滤条件获取schedule信息错误
#define URL_SCHEDULECONTROLLER_GET_SCHEDULES_PARAMETER_ERROR						9020				/// 获取schedules信息错误,参数错误
#define URL_SCHEDULECONTROLLER_GET_SCHEDULES_ERROR									9021				/// 获取schedules信息错误
#define URL_SCHEDULECONTROLLER_POST_SCHEULE_INPLAYING_ERROR							9022				/// 创建schedule错误,此段时间有影片正在播放
#define URL_SCHEDULECONTROLLER_POST_SPL_UUID_FORMAT_ERROR							9023				/// 创建schedule,spl uuid格式错误
#define URL_SCHEDULECONTROLLER_POST_SCHEDULE_UUID_FORMAT_ERROR						9024				/// 创建schedule,schedule uuid格式错误
#define URL_SCHEDULECONTROLLER_CHECK_SPL_UUID_FORMAT_ERROR							9025				/// 检查spl uuid格式错误
#define URL_SCHEDULECONTROLLER_GET_SPL_INFO_ERROR									9026				/// 获取spl信息错误
#define URL_SCHEDULECONTROLLER_SPL_INVALID_ERROR									9027				/// spl内容无效
#define URL_SCHEDULECONTROLLER_STARTAT_IN_PASS_ERROR								9028				/// 开始时间在过去错误
#define URL_SCHEDULECONTROLLER_STARTAT_ALREADY_EXIST_ERROR							9029				/// 开始时间段已经被占用错误
#define URL_SCHEDULECONTROLLER_STARTAT_INPLAYING_ERROR								9030				/// 此段时间有影片正在播放
#define URL_SCHEDULECONTROLLER_STARTAT_PLAYNOW_INPLAYING_ERROR						9031				/// 当前时间正在播放
#define URL_SCHEDULECONTROLLER_PUT_STARTAT_ERROR									9032				/// 修改schedule的开始时间错误
#define URL_SCHEDULECONTROLLER_CHECK_SCHEDULE_UUID_FORMAT_ERROR						9033				/// 检查schedule uuid格式错误
#define URL_SCHEDULECONTROLLER_STARTAT_SCHEDULE_STATE_INVALID_ERROR					9034				/// 检查排期开始时间时排期状态无效



///放映管理 10000
#define URL_SCREENINGCONTROLLER_NO_SCREENINGID_ERROR								10001				/// 没有指定的screening id
#define URL_SCREENINGCONTROLLER_POST_NO_SPLID_ERROR									10002				/// 创建screening没有指定的splid
#define URL_SCREENINGCONTROLLER_POST_NO_CPLID_ERROR									10003				/// 创建screening没有指定的cplid
#define URL_SCREENINGCONTROLLER_NO_SPL_ERROR										10004				/// 指定的screening下没有spl
#define URL_SCREENINGCONTROLLER_NO_CPL_ERROR										10005				/// 指定的screening下没有spl
#define URL_SCREENINGCONTROLLER_GET_ERROR											10006				/// 获取screening错误
#define URL_SCREENINGCONTROLLER_POST_ERROR											10007				/// 创建screening错误
#define URL_SCREENINGCONTROLLER_PUT_ERROR											10008				/// 修改screening错误
#define URL_SCREENINGCONTROLLER_DELETE_ERROR										10009				/// 删除screening错误
#define URL_SCREENINGCONTROLLER_POST_OVERLAP_ERROR									10010				/// 创建screening错误,放映重叠
#define URL_SCREENINGCONTROLLER_PUT_PLAYLAST_ALREADY_FIRST_ERROR					10011				/// 播放上一个错误，已经是第一个
#define URL_SCREENINGCONTROLLER_PUT_PLAYNEXT_ALREADY_LAST_ERROR						10012				/// 播放下一个错误，已经是最后一个
#define URL_SCREENINGCONTROLLER_GET_SCREENINGS_PARAMETER_ERROR						10013				/// 根据过滤条件获取screening信息错误,参数错误
#define URL_SCREENINGCONTROLLER_GET_SCREENINGS_ERROR								10014				/// 获取screenings信息错误,参数错误
#define URL_SCREENINGCONTROLLER_GET_SCREENING_BYFILTER_PARAMETER_ERROR				10015				/// 根据过滤条件获取screenings信息错误,参数错误
#define URL_SCREENINGCONTROLLER_GET_SCREENING_BYFILTER_ERROR						10016				/// 根据过滤条件获取screenings信息错误
#define URL_SCREENINGCONTROLLER_GET_SCREENING_BYID_PARAMETER_ERROR					10017				/// 根据id获取screening信息错误,参数错误
#define URL_SCREENINGCONTROLLER_GET_SCREENING_BYID_ERROR							10018				/// 根据id获取screening信息错误
#define URL_SCREENINGCONTROLLER_GET_SCREENINGELEMENTS_PARAMETER_ERROR				10019				/// 获取screening元素信息s错误,参数错误
#define URL_SCREENINGCONTROLLER_GET_SCREENINGELEMENTS_ERROR							10020				/// 获取screening元素信息s错误
#define URL_SCREENINGCONTROLLER_GET_SCREENINGELEMENT_BYID_PARAMETER_ERROR			10021				/// 根据id获取screening元素信息错误,参数错误
#define URL_SCREENINGCONTROLLER_GET_SCREENINGELEMENT_BYID_ERROR						10022				/// 根据过滤条件获取screening元素信息错误
#define URL_SCREENINGCONTROLLER_GET_SCREENINGELEMENT_BYFILTER_PARAMETER_ERROR		10023				/// 根据过滤条件获取screening元素信息s错误,参数错误
#define URL_SCREENINGCONTROLLER_GET_SCREENINGELEMENT_BYFILTER_ERROR					10024				/// 根据过滤条件获取screening元素信息s错误
#define URL_SCREENINGCONTROLLER_POST_LOAD_SPL_PARAMETER_ERROR						10025				/// 加载spl错误，参数错误
#define URL_SCREENINGCONTROLLER_POST_LOAD_SPL_NOT_EXIST_ERROR						10026				/// 加载spl错误，spl不存在
#define URL_SCREENINGCONTROLLER_POST_LOAD_SPL_INVALID_ERROR							10027				/// 加载spl错误，spl无效
#define URL_SCREENINGCONTROLLER_POST_LOAD_SPL_OTHER_LOADING_ALREADY_ERROR			10028				/// 加载spl错误，其他spl已经被加载
#define URL_SCREENINGCONTROLLER_GET_LOADING_SPL_PARAMETER_ERROR						10029				/// 获取加载的spl信息错误，参数错误
#define URL_SCREENINGCONTROLLER_GET_LOADING_SPL_NOT_EXIST_ERROR						10030				/// 获取加载的spl信息错误，spl不存在
#define URL_SCREENINGCONTROLLER_GET_LOADING_SPL_INVALID_ERROR						10031				/// 获取加载的spl信息错误，spl无效
#define URL_SCREENINGCONTROLLER_GET_LOADING_NO_SPL_LOADING_ERROR					10032				/// 获取加载的spl信息错误，没有加载的spl
#define URL_SCREENINGCONTROLLER_APPLY_PLAYCONTROL_INSCHEDULE_ERROR					10033				/// 排期模式下使用播控功能错误
#define URL_SCREENINGCONTROLLER_POST_UNLOAD_SPL_INPLAYING_ERROR						10034				/// 卸载spl错误，spl正在放映
#define URL_SCREENINGCONTROLLER_CREATESCREENING_SPL_NOLOAD_ERROR					10035				/// 创建screening错误,spl没有加载
#define URL_SCREENINGCONTROLLER_CREATESCREENING_SPL_NOTLOADED_SPL_ERROR				10036				/// 创建screening错误,放映的不是被加载的spl
#define URL_SCREENINGCONTROLLER_POST_SPL_INVALID_ERROR								10037				/// 创建放映失败,spl无效
#define URL_SCREENINGCONTROLLER_CREATESCREENING_SCHDULE_UUID_INVALID_ERROR			10038				/// 创建screening错误,排期uuid不合法
#define URL_SCREENINGCONTROLLER_CREATESCREENING_SCREENING_UUID_INVALID_ERROR		10039				/// 创建screening错误,放映uuid不合法
#define URL_SCREENINGCONTROLLER_CREATESCREENING_SPL_UUID_INVALID_ERROR				10040				/// 创建screening错误,节目uuid不合法
#define URL_SCREENINGCONTROLLER_CREATESCREENING_INSDI_INPUT_ERROR					10041				/// 创建screening错误,板卡为sdi输入模式
#define URL_SCREENINGCONTROLLER_CREATESCREENING_IMB_CONNECTED_ERROR					10042				/// 创建screening错误,板卡没有连接


/// 自动化管理 11000
#define URL_AUTOMATIONCONTROLLER_NO_AUTOMATIONID_ERROR								11001				/// 没有指定的automation id
#define URL_AUTOMATIONCONTROLLER_NO_AUTOMATIONELEMENTID_ERROR						11002				/// 没有指定的automation id
#define URL_AUTOMATIONCONTROLLER_NO_CPL_SPL_ERROR									11003				/// 指定automation下没有cpl或spl
#define URL_AUTOMATIONCONTROLLER_NO_CUE_ERROR										11004				/// 指定automation下没有cue
#define URL_AUTOMATIONCONTROLLER_POST_INVALIDSPL_ERROR								11005				/// 创建automation时无效的spl
#define URL_AUTOMATIONCONTROLLER_POST_INVALIDSPLELEMENT_ERROR						11006				/// 创建automation时无效的splelement
#define URL_AUTOMATIONCONTROLLER_POST_INVALIDOFFSETETYPE_ERROR						11007				/// 创建automation时无效的offset type
#define URL_AUTOMATIONCONTROLLER_POST_INVALIDOFFSETE_ERROR							11008				/// 创建automation时无效的offset值
#define URL_AUTOMATIONCONTROLLER_POST_INVALIDTRIGGER_ERROR							11009				/// 创建automation时无效的trigger
#define URL_AUTOMATIONCONTROLLER_GET_ERROR											11010				/// 获取automation错误
#define URL_AUTOMATIONCONTROLLER_POST_ERROR											11011				/// 创建automation错误
#define URL_AUTOMATIONCONTROLLER_PUT_ERROR											11012				/// 修改automation错误
#define URL_AUTOMATIONCONTROLLER_DELETE_ERROR										11013				/// 删除automation错误

/// imb板卡管理 12000
#define URL_IMBCONTROLLER_NO_IMBID_ERROR											12001				/// 没有指定的imb id
#define URL_IMBCONTROLLER_IMB_CONNECT_ERROR											12002				/// imb板卡连接错误
#define URL_IMBCONTROLLER_IMB_INIT_ERROR											12003				/// imb板卡初始化错误
#define URL_IMBCONTROLLER_IMB_SET_ERROR												12004				/// imb板卡设置错误
#define URL_IMBCONTROLLER_IMB_GETSECURITYLOG_INPLAYING_ERROR						12005				/// imb板卡获取安全日志错误 在播放过程中
#define URL_IMBCONTROLLER_GETCERT_INPLAYING_ERROR									12006				/// imb板卡获取设备证书错误 在播放过程中
#define URL_IMBCONTROLLER_GET_ERROR													12007				/// 获取imb错误
#define URL_IMBCONTROLLER_POST_ERROR												12008				/// 创建imb错误
#define URL_IMBCONTROLLER_PUT_ERROR													12009				/// 修改imb错误
#define URL_IMBCONTROLLER_DELETE_ERROR												12010				/// 删除imb错误
#define SMS_IMBCONTROLLER_IMB_GETSTATE_ERROR										12011				/// imb板卡获取板卡状态失败
#define SMS_IMBCONTROLLER_IMB_TRANS_VIDEO_ERROR										12012				/// imb板卡传输视频失败
#define SMS_IMBCONTROLLER_IMB_TRANS_AUDIO_ERROR										12013				/// imb板卡传输音频失败
#define SMS_IMBCONTROLLER_IMB_VIDEO_MODE_ERROR										12014				/// 视频模式错误
#define SMS_IMBCONTROLLER_IMB_INIT_SM_ERROR											12015				/// 初始化安全管理器错误
#define SMS_IMBCONTROLLER_IMB_INIT_VIDEODECODER_ERROR								12016				/// 初始化视频解码器错误
#define URL_IMBCONTROLLER_IMB_RUN_ERROR												12017				/// imb板卡 开始播放失败
#define URL_IMBCONTROLLER_IMB_PAUSE_ERROR											12018				/// imb板卡 暂停播放失败
#define URL_IMBCONTROLLER_IMB_STOP_ERROR											12019				/// imb板卡 停止播放失败
#define URL_IMBCONTROLLER_IMB_GETSECURITYLOG_ERROR									12020				/// imb板卡获取安全日志错误
#define URL_IMBCONTROLLER_GETCERT_ERROR												12021				/// imb板卡获取设备证书错误
#define URL_IMBCONTROLLER_DEVICE_USING_ERROR										12022				/// imb板卡正在被占用错误
#define URL_IMBCONTROLLER_RESETPLAYSTATE_INPLAYING_ERROR							12023				/// 重置板卡播放状态错误 板卡在播放过程中
#define URL_IMBCONTROLLER_ALLOC_DEVICE_RESOURCE_ERROR								12024				/// 申请设备资源错误 new 设备对象相关
#define URL_IMBCONTROLLER_IMB_GETSECURITYLOG_EMPTY_ERROR							12025				/// imb板卡获取安全日志错误,此时间段没有安全日志，日志信息为空
#define SMS_IMBCONTROLLER_IMB_INIT_VIDEOOUTPUT_ERROR								12026				/// 初始化视频输出错误
#define URL_IMBCONTROLLER_IMB_SET_IMBINPUTMODE_INPLAYING_ERROR						12027				/// imb板卡设置输入模式错误 在播放过程中
#define URL_IMBCONTROLLER_IMB_CREATE_VIDEO_INPUT_ERROR								12028				/// imb板卡创建视频输入对象错误
#define URL_IMBCONTROLLER_IMB_GET_VIDEO_INPUT_ERROR									12029				/// imb板卡获取视频输入模式错误
#define URL_IMBCONTROLLER_IMB_SET_VIDEO_INPUT_ERROR									12030				/// imb板卡获取视频输入模式错误
#define URL_IMBCONTROLLER_IMB_ENABLE_VIDEO_INPUT_ERROR								12031				/// imb板卡使能视频输入错误
#define URL_IMBCONTROLLER_IMB_DISABLE_VIDEO_INPUT_ERROR								12032				/// imb板卡禁用视频输入错误
#define URL_IMBCONTROLLER_PUT_MARRAGE_ERROR											12033				/// imb板卡嫁接错误
#define URL_IMBCONTROLLER_PUT_RESET_ERROR											12034				/// imb板卡复位错误
#define URL_IMBCONTROLLER_MARRAGE_INPLAYING_ERROR									12035				/// imb板卡嫁接失败 在播放过程中
#define URL_IMBCONTROLLER_MARRAGEING_ERROR											12036				/// imb板卡嫁接失败 在嫁接过程中
#define URL_IMBCONTROLLER_GET_IMB_BYFILTER_PARAMETER_ERROR							12037				/// 根据过滤条件获取imb信息错误,参数错误
#define URL_IMBCONTROLLER_GET_IMB_BYFILTER_ERROR									12038				/// 根据过滤条件获取imb信息错误
#define URL_IMBCONTROLLER_GET_IMB_BYID_PARAMETER_ERROR								12039				/// 根据id获取imb信息错误,参数错误
#define URL_IMBCONTROLLER_GET_IMB_BYID_ERROR										12040				/// 根据id获取imb信息错误
#define URL_IMBCONTROLLER_IMB_GET_IMBINPUTMODE_INPLAYING_ERROR						12041				/// imb板卡获取输入模式错误 在播放过程中
#define URL_IMBCONTROLLER_GETSMSTATUS_ERROR											12042				/// 获取imb板卡安全管理器状态失败
#define URL_IMBCONTROLLER_POST_LOAD_SPL_PARAMETER_ERROR								12043				/// 加载spl错误，参数错误
#define URL_IMBCONTROLLER_POST_LOAD_SPL_NOT_EXIST_ERROR								12044				/// 加载spl错误，spl不存在
#define URL_IMBCONTROLLER_POST_LOAD_SPL_INVALID_ERROR								12045				/// 加载spl错误，spl无效
#define URL_IMBCONTROLLER_POST_LOAD_SPL_OTHER_LOADING_ALREADY_ERROR					12046				/// 加载spl错误，其他spl已经被加载
#define URL_IMBCONTROLLER_GET_LOADING_SPL_PARAMETER_ERROR							12047				/// 获取加载的spl信息错误，参数错误
#define URL_IMBCONTROLLER_GET_LOADING_SPL_NOT_EXIST_ERROR							12048				/// 获取加载的spl信息错误，spl不存在
#define URL_IMBCONTROLLER_GET_LOADING_SPL_INVALID_ERROR								12049				/// 获取加载的spl信息错误，spl无效
#define URL_IMBCONTROLLER_GET_LOADING_NO_SPL_LOADING_ERROR							12050				/// 获取加载的spl信息错误，没有加载的spl
#define URL_IMBCONTROLLER_POST_UNLOAD_SPL_INPLAYING_ERROR							12051				/// 卸载spl错误，spl正在放映
#define SMS_IMBCONTROLLER_IMB_TRANS_VIDEO_FRAME_DATA_ERROR							12052				/// 发送视频帧时,数据错误
#define SMS_IMBCONTROLLER_IMB_TRANS_AUDIO_FRAME_DATA_ERROR							12053				/// 发送音频帧时,数据错误
#define SMS_IMBCONTROLLER_IMB_TRANS_VIDEO_GET_BUFF_ERROR							12054				/// 发送视频帧时,获取视频帧缓冲区错误
#define SMS_IMBCONTROLLER_IMB_TRANS_AUDIO_GET_BUFF_ERROR							12055				/// 发送音频帧时,获取音频帧缓冲区错误
#define SMS_IMBCONTROLLER_IMB_TRANS_VIDEO_GET_BUFF_ADDRESS_ERROR					12056				/// 发送视频帧时,获取视频帧缓冲区地址错误
#define SMS_IMBCONTROLLER_IMB_TRANS_AUDIO_GET_BUFF_ADDRESS_ERROR					12057				/// 发送音频帧时,获取音频帧缓冲区地址错误
#define SMS_IMBCONTROLLER_IMB_TRANS_AVFRAME_DATA_INVALID_ERROR						12058				/// 发送视频帧时,音视频帧数据无效
#define SMS_IMBCONTROLLER_CP850_TRANS_ATMOS_ERROR									12059				/// CP850发送atmos数据帧失败
#define SMS_IMBCONTROLLER_IMB_NOT_VALID_DEVICE_ERROR								12060				/// 无效的imb板卡设备
#define SMS_IMBCONTROLLER_SMSSTORE_NOT_VALID_DEVICE_ERROR							12061				/// 无效的sms存储设备


/// 时区管理 13000
#define URL_TIMEZONECONTROLLER_NO_TIMEZONE_ERROR									13001				/// 没有指定的时区
#define URL_TIMEZONECONTROLLER_GET_ERROR											13002				/// 获取时区错误
#define URL_TIMEZONECONTROLLER_PUT_ERROR											13003				/// 修改时区错误
#define URL_TIMEZONECONTROLLER_DELETE_ERROR											13004				/// 删除时区错误


/// 状态管理 14000
#define URL_SERVERSTATECONTROLLER_GET_ERROR											14001				/// 获取系统状态错误


/// 日志管理 15000
#define URL_LOGCONTROLLER_NO_LOGID_ERROR											15001				/// 没有指定的log id
#define URL_LOGCONTROLLER_GET_LOGTIME_ERROR											15002				/// 获取日志，时间输入错误
#define URL_LOGCONTROLLER_GET_ERROR													15003				/// 获取日志错误
#define URL_LOGCONTROLLER_POST_ERROR												15004				/// 创建日志错误
#define URL_LOGCONTROLLER_PUT_ERROR													15005				/// 修改日志错误
#define URL_LOGCONTROLLER_DELETE_ERROR												15006				/// 删除日志错误

/// ftp管理 16000
#define URL_FTPCONTROLLER_NO_FTPID_ERROR											16001				/// 没有指定的ftp id
#define URL_FTPCONTROLLER_FTP_ADDRESS_ERROR											16002				/// ftp ip地址错误
#define URL_FTPCONTROLLER_FTP_USERNAME_PASSWORD_ERROR								16003				/// ftp 用户名密码
#define URL_FTPCONTROLLER_FTP_PATH_ERROR											16004				/// ftp 路径错误
#define URL_FTPCONTROLLER_GET_ERROR													16005				/// 获取ftp错误
#define URL_FTPCONTROLLER_POST_ERROR												16006				/// 创建ftp错误
#define URL_FTPCONTROLLER_PUT_ERROR													16007				/// 修改ftp错误
#define URL_FTPCONTROLLER_DELETE_ERROR												16008				/// 删除ftp错误
#define URL_FTPCONTROLLER_POST_PUT_FTPNAME_ALREADY_EXIST_ERROR						16009				/// 创建或修改ftp错误,名称已经存在
#define URL_FTPCONTROLLER_POST_PUT_FTP_ALREADY_EXIST_ERROR							16010				/// 创建或修改ftp错误，ftp参数信息已经存在（ip、端口号、用户名、路径唯一）

/// trigger管理 17000
#define URL_TRIGGERCONTROLLER_NO_TRIGGERID_ERROR									17001			/// 没有指定的trigger id
#define URL_TRIGGERCONTROLLER_GET_ERROR												17002			/// 获取trigger错误
#define URL_TRIGGERCONTROLLER_POST_ERROR											17003			/// 创建trigger错误
#define URL_TRIGGERCONTROLLER_PUT_ERROR												17004			/// 修改trigger错误
#define URL_TRIGGERCONTROLLER_DELETE_ERROR											17005			/// 删除trigger错误

/// macro管理 18000
#define URL_MACROCONTROLLER_NO_MACROID_ERROR										18001			/// 没有指定的macro id
#define URL_MACROCONTROLLER_GET_ERROR												18002			/// 获取macro错误
#define URL_MACROCONTROLLER_POST_ERROR												18003			/// 创建macro错误
#define URL_MACROCONTROLLER_PUT_ERROR												18004			/// 修改macro错误
#define URL_MACROCONTROLLER_DELETE_ERROR											18005			/// 删除macro错误

/// event管理 19000
#define URL_EVENTCONTROLLER_NO_EVENTID_ERROR										19001			/// 没有指定的event id
#define URL_EVENTCONTROLLER_GET_ERROR												19002			/// 获取event错误
#define URL_EVENTCONTROLLER_POST_ERROR												19003			/// 创建event错误
#define URL_EVENTCONTROLLER_PUT_ERROR												19004			/// 修改event错误
#define URL_EVENTCONTROLLER_DELETE_ERROR											19005			/// 删除event错误

/// splpack管理 20000
#define URL_SPLPACKCONTROLLER_NO_SPLPACKID_ERROR									20001			/// 没有指定的splpack id
#define URL_SPLPACKCONTROLLER_GET_ERROR												20002			/// 获取splpack错误
#define URL_SPLPACKCONTROLLER_POST_ERROR											20003			/// 创建splpack错误
#define URL_SPLPACKCONTROLLER_PUT_ERROR												20004			/// 修改splpack错误
#define URL_SPLPACKCONTROLLER_DELETE_ERROR											20005			/// 删除splpack错误

/// las管理 21000
#define URL_LASCONTROLLER_NO_LASID_ERROR											21001			/// 没有指定的imb id
#define URL_LASCONTROLLER_LAS_CONNECT_ERROR											21002			/// imb板卡连接错误
#define URL_LASCONTROLLER_GET_ERROR													21003			/// 获取imb错误
#define URL_LASCONTROLLER_POST_ERROR												21004			/// 创建imb错误
#define URL_LASCONTROLLER_PUT_ERROR													21005			/// 修改imb错误
#define URL_LASCONTROLLER_DELETE_ERROR												21006			/// 删除imb错误






//add by wangwei  start  2015-05-14 
#define UUID_LENGTH_ERROR															22001			///string input length error
#define INGEST_NOT_WORKING															22002			///ingest not working 
#define USER_INPUT_TIME_FORMAT_ERROR												22003			///input time format error
#define PATH_INPUT_ERROR															22004           ///ingest path input error
#define ASSET_TYPE_INPUT_ERROR														22005           ///assetxml' type input error
#define SEEK_POSITION_INPUT_ERROR													22006			///seek position input error
#define PARSE_FTP_PATH_ERROR														22007			///ftp url parse error
#define INPUT_ERROR_SPL_ID														    22008			///input error spl uuid
#define INPUT_ERROR_SCHEDULE_ID														22009			///input error schedule uuid
#define DCP_PATH_INPUT_ERROR														22010			///dcp path input error
#define FTP_USERNAME_OR_PASSWD_ERROR												22011			///ftp user or passwd is empty
#define INPUT_FILE_PATH_ERROR														22012			///input error path
#define INPUT_ERROR_IP_PATH															22013			///input error IP path
#define PATH_DO_NOT_EXIST_ERROR														22014			///path do not exist error
#define PKL_FILE_NOT_EXIST_ERROR													22015			///pkl file not exist error
#define CPL_FILE_NOT_EXIST_ERROR													22016			///cpl file not exist error
#define FILE_NOT_EXIST_ERROR														22017			///file not exist error
#define CAN_NOT_OPEN_FILE_ERROR														22018			///can not open file error
#define INPUT_DCP_PAHT_ERROR														22019			///input dcp path error
#define INPUT_CPL_PAHT_ERROR														22019			///input cpl path error
#define INPUT_PKL_PAHT_ERROR														22019			///input pkl path error


//sms 状态码
#define SMS__SUCCESS_CODE															20101			///sms state is success
#define SMS_ERROR_CODE																20102			///sms state is error
#define SMS__SYSTEM_EOOR															20103			///sms state is system error 
//ingest job 状态 
#define INGESTJOB_SCHEDULED_CODE													20301			///ingest job state is scheduled
#define INGESTJOB_RUNNING_CODE														20302			///ingest job state is running 
#define INGESTJOB_PAUSING_CODE														20303			///ingest job state is pausing 
#define INGESTJOB_CHECK_CODE														20304			///ingest job state is check
#define INGESTJOB_FINISHED_CODE														20305			///ingest job state is finished 
#define INGESTJOB_FINISHEDERROR_CODE												20306			///ingest job state is finished error
//screenings 状态
#define SCREENINGS_PLAYING_CODE														20201			///screen state is playing 
#define SCREENINGS_PAUSING_CODE														20202			///screen state is pausing
#define SCREENINGS_FINISHED_CODE													20203			///screen state is finished
#define SCREENINGS_FINISHED_ABORT_CODE												20204			///screen state is finished abort 手动停止
#define SCREENINGS_FINISHED_ERROR_CODE												20205			///screen state is finished error 手动失败
#define SCREENINGS_NOT_EXECUTED_CODE												20206			///screen state is not executed   不再执行
////cpl check状态
#define CPLCHECK_SCHEDULED_CODE														20401			///cpl check state is scheduled
#define CPLCHECK_RUNNING_CODE														20402			///cpl check state is running
#define CPLCHECK_PAUSING_CODE														20403			///cpl check state is pausing 
#define CPLCHECK_FINISHED_CODE														20404			///cpl check state is finished
#define CPLCHECK_FINISHED_ERROR_CODE												20405			///cpl check state is error 


//add wangxianzhi 2015-05-22
#define    URL_SPLCONTROLLER_POST_CPL_INVALID_ERROR                                 24001           ///spl 创建失败，因为cpl无效


//end


////normal正常、warning警告信息message_code编码定义 normal 25000 ---27000
///cpl 1-200
#define CPL_INFO_CREATE																25001
#define CPL_INFO_CREATE_LOCAL														25002
#define CPL_INFO_DELETE																25003
#define CPL_INFO_DELETE_BY_UUID														25004
#define CPL_INFO_UPDATE_STORE_PATH													25005
#define CPL_INFO_CANCEL_HASH_CHECK													25006
#define CPL_INFO_CREATE_DOWN_DCPCONFIGFILE_BY_FTP_FAILED							25008
#define CPL_INFO_CREATE_COPY_CPLFILE_FAILED											25009
#define CPL_INFO_CREATE_COPY_PKLFILE_FAILED											25010
#define CPL_INFO_CREATE_COPY_ASSETMAPFILE_FAILED									25011
#define CPL_INFO_CREATE_DOWN_CPLFILE_BY_FTP_FAILED									25012
#define CPL_INFO_CREATE_DOWN_PKLFILE_BY_FTP_FAILED									25013
#define CPL_INFO_CREATE_DOWN_ASSETMAPFILE_BY_FTP_FAILED								25014
#define CPL_INFO_SCANDCP_DOWN_DCPCONFIGFILE_BY_FTP_FAILED							25015
#define CPL_INFO_SCANDCP_PARSE_DCPCONFIGFILE_BY_FTP_FAILED							25016
#define CPL_INFO_VIDEO_AUDIO_FRAME_COUNT_NOTMATCH									25017
#define CPL_INFO_VIDEO_SUBTITLE_FRAME_COUNT_NOTMATCH								25018
#define CPL_INFO_IS_INVALID															25019

///kdm 200-300
#define KDM_INFO_CREATE																25201
#define KDM_INFO_CREATE_LOCAL														25202
#define KDM_INFO_DELETE																25203
#define KDM_INFO_DELETE_BY_UUID														25204
#define KDM_INFO_UPDATE_STORE_PATH													25205
#define KDM_INFO_CANCEL_HASH_CHECK													25206
#define KDM_INFO_SCANKDM_PARSE_KDMFILE_FAILED										25207
#define KDM_INFO_SCANKDM_IMB_KDM_NOTMATCH											25208
#define KDM_INFO_SCANKDM_DOWN_KDMFILE_BY_FTP_FAILED									25209
#define KDM_INFO_SCANKDM_PARSE_KDMFILE_BY_FTP_FAILED								25210
#define KDM_INFO_SCANKDM_IMB_KDM_NOTMATCH_BY_FTP_FAILED								25211

///spl 300-400
#define SPL_INFO_CREATE																25201
#define SPL_INFO_CREATE_LOCAL														25202
#define SPL_INFO_DELETE																25203
#define SPL_INFO_DELETE_BY_UUID														25204

///schedule 300-400
#define SCHEDULE_INFO_CREATE														25301
#define SCHEDULE_INFO_CREATE_LOCAL													25302
#define SCHEDULE_INFO_DELETE														25303
#define SCHEDULE_INFO_DELETE_BY_UUID												25304

///screening 400-500
#define SCREENING_INFO_CREATE														25401
#define SCREENING_INFO_CREATE_LOCAL													25402
#define SCREENING_INFO_DELETE														25403
#define SCREENING_INFO_DELETE_BY_UUID												25404

///ingestjob 500-600
#define INGESTJOB_INFO_CREATE														25501
#define INGESTJOB_INFO_CREATE_LOCAL													25502
#define INGESTJOB_INFO_DELETE														25503
#define INGESTJOB_INFO_DELETE_BY_UUID												25504
#define INGESTJOB_CANCEL															25505
#define INGESTJOB_CANCEL_BY_UUID													25506

///cue 600-700
#define CUE_INFO_CREATE																25601
#define CUE_INFO_CREATE_LOCAL														25602
#define CUE_INFO_DELETE																25603
#define CUE_INFO_DELETE_BY_UUID														25604

///cuemission 700-800
#define CUEMISSION_INFO_CREATE														25701
#define CUEMISSION_INFO_CREATE_LOCAL												25702
#define CUEMISSION_INFO_DELETE														25703
#define CUEMISSION_INFO_DELETE_BY_UUID												25704
#define CUEMISSION_INFO_EXECUET_SCRIPT												25705
#define CUEMISSION_INFO_EXECUET_NOT_SCRIPT_FILE_FAILED								25706

///automation 800-900
#define AUTOMATION_INFO_CREATE														25801
#define AUTOMATION_INFO_CREATE_LOCAL												25802
#define AUTOMATION_INFO_DELETE														25803
#define AUTOMATION_INFO_DELETE_BY_UUID												25804

///systemconfig 900-1000
#define SYSTEMCONFIG_INFO_CREATE													25901
#define SYSTEMCONFIG_INFO_CREATE_LOCAL												25902
#define SYSTEMCONFIG_INFO_DELETE													25903
#define SYSTEMCONFIG_INFO_DELETE_BY_UUID											25904

///imbdevice 1000-1200
#define IMBDEVICE_INFO_CREATE														26001
#define IMBDEVICE_INFO_CREATE_LOCAL													26002
#define IMBDEVICE_INFO_DELETE														26003
#define IMBDEVICE_INFO_DELETE_BY_UUID												26004
#define IMBDEVICE_4K_NOT_SUPPORT													26005


///main 1300-1500
#define MAIN_INTERFACE_LOG_REQUEST													26301
#define MAIN_INTERFACE_LOG_RESPONSE													26302
#define MAIN_ADJUST_SYSTEM_TIME														26303
#define MAIN_ENTER_PROGRAM															26304
#define MAIN_EXIT_PROGRAM															26305


///cp850 27000-27100
#define CP850_INFO_FLUSH_ERROR														27001			///cp850设置flush失败
#define CP850_INFO_CONNECTED_ERROR													27002			///cp850连接失败
#define CP850_INFO_SETSHOW_ERROR													27003			///cp850设置setshow失败
#define CP850_INFO_DISCONNECT_ERROR													27004			///cp850断开连接失败
#define CP850_INFO_GETSTATUS_ERROR													27005			///cp850获取状态失败
#define CP850_INFO_GETIP_ERROR														27006			///获取cp850IP地址失败
#define CP850_INFO_GETSERNU_ERROR													27007			///获取cp850序列号失败
#define CP850_INFO_GETVERSION_ERROR													27008			///获取cp850软件版本失败
#define CP850_INFO_GETCERTIFICATE_ERROR												27009			///获取cp850证书失败
#define CP850_INFO_GETDELAYINFO_ERROR												27010			///获取cp850延迟信息失败
#define CP850_INFO_ISNOTCONNECTED													27011			///cp850当前连接状态为否
#define CP850_INFO_CONNECTDATAIPERROR												27012			///cp850连接dataip失败
#define CP850_INFO_CONNECTCMDIPERROR												27013			///cp850连接cmdlp失败
#define CP850_INFO_SETDATAIPERROR													27014			///cp850设置dataip失败
#define CP850_INFO_SETCMDIPERROR													27015			///cp850设置cmdip失败
#define CP850_INFO_GETSYSTIMEERROR													27016			///cp850获取系统时间失败
#define CP850_INFP_GETPUBHASHERROR													27017			///cp850获取公钥哈希值失败
#define CP850_INFO_READDATABASEERROR												27018			///cp850读取数据库失败
#define CP850_INFO_GETCERTERROR														27019			///获取cp850证书失败
#define CP850_INFO_GETSERNUERROR													27020			///获取cp850序列号失败
#define CP850_INFO_GETVERSIONERROR													27021			///获取cp850软件版本失败
#define CP850_INFO_TLSCONNECTERROR													27022			///cp850TLS通信失败
#define CP850_INFO_CONNECTERROR														27023			///cp850连接失败
#define CP850_INFO_TRANSATMOSERROR													27024			///传输atmos帧数据失败
#define CP850_INFO_TRANSATMOS_HEADERERROR											27025			///传输atmos帧头失败
#define CP850_INFO_SMSCP850IPNOTMATCHTOCP850MECHINEERROR							27026			///SMS更新的IP和cp850中的IP不匹配
#define CP850_INFO_SMSCP850ATMOSISSCREENING											27027			///正在播放atmos影片

///devicelicense 28000-28100
#define URL_DEVICELICENSE_TESTCONNECT_SERVER_ERROR									28001			///测试链接授权服务器失败
#define URL_DEVICELICENSE_LICPARSERSDK_INITIALIZE_ERROR								28002			///授权服务sdk 初始化失败
#define URL_DEVICELICENSE_DOWNLOADLICENSE_ERROR										28003			///下载许可证失败
#define URL_DEVICELICENSE_PARSELICENSE_ERROR										28004			///解析许可证错误
#define URL_DEVICELICENSE_LICENSE_EXPIRED_ERROR										28005			///许可证已经过期
#define URL_DEVICELICENSE_LICENSE_NOT_YET_VALID_ERROR								28006			///许可证尚未启效

//add by yin 2016.9.5 start
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTIFICATE_FILE_NOT_EXIST   				28007   //载入的证书文件不存在
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTIFICATE_FILE_NOT_READABLE   			28008	//载入的证书不可读
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTIFICATE_FILE_OPEN_ERROR   				28009	//载入的证书不能打开
	
#define URL_DEVICELICENSE_LICSDKERR_LOAD_PRIVATEKEY_FILE_NOT_EXIST   				28010	//载入的私钥文件不存在
#define URL_DEVICELICENSE_LICSDKERR_LOAD_PRIVATEKEY_FILE_NOT_READABLE   			28011	//载入的私钥文件不可读
#define URL_DEVICELICENSE_LICSDKERR_LOAD_PRIVATEKEY_FILE_OPEN_ERROR   				28012	//载入的私钥不能打开

#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTTIFICATE_CHAIN_FILE_NOT_EXIST   		28013	//载入的证书链文件不存在
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTTIFICATE_CHAIN_FILE_OPEN_ERROR   		28014	//载入的证书链文件打开错误
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTTIFICATE_CHAIN_FILE_LSEEK_ERROR  		28015	//载入的证书链文件执行lseek时发生错误
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTTIFICATE_CHAIN_FILE_IS_EMPTY	  		28016	//载入的证书链文件是空文件
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTTIFICATE_CHAIN_FILE_MORN_THAN_10K 		28017	//载入的证书链文件长度大于10K
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTTIFICATE_CHAIN_FILE_READ_ERROR 		28018	//载入的证书链文件，read时发生错误 
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTTIFICATE_LSEEK_ERROR					28019	//载入的证书文件，lseek时发生错误 
#define URL_DEVICELICENSE_LICSDKERR_LOAD_CERTTIFICATE_FILE_READ_ERROR				28020	//载入的证书文件，read时发生错误 

#define URL_DEVICELICENSE_LICSDKERR_PKCS12_FILE_NOT_EXIST							28021   //P12文件不存在
#define URL_DEVICELICENSE_LICSDKERR_PKCS12_PARSER_ERROR								28022   //P12文件解析错误 
#define URL_DEVICELICENSE_LICSDKERR_PATH_NOT_EXIST									28023	//目录不存在
#define URL_DEVICELICENSE_LICSDKERR_NETWORK_IS_NOT_CONNECTED							28024	//connect 连接失败
#define URL_DEVICELICENSE_LICSDKERR_DONT_EXIST_LICENSE_FILE							28025   //下载许可证失败.
#define URL_DEVICELICENSE_LICSDKERR_CREATE_SOCKETE_FAILD							28026

#define URL_DEVICELICENSE_LICSDKERR_KLV_PARAMETER_ERROR								28027	//封装消息时，参数填入错误
#define URL_DEVICELICENSE_LICSDKERR_ADDKLVKEYVALUE_ERROR							28028	//封装消息，V值填入错误
#define URL_DEVICELICENSE_LICSDKERR_ADDKLVLENVALUE_ERROR							28029	//封装消息，L值填入错误 
#define URL_DEVICELICENSE_LICSDKERR_ADDREQUESTID_ERROR								28030	//封装消息，ID域填充出错
#define URL_DEVICELICENSE_LICSDKERR_VERIFY_LICENSE_INTEGRITY_ERROR					28031	//许可证完整性校验发生错误 
#define URL_DEVICELICENSE_LICSDKERR_EVP_PRIVATE_KEY_IS_NULL							28032	//从p12文件解出来的密钥为NULL
#define URL_DEVICELICENSE_LICSDKERR_PARSER_LICENSE_FAILD							28033	//解析许可证文件错误
#define URL_DEVICELICENSE_LICSDKERR_LOAD_PRIVATE_KEY_IS_NULL						28034	//载入p12文件密钥错误
#define URL_DEVICELICENSE_LICSDKERR_WRITE_TO_BUFFER_ERROR							28035	//base64过程中，写入缓冲区发生错误
#define URL_DEVICELICENSE_LICSDKERR_ENDCODING_EXCEEDS_BUFFER_LENGTH					28036	//base64过程中，具体问孙博士
#define URL_DEVICELICENSE_LICSDKERR_GET_THUMB_2										28037	//取指纹第二个错误
#define URL_DEVICELICENSE_LICSDKERR_GET_THUMB_3										28038	//取指纹第三个错误
#define URL_DEVICELICENSE_LICSDKERR_GET_THUMB_4										28039	//取指纹第四个错误
#define URL_DEVICELICENSE_LICSDKERR_GET_THUMB_5										28040	//取指纹第五个错误
#define URL_DEVICELICENSE_LICSDKERR_GET_THUMB_6										28041	//取指纹第六个错误


#define URL_DEVICELICENSE_LICSDKERR_PARSER_KLV_K_PARSER_ERROR						28042	     //klv中的K解析错误 
#define URL_DEVICELICENSE_LICSDKERR_PARSER_KLV_LEN_READ_ERROR						28043	     //klv中的l读取错误
#define URL_DEVICELICENSE_LICSDKERR_PARSER_KLV_LEN_PARSER_ERROR						28044	   //klv中的len解析错误 
#define URL_DEVICELICENSE_LICSDKERR_PARSER_KLV_V_READ_ERROR							28045	     //klv中的V读取错误 
#define URL_DEVICELICENSE_LICSDKERR_IP_IS_NOT_VALID									28046	         //IP地址不合法
#define URL_DEVICELICENSE_LICSDKERR_INIT_INPUT_ARGS_ERROR							28047	       //初始化函数中，参数输入不合法
#define URL_DEVICELICENSE_LICSDKERR_VERIFY_CHAIN_CHAINFILE_ERR						28048	    //验证证书链中 开源函数load_chainfile 执行错误
#define URL_DEVICELICENSE_LICSDKERR_VERIFY_CHAIN_DO_CERTFORMATVERIFY_ERR			28049	//验证证书链中 开源函数do_certformatverify 执行错误
#define URL_DEVICELICENSE_LICSDKERR_VERIFY_CHAIN_DO_CHAINVERIFY_ERR					28050	  //验证证书链中 开源函数do_chainverify 执行错误
#define URL_DEVICELICENSE_LICSDKERR_LICENSE_SECENV_CHECKKEYPAIRERR					28051	  //p12文件解析出来的私钥与设备证书不匹配
#define URL_DEVICELICENSE_LICSDKERR_PRIVATEKEY_P12_FILE_NOT_EXIST					28052	    //p12文件不存在
#define URL_DEVICELICENSE_LICSDKERR_PARSER_P12_FILE_ERROR							28053	        //p12解析函数执行失败
#define URL_DEVICELICENSE_LICSDKERR_VERYFY_CERTIFICATE_CHAIN_ERR					28054	    //叶子证书与证书链文件不匹配
#define URL_DEVICELICENSE_LICSDKERR_GET_CERT_CHAIN_ERR								28055	        //获得证书链文件错误
#define URL_DEVICELICENSE_LICSDKERR_GET_LEAF_CERT_ERR								28056	          //获得叶子证书文件错误 
#define URL_DEVICELICENSE_LICSDKERR_DEVICE_LICENSE_FILE_SIZE_IS_0					28057	    //下载的许可证文件长度为 0 
#define URL_DEVICELICENSE_LICSDKERR_KEY_AND_CERT_IS_NOT_PAIRS						28058	      //设备证书与密钥不匹配
#define URL_DEVICELICENSE_LICSDKERR_GET_ROOT_CERT_ERR								28059	          //设备证书与密钥不匹配
#define URL_DEVICELICENSE_LICSDKERR_PARSERlICENSE_CERTIFICATE_FILE_OPEN_ERROR		28060	//解析许可证时候，许可证文件打开失败
#define URL_DEVICELICENSE_LICSDKERR_PARSERlICENSE_CERTTIFICATE_LSEEK_ERROR			28061	//解析许可证时候，lseek 执行出错

#define URL_DEVICELICENSE_LICSDKERR_RECEIVE_V_LENGTH_IS_0							28062	//在接收V的时候，V的长度为0
#define URL_DEVICELICENSE_LICSDKERR_INITIALIZE_IS_FAILD								28063	//初始化失败
#define URL_DEVICELICENSE_LICSDKERR_READ_KLV_K_ERROR								28064	//read阻塞，读取服务器消息处于等待

#define URL_DEVICELICENSE_LICSDKERR_LICENSE_PARSER_NOTINVALIDITYTIMEERR				28065	//许可证时间过期
#define URL_DEVICELICENSE_LICSDKERR_LICENSE_PARSER_ERROR							28066	//许可证解析失败
#define URL_DEVICELICENSE_LICSDKERR_SELECT_ERROR									28067	//下载许可证时的 selcet 函数出错 
#define URL_DEVICELICENSE_LICSDKERR_SERVER_IS_SHUT_DOWN								28068	//服务器关闭
#define URL_DEVICELICENSE_LICSDKERR_RECEIVE_LICENSE_FILE_LENGTH_IS_0				28069	//接收到的许可证文件是空
#define URL_DEVICELICENSE_LICSDKERR_LICENSE_FILE_NOT_EXIST                  28070   //许可证文件不存在
#define URL_DEVICELICENSE_LICSDKERR_KEY_AND_PWD_IS_NOT_PAIRS				        28071	//p12文件与口令不匹配(口令不对)
#define URL_DEVICELICENSE_LICSDKERR_GET_THUMD_FAILD									28072	//获取指纹失败
#define URL_DEVICELICENSE_LICSDKERR_CONNECT_TO_SERVER_FAILD         28073 //连接服务器失败
#define URL_DEVICELICENSE_LICSDKERR_NET_IS_IMPASSABLE								28074	//网络不通

#define URL_DEVICELICENSE_LEAFCERT_AND_HARDWARE_IS_NOT_PAIR				28075	//设备证书与当前设备信息不匹配
#define URL_DEVICELICENSE_LICENSE_TIME_NOTINVALIDITYTIMEERR2				28076	//许可证尚未启效
//add by yin 2016.9.5end


//add by yin 2016.9.29 start
#define URL_DEVICELICENSE_SERIALNUMTOOL_CREATE_SOCKET_ERROR         28077  //创建套接字错误
#define URL_DEVICELICENSE_SERIALNUMTOOL_IOCTL_ERROR         28078  //ioctl命令获取网卡id出错	
#define URL_DEVICELICENSE_SERIALNUMTOOL_GETUID_ERROR         28079  //获取调用程序的真实用户ID出错
#define URL_DEVICELICENSE_SERIALNUMTOOL_CANNOT_GET_DISKID_ERROR         28080  //目前提供的方法均未能获取硬盘id
#define URL_DEVICELICENSE_SERIALNUMTOOL_FOPEN_ERROR         28081  //打开文件操作失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_VERIFY_CN_ERROR         28082  // 验证设备唯一标识中包含的cn值与设备证书中的CN值相符性失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_VERIFY_NETWORKCARD_ID_ERROR         28083  //验证设备唯一标识中包含的网卡id（macid）与实际操作环境中获取的网卡id（macid）不符
#define URL_DEVICELICENSE_SERIALNUMTOOL_VERIFY_DISK_ID_ERROR         28084 //验证设备唯一标识中包含的硬盘id与实际操作环境中获取的硬盘id不符

#define URL_DEVICELICENSE_SERIALNUMTOOL_OPEN_DISK_ERROR         28085  //访问打开硬盘操作失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_IOCTL_GET_DISKID_ERROR         28086  //IOCTL命令获取硬盘id失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_IOCTL_GET_VERSION_ERROR         28087  //IOCTL命令获取版本失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_WAY2_GET_DISKID_ERROR         28088  //运用方法二获取硬盘id失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_HDPARM_GET_DISKID_ERROR         28089  //运用hdparm命令获取硬盘id失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_LSHW_GET_DISKID_ERROR         28090  //运用lshw命令获取硬盘id失败

#define URL_DEVICELICENSE_SERIALNUMTOOL_OPEN_MTAB_ERROR         28091  //打开/etc/mtab文件失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_GET_DISKNAME_ERROR         28092  //获取disk name为空

#define URL_DEVICELICENSE_SERIALNUMTOOL_IFSTREAM_OPEN_ERROR         28093  //ifstream打开文件失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_GET_SUBSTR_ERROR         28094  //根据关键词获取子串失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_SCSI_IO_FUCTION_ERROR         28095  //scsi_io函数返回失败
#define URL_DEVICELICENSE_SERIALNUMTOOL_VERIFY_MBCARD_ID_ERROR        28096 //验证设备唯一标识中包含的MB板卡序列号与实际操作环境中获取的MB板卡序列号不符
//add by yin 2016.9.29 end



#endif