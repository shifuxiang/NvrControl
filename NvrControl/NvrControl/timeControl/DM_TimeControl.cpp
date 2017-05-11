#include <stdlib.h>
#include <sys/time.h>

#include "DM_TimeControl.h"

#include "../FileManager/FileManager_linux.h"
#include "../myLog/MyLogger.h"


extern char g_NvrIP[50];
extern char g_NvrPort[50];
extern char g_NvrUserName[50];
extern char g_NvrPassword[50];
extern MyLogger g_time_logwrite;
extern NvrControl g_nvrcontrol;

timeControl::timeControl()
{
	
}
timeControl::~timeControl()
{
	
}
int timeControl::GetSystemTime(timeStruct & timeInfo)
{
	int nRet = 0;
	char buff_temp[255] = {'\0'};
	//测试程序响应需要的时间
	NET_TIME  timeinfo;
	
	struct timeval tv;    
	gettimeofday(&tv,NULL);
	
	memset(buff_temp, 0, sizeof(buff_temp));
	sprintf(buff_temp, "timecontrol module,start pragram start time is %lld",(tv.tv_sec * 1000 + tv.tv_usec / 1000));
	g_time_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
	nRet = CLIENT_QueryDeviceTime(g_nvrcontrol.m_lLoginHandle,&timeinfo);
	gettimeofday(&tv,NULL);
	memset(buff_temp, 0, sizeof(buff_temp));
	sprintf(buff_temp, "time control module,end pragram end time is %lld",(tv.tv_sec * 1000 + tv.tv_usec / 1000));
	g_time_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
	if(nRet == 0)
	{
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "time control module,get nvr system time failed ");
		g_time_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		//nRet = -1;
		nRet = URL_TIMECONTROL_GETSYSTEMTIME_ERROR;
	}
	else
	{
		timeInfo.unYear   = timeinfo.dwYear;
		timeInfo.unMonth  = timeinfo.dwMonth;
		timeInfo.unDay	  = timeinfo.dwDay;
		timeInfo.unHour   = timeinfo.dwHour;
		timeInfo.unMinute = timeinfo.dwMinute;
		timeInfo.unSecond = timeinfo.dwSecond;
		//nRet =0;
		nRet = NVR_SUCCESS;
	}
	return nRet;
}

int timeControl::SetSystemTime(timeStruct  timeInfo)
{
	int nRet = NVR_SUCCESS;
	///测试程序响应需要的时间
	struct timeval tv;    
	gettimeofday(&tv,NULL);
	char buff_temp[255] = {'\0'};
	memset(buff_temp, 0, sizeof(buff_temp));
	sprintf(buff_temp, "set  pragram start time is %lld",(tv.tv_sec * 1000 + tv.tv_usec / 1000));
	g_time_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
	NET_TIME  timeInfos;
	timeInfos.dwYear = timeInfo.unYear;
	timeInfos.dwMonth = timeInfo.unMonth;
	timeInfos.dwDay = timeInfo.unDay;
	timeInfos.dwHour = timeInfo.unHour;
	timeInfos.dwMinute = timeInfo.unMinute;
	timeInfos.dwSecond = timeInfo.unSecond;
	nRet = CLIENT_SetupDeviceTime(g_nvrcontrol.m_lLoginHandle,&timeInfos);
	if(nRet == 0)
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "timecontrol module,set nvr ip failed");
		g_time_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		//nRet = -1;
		nRet = URL_TIMECONTROL_SETSYSTEMTIME_ERROR;
	}
	else
	{
		//nRet = 0;
		nRet = NVR_SUCCESS;
	}
	gettimeofday(&tv,NULL);
	memset(buff_temp, 0, sizeof(buff_temp));
	sprintf(buff_temp, "timecontrol module,set pragram end time is %lld",(tv.tv_sec * 1000 + tv.tv_usec / 1000));
	g_time_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
	return nRet;
}

int timeControl::DM_Init()
{
	int nRet = NVR_SUCCESS;
	int isping_ok;
	CFileManager filemanger;
	filemanger.PingIsOk(g_NvrIP,&isping_ok);
	if(!isping_ok )
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "can not ping nvr ip");
		g_time_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		nRet = URL_NVRIPCANNOTPING_ERROR;
		return nRet;
	}
	else
	{
		string ip = g_NvrIP;
		string username = g_NvrUserName;
		string password = g_NvrPassword;
		nRet = g_nvrcontrol.DM_Login(ip,atoi(g_NvrPort),username,password);
		if(nRet != 0)
		{
			std::cout <<"login failed!"<<std::endl;
		}
	}
	return nRet;

}
int timeControl::DM_Release()
{
	int nRet = NVR_SUCCESS;
	nRet = g_nvrcontrol.DM_Logout(g_nvrcontrol.m_lLoginHandle);
	return nRet;
}



