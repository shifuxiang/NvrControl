#ifndef DOWNLOAD_CONTROL_H
#define DOWNLOAD_CONTROL_H
#include <iostream>
#include <vector>
#include "../so/dhnetsdk.h"
#include "../so/dhplay.h"
//#include "Download_Table.h"
#include "DownloadControl_Struct.h"
//#include "../Nvr/Nvr_Control.h"
#include"../Nvr_Ret.h"
#include"../Nvr_Types.h"
typedef struct DM_DownLoadInfo
{
	int id;
	std::string cinemaName;
	std::string HallNo;
	int pos;
	std::string state;
	std::string start_time;
	std::string end_time;
	std::string ipcIP;

}DM_DownLoadInfo;
typedef std::vector<DM_DownLoadInfo > * PDM_DownLoadInfos;
typedef std::vector<DM_DownLoadInfo > DM_DownLoadInfos;
//class NvrControl;
class downLoad
{
public:
	downLoad();
	~downLoad();
	/***************************************************\
	函数功能：设置指定Nvr的下载速度
	参数1：Nvr的id
	返回值：成功返回0,失败返回其他值
	\***************************************************/
	int DM_SetNvrDownloadSpeed(int id,bool isOK);

	/***************************************************\
	函数功能：按时间下载指定Nvr的指定摄像头的录制的视频文件
	参数1：指定Nvr的id
	参数2：影厅号
	参数3：摄像头位置，0表示前置，1表示后置
	参数4：开始下载时间
	参数5：结束下载时间
	参数6: 下载路径
	返回值：成功返回0，失败返回其他值
	\***************************************************/
	int DM_DownLoadByTime(int id,int nAudiNU,int nDevicePo,NET_TIME tmStart,NET_TIME  tmEnd,string storePath,string mp4name);

	/***************************************************\
	函数功能：获取全部下载记录
	参数1：下载记录信息
	返回值：成功返回0，失败返回其他值
	\***************************************************/
	int DM_GetDownLoadInfo(DOWNLOAD_INFOS * downloadInfos);
	/***************************************************\
	函数功能：按时间获取下载记录
	参数1：开始时间
	参数2：结束时间
	参数3：下载记录信息
	返回值：成功返回0，失败返回其他值
	\***************************************************/
	int DM_GetDownLoadInfo(std::string start_time,std::string end_time,DOWNLOAD_INFOS * downloadInfo);

	/****************************************************\
	函数功能：根据状态获取下载信息
	参数1：下载信息
	返回值：成功返回0，失败返回其他值
	\****************************************************/
	int DM_GetDownloadInfoByState(DOWNLOAD_INFOS *pDownloadInfos);

	/****************************************************\
	转换函数
	转换完更新数据库
	\****************************************************/
	int DM_Convert();

	/****************************************************\
	函数功能：获取当前正在下载的原始文件的数量
	参数1：当前并发下载原始文件的数量
	返回值：成功返回0，失败返回其他值
	\****************************************************/
	int DM_GetDownLoadInfoCountByStateAndIpcIP(int &count);

	/****************************************************\
	函数功能：通过sql语句获取下载信息
	参数1：sql语句
	参数2：下载信息
	返回值：成功返回0，失败返回其他值
	\****************************************************/
	int DM_GetDownloadInfoBySql(string sql,DOWNLOAD_INFO *pDownloadInfo);

	int DM_GetErrorString();
public:
	int NewSpaceDeviceDownloadInfo(DOWNLOAD_INFO **pDownloadInfo);
	//
	int DeleteSpaceDeviceDownloadInfo(DOWNLOAD_INFO **pDownloadInfo);
	//
    int ZeroSpaceDeviceDownloadInfo(DOWNLOAD_INFO * pDownloadInfo);
	//
	int DeleteSpaceDownloadInfos(DOWNLOAD_INFOS *pDownloadInfos);
	//
	int ZeroSpaceDownloadInfos(DOWNLOAD_INFOS *pDownloadInfos);
	long long m_downloadID;

public:
	int GetDownloadErrorString(int errorcode,REPORT_STATUS *preportstatus);
private:
	//NvrControl m_nvrcontrol;
	//NvrControl m_nvrcontrol1;
	bool isOK1;
	bool isOK2;
	//DOWNLOAD_ITEM_TBL * pDownloadItem;
	downloadtable downloadTable;

	
	
#if 0
	int m_ChannelID;
	int m_DownloadID;
	LPNET_TIME m_start_time;
	LPNET_TIME m_end_time;
#endif
};


#endif