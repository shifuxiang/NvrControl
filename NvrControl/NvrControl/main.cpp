#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "./database/CppMySQL3DB.h"
#include "./threadManage/C_CS.h"
#include "./threadManage/C_ThreadData.h"
#include "./threadManage/C_ThreadManage.h"
#include "./para/ec_config.h"
#include "./Nvr/Nvr_Control.h"
#include "./FileManager/FileManager_linux.h"
#include "./downloadControl/DownloadControl.h"
#include "./para/ec_config.h"
//#include "./database/pub.h"
#include "./ipcControl/ipcControl.h"
#include "./timeControl/DM_TimeControl.h"
#include "./myLog/MyLogger.h"
#include "./Nvr/Nvr_Control.h"
#include "Nvr_Types.h"
#include "Nvr_Ret.h"
//using namespace std;
#if 0
std::string g_NVRIP;
std::string g_NVRUserName;
std::string g_NVRPassword;
std::string g_NVRPort;
std::string g_CinemaName;
#endif


std::string g_debuginfocfg_fullpath;
char g_CinemaName[50];
char g_NvrIP[50];
char g_NvrPort[50];
char g_NvrUserName[50];
char g_NvrPassword[50];
downLoad g_Download;
int g_LoginHandle;
char g_db_ip[50];
char g_db_username[50];
char g_db_password[50];
char g_db_dbname[50];
ipccontrol g_ipcControl;
ec_config g_config;
timeControl g_timeControl;
NvrControl g_nvrcontrol;
MyLogger g_Download_logwrite;
MyLogger g_ipc_logwrite;
MyLogger g_time_logwrite;
MyLogger g_nvr_logwrite;
MyLogger g_interface_logwriter;

int readValue()
{
	int nRet = 0;
	memset(g_CinemaName,0,sizeof(g_CinemaName));
	memset(g_NvrIP,0,sizeof(g_NvrIP));
	memset(g_NvrPort,0,sizeof(g_NvrPort));
	memset(g_NvrUserName,0,sizeof(g_NvrUserName));
	memset(g_NvrPassword,0,sizeof(g_NvrPassword));
	ec_config debugcfg;
	debugcfg.readvalue("NVR_INFO","CinemaName",g_CinemaName,g_debuginfocfg_fullpath.c_str());
	debugcfg.readvalue("NVR_INFO","NvrIP",g_NvrIP,g_debuginfocfg_fullpath.c_str());
	debugcfg.readvalue("NVR_INFO","NvrPort",g_NvrPort,g_debuginfocfg_fullpath.c_str());
	debugcfg.readvalue("NVR_INFO","NvrUserName",g_NvrUserName,g_debuginfocfg_fullpath.c_str());
	debugcfg.readvalue("NVR_INFO","NvrPassword",g_NvrPassword,g_debuginfocfg_fullpath.c_str());
	return nRet;
}