int timeControl::GetTimeControlErrorString(int errorcode,REPORT_STATUS *preportstatus)
{
	int nRet = NVR_SUCCESS;
	memset(preportstatus,0,sizeof(preportstatus));
	sprintf(preportstatus->status,"failed");
	sprintf(preportstatus->error_code_str,"%d",errorcode);
	sprintf(preportstatus->level,"error");
	sprintf(preportstatus->module,"timecontrol");
	switch(errorcode)
	{
	case URL_TIMECONTROL_GETSYSTEMTIME_ERROR:
		sprintf(preportstatus->message,"timecontrol module;get nvr system time failed!");
		sprintf(preportstatus->message_la,"时间管理模块,获取nvr系统时间失败!");
		break;
	case URL_TIMECONTROL_SETSYSTEMTIME_ERROR:
		sprintf(preportstatus->message,"timecontrol module,set nvr system time failed!");
		sprintf(preportstatus->message_la,"时间管理模块，设置nvr系统时间失败!");
		break;
	default:
		sprintf(preportstatus->status,"successful");
		sprintf(preportstatus->error_code_str,"%d",errorcode);
		sprintf(preportstatus->message,"is successful");
		sprintf(preportstatus->message_la,"successful!");
		sprintf(preportstatus->level,"successful");
		sprintf(preportstatus->module,"timecontrol");
		break;
	}
	return nRet;
}


