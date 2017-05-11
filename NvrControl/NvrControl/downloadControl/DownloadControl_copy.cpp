#include "DownloadControl.h"
#include "../Nvr/Nvr_Control.h"
#include "../FileManager/FileManager_linux.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <sys/statfs.h>
#include "../para/ec_config.h"
#include "../ipcControl/ipcControl.h"
#include <time.h>
#include "../myLog/MyLogger.h"
#include <sys/types.h>
#include <dirent.h>
extern "C"
{
	#include <libavutil/timestamp.h>
	#include <libavformat/avformat.h>
}
extern int g_LoginHandle;
int m_ChannelID;
long long  m_DownloadID;
int m_DownloadID1;
NET_TIME m_start_time = {0};
NET_TIME m_end_time = {0};
extern char g_NvrIP[50];
extern char g_NvrPort[50];
extern char g_NvrUserName[50];
extern char g_NvrPassword[50];
NvrControl nvrcontrol;
NvrControl nvrcontrol1;
extern MyLogger g_Download_logwrite;
extern NvrControl g_nvrcontrol;

#define PORT 0
#define BUF_VIDEO_RENDER 3
#define SOURCEBUF_SIZE          (500 * 1024)
bool m_isConverting = false;
bool m_isConverting1 = false;
pthread_mutex_t m_mutex_checking;
int i = pthread_mutex_init(&m_mutex_checking,NULL);
pthread_mutex_t m_mutex_coverting;
int a = pthread_mutex_init(&m_mutex_coverting,NULL);

downLoad::downLoad()
{
	//m_nvrcontrol = new NvrControl();
	//isOK1 = false;
	//isOK2 = false;
	//downloadTable.NewSpaceDownload(&pDownloadItem);
	m_downloadID = 0;
}
downLoad::~downLoad()
{
	//delete []m_nvrcontrol;
	//downloadTable.DeleteSpaceDownload(&pDownloadItem);
}
int downLoad::DM_SetNvrDownloadSpeed(int id,bool isOK)
{
	int nRet = 0;
	#if 1
	//nRet = nvrcontrol.DM_InitSDK();
	int isping_ok;
	CFileManager filemanger;
	filemanger.PingIsOk(g_NvrIP,&isping_ok);
	if(!isping_ok )
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "ping nvr ip is failed ,this ip can not using!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		return -1;
	}
	else
	{
		//test
		//nRet = nvrcontrol.DM_Login(g_NvrIP,atoi(g_NvrPort),g_NvrUserName,g_NvrPassword);
		nRet = g_nvrcontrol.DM_Login(g_NvrIP,atoi(g_NvrPort),g_NvrUserName,g_NvrPassword);
		//test
		
	}
	cout << nvrcontrol.m_lLoginHandle <<endl;
	#endif
	DHDEV_DOWNLOAD_STRATEGY_CFG * downloadStrategycfg = new DHDEV_DOWNLOAD_STRATEGY_CFG[1];
	downloadStrategycfg->bEnable = isOK;
	downloadStrategycfg->dwSize = sizeof(DHDEV_DOWNLOAD_STRATEGY_CFG);
	//test
	//nRet = CLIENT_SetDevConfig(nvrcontrol.m_lLoginHandle,DH_DEV_DOWNLOAD_STRATEGY,0xFFFFFFFF,downloadStrategycfg,sizeof(DHDEV_DOWNLOAD_STRATEGY_CFG));
	//test
	std::cout << g_nvrcontrol.m_lLoginHandle<<std::endl;
	nRet = CLIENT_SetDevConfig(g_nvrcontrol.m_lLoginHandle,DH_DEV_DOWNLOAD_STRATEGY,0xFFFFFFFF,downloadStrategycfg,sizeof(DHDEV_DOWNLOAD_STRATEGY_CFG));
	if(!nRet)
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "set nvr download speed is failed!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		nRet = -1;
	}
	#if 1
	//test
	//nRet = nvrcontrol.DM_Logout(nvrcontrol.m_lLoginHandle);
	nRet = g_nvrcontrol.DM_Logout(g_nvrcontrol.m_lLoginHandle);
	//test

	//nvrcontrol.DM_Cleanup();
	#endif
	//delete[]downloadStrategycfg;
	return nRet;
}

void TimeDownLoadCallBack(LLONG lPlayHandle, DWORD dwTotalSize,DWORD dwDownLoadSize,int id)
{
	downloadtable downloadTable;
	char state[50];
	memset(state,0,sizeof(state));
	cout << "lPlayHandle:"<<lPlayHandle <<endl;
	cout << "m_DownloadID:"<<m_DownloadID<<endl;
#if 0
	vector<long long> DW_Handle;
	long long downHandle = m_DownloadID;
	DW_Handle.push_back(downHandle);
	vector<long long> PL_Handle;
	long long playHandle = lPlayHandle;
	PL_Handle.push_back(playHandle);
#endif
#if 1
	DOWNLOAD_ITEMS_TBL downloadItems;
	downloadTable.GetAllDownloadInfo(downloadItems);
	for(DOWNLOAD_ITEMS_TBL::iterator it = downloadItems.begin();it != downloadItems.end();++it)
	{
		DOWNLOAD_ITEM_TBL * pDownloadItem = (DOWNLOAD_ITEM_TBL *)(*it);
		if(lPlayHandle == atoll(pDownloadItem->downloadID))
		{       
			if(-1 !=  dwDownLoadSize)
			{ 
				std::cout <<"shifuxiang"<<std::endl;
			}
			else
			{       
	#if 0
				sprintf(state,"end");
				pthread_mutex_lock(&m_mutex_checking);
				downloadTable.updateDownloadInfoByDownloadID("state",state,m_DownloadID);
				pthread_mutex_unlock(&m_mutex_checking);
	#endif
				cout <<dwDownLoadSize<<endl;
				pthread_mutex_lock(&m_mutex_checking);
				char temp_buff[10] = {'\0'};
				memset(temp_buff,0,sizeof(temp_buff));
				sprintf(temp_buff,"%lld",lPlayHandle);
				string downloadId = temp_buff;
				std::cout << id<<std::endl;
				long long mdownlodID = atoll(pDownloadItem->downloadID);
				//downloadTable.updateDownloadInfoByid(id,"DownLoadID",downloadId);
				sprintf(state,"end");
				downloadTable.updateDownloadInfoByDownloadID("state",state,mdownlodID);
				pthread_mutex_unlock(&m_mutex_checking);
				
				cout << "done"<<endl;
				//CLIENT_Cleanup();
				//cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk"<<endl;
				///按照m_DownloadID更改数据库下载状态
		#if 0
				
				//if(atoll(pDownloadItem->downloadID) != 0)
				//{
					//CLIENT_StopDownload(atoll(pDownloadItem->downloadID));
				//}
				cout << atoll(pDownloadItem->loginHandle)<<endl;
				int nRet = nvrcontrol.DM_Logout(nvrcontrol.m_lLoginHandle);
				//int nRet = CLIENT_Logout(atoll(pDownloadItem->loginHandle));
				if(nRet == 0)
				{
					cout << "logout failed!"<<endl;
					return ;
				}
				//nvrcontrol.DM_Cleanup();
				CLIENT_Cleanup();
				cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk"<<endl;
		#endif
				return;
			}
		}
	}
	downloadTable.DeleteSpaceDownloads(&downloadItems);
#endif
#if 0
	if(lPlayHandle == m_DownloadID)
	{       
		if(-1 !=  dwDownLoadSize)
		{       
			//i++; 
			std::cout <<"shifuxiang"<<std::endl;
		}
		else
		{       
#if 0
			sprintf(state,"end");
			pthread_mutex_lock(&m_mutex_checking);
			downloadTable.updateDownloadInfoByDownloadID("state",state,m_DownloadID);
			pthread_mutex_unlock(&m_mutex_checking);
#endif
			pthread_mutex_lock(&m_mutex_checking);
			char temp_buff[10] = {'\0'};
			memset(temp_buff,0,sizeof(temp_buff));
			sprintf(temp_buff,"%lld",lPlayHandle);
			string downloadId = temp_buff;
			std::cout << id<<std::endl;
			//downloadTable.updateDownloadInfoByid(id,"DownLoadID",downloadId);
			sprintf(state,"end");
			downloadTable.updateDownloadInfoByDownloadID("state",state,m_DownloadID);
			pthread_mutex_unlock(&m_mutex_checking);
			cout << "done"<<endl;
			///按照m_DownloadID更改数据库下载状态
			return;
		}
	}
#endif

}

