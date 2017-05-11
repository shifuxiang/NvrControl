#ifndef NVR_CONTROL_H
#define NVR_CONTROL_H
#include <iostream>
#include "../so/dhnetsdk.h"
#include "../so/dhconfigsdk.h"
#include <vector>
#include "../Nvr_Types.h"
using namespace std;
typedef struct DM_NvrInfo
{
	int id;
	string cinemaName;
	string nvrIP;
	string NvrPort;
	string UserName;
	string PassWord;
	int IpcNo;
}DM_NvrInfo;
typedef vector<DM_NvrInfo> DM_NvrInfos;
typedef vector<DM_NvrInfo> *PDM_NvrInfos;

typedef struct Time_Info
	{
		int nYear;
		int nMonth;
		int nDay;
		int nHour;
		int nMinute;
		int nSecond;
	}Time_Info;
class NvrControl
{
public:
	
	NvrControl()
	{
		m_lLoginHandle = 0;
		m_nStDevInfoNu = 0;
	}
	~NvrControl()
	{}
	/***************************************************************\
	函数功能：初始化sdk
	返回值：成功返回0，失败返回其他值
	\***************************************************************/
	int DM_InitSDK();
	/***************************************************************\
	函数功能：注册用户到设备
	参数1：nvr的IP地址
	参数2：端口号
	参数3：用户名
	参数4：密码
	返回值：成功返回设备ID，失败返回0
	\***************************************************************/
	//int DM_Login(char *NvrIP,WORD Port,char *UserName,char *Password);
	//test
	int DM_Login(string NvrIP,WORD Port,string UserName,string Password);
	//test
	/**************************************************************\
	函数功能：注销设备用户
	参数1：Login函数的返回值
	返回值：成功返回0,失败返回其他值
	\**************************************************************/
	int DM_Logout(LLONG lLoginID);

	/*************************************************************\
	函数功能：清空SDK，释放SDK所占用的资源，在所有的SDK函数调用结束
	之后
	\*************************************************************/
	void DM_Cleanup();

	/******************************************************************\
	函数功能：设置nvr的信息
	参数1：nvrip
	参数2：nvr端口号
	参数3：nvr用户名
	参数4：nvr密码
	返回值：成功返回0，失败返回其他值
	\******************************************************************/
	int DM_SetNvrInfo(string nvrIP,int nvrPort,string username,string password);

	/*******************************************************************\
	函数功能：获取全部nvr信息
	参数1：全部nvr信息
	返回值：成功返回0，失败返回其他值
	\*******************************************************************/
	int DM_GetAllNvrInfo(DM_NvrInfos&nvrinfos);

	/*******************************************************************\
	函数功能：根据id获取nvr信息
	参数1：id
	参数2：nvr信息
	返回值：成功返回0，失败返回其他值
	\*******************************************************************/
	int DM_GetNvrInfoById(int id,DM_NvrInfo & nvrinfo);

	/*******************************************************************\
	函数功能：设置Nvr下载速度
	返回值：成功返回0，失败返回其他值
	\*******************************************************************/
	int DM_SetNvrDownloadSpeed();

	/**************************************************************\
	函数功能：获取nvr，IPC时间
	参数1：时间信息
	返回值：成功返回0.失败返回其他值
	\**************************************************************/
	int DM_GetNVRIPCTime(Time_Info &timeInfo);

	/**************************************************************\
	函数功能：设置nvr，ipc时间
	参数1：时间信息
	返回值:成功返回0，失败返回其他值
	\**************************************************************/
	int DM_SetNVRIPCTime(Time_Info timeInfo);

public:
	/**************************************************************\
	函数功能：获取错误信息
	参数1：错误码，
	参数2：错误信息
	返回值：成功返回0，失败返回其他值
	\**************************************************************/
	int GetNvrErrorString(int errorcode,REPORT_STATUS *preportstatus);


	LLONG m_lLoginHandle;
	int m_nStDevInfoNu;
};

#endif