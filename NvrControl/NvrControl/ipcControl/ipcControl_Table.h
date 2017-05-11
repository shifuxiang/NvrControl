#ifndef IPCCONTROL_TABLE_H
#define IPCCONTROL_TABLE_H
#include "../database/pub.h"
#include <mysql.h>

#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct IPC_ITEM_TBL
{
	 char *	id;							////id值
	 char * cinemaName;					////影院名称
	 char * HallNo;						////影厅号
	 char * ipcPosition;				////摄像头位置
	 char * frameRate;					////帧率
	 char * CBR;						////
	 char * resolvingRate;				////
	 char * decodeMode;					////编码模式
	 char * ip;							////ip地址
	 char * port;						////端口号
	 char * username;					////用户名
	 char * password;					////密码
	 char * mode;						////日夜模式
	 char * channelID;					////通道号
}IPC_ITEM_TBL;

typedef vector<IPC_ITEM_TBL *> IPC_ITEMS_TBL;

class IpcTable:public PubFun
{
public:
	IpcTable();
	~IpcTable();
	/*************************************************\
	函数功能：获取所有ipc信息
	参数1：获取到的ipc信息
	返回值：成功返回0，失败返回其他值
	\*************************************************/
	int GetIPCInfos(IPC_ITEMS_TBL * pIpcs);

	/*************************************************\
	函数功能：根据影厅号，前后置摄像头获取ipc信息
	参数1：影厅号
	参数2：前后置摄像头
	参数3：ipc信息
	返回值：成功返回0，失败返回其他值
	\*************************************************/
	int GetIpcInfoByHallNoAndPosition(int HallNO,int position,IPC_ITEM_TBL * pIpcInfo);

	/**************************************************\
	函数功能：根据id获取ipc信息
	参数1：id值
	参数2：ipc信息
	返回值：成功返回0，失败返回其他值
	\**************************************************/
	int GetIpcInfoById(int id,IPC_ITEM_TBL * pIpcInfo);

	/***************************************************\
	函数功能：插入ipc信息
	参数1：ipc信息
	返回值：成功返回0，失败返回其他值
	\***************************************************/
	int InsertIpcInfo(IPC_ITEM_TBL *ipcinfo);

	/***************************************************\
	函数功能：根据id更新ipc信息
	参数1：id值
	参数2：列名
	参数3：列值
	返回值：成功返回0，失败返回其他值
	\***************************************************/
	int UpdateIpcInfo(int id,string columnName,string coumnValue);

	/***************************************************\
	函数功能：根据影厅号，前后位置删除指定的摄像头
	参数1：影厅号
	参数2：位置
	返回值：成功返回0，失败返回其他值
	\***************************************************/
	int DeleteIpcInfoByHallNoAndPosition(int HallNo,int position);
	
	/****************************************************\
	函数功能：根据id删除指定的摄像头
	参数1：id号
	返回值：成功返回0，失败返回其他值
	\****************************************************/
	int DeleteIpcInfoById(int id);

	/****************************************************\
	函数功能：删除全部摄像头
	返回值：成功返回0，失败返回其他值
	\****************************************************/
	int DeleteAllIpc();

public:
	////申请内存空间
	void NewSpaceIpc(IPC_ITEM_TBL**ipcinfo);
	////释放内存空间
	void DeleteSpaceIpc(IPC_ITEM_TBL**ipcinfo); 
	////清空内存空间
	void ZeroSpaceIpc(IPC_ITEM_TBL*ipcinfo);
protected:
private:
	int MapItemVarToArray(IPC_ITEM_TBL *pItem);
	COLUMN_VALUE_MAP  m_ipc_column_value_map[14];
};

#endif