bool startConvert(string mp4FileName)
{
	string destPathEdit= mp4FileName;
	PLAY_SetStreamOpenMode(PORT, STREAME_FILE);
	PLAY_OpenStream(PORT, NULL, 0, SOURCEBUF_SIZE);
	PLAY_Play(PORT, NULL); 
	BOOL retValue = PLAY_StartDataRecord(PORT, (char*)destPathEdit.c_str(), 2);
	if (!retValue)
	{
		// 触发失败事件
		//emit startConvertFailed();	
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "convert to avi failed!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		m_isConverting = false;
		PLAY_Stop(PORT);
		PLAY_CloseStream(PORT);
		return false;
	}
	return true;
}

void stopConvert()
{
	PLAY_StopDataRecord(PORT);
	PLAY_Stop(PORT);
	PLAY_CloseStream(PORT);
}


void CALLBACK DownLoadPos(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, NET_RECORDFILE_INFO recordfileinfo, LDWORD dwUser)
{
#if 1
	if (dwDownLoadSize  != -1)
	{
		TimeDownLoadCallBack(lPlayHandle,dwTotalSize,dwDownLoadSize,dwUser);
	}
	else
	{       
		//isOK1 = true;
		TimeDownLoadCallBack(lPlayHandle,dwTotalSize,dwDownLoadSize,dwUser);
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "download to .dav file success!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		cout <<" else ........."<<endl;

		cout <<"lllllllllllllllllllllllllllllllllllllll"<<endl;
		

		return;
		//CLIENT_StopDownload(m_DownloadID);
#if 0
		FILE * file =  fopen("/home/sfx/download.dav","rw+");
		if (!startConvert())
		{
			fclose(file);
			CLIENT_Logout(nvrcontrol.m_lLoginHandle);
			CLIENT_Cleanup();
			return ;
		}
		long long readPos = 0;
		const int READ_LEN = 1 * 512;
		unsigned char readBuf[READ_LEN] = {0};
		m_isConverting = true;

		while (m_isConverting)
		{           
			int count = fread(readBuf,1,READ_LEN,file);			
			if(count < READ_LEN)
			{
				break;
			}        
			while (!PLAY_InputData(PORT, readBuf, READ_LEN) && m_isConverting)
			{
				usleep(30);
			}
			readPos += READ_LEN;
			if (m_isConverting)
			{
				//double proPercent = ((double)readPos / (double)fileLen) * 500;
				//emit valueChanged(proPercent);
			}
			std::cout << "lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll"<<std::endl;
		}

		if (m_isConverting)
		{
			m_isConverting = false;
			//emit convertCompleted();
			//emit changeUIState(CANCEL);
		}
		while ((PLAY_GetBufferValue(PORT, BUF_VIDEO_RENDER) + PLAY_GetSourceBufferRemain(PORT)) > 0)
		{
			usleep(5);
		}
		
		sleep(10);
		stopConvert();
		fclose(file);
#endif
		
	}
	#endif
	return ;
 }

int download()
{
	std::cout << g_LoginHandle<<std::endl;
	std::cout << m_start_time.dwDay<<std::endl;
	std::cout << g_LoginHandle <<std::endl;
	char buff_temp[50] = {'\0'};
	char buff_mp4temp[50] = {'\0'};
	memset(buff_temp,0,sizeof(buff_temp));
	memset(buff_temp,0,sizeof(buff_mp4temp));
	sprintf(buff_temp,"/home/sfx/download_%d_%d_%d.dav",m_start_time.dwHour,m_start_time.dwMinute,m_start_time.dwSecond);
	sprintf(buff_temp,"/home/sfx/download_%d_%d_%d.mp4",m_start_time.dwHour,m_start_time.dwMinute,m_start_time.dwSecond);
	m_DownloadID = CLIENT_DownloadByTime(nvrcontrol.m_lLoginHandle, 0, 0,&m_start_time, &m_end_time,buff_temp,DownLoadPos,(DWORD)0);
	std::cout <<"download id is:"<< m_DownloadID<<std::endl;
	return m_DownloadID;
}

void * download_byTime__thread(LPVOID pvoid)
{
         download();
}