void * covert(LPVOID pvoid)
{
	g_Download.DM_Convert();
}
int main(int argc,char ** argv)
{
	int nRet = 0;
	int NvrPort = 0;
	char NvrIP[50];
	char cinemaName[50];
	char NvrUserName[50];
	char NvrPassword[50];

	char sec_name[50];
	char key_name[50];
	char key_value[50];
	char logconf_path[255] = {'\0'};
	int max_retry = 0;
	int retry_num = 0;
	ec_config debugcfg;
	PubFun pubfun;
	g_debuginfocfg_fullpath = "./NvrControl.ini";

#if 0

	memset(sec_name,0,sizeof(sec_name));
	sprintf(sec_name,"NVR_INFO");
	memset(key_name,0,sizeof(key_name));
	sprintf(key_name,"CinemaName");
	memset(key_value,0,sizeof(key_value));
	sprintf(key_value,"%s",cinemaName);
	//debugcfg.writevalue(sec_name,key_name,key_value,g_debuginfocfg_fullpath.c_str());
	//debugcfg.writevalue(sec_name,key_name,key_value,"/home/sfx/NvrControl/NvrControl.ini");
	debugcfg.writevalue(sec_name,key_name,key_value,"NvrControl.ini");
#endif
	memset(logconf_path,0,sizeof(logconf_path));
	sprintf(logconf_path,"./Nvrlog.conf");
	
	g_Download_logwrite.Init(logconf_path,"download");
	g_ipc_logwrite.Init(logconf_path,"ipc");
	g_time_logwrite.Init(logconf_path,"time");
	g_nvr_logwrite.Init(logconf_path,"nvr");
	g_interface_logwriter.Init(logconf_path,"interface");

	C_ThreadManage *pThreadMessage = C_ThreadManage::GetInstance();
	nRet = pThreadMessage->InitThreadData();
	if(nRet != 0)
	{
		return nRet;
	}
	nRet = pThreadMessage->InitWebserviceThread();
	if(nRet != 0)
	{
		return nRet;
	}
	
#if 0
	std::cout <<"input cinemaName:"<<std::endl;
	std::cin >>cinemaName;
	std::cout <<"input NVRIP:"<<std::endl;
	std::cin >> NvrIP;
	std::cout <<"input NVRPORT:"<<std::endl;
	std::cin >>NvrPort;
	std::cout <<"input NVRUSERNAME:"<<std::endl;
	std::cin>>NvrUserName;
	std::cout <<"intput NVRPASSWORD:"<<std::endl;
	std::cin >>NvrPassword;
	memset(sec_name,0,sizeof(sec_name));
	sprintf(sec_name,"NVR_INFO");
	memset(key_name,0,sizeof(key_name));
	sprintf(key_name,"CinemaName");
	memset(key_value,0,sizeof(key_value));
	sprintf(key_value,"%s",cinemaName);
	debugcfg.writevalue(sec_name,key_name,key_value,g_debuginfocfg_fullpath.c_str());
	memset(key_name,0,sizeof(key_name));
	sprintf(key_name,"NvrIP");
	memset(key_value,0,sizeof(key_value));
	sprintf(key_value,"%s",NvrIP);
	debugcfg.writevalue(sec_name,key_name,key_value,g_debuginfocfg_fullpath.c_str());
	memset(key_name,0,sizeof(key_name));
	sprintf(key_name,"NvrPort");
	memset(key_value,0,sizeof(key_value));
	sprintf(key_value,"%d",NvrPort);
	debugcfg.writevalue(sec_name,key_name,key_value,g_debuginfocfg_fullpath.c_str());
	memset(key_name,0,sizeof(key_name));
	sprintf(key_name,"NvrUserName");
	memset(key_value,0,sizeof(key_value));
	sprintf(key_value,"%s",NvrUserName);
	debugcfg.writevalue(sec_name,key_name,key_value,g_debuginfocfg_fullpath.c_str());
	memset(key_name,0,sizeof(key_name));
	sprintf(key_name,"NvrPassword");
	memset(key_value,0,sizeof(key_value));
	sprintf(key_value,"%s",NvrPassword);
	debugcfg.writevalue(sec_name,key_name,key_value,g_debuginfocfg_fullpath.c_str());
#endif
	nRet = readValue();
	NvrControl nvrcontrol;
	nRet = g_nvrcontrol.DM_InitSDK();
	char buff_temp[255] = {'\0'};
	memset(buff_temp, 0, sizeof(buff_temp));
	sprintf(buff_temp, "interface module,start uo program!\n");
	g_interface_logwriter.PrintLog(MyLogger::INFO,"%s",buff_temp);
#if 1
	memset(g_db_ip,0,sizeof(g_db_ip));
	memset(g_db_username,0,sizeof(g_db_username));
	memset(g_db_password,0,sizeof(g_db_password));
	memset(g_db_dbname,0,sizeof(g_db_dbname));
	pubfun.GetDataBaseInfoFromConfigFile(g_db_dbname,g_db_ip,g_db_username,g_db_password);
#endif
	//g_timeControl.SetNvtServer(true,"127.0.0.1",123,10);
#if 1
	pthread_t covertThread;
	pthread_attr_t attr;
	if(pthread_attr_init(&attr) != 0)
	{
		std::cout <<"init attr error!"<<std::endl;
	}
	if(pthread_create(&covertThread, &attr, covert, NULL) != 0)
	{
		std::cout<<"create thread error! "<<std::endl;
	}
	pthread_join(covertThread,NULL);
#endif
	while(true)
	{
		sleep(60);
	}
	
	C_ThreadManage::DestoryInstance();
	g_nvrcontrol.DM_Cleanup();
	return nRet;
}


int GetReportStatusInfo(int errorcode,REPORT_STATUS *preportstatus)
{
	int nRet = 0;
	memset(preportstatus,0,sizeof(preportstatus));
	if( 0 == errorcode)
	{
		sprintf(preportstatus->status,"successfull");
		sprintf(preportstatus->error_code_str,"0");
		sprintf(preportstatus->message,"is successfull");
	}
	if(errorcode > 420200000 &&errorcode < 420300000)
	{
		g_nvrcontrol.GetNvrErrorString(errorcode,preportstatus);
	}
	if(errorcode >420300000 && errorcode < 420400000)
	{
		g_ipcControl.GetIPCErrorString(errorcode,preportstatus);
	}
	if(errorcode >420100000 && errorcode < 420200000)
	{
		g_Download.GetDownloadErrorString(errorcode,preportstatus);
	}
	if(errorcode >420400000 && errorcode < 420500000)
	{
		g_timeControl.GetTimeControlErrorString(errorcode,preportstatus);
	}
	return nRet;
}