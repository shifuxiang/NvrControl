#ifndef IPCCONTROL_H
#define IPCCONTROL_H
#include <iostream>
#include "../so/dhnetsdk.h"
#include "../so/dhconfigsdk.h"
//#include "ipcControl_Table.h"
#include "ipcControl_Struct.h"
#include "../Nvr/Nvr_Control.h"

#include <vector>
using namespace std;
#if 0
typedef struct DM_IpcInfo
{
	int id;
	int HallNo;
	int pos;
	int frameRate;
	int stream;
	int ResoluRatio;
	string codeMode;
	string IpcIP;
	string IpcPort;
	string mode;
	string username;
	string password;
}DM_IpcInfo;

typedef vector<DM_IpcInfo> DM_IpcInfos;
typedef vector<DM_IpcInfo> * pDM_IpcInfos;
#endif

typedef vector<string> ResoluRatios;

class ipccontrol
{
public:
	/************************************************************\
	函数功能：设置摄像头信息
	参数1：影厅号
	参数2：前后置摄像头
	参数3;通道号
	返回值：成功返回0，失败返回其他值
	\************************************************************/
	int DM_SetIpcInfo(int nAudiNU,int nDevicePo,int nChannelId);

	/************************************************************\
	函数功能：获取摄像头通道号根据影厅号，前后置摄像头
	参数1：影厅号
	参数2：前后置摄像头
	参数3：通道号
	返回值：成功返回0，失败返回其他值
	\************************************************************/
	int DM_GetIpcInfo(int nAudiNU,int nDevicePo,int &nChannelID);

	/************************************************************\
	函数功能：设置摄像头分辨率，帧率，编码格式，码流
	参数1：影厅号
	参数2：前后置摄像头
	参数3：分辨率
	参数4：帧率
	参数5：编码格式
	参数6：码流
	返回值：成功返回0，失败返回其他值
	\**********i**************************************************/
	int DM_SetIpcVedioQuality(int nAudiNU,int nDevicePo,string ResoluRatio,int frame,string CodeMode,int stream);

	/*************************************************************\
	函数功能：获取摄像头设备支持的分辨率
	参数1：影厅号
	参数2：前后置摄像头
	参数3：分辨率数组
	返回值：成功返回0，失败返回其他值
	\*************************************************************/
	int DM_GetIpcResoluRatio(int nAudiNU,int nDevicePo,ResoluRatios & resoluratios);

	/*************************************************************\
	函数功能：获取摄像头分辨率，帧率，编码格式，码流
	参数1：影厅号
	参数2：前后置摄像头
	参数3：分辨率
	参数4：帧率
	参数5：编码格式
	参数6：码流
	返回值：成功返回0，失败返回其他值
	\*************************************************************/
	int DM_GetIpcVedioQuality(int nAudiNU,int nDevicePo,string &ResoluRatio,int &frame,string &CodeMode,int &stream);

	/**************************************************************\
	函数功能：设置摄像头的日夜模式
	参数1：影厅号
	参数2：前后置摄像头
	参数3：模式值,当mode为0时置为白天模式，即始终未彩色
			当mode为1时为自动切换，当mode为2时置为夜模式，即始终为
			黑白色
	返回值：成功返回0，失败返回其他值
	\**************************************************************/
	int DM_SetIPCDayOrNeightMode(int nAudiNU,int nDevicePo,int Mode);

	/****************************************************************\
	函数功能：设置摄像头自动聚焦
	参数1：影厅号
	参数2：前后置摄像头
	参数3：使能
	返回值：成功返回0，失败返回其他值
	\****************************************************************/
	int DM_SetAutoFocus(int nAudiNU,int nDevicePo,bool isEnable);

	/**************************************************************\
	函数功能：设置摄像头变焦
	参数1：影厅号
	参数2：前后置摄像头
	参数3：步长，即每次调整摄像头倍数时调整的值
	参数4：加倍或者减倍(DH_PTZ_ZOOM_ADD_CONTROL加倍，DH_PTZ_ZOOM_DEC_CONTROL减倍)
	返回值：成功返回0，失败返回其他值
	\**************************************************************/
	int DM_SetIPCZoom(int nAudiNU,int nDevicePo,int nStep,int nType);

	/**************************************************************\
	函数功能：获取错误信息
	参数1：错误码
	参数2：错误信息
	返回值：成功返回0，失败返回其他值
	\**************************************************************/
	int GetIPCErrorString(int errorcode,REPORT_STATUS *preportstatus);

	//
	int NewSpaceDeviceIPCInfo(DEV_IPC_INFO **pdeviceipcinfo);
	//
	int DeleteSpaceDeviceIPCInfo(DEV_IPC_INFO **pdeviceipcinfo);
	//
    int ZeroSpaceDeviceIPCInfo(DEV_IPC_INFO * pdeviceipcinfo);
	//
	int DeleteSpaceIPCInfos(DEV_IPC_INFOS *pipcinfos);
	//
	int ZeroSpaceIPCInfos(DEV_IPC_INFOS *pipcinfos);
};

#endif