#ifndef DOWNLOAD_TABLE_H
#define DOWNLOAD_TABLE_H
#include "../database/pub.h"
#include <mysql.h>

#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct DOWNLOAD_ITEM_TBL
{
	 char *	id;							////id值
	 char * cinemaName;					////影院名称
	 char * HallNo;						////影厅号
	 char * IPCPosition;				////摄像头位置
	 char * state;						////下载状态
	 char * starttime;					////开始下载时间
	 char * endtime;					////结束下载时间
	 char * ipcIP;						////ipc的IP地址
	 char * downloadID;					////下载的ID
	 char * filename;					////下载的原始文件的文件名
	 char * mp4filename;				////mp4文件名
	 char * covertstate;				////转换封装格式的状态
	 char * avifilename;                ////avi文件名
	 char * loginHandle;				////登录id
}DOWNLOAD_ITEM_TBL;

typedef vector<DOWNLOAD_ITEM_TBL *> DOWNLOAD_ITEMS_TBL;




class downloadtable:public PubFun
{
public:
	downloadtable();
	~downloadtable();

	/*****************************************************\
	函数功能：插入下载信息
	参数1：下载信息
	成功返回0，失败返回其他值
	\*****************************************************/
	int insertDownloadInfo(DOWNLOAD_ITEM_TBL * pItem);

	/*****************************************************\
	函数功能：更新下载信息（根据下载id）
	参数1：列名
	参数2：列值
	参数3：下载id
	返回值：成功返回0，失败返回其他值
	\*****************************************************/
	int updateDownloadInfoByDownloadID(string columnName,string columnValue,long long downloadID);

	/******************************************************\
	函数功能：根据ID值更新下载信息
	参数1：id值
	参数2：列名
	参数3：列值
	返回值：成功返回0，失败返回其他值
	\******************************************************/
	int updateDownloadInfoByid(int id,string columnName,string columnValue);

	/******************************************************\
	函数功能：获取全部下载信息
	参数1：下载信息
	返回值：成功返回0，失败返回其他值
	\******************************************************/
	int GetAllDownloadInfo(DOWNLOAD_ITEMS_TBL & downloadinfos);

	/******************************************************\
	函数功能：根据影厅号，前后置摄像头获取下载信息
	参数1：影厅号
	参数2：前后置摄像头
	参数3：下载信息
	返回值：成功返回0，失败返回其他值
	\******************************************************/
	int GetDownloadInfoByHallNoAndIpcPo(int HallNo,int ipcPo,DOWNLOAD_ITEMS_TBL & downloadinfos);

	/******************************************************\
	函数功能：根据下载id获取下载信息
	参数1：下载id
	参数2：下载信息
	返回值：成功返回0，失败返回其他值
	\******************************************************/
	int GetDownloadInfoByDownloadID(int downloadId,DOWNLOAD_ITEM_TBL & downloadinfo);

	/******************************************************\
	函数功能：根据下载状态获取下载信息
	参数1：下载信息
	返回值：成功返回0，失败返回其他值
	\******************************************************/
	int GetDownloadInfoBystate(DOWNLOAD_ITEMS_TBL & downloadinfos);

	/******************************************************\
	函数功能：获取最新插入的项
	参数1：id值
	返回值：成功返回0，失败返回其他值
	\******************************************************/
	int GetLatestInsertId(int &id);

	/*******************************************************\
	函数功能：根据sql获取下载信息
	参数1：sql语句
	参数2：下载信息
	返回值：成功返回0，失败返回其他值
	\*******************************************************/
	int GetDownloadInfoBySql(string sql,DOWNLOAD_ITEMS_TBL & downloadinfos);

	/*******************************************************\
	函数功能：根据sql语句获取下载信息
	参数1：sql语句
	参数2：下载信息
	返回值：成功返回0，失败返回其他值
	\*******************************************************/
	int GetDownloadInfoBySql(string sql,DOWNLOAD_ITEM_TBL *downloadinfo);

public:
	////申请内存空间
	void NewSpaceDownload(DOWNLOAD_ITEM_TBL**downloadinfo);
	////释放内存空间
	void DeleteSpaceDownload(DOWNLOAD_ITEM_TBL**downloadinfo); 
	////清空内存空间
	void ZeroSpaceDownload(DOWNLOAD_ITEM_TBL*downloadinfo);

	void DeleteSpaceDownloads(DOWNLOAD_ITEMS_TBL * downloadinfos);
protected:
private:
	int MapItemVarToArray(DOWNLOAD_ITEM_TBL *pItem);
	COLUMN_VALUE_MAP  m_download_column_value_map[14];
};

#endif