int downLoad::DM_DownLoadByTime(int id,int nAudiNU,int nDevicePo,NET_TIME tmStart,NET_TIME  tmEnd)
{
	int nRet = 0;
	int nChannelId = 0;
	ipccontrol ipcControl;
	nRet = ipcControl.DM_GetIpcInfo(nAudiNU,nDevicePo,nChannelId);
	if(nRet != 0)
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "get ipc info failed error nu:%d\n",nRet);
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		return nRet;
	}
#if 0
	if(m_DownloadID != 0)
	{
		std::cout<<m_DownloadID<<std::endl;
		std::cout<<"stop download !"<<std::endl;
		CLIENT_StopDownload(m_DownloadID);
		std::cout << m_DownloadID<<std::endl;
		m_DownloadID = 0;
	}
#endif

	////获取文件存储路径剩余存储空间的大小
	////当存储文件的磁盘存储空间剩余小于100M的时候返回无法继续下载
#if 0
	struct statfs diskInfo;
	statfs("/home/sfx/",&diskInfo);
	//unsigned long long blocksize = diskInfo.f_bsize;
	//unsigned long long availableDisk = diskInfo.f_bavail * blocksize;
	long remainSpace = (diskInfo.f_bavail/1024*diskInfo.f_bsize/1024)/1024;
	if(remainSpace <= 192)
	{
		std::cout <<"disk remain space is too little!"<<std::endl;
		return -1;
	}
#endif

	////设置并发量，当同一台nvr的并发量超过20时，请用户终止本次操作，稍后再下载
	DOWNLOAD_INFOS downloadInfos;
	pthread_mutex_lock(&m_mutex_checking);
	//DM_GetDownLoadInfo(&downloadInfos);
	int count = 0;
	DM_GetDownLoadInfoCountByStateAndIpcIP(count);
	pthread_mutex_unlock(&m_mutex_checking);
	if(count >= 18)
	{
		////
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "Concurrency nu > 18!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		return -1;
	}
#if 1
	//nRet = nvrcontrol.DM_InitSDK();
	int isping_ok;
	CFileManager filemanger;
	filemanger.PingIsOk(g_NvrIP,&isping_ok);
	if(!isping_ok )
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "ping nvr ip is failed ,this ip can not using!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		return -1;
	}
	else
	{
		//test
		//nRet = nvrcontrol.DM_Login(g_NvrIP,atoi(g_NvrPort),g_NvrUserName,g_NvrPassword);
		nRet = g_nvrcontrol.DM_Login(g_NvrIP,atoi(g_NvrPort),g_NvrUserName,g_NvrPassword);
		//test
		if(nRet != 0)
		{
			char buff_temp[255] = {'\0'};
			memset(buff_temp, 0, sizeof(buff_temp));
			sprintf(buff_temp, "download :login failed!\n");
			g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		}
	}
#endif
#if 1
	m_start_time.dwDay = tmStart.dwDay;
	m_start_time.dwHour = tmStart.dwHour;
	m_start_time.dwMinute = tmStart.dwMinute;
	m_start_time.dwMonth = tmStart.dwMonth;
	m_start_time.dwSecond = tmStart.dwSecond;
	m_start_time.dwYear = tmStart.dwYear;
#endif
#if 1
	m_end_time.dwDay = tmEnd.dwDay;
	m_end_time.dwHour = tmEnd.dwHour;
	m_end_time.dwMinute = tmEnd.dwMinute;
	m_end_time.dwMonth = tmEnd.dwMonth;
	m_end_time.dwSecond = tmEnd.dwSecond;
	m_end_time.dwYear = tmEnd.dwYear;
#endif

	///修改结束时间设置，因为下载时发现每次下载的视频在结束时总是会缺少2到3秒的视频
#if 0
	if(tmEnd.dwSecond < 57)
	{
		tmEnd.dwSecond += 3;
		m_end_time.dwSecond = tmEnd.dwSecond;
	}
	else
	{
		tmEnd.dwMinute += 1;
		m_end_time.dwSecond = tmEnd.dwSecond-57;   //秒 = 原始数据+3-60
	}
	if(tmEnd.dwMinute != 60)
	{
		m_end_time.dwMinute = tmEnd.dwMinute;
	}
	else
	{
		tmEnd.dwHour += 1;
		m_end_time.dwMinute = 0;					//分在进位后仅剩下0
	}
	if(tmEnd.dwHour != 24)
	{
		m_end_time.dwHour = tmEnd.dwHour;
	}
	else
	{
		tmEnd.dwDay += 1;
		m_end_time.dwHour = 0;						//时在进位后仅剩下0
	}
	if(!(tmEnd.dwYear%100))
	{
		if(!(tmEnd.dwYear%400))
		{
			if(2 == tmEnd.dwMonth)
			{
				if(29 <  tmEnd.dwDay)
				{
					tmEnd.dwMonth += 1;
					//tmEnd.dwDay = 0;
					m_end_time.dwDay = 0;
				}
				else
				{
					m_end_time.dwDay = tmEnd.dwDay;
				}
			}
			else if((1 == tmEnd.dwMonth)||(3 == tmEnd.dwMonth)||(5 == tmEnd.dwMonth)||(7 == tmEnd.dwMonth)||(8 == tmEnd.dwMonth)||(10 == tmEnd.dwMonth)||(12 == tmEnd.dwMonth))
			{
				if(tmEnd.dwDay > 31)
				{
					tmEnd.dwMonth += 1;
					//tmEnd.dwDay = 0;
					m_end_time.dwDay = 0;
				}
				else
				{
					m_end_time.dwDay = tmEnd.dwDay;
				}
			}
			else
			{
				if(tmEnd.dwDay > 30)
				{
					tmEnd.dwMonth += 1;
					//tmEnd.dwDay = 0;
					m_end_time.dwDay = 0;
				}
				else
				{
					m_end_time.dwDay = tmEnd.dwDay;
				}
			}
		}
	}
	if(!(tmEnd.dwYear%4)&&(tmEnd.dwYear%100))
	{
		if(2 == tmEnd.dwMonth)
		{
			if(29 <  tmEnd.dwDay)
			{
				tmEnd.dwMonth += 1;
				//tmEnd.dwDay = 0;
				m_end_time.dwDay = 0;
			}
			else
			{
				m_end_time.dwDay = tmEnd.dwDay;
			}
		}
		else if((1 == tmEnd.dwMonth)||(3 == tmEnd.dwMonth)||(5 == tmEnd.dwMonth)||(7 == tmEnd.dwMonth)||(8 == tmEnd.dwMonth)||(10 == tmEnd.dwMonth)||(12 == tmEnd.dwMonth))
		{
			if(tmEnd.dwDay > 31)
			{
				tmEnd.dwMonth += 1;
				//tmEnd.dwDay = 0;
				m_end_time.dwDay = 0;
			}
			else
			{
				m_end_time.dwDay = tmEnd.dwDay;
			}
		}
		else
		{
			if(tmEnd.dwDay > 30)
			{
				tmEnd.dwMonth += 1;
				//tmEnd.dwDay = 0;
				m_end_time.dwDay = 0;
			}
			else
			{
				m_end_time.dwDay = tmEnd.dwDay;
			}
		}
	}
	if(tmEnd.dwYear%4)
	{
		if(2 == tmEnd.dwMonth)
		{
			if(tmEnd.dwDay > 28)
			{
				tmEnd.dwMonth += 1;
				m_end_time.dwDay = 0;
			}
			else
			{
				m_end_time.dwDay = tmEnd.dwDay;
			}
		}
		else if((1 == tmEnd.dwMonth)||(3 == tmEnd.dwMonth)||(5 == tmEnd.dwMonth)||(7 == tmEnd.dwMonth)||(8 == tmEnd.dwMonth)||(10 == tmEnd.dwMonth)||(12 == tmEnd.dwMonth))
		{
			if(tmEnd.dwDay > 31)
			{
				tmEnd.dwMonth += 1;
				//tmEnd.dwDay = 0;
				m_end_time.dwDay = 0;
			}
			else
			{
				m_end_time.dwDay = tmEnd.dwDay;
			}
		}
		else
		{
			if(tmEnd.dwDay > 30)
			{
				tmEnd.dwMonth += 1;
				//tmEnd.dwDay = 0;
				m_end_time.dwDay = 0;
			}
			else
			{
				m_end_time.dwDay = tmEnd.dwDay;
			}
		}

	}
	if(tmEnd.dwMonth > 12)
	{
		tmEnd.dwYear += 1;
		m_end_time.dwMonth = 0;
	}
	else
	{
		m_end_time.dwMonth = tmEnd.dwMonth;
	}

	m_end_time.dwYear = tmEnd.dwYear;