#if 1    ///首先了解ntp服务器
int timeControl::SetNvtServer(bool isOK,string ip,int port,int updatePeriod)
{
	int nRet = 0;
	bool  b3GProtocol = false;
	NvrControl nvrcontrol;
	nRet = nvrcontrol.DM_InitSDK();
	if(nRet == 0)
	{
		return -1;
	}
	int isping_ok;
	CFileManager filemanger;
	filemanger.PingIsOk(g_NvrIP,&isping_ok);
	if(!isping_ok )
	{
		return -1;
	}
	else
	{
		//nRet = nvrcontrol.DM_Login(g_NvrIP,atoi(g_NvrPort),g_NvrUserName,g_NvrPassword);
	}
	int len = 0;
	DH_DEV_ENABLE_INFO stDevEn = {0};
	CFG_DSPENCODECAP_INFO dspcpdecap = {0};
	bool bRet = CLIENT_QuerySystemInfo(nvrcontrol.m_lLoginHandle, ABILITY_DEVALL_INFO, (char*)&stDevEn, sizeof(DH_DEV_ENABLE_INFO), &len);
	if (bRet&&len == sizeof(DH_DEV_ENABLE_INFO))
	{
		if (stDevEn.IsFucEnable[EN_JSON_CONFIG]!=0 || nvrcontrol.m_nStDevInfoNu> 32)
		{
			b3GProtocol = TRUE;
		}
		else
		{
			b3GProtocol = FALSE;
		}
	}

	//DHDEV_NTP_CFG * pNtpInfo = new DHDEV_NTP_CFG[]
	if (b3GProtocol == TRUE)
	{
		char *szOutBuffer = new char[32*1024];
		if (szOutBuffer == NULL)
		{
			goto _out;     
		}
		memset(szOutBuffer, 0, 32*1024);                 
		int nerror = 0;
		CFG_NTP_INFO stuEncodeInfo = {0};
		int nrestart = 0;
		BOOL bSuccess = CLIENT_GetNewDevConfig(nvrcontrol.m_lLoginHandle, CFG_CMD_NTP, NULL, szOutBuffer, 32*1024, &nerror, 5000);
		if (bSuccess)
		{
			int nRetLen = 0;
			BOOL bRet = CLIENT_ParseData(CFG_CMD_NTP, (char *)szOutBuffer, &stuEncodeInfo, sizeof(CFG_NTP_INFO), &nRetLen);
			if (bRet == FALSE)
			{
				//printf("CLIENT_ParseData: CFG_CMD_ENCODE failed!\n");
			}
		}
		else
		{
			//printf("CLIENT_GetNewDevConfig: CFG_CMD_ENCODE failed!\n");
		}

		//stuEncodeInfo.stuMainStream[0].stuVideoFormat.nFrameRate = 25;
		//stuEncodeInfo.stuMainStream[0].stuVideoFormat.nWidth = 1920;
		//stuEncodeInfo.stuMainStream[0].stuVideoFormat.nHeight = 1080;
		stuEncodeInfo.bEnable = true;
		stuEncodeInfo.emTimeZoneType = EM_CFG_TIME_ZONE_13;
		stuEncodeInfo.nPort = 123;
		stuEncodeInfo.nSandbyServerNum = 1;
		stuEncodeInfo.nUpdatePeriod = 1;
		//stuEncodeInfo.stuStandbyServer
		memset(stuEncodeInfo.szAddress,0,sizeof(stuEncodeInfo.szAddress));
		sprintf(stuEncodeInfo.szAddress,"172.23.142.157");
		//stuEncodeInfo.szAddress = "127.0.0.1";
		//stuEncodeInfo.szTimeZoneDesc
		memset(szOutBuffer, 0, 32*1024);
		bSuccess = CLIENT_PacketData(CFG_CMD_NTP, (char *)&stuEncodeInfo, sizeof(CFG_NTP_INFO), szOutBuffer, 32*1024);

		if (bSuccess == FALSE)
		{
			//printf("CLIENT_PacketData: CFG_CMD_ENCODE failed!\n");
		}
		else
		{
			bSuccess = CLIENT_SetNewDevConfig(nvrcontrol.m_lLoginHandle, CFG_CMD_NTP, NULL, szOutBuffer, 32*1024, &nerror, &nrestart, 3000);             
			//bSuccess = CLIENT_SetNewDevConfig(lLoginHandle, CFG_CMD_HDVR_DSP, 0, szOutBuffer, 100*1024, &nerror, &nrestart, 3000);                
			//bSuccess = CLIENT_SetNewDevConfig(lLoginHandle, DH_DEV_CHANNELCFG, 0, szOutBuffer, 32*1024, &nerror, &nrestart, 3000);                
			if (bSuccess)
			{
				//cout << nrestart <<endl;
				//cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk"<<endl;
				if (nrestart == 1)
				{
					//printf("Save config info successfully!devide need restart!\n");
				}
			}
			else
			{
				//printf("CLIENT_SetNewDevConfig CFG_CMD_ENCODE failed!\n");
			}               
		}
		delete []szOutBuffer;
	}

	else
	{
		//cout << "llllllllllllllllllllllllllllllllll"<<endl;
#if 0
		DWORD dwRetLen = 0;
		if (pChannelInfo == NULL)
		{
			goto _out;
		}
		memset(pChannelInfo, 0, nChannelCount*sizeof(DHDEV_CHANNEL_CFG));
		BOOL bSuccess = CLIENT_GetDevConfig(lLoginHandle, DH_DEV_CHANNELCFG, -1, pChannelInfo, nChannelCount * sizeof(DHDEV_CHANNEL_CFG), &dwRetLen);
		if (!(bSuccess&&dwRetLen == nChannelCount * sizeof(DHDEV_CHANNEL_CFG)))
		{
			printf("CLIENT_GetDevConfig: DH_DEV_CHANNELCFG failed!\n");
		}
		pChannelInfo[0].stMainVideoEncOpt[0].byFramesPerSec = 25;//修改帧率
		pChannelInfo[0].stMainVideoEncOpt[0].byImageSize  = CAPTURE_SIZE_D1;
		bSuccess = CLIENT_SetDevConfig(lLoginHandle, DH_DEV_CHANNELCFG,0, pChannelInfo, nChannelCount * sizeof(DHDEV_CHANNEL_CFG));
		if (bSuccess == FALSE)
		{
			printf("CLIENT_SetDevConfig: DH_DEV_CHANNELCFG failed!\n");
		}
		delete []pChannelInfo;
#endif
		DWORD dwRetLen = 0;
		DHDEV_NTP_CFG * ntpInfo = new DHDEV_NTP_CFG();
		memset(ntpInfo,0,sizeof(DHDEV_NTP_CFG));
		bool bSuccess = CLIENT_GetDevConfig(nvrcontrol.m_lLoginHandle,DH_DEV_NTP_CFG,NULL,ntpInfo,sizeof(DHDEV_NTP_CFG),&dwRetLen);

		ntpInfo->bEnable = true;
		ntpInfo->nHostPort = 123;
		ntpInfo->nTimeZone = DH_TIME_ZONE_13;
		ntpInfo->nType = 1;
		ntpInfo->nUpdateInterval = 1;
		//ntpInfo->szDomainName
		//ntpInfo->szHostIp = "172.23.142.157"
		memset(ntpInfo->szHostIp,0,sizeof(ntpInfo->szHostIp));
		sprintf(ntpInfo->szHostIp,"172.23.142.157");
		bSuccess = CLIENT_SetDevConfig(nvrcontrol.m_lLoginHandle, DH_DEV_NTP_CFG,NULL, ntpInfo, sizeof(DHDEV_NTP_CFG));
		if (bSuccess == FALSE)
		{
			printf("CLIENT_SetDevConfig: DH_DEV_CHANNELCFG failed!\n");
		}
		delete []ntpInfo;

	}
_out:
	nvrcontrol.DM_Logout(nvrcontrol.m_lLoginHandle);
	nvrcontrol.DM_Cleanup();

	
	return nRet;
}
#endif