#endif
#if 0
	pthread_attr_t attr;
	pthread_t pthread_download_proc;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&pthread_download_proc, &attr, download_byTime__thread, 0);
	pthread_attr_destroy (&attr);
#endif

	int duration =(tmEnd.dwDay- tmStart.dwDay)*86400 +(tmEnd.dwHour-tmStart.dwHour)*3600+(tmEnd.dwMinute-tmStart.dwMinute)*60+(tmEnd.dwSecond-tmStart.dwSecond);
	time_t tt = time(NULL);
	tm * t = localtime(&tt);
	ec_config readCfg;
	char sec_name[BUFF_SIZE_50];
	char configfilepath[BUFF_SIZE_255];
	char path[255] = {'\0'};
	memset(sec_name,0,sizeof(sec_name));
	memset(configfilepath,0,sizeof(configfilepath));
	memset(path,0,sizeof(path));
	sprintf(sec_name,"DOWNLOAD_INFO");
	sprintf(configfilepath,"./NvrControl.ini");	
	readCfg.readvalue(sec_name,"path",path,configfilepath);
	DIR* openSuccess = opendir(path);
	if(openSuccess == NULL)
	{
		char str[255] = {'\0'};
		memset(str,0,sizeof(str));
		sprintf(str,"mkdir %s",path);
		system(str);
	}
	char ALLPath[255] = {'\0'};
	memset(ALLPath,0,sizeof(ALLPath));
	sprintf(ALLPath,"%s/download_%d_%d_%d%d%d_%d%d%d_%d_%d%d%d_%d%d%d.dav",path,
		nAudiNU,
		nDevicePo,
		tmStart.dwYear,
		tmStart.dwMonth,
		tmStart.dwDay,
		tmStart.dwHour,
		tmStart.dwMinute,
		tmStart.dwSecond,
		duration,
		t->tm_year+1900,
		t->tm_mon+1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec);
	//sprintf(ALLPath,"%s/download_%d_%d_%d_%d_%d_%d_%d_%d__%d_%d%d.dav",path,t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec,nAudiNU,nDevicePo,tmStart.dwHour,tmStart.dwMinute,tmStart.dwSecond);
	char ALLPathMP4[255] = {'\0'};
	memset(ALLPathMP4,0,sizeof(ALLPathMP4));
	sprintf(ALLPathMP4,"%s/download_%d_%d_%d%d%d_%d%d%d_%d_%d%d%d_%d%d%d.mp4",path,
		nAudiNU,
		nDevicePo,
		tmStart.dwYear,
		tmStart.dwMonth,
		tmStart.dwDay,
		tmStart.dwHour,
		tmStart.dwMinute,
		tmStart.dwSecond,
		duration,
		t->tm_year+1900,
		t->tm_mon+1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec);
	//sprintf(ALLPathMP4,"%s/download_%d_%d_%d_%d_%d_%d_%d_%d__%d_%d_%d.mp4",path,t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec,nAudiNU,nDevicePo,tmStart.dwHour,tmStart.dwMinute,tmStart.dwSecond);
	char ALLPathAVI[255] = {'\0'};
	memset(ALLPathAVI,0,sizeof(ALLPathAVI));
	//sprintf(ALLPathAVI,"%s/download_%d_%d_%d_%d_%d_%d_%d_%d__%d_%d_%d.avi",path,t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec,nAudiNU,nDevicePo,tmStart.dwHour,tmStart.dwMinute,tmStart.dwSecond);
	sprintf(ALLPathAVI,"%s/download_%d_%d_%d%d%d_%d%d%d_%d_%d%d%d_%d%d%d.avi",path,
		nAudiNU,
		nDevicePo,
		tmStart.dwYear,
		tmStart.dwMonth,
		tmStart.dwDay,
		tmStart.dwHour,
		tmStart.dwMinute,
		tmStart.dwSecond,
		duration,
		t->tm_year+1900,
		t->tm_mon+1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec);
	char buff_temp[50] = {'\0'};
	char buff_mp4temp[50] = {'\0'};
	memset(buff_temp,0,sizeof(buff_temp));
	memset(buff_temp,0,sizeof(buff_mp4temp));
	sprintf(buff_temp,"/home/sfx/download_%d_%d_%d.dav",m_start_time.dwHour,m_start_time.dwMinute,m_start_time.dwSecond);
	sprintf(buff_temp,"/home/sfx/download_%d_%d_%d.avi",m_start_time.dwHour,m_start_time.dwMinute,m_start_time.dwSecond);
	//m_DownloadID = CLIENT_DownloadByTime(nvrcontrol.m_lLoginHandle, 0, 0,&m_start_time, &m_end_time,buff_temp,DownLoadPos,(DWORD)0);

	//写入数据库下载信息
	DOWNLOAD_ITEM_TBL * pDownloadItem = NULL;
	downloadTable.NewSpaceDownload(&pDownloadItem);
	char start_time[50] = {'\0'};
	char end_time[50] = {'\0'};
	memset(start_time,0,sizeof(start_time));
	memset(end_time,0,sizeof(end_time));
	sprintf(start_time,"%d/%d/%d  %d:%d:%d",m_start_time.dwYear,m_start_time.dwMonth,m_start_time.dwDay,m_start_time.dwHour,m_start_time.dwMinute,m_start_time.dwSecond);
	sprintf(end_time,"%d/%d/%d  %d:%d:%d",m_end_time.dwYear,m_end_time.dwMonth,m_end_time.dwDay,m_end_time.dwHour,m_end_time.dwMinute,m_end_time.dwSecond);
	sprintf(pDownloadItem->downloadID,"%d",m_DownloadID);
	sprintf(pDownloadItem->endtime,"%s",end_time);
	sprintf(pDownloadItem->starttime,"%s",start_time);
	sprintf(pDownloadItem->HallNo,"%d",nAudiNU);
	sprintf(pDownloadItem->IPCPosition,"%d",nDevicePo);
	sprintf(pDownloadItem->filename,"%s",ALLPath);
	sprintf(pDownloadItem->mp4filename,"%s",ALLPathMP4);
	sprintf(pDownloadItem->state,"begin");
	sprintf(pDownloadItem->avifilename,"%s",ALLPathAVI);
	//test
	//sprintf(pDownloadItem->loginHandle,"%lld",nvrcontrol.m_lLoginHandle);
	sprintf(pDownloadItem->loginHandle,"%lld",g_nvrcontrol.m_lLoginHandle);
	//test
	pthread_mutex_lock(&m_mutex_checking);
	downloadTable.insertDownloadInfo(pDownloadItem);
	int c = 0;
	downloadTable.GetLatestInsertId(c);
	pthread_mutex_unlock(&m_mutex_checking);
	std::cout << c <<std::endl;
	//m_DownloadID = CLIENT_DownloadByTime(nvrcontrol.m_lLoginHandle, 0, 0,&m_start_time, &m_end_time,ALLPath,DownLoadPos,(DWORD)0);
	std::cout << atoi(pDownloadItem->id)<<std::endl;
	//m_DownloadID = CLIENT_DownloadByTime(nvrcontrol.m_lLoginHandle, 0, 0,&m_start_time, &m_end_time,ALLPath,DownLoadPos,c);
	////test
	//m_DownloadID = CLIENT_DownloadByTime(nvrcontrol.m_lLoginHandle, nChannelId, 0,&m_start_time, &m_end_time,ALLPath,DownLoadPos,c);
	m_DownloadID = CLIENT_DownloadByTime(g_nvrcontrol.m_lLoginHandle, nChannelId, 0,&m_start_time, &m_end_time,ALLPath,DownLoadPos,c);
	////test
	std::cout << m_DownloadID <<std::endl;
	m_downloadID = m_DownloadID;
	char temp[25] = {'\0'};
	memset(temp,0,sizeof(temp));
	sprintf(temp,"%lld",m_DownloadID);
	downloadTable.updateDownloadInfoByid(c,"DownLoadID",temp);
	if(m_DownloadID == 0)
	{
		char state[25] = {'\0'};
		memset(state,0,sizeof(state));
		sprintf(state,"failed");
		downloadTable.updateDownloadInfoByid(c,"state",state);
		nRet = -1;
		//test
		//nvrcontrol.DM_Logout(nvrcontrol.m_lLoginHandle);
		//nvrcontrol.DM_Cleanup();
		g_nvrcontrol.DM_Logout(g_nvrcontrol.m_lLoginHandle);
		//test
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "download by time failed!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
	}
	///更新数据库
	//pDownloadItem->downloadID = m_DownloadID;
	downloadTable.DeleteSpaceDownload(&pDownloadItem);
	return nRet;
}


int downLoad::DM_GetDownloadInfoByState(DOWNLOAD_INFOS *pDownloadInfos)
{
	int nRet = 0;
	DOWNLOAD_ITEMS_TBL downloadItems;
	//pthread_mutex_lock(&m_mutex_checking);
	downloadTable.GetDownloadInfoBystate(downloadItems);
	//pthread_mutex_unlock(&m_mutex_checking);
	for(DOWNLOAD_ITEMS_TBL::iterator it = downloadItems.begin();it != downloadItems.end();++it)
	{
		DOWNLOAD_INFO *downloadInfo = (DOWNLOAD_INFO *)new DOWNLOAD_INFO;
		downloadInfo->pdownloaditem = (DOWNLOAD_ITEM_TBL *)(*it);
		pDownloadInfos->push_back(downloadInfo);
	}
	
	return nRet;
}

//

static void log_packet(const AVFormatContext *fmt_ctx, const AVPacket *pkt, const char *tag)
{
    AVRational *time_base = &fmt_ctx->streams[pkt->stream_index]->time_base;

    printf("%s: pts:%s pts_time:%s dts:%s dts_time:%s duration:%s duration_time:%s stream_index:%d\n",
           tag,
           av_ts2str(pkt->pts), av_ts2timestr(pkt->pts, time_base),
           av_ts2str(pkt->dts), av_ts2timestr(pkt->dts, time_base),
           av_ts2str(pkt->duration), av_ts2timestr(pkt->duration, time_base),
           pkt->stream_index);
}

int covertavitomp4(string inputname,string outputname)
{
	AVOutputFormat *ofmt = NULL;
    AVFormatContext *ifmt_ctx = NULL, *ofmt_ctx = NULL;
    AVPacket pkt;
    const char *in_filename, *out_filename;
    int ret, i;
#if 0
    if (argc < 3) {
        printf("usage: %s input output\n"
               "API example program to remux a media file with libavformat and libavcodec.\n"
               "The output format is guessed according to the file extension.\n"
               "\n", argv[0]);
        return 1;
    }
#endif

#if 0
    in_filename  = outputname.c_str();
	int b = outputname.find(".");
	string output = outputname.substr(0,b);
	output = output+".mp4";
    out_filename = output.c_str();
#endif
	in_filename = inputname.c_str();
	out_filename = outputname.c_str();

    av_register_all();

    if ((ret = avformat_open_input(&ifmt_ctx, in_filename, 0, 0)) < 0) {
        fprintf(stderr, "Could not open input file '%s'", in_filename);
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "convert avi to mp4 failed ,can not open avi file!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
        goto end;
    }

    if ((ret = avformat_find_stream_info(ifmt_ctx, 0)) < 0) {
        fprintf(stderr, "Failed to retrieve input stream information");
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "covert avi to mp4 failed ,Failed to retrieve input stream information!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
        goto end;
    }

    av_dump_format(ifmt_ctx, 0, in_filename, 0);

    avformat_alloc_output_context2(&ofmt_ctx, NULL, NULL, out_filename);
    if (!ofmt_ctx) {
        fprintf(stderr, "Could not create output context\n");
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "covert avi to mp4 failed,Could not create output context!\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
        ret = AVERROR_UNKNOWN;
        goto end;
    }

    ofmt = ofmt_ctx->oformat;

    for (i = 0; i < ifmt_ctx->nb_streams; i++) {
        AVStream *in_stream = ifmt_ctx->streams[i];
        AVStream *out_stream = avformat_new_stream(ofmt_ctx, in_stream->codec->codec);
        if (!out_stream) {
            fprintf(stderr, "Failed allocating output stream\n");
			char buff_temp[255] = {'\0'};
			memset(buff_temp, 0, sizeof(buff_temp));
			sprintf(buff_temp, "covert avi to mp4 failed,Failed allocating output stream!\n");
			g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
            ret = AVERROR_UNKNOWN;
            goto end;
        }

        ret = avcodec_copy_context(out_stream->codec, in_stream->codec);
        if (ret < 0) {
            fprintf(stderr, "Failed to copy context from input to output stream codec context\n");
			char buff_temp[255] = {'\0'};
			memset(buff_temp, 0, sizeof(buff_temp));
			sprintf(buff_temp, "covert avi to mp4 failed,Failed to copy context from input to output stream codec context!\n");
			g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
            goto end;
        }
        out_stream->codec->codec_tag = 0;
        if (ofmt_ctx->oformat->flags & AVFMT_GLOBALHEADER)
            out_stream->codec->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
    }
    av_dump_format(ofmt_ctx, 0, out_filename, 1);

    if (!(ofmt->flags & AVFMT_NOFILE)) {
        ret = avio_open(&ofmt_ctx->pb, out_filename, AVIO_FLAG_WRITE);
        if (ret < 0) {
            fprintf(stderr, "Could not open output file '%s'", out_filename);
			char buff_temp[255] = {'\0'};
			memset(buff_temp, 0, sizeof(buff_temp));
			sprintf(buff_temp, "covert avi to mp4 failed,Could not open output file '%s'", out_filename);
			g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
            goto end;
        }
    }
    ret = avformat_write_header(ofmt_ctx, NULL);
    if (ret < 0) {
        fprintf(stderr, "Error occurred when opening output file\n");
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "covert avi to mp4 failed,Error occurred when opening output file\n");
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
        goto end;
    }

    while (1) {
        AVStream *in_stream, *out_stream;

        ret = av_read_frame(ifmt_ctx, &pkt);
        if (ret < 0)
            break;

        in_stream  = ifmt_ctx->streams[pkt.stream_index];
        out_stream = ofmt_ctx->streams[pkt.stream_index];

        log_packet(ifmt_ctx, &pkt, "in");

        /* copy packet */
        pkt.pts = av_rescale_q_rnd(pkt.pts, in_stream->time_base, out_stream->time_base,(AVRounding)(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
        pkt.dts = av_rescale_q_rnd(pkt.dts, in_stream->time_base, out_stream->time_base, (AVRounding)(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
        pkt.duration = av_rescale_q(pkt.duration, in_stream->time_base, out_stream->time_base);
        pkt.pos = -1;
        log_packet(ofmt_ctx, &pkt, "out");

        ret = av_interleaved_write_frame(ofmt_ctx, &pkt);
        if (ret < 0) {
            fprintf(stderr, "Error muxing packet\n");
			char buff_temp[255] = {'\0'};
			memset(buff_temp, 0, sizeof(buff_temp));
			sprintf(buff_temp, "covert avi to mp4 failed,Error muxing packet\n");
			g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
            break;
        }
        av_packet_unref(&pkt);
    }

    av_write_trailer(ofmt_ctx);
end:

    avformat_close_input(&ifmt_ctx);

    /* close output */
    if (ofmt_ctx && !(ofmt->flags & AVFMT_NOFILE))
        avio_closep(&ofmt_ctx->pb);
    avformat_free_context(ofmt_ctx);

    if (ret < 0 && ret != AVERROR_EOF) {
        fprintf(stderr, "Error occurred: %s\n", av_err2str(ret));
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "covert avi to mp4 failed,Error occurred: %s\n", av_err2str(ret));
		g_Download_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
        return 1;
    }

	cout <<"lllllllllllllllllllllllllllllllllllllllllllllllllllllll"<<endl;

#if 0
	int b = outputname.find(".");
	string davName = inputname.substr(0,b);
	davName = davName+".dav";
	char cmd[255] = {'\0'};
	memset(cmd,0,sizeof(cmd));
	sprintf(cmd,"rm -rf %s ",davName.c_str());
	system(cmd);

	memset(cmd,0,sizeof(cmd));
	sprintf(cmd,"rm -rf %s",inputname.c_str());
	system(cmd);
#endif
    return 0;
}
void * ConvertPackageFormat(LPVOID pvoid)
{
	//线程函数
	pthread_mutex_lock(&m_mutex_coverting);
	DOWNLOAD_INFO * pdownloadinfo = (DOWNLOAD_INFO *)pvoid;
	downloadtable download;
	//pthread_mutex_lock(&m_mutex_checking);
	//download.updateDownloadInfoByid(atoi(pdownloadinfo->pdownloaditem->id),"covertstate","begin");
	//download.updateDownloadInfoByDownloadID("covertstate","begin",atoi(pdownloadinfo->pdownloaditem->downloadID));
	char state[50] = {'\0'};
	memset(state,0,sizeof(state));
	sprintf(state,"begin");
	download.updateDownloadInfoByDownloadID("ipcIp",state,atoll(pdownloadinfo->pdownloaditem->downloadID));
	//pthread_mutex_unlock(&m_mutex_checking);
#if 1
	FILE * file =  fopen(pdownloadinfo->pdownloaditem->filename,"rw+");
	//if (!startConvert(pdownloadinfo->pdownloaditem->mp4filename))
#if 1
	if (!startConvert(pdownloadinfo->pdownloaditem->avifilename))
	{
		fclose(file);
		//test
		//CLIENT_Logout(nvrcontrol.m_lLoginHandle);
		//CLIENT_Cleanup();
		g_nvrcontrol.DM_Logout(g_nvrcontrol.m_lLoginHandle);
		//test
		return 0;
	}
#endif
	long long readPos = 0;
	const int READ_LEN = 1 * 512;
	unsigned char readBuf[READ_LEN] = {0};
	m_isConverting = true;

	while (m_isConverting)
	{           
		int count = fread(readBuf,1,READ_LEN,file);			
		if(count < READ_LEN)
		{
			break;
		}        
		while (!PLAY_InputData(PORT, readBuf, READ_LEN) && m_isConverting)
		{
			usleep(30);
		}
		readPos += READ_LEN;
		if (m_isConverting)
		{
			//double proPercent = ((double)readPos / (double)fileLen) * 500;
			//emit valueChanged(proPercent);
		}
		std::cout << "lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll"<<std::endl;
	}

	if (m_isConverting)
	{
		m_isConverting = false;
		//emit convertCompleted();
		//emit changeUIState(CANCEL);
	}
	while ((PLAY_GetBufferValue(PORT, BUF_VIDEO_RENDER) + PLAY_GetSourceBufferRemain(PORT)) > 0)
	{
		usleep(5);
	}
		
	sleep(10);
	stopConvert();
	fclose(file);

	//covertavitomp4(pdownloadinfo->pdownloaditem->filename,pdownloadinfo->pdownloaditem->mp4filename);
	covertavitomp4(pdownloadinfo->pdownloaditem->avifilename,pdownloadinfo->pdownloaditem->mp4filename);
	pthread_mutex_lock(&m_mutex_checking);
	//download.updateDownloadInfoByid(atoi(pdownloadinfo->pdownloaditem->id),"covertstate","end");
	//char state[50] = {'\0'};
	memset(state,0,sizeof(state));
	sprintf(state,"end");
	download.updateDownloadInfoByDownloadID("ipcIp",state,atoll(pdownloadinfo->pdownloaditem->downloadID));
	pthread_mutex_unlock(&m_mutex_checking);
	pthread_mutex_unlock(&m_mutex_coverting);
	//sleep(300);
#if 1
	char cmd[128] = {'\0'};
	memset(cmd,0,sizeof(cmd));
	sprintf(cmd,"rm -rf %s",pdownloadinfo->pdownloaditem->avifilename);		
	system(cmd);

	//char cmd[128] = {'\0'};
	memset(cmd,0,sizeof(cmd));
	sprintf(cmd,"rm -rf %s",pdownloadinfo->pdownloaditem->filename);
	system(cmd);
#endif
#endif
#if 0
	char cmd[255];
	memset(cmd,0,sizeof(cmd));
	sprintf(cmd,"ffmpeg -y -i %s %s",pdownloadinfo->pdownloaditem->filename,pdownloadinfo->pdownloaditem->mp4filename);
	system(cmd);
	pthread_mutex_lock(&m_mutex_checking);
	//download.updateDownloadInfoByid(atoi(pdownloadinfo->pdownloaditem->id),"covertstate","end");
	//char state[50] = {'\0'};
	memset(state,0,sizeof(state));
	sprintf(state,"end");
	download.updateDownloadInfoByDownloadID("ipcIp",state,atoi(pdownloadinfo->pdownloaditem->downloadID));
	pthread_mutex_unlock(&m_mutex_checking);
#endif
}
int downLoad::DM_Convert()
{
	//pthread_mutex_lock(&m_mutex_coverting);
	//DOWNLOAD_INFOS downloadInfos;
	while(true)
	{
		DOWNLOAD_INFOS downloadInfos;
		pthread_mutex_lock(&m_mutex_checking);
		DM_GetDownloadInfoByState(&downloadInfos);
		pthread_mutex_unlock(&m_mutex_checking);
		for(DOWNLOAD_INFOS::iterator it = downloadInfos.begin();it != downloadInfos.end();++it)
		{
			DOWNLOAD_INFO * pdownloadinfo = (DOWNLOAD_INFO *)(*it);
			if(!strcmp(pdownloadinfo->pdownloaditem->state," "))
			{
				break;
			}
			if(!strcmp(pdownloadinfo->pdownloaditem->state,"end"))
			{
				
				///启动转换线程
#if 1
				///当下载完原始文件以后，注销掉当次的设备用户
				//test
				int nRet = CLIENT_Logout(atoll(pdownloadinfo->pdownloaditem->loginHandle));
				if(nRet == 0)
				{
					cout << "logout failed!"<<endl;
				}
				//CLIENT_Cleanup();
				///test
#endif
				pthread_attr_t attr;
				pthread_t pthread_convert_proc;
				pthread_attr_init(&attr);
				pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
				
				pthread_create(&pthread_convert_proc, &attr, ConvertPackageFormat, pdownloadinfo);
				
				pthread_attr_destroy (&attr);
				
			}
			sleep(10);
			///使转换线程呈现线性执行，这样起到防止转换线程重复讲一个.dav转换为.avi文件
			///原先的操作使得线程船箭以后在等待执行，然后重新从数据库中获取到的信息还有已创建县城所占用的信息
			///所以导致重复转换的现象
			while(true)
			{
				DOWNLOAD_INFOS downloadInfos1;
				char sql[512] = {'\0'};
				memset(sql,0,sizeof(sql));
				sprintf(sql,"select * from downLoad where state = 'end' and ipcIp = 'begin'");
				DOWNLOAD_ITEMS_TBL downloadtableinfos;
				pthread_mutex_lock(&m_mutex_checking);
				downloadTable.GetDownloadInfoBySql(sql,downloadtableinfos);
				pthread_mutex_unlock(&m_mutex_checking);
				if(downloadtableinfos.size() == 0)
				{
					break;
				}
				sleep(2);
			}
		}
		sleep(10);
	}
	//pthread_mutex_unlock(&m_mutex_coverting);
}

void * deletefile(void *pvoid)
{
	DOWNLOAD_INFO * pdownloadinfo = (DOWNLOAD_INFO *)(pvoid);
	char cmd[128] = {'\0'};
	memset(cmd,0,sizeof(cmd));
	sprintf(cmd,"rm -rf %s",pdownloadinfo->pdownloaditem->filename);
	system(cmd);
	memset(cmd,0,sizeof(cmd));
	sprintf(cmd,"rm -rf %s",pdownloadinfo->pdownloaditem->avifilename);	
	system(cmd);
}
int downLoad::DM_Delete()
{
	int nRet = 0;
	while(true)
	{
		//sleep(10);
		DOWNLOAD_INFOS downloadInfos;
		pthread_mutex_lock(&m_mutex_checking);
		DM_GetDownloadInfoByState(&downloadInfos);
		pthread_mutex_unlock(&m_mutex_checking);
		for(DOWNLOAD_INFOS::iterator it = downloadInfos.begin();it != downloadInfos.end();++it)
		{
			//DOWNLOAD_INFO * pdownloadinfo = (DOWNLOAD_INFO *)new DOWNLOAD_INFO;
			//pdownloadinfo = (DOWNLOAD_INFO *)(*it);
			DOWNLOAD_INFO * pdownloadinfo = (DOWNLOAD_INFO *)(*it);
			if(!strcmp(pdownloadinfo->pdownloaditem->ipcIP,"end"))
			{
				
				///启动删除线程
				pthread_attr_t attr;
				pthread_t pthread_convert_proc;
				pthread_attr_init(&attr);
				pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
				
				pthread_create(&pthread_convert_proc, &attr, deletefile, pdownloadinfo);
				
				pthread_attr_destroy (&attr);
				
			}
			sleep(10);
		}
		//DeleteSpaceDownloadInfos(&downloadInfos);
		sleep(30);
	}
	return nRet;
}

int downLoad::DM_GetDownLoadInfo(DOWNLOAD_INFOS * downloadInfos)
{
	int nRet = 0;
	DOWNLOAD_ITEMS_TBL downloadItems;
	//pthread_mutex_lock(&m_mutex_checking);
	//downloadTable.GetDownloadInfoBystate(downloadItems);
	downloadTable.GetAllDownloadInfo(downloadItems);
	for(DOWNLOAD_ITEMS_TBL::iterator it = downloadItems.begin();it != downloadItems.end();++it)
	{
		DOWNLOAD_INFO *downloadInfo = (DOWNLOAD_INFO *)new DOWNLOAD_INFO;
		downloadInfo->pdownloaditem = (DOWNLOAD_ITEM_TBL *)(*it);
		downloadInfos->push_back(downloadInfo);
	}
	return nRet;
}

int downLoad::DM_GetDownLoadInfoCountByStateAndIpcIP(int &count)
{
	int nRet = 0;
	DOWNLOAD_ITEMS_TBL downloadItems;
	char sql[512] = {'\0'};
	memset(sql,0,sizeof(sql));
	sprintf(sql,"select * from downLoad where state = 'begin' and ipcIp = ' '");
	downloadTable.GetDownloadInfoBySql(sql,downloadItems);
	count = downloadItems.size();
	return nRet;
}

int downLoad::DM_GetDownloadInfoBySql(string sql,DOWNLOAD_INFO *pDownloadInfo)
{
	int nRet = 0;
	DOWNLOAD_ITEM_TBL downloadItems;
	downloadTable.GetDownloadInfoBySql(sql,pDownloadInfo->pdownloaditem);
	//pDownloadInfo
	return nRet;
}
int downLoad::NewSpaceDeviceDownloadInfo(DOWNLOAD_INFO **pDownloadInfo)
{
	int nRet = 0;
	if(NULL != *pDownloadInfo)
	{
		return nRet;
	}
	*pDownloadInfo = new DOWNLOAD_INFO;
	(*pDownloadInfo)->pdownloaditem = NULL;
	downloadTable.NewSpaceDownload(&((*pDownloadInfo)->pdownloaditem));
	return nRet;
}

int downLoad::DeleteSpaceDeviceDownloadInfo(DOWNLOAD_INFO **pDownloadInfo)
{
	int nRet = 0;
	if(NULL == (*pDownloadInfo))
	{
		return nRet;
	}
	downloadTable.DeleteSpaceDownload(&((*pDownloadInfo)->pdownloaditem));
	if(NULL != (*pDownloadInfo))
	{
		delete (*pDownloadInfo);
		*pDownloadInfo = NULL;
	}
	return nRet;
}

int downLoad::ZeroSpaceDeviceDownloadInfo(DOWNLOAD_INFO * pDownloadInfo)
{
	int nRet = 0;
	if(NULL == pDownloadInfo)	
	{
		return nRet;
	}
	downloadTable.ZeroSpaceDownload(pDownloadInfo->pdownloaditem);
	return nRet;
}

int downLoad::DeleteSpaceDownloadInfos(DOWNLOAD_INFOS *pDownloadInfos)
{
	int nRet = 0;
	if(NULL == pDownloadInfos)
	{
		return nRet;
	}
	if(pDownloadInfos->size() > 0)
	{
		for(int i = 0; i<pDownloadInfos->size(); i++)
		{
			DOWNLOAD_INFO *ptemp = (DOWNLOAD_INFO *)((*pDownloadInfos)[i]);
			DeleteSpaceDeviceDownloadInfo(&ptemp);
		}
		pDownloadInfos->clear();
	}
	return nRet;
}

int downLoad::ZeroSpaceDownloadInfos(DOWNLOAD_INFOS *pDownloadInfos)
{
	int nRet = 0;
	if(NULL == pDownloadInfos)
	{
		return nRet;
	}

	if(pDownloadInfos->size() > 0)
	{
		for(int i = 0; i<pDownloadInfos->size(); i++)
		{
			DOWNLOAD_INFO *ptemp = (DOWNLOAD_INFO *)((*pDownloadInfos)[i]);
			ZeroSpaceDeviceDownloadInfo(ptemp);
		}
	}
	return nRet;
}