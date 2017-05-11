#include "mons.nsmap"
#include "soapH.h"
#include <iostream>
#include <cstdio>
#include "../para/C_Para.h"
//#include "../jobs/DataManager.h"
//#include "../jobs/Invoke.h"
#include "../log/C_LogManage.h"
#include "../downloadControl/DownloadControl.h"
#include "../so/dhnetsdk.h"
#include "../ipcControl/ipcControl.h"
#include "../timeControl/DM_TimeControl.h"
using namespace std;
//extern int g_RunState;
extern time_t g_tmDBSynch;
extern ipccontrol g_ipcControl;
extern timeControl g_timeControl;
extern NvrControl g_nvrcontrol;
#define  LOGINFFMT(errid,fmt,...)  C_LogManage::GetInstance()->WriteLogFmt(ULOG_INFO,LOG_MODEL_JOBS,0,errid,fmt,##__VA_ARGS__)
REPORT_STATUS preportstatus = { 0 };
#if 1

extern int GetReportStatusInfo(int errorcode, REPORT_STATUS *preportstatus);

extern downLoad g_Download;
int mons__GetoneInfos(struct soap * csoap,struct mons__get1 &ret)
{
	ret.i = 1;
	return 0;
}

int mons__SetDlSpeed(struct soap * cSoap,bool isOK,struct mons__SetDLSpeedResponse &ret)
{
	int nRet = 0;
	nRet = g_Download.DM_SetNvrDownloadSpeed(0,isOK);
	if(nRet == 0)
	{
		ret.isTrue = true;
	}
	if(nRet != 0)
	{
		char temperror[50];
        memset(&temperror,0,sizeof(temperror));
        sprintf(temperror, "%d", nRet);
        GetReportStatusInfo(nRet, &preportstatus);
        char tempstatus[50];
        memset(&tempstatus,0,sizeof(tempstatus));
        sprintf(tempstatus,"<state>faild</state>");
        return  soap_receiver_fault_subcode(cSoap, temperror, preportstatus.message, tempstatus);
	}
	return nRet;
}

int mons__DownLoadByTime(struct soap * cSoap,int id,int nAudiNU,int nDevicePo,struct mons__DownloadTime tmStart,
							struct mons__DownloadTime  tmEnd,
							std::string storePath,
							std::string mp4name,
							struct mons__DownloadTimeResponse &ret)
{
	int nRet = 0;
	NET_TIME start_time;
	NET_TIME end_time;
	start_time.dwYear = tmStart.dwYear;
	start_time.dwMonth = tmStart.dwMonth;
	start_time.dwDay = tmStart.dwDay;
	start_time.dwHour = tmStart.dwHour;
	start_time.dwMinute = tmStart.dwMinute;
	start_time.dwSecond = tmStart.dwSecond;
	end_time.dwYear = tmEnd.dwYear;
	end_time.dwMonth = tmEnd.dwMonth;
	end_time.dwDay = tmEnd.dwDay;
	end_time.dwHour = tmEnd.dwHour;
	end_time.dwMinute = tmEnd.dwMinute;
	end_time.dwSecond = tmEnd.dwSecond;
	int i = g_Download.DM_DownLoadByTime(id,nAudiNU,nDevicePo,start_time,end_time,storePath,mp4name);
	
	DOWNLOAD_INFO * pDownloadInfo = NULL;
	g_Download.NewSpaceDeviceDownloadInfo(&pDownloadInfo);
	char sql[255] = {'\0'};
	memset(sql,0,sizeof(sql));
	sprintf(sql,"select * from downLoad where DownLoadID = %lld",g_Download.m_downloadID);
	g_Download.DM_GetDownloadInfoBySql(sql,pDownloadInfo);
	
	if(i == 0)
	{
		//ret.downloadID = g_Download.m_downloadID;
		ret.id = atol(pDownloadInfo->pdownloaditem->id);
		ret.fileNameMp4 = pDownloadInfo->pdownloaditem->mp4filename;
		ret.isOK = true;
	}
	else
	{
		char temperror[50];
        memset(&temperror,0,sizeof(temperror));
        sprintf(temperror, "%d", i);
        GetReportStatusInfo(i, &preportstatus);
        char tempstatus[50];
        memset(&tempstatus,0,sizeof(tempstatus));
        sprintf(tempstatus,"<state>faild</state>");
        return  soap_receiver_fault_subcode(cSoap, temperror, preportstatus.message, tempstatus);
	}
	g_Download.DeleteSpaceDeviceDownloadInfo(&pDownloadInfo);
	cout << ret.isOK<<endl;
	return nRet;
}

int mons__SetIpcInfo(struct soap * cSoap,int HallNo,int ipcPo,int channelID,struct mons__SetIpcInfoRes &ret)
{
	int nRet = 0;
	nRet = g_ipcControl.DM_SetIpcInfo(HallNo,ipcPo,channelID);
	if(0 == nRet)
	{
		ret.isOK = true;
	}

	else
	{
		//ret.isOK =false;
		char temperror[50];
        memset(&temperror,0,sizeof(temperror));
        sprintf(temperror, "%d", nRet);
        GetReportStatusInfo(nRet, &preportstatus);
        char tempstatus[50];
        memset(&tempstatus,0,sizeof(tempstatus));
        sprintf(tempstatus,"<state>faild</state>");
        return  soap_receiver_fault_subcode(cSoap, temperror, preportstatus.message, tempstatus);
	}
	return nRet;
}

int mons__GetSystemTimeInfo(struct soap* cSoap,struct mons__GetSystemTimeRes &ret)
{
	int nRet = 0;
	timeStruct timeInfo;
	nRet = g_timeControl.GetSystemTime(timeInfo);
	if(nRet == 0)
	{
		ret.unYear = timeInfo.unYear;
		ret.unMonth = timeInfo.unMonth;
		ret.unDay = timeInfo.unDay;
		ret.unHour = timeInfo.unHour;
		ret.unMinute = timeInfo.unMinute;
		ret.unSecond = timeInfo.unSecond;
	}
	else
	{
		char temperror[50];
        memset(&temperror,0,sizeof(temperror));
        sprintf(temperror, "%d", nRet);
        GetReportStatusInfo(nRet, &preportstatus);
        char tempstatus[50];
        memset(&tempstatus,0,sizeof(tempstatus));
        sprintf(tempstatus,"<state>faild</state>");
        return  soap_receiver_fault_subcode(cSoap, temperror, preportstatus.message, tempstatus);
	}
	return nRet;
}


int mons__SetSystemTime(struct soap* cSoap,struct mons__SetSystemtimeInfo timeInfos,struct mons__SetSystemInfoRes &ret)
{
	int nRet = 0;
	timeStruct timeInfo;
	timeInfo.unYear = timeInfos.unYear;
	timeInfo.unMonth = timeInfos.unMonth;
	timeInfo.unDay = timeInfos.unDay;
	timeInfo.unHour = timeInfos.unHour;
	timeInfo.unMinute = timeInfos.unMinute;
	timeInfo.unSecond = timeInfos.unSecond;
	nRet = g_timeControl.SetSystemTime(timeInfo);
	if(nRet != 0)
	{
		char temperror[50];
        memset(&temperror,0,sizeof(temperror));
        sprintf(temperror, "%d", nRet);
        GetReportStatusInfo(nRet, &preportstatus);
        char tempstatus[50];
        memset(&tempstatus,0,sizeof(tempstatus));
        sprintf(tempstatus,"<state>faild</state>");
        return  soap_receiver_fault_subcode(cSoap, temperror, preportstatus.message, tempstatus);
	}
	else
	{
		ret.isOK = true;
	}
	return nRet;
}

int mons__DInit(struct soap * cSoap,struct mons__InitRes &ret)
{
	int nRet = 0;
	nRet = g_timeControl.DM_Init();
	if(nRet == 0)
	{
		ret.isOK = true;
	}
	else
	{
		ret.isOK = false;
	}
	return nRet;
}

int mons__DRelease(struct soap * cSoap,struct mons__ReleaseRes &ret)
{
	int nRet = 0;
	nRet = g_timeControl.DM_Release();
	if(nRet == 0)
	{
		ret.isOK = true;
	}
	else
	{
		ret.isOK = false;
	}
	return nRet;
}

int mons__GetIpcResoluRatio(struct soap * cSoap,int nAudiNU,int nDevicePo,struct mons__GetIpcResoluRatioInfo &ret)
{
	int nRet = 0;
	ResoluRatios resoluratios;
	nRet = g_ipcControl.DM_GetIpcResoluRatio(nAudiNU,nDevicePo,resoluratios);
	if(nRet != 0)
	{
		char temperror[50];
        memset(&temperror,0,sizeof(temperror));
        sprintf(temperror, "%d", nRet);
        GetReportStatusInfo(nRet, &preportstatus);
        char tempstatus[50];
        memset(&tempstatus,0,sizeof(tempstatus));
        sprintf(tempstatus,"<state>faild</state>");
        return  soap_receiver_fault_subcode(cSoap, temperror, preportstatus.message, tempstatus);
	}

	for(ResoluRatios::iterator it = resoluratios.begin();it != resoluratios.end();++it)
	{
		string resolution = *it;
		ret.ResoluRatios.push_back(resolution);
	}
	return nRet;
}

int mons__GetIpcVedioQuality(struct soap * cSoap,int nAudiNU,int nDevicePo,struct mons__GetIpcVedioQualityInfoRes &ret)
{
	int nRet = 0;
	std::string ResoluRatio;
	int frame = 0;
	std::string CodeMode;
	int stream = 0;
	g_ipcControl.DM_GetIpcVedioQuality(nAudiNU,nDevicePo,ResoluRatio,frame,CodeMode,stream);
	ret.vedioQuality.ResoluRatio = ResoluRatio;
	ret.vedioQuality.frame = frame;
	ret.vedioQuality.CodeMode = CodeMode;
	ret.vedioQuality.stream = stream;
	return nRet;
}

int mons__SetIpcVedioQuality(struct soap * cSoap,int nAudiNU,int nDevicePo,struct mons__SetIpcVedioQualityInfo vedioInfo,struct mons__SetIpcVedioQualityInfoRes &ret)
{
	int nRet = 0;
	nRet = g_ipcControl.DM_SetIpcVedioQuality(nAudiNU,nDevicePo,vedioInfo.ResoluRatio,vedioInfo.frame,vedioInfo.CodeMode,vedioInfo.stream);
	if(nRet == 0)
	{
		ret.isOK = true;
	}
	else
	{
		ret.isOK = false;
	}
	return nRet;
}

#if 0
int mons__LoginNvr(struct soap* cSoap,std::string ip,int port,std::string username,std::string password,struct mons__LoginNvrResponse &ret)
{
	int nRet = 0;
	nRet = g_nvrcontrol.DM_Login(ip.c_str(),port,username.c_str(),password.c_str());
	if(nRet != 0)
	{
		char temperror[50];
        memset(&temperror,0,sizeof(temperror));
        sprintf(temperror, "%d", nRet);
        GetReportStatusInfo(nRet, &preportstatus);
        char tempstatus[50];
        memset(&tempstatus,0,sizeof(tempstatus));
        sprintf(tempstatus,"<state>faild</state>");
        return  soap_receiver_fault_subcode(cSoap, temperror, preportstatus.message_la, tempstatus);
	}
	ret.isOK = true;
	return nRet;
}
#endif


int mons__GetMontorState(struct soap* cSoap, struct mons__MontorStateRes &ret)
{
#if 0
	int nRole = C_Para::GetInstance()->GetRole();
	ret.bMain = C_Para::GetInstance()->IsMain();

	if((nRole == 4 || nRole == 2) /*&& 0 == g_tmDBSynch*/)// TMPMAINROLE
	{
		CDataManager *pDM = CDataManager::GetInstance();
		time_t tm;
		time(&tm);
		ret.lSynch=tm;
	}
	else
	{
		ret.lSynch = 0;
	}

	int nRunState = GlobalStatus::GetInstinct()->GetStatus();
	// 如果正在启动时状态为0，启动完成后状态为本机现在的角色
	ret.iState = (0 == nRunState || 2 == nRunState || 3 == nRunState) ? 0 :nRole;
#endif	
	return 0;
}

int mons__GetTMSState(struct soap* cSoap, struct mons__TmsStateRes &ret)
{
#if 0
	CDataManager *pDM = CDataManager::GetInstance();
	ret.bRun = pDM->GetTMSStat() == 0 ? 1 : 0;
	ret.iState = 0x01;
	ret.iWorkState = 0x0f;
#endif
	return 0;
}

int mons__GetSMSState(struct soap* cSoap , std::vector<struct mons__SMSState> &vecret)
{
#if 0
	CDataManager *pDM = CDataManager::GetInstance();
	std::vector<SMSStatus> vecSMSState;

	// 处于恢复状态不进行状态获取
	int nRunState = GlobalStatus::GetInstinct()->GetStatus();
	//if(2 == g_RunState)
    if(2 == nRunState|| 0 == nRunState)
	{
		return 0;
	}
	pDM->GetSMSStat(vecSMSState);
	int nLen = vecSMSState.size();
	for(int i = 0 ;i < nLen ;i++)
	{
		mons__SMSState node;
		node.HallId = vecSMSState[i].hallid;
		node.bRun = vecSMSState[i].nRun;
		node.state = vecSMSState[i].nStatus<<8;
		switch(vecSMSState[i].nStatus)
		{
		case 101:
		case 201:
		case 202:
		case 203:
		case 204:
		case 206:
		case 301:
		case 302:
		case 303:
		case 304:
		case 305:
		case 401:
		case 402:
		case 403:
		case 404:
			node.state |= 0;
			break;
		case 102:
		case 103:
			node.state |= 1;
			break;
		case 205:
		case 306:
		case 405:
			node.state |= 2;
			break;
		}
	
		node.position = 25;//vecSMSState[i].nPosition;
		node.strSplUuid = "C80CF8FC-D6F5-26F8-3927-E30B0AE06C56";//vecSMSState[i].strSPLUuid;
		vecret.push_back(node);
	}
#endif	
	return 0;
}

int mons__GetRaidtate(struct soap* cSoap, struct mons__RaidStateRes &ret)
{
#if 0
	CDataManager *pDM = CDataManager::GetInstance();
	std::map<int,DiskDriveInfo> mapdf;
	pDM->GetDevStat(mapdf);

	if(mapdf.size() == 0)
	{
		ret.ReadSpeed = 0;
		ret.WriteSpeed = 0;
		ret.state = 1;
		return 0;
	}

	int nSpeed = 0;
	bool bError = false;
	int nSum=mapdf.size();
	for(int i=0;i<nSum;i++)
	{
		// 取最小值.
		std::map<int,DiskDriveInfo>::iterator it = mapdf.find(i);
		if(it!=mapdf.end())
		{
			struct DiskDriveInfo &ddi = it->second;
			int nDriveSpeed = ddi.driveSpeed.empty() ? 0:atoi(ddi.driveSpeed.c_str());
			if(nSpeed == 0 || nSpeed > nDriveSpeed )
			{
				nSpeed = nDriveSpeed;
			}
			int nPos = ddi.driveFirmwareState.find("Online");
			if(nPos != std::string::npos)
			{
				ret.diskState.push_back(0);
				bError = false||bError;
			}
			else
			{
				ret.diskState.push_back(1);
				bError = true||bError;
			}
		}
		else
		{
			ret.diskState.push_back(0);
			bError = false||bError;
		}
		
	}
	

	ret.ReadSpeed = nSpeed;
	ret.WriteSpeed = nSpeed;
	ret.state = bError ? 1 : 0;
#endif
	return 0;
}

int mons__GetEthState(struct soap* cSoap, std::vector<struct mons__ethstate> &vecret)
{
#if 0
	CDataManager *pDM = CDataManager::GetInstance();
	std::map<std::string,EthStatus> mapEthStatus;
	pDM->GetNetStat(mapEthStatus);
	std::map<std::string,EthStatus>::iterator it = mapEthStatus.begin();
	for(;it != mapEthStatus.end();it++)
	{
		mons__ethstate node;
		EthStatus &Ethinfo = it->second;
		node.eth=atoi(Ethinfo.strName.substr(3).c_str());
		node.type = Ethinfo.nTaskType;
		node.ConnectState = Ethinfo.nConnStatue;
		node.speed = (Ethinfo.nRxSpeed + Ethinfo.nTxSpeed)/2;
		vecret.push_back(node);
	}
	 
#endif
	return 0;
}

int mons__GetSwitchState(struct soap* cSoap, struct mons__SwitchStateRes &ret)
{
#if 0
	ret.Switch1State = 1;
	ret.Switch2State = 2;
#endif
	return 0;
}

int mons__GetIngestSpeedLimit(struct soap* cSoap, struct mons__IngestSpeedLimitRes &ret)
{
#if 0
	CDataManager *pDM = CDataManager::GetInstance();
	std::vector<SMSStatus> vecSMSState;

	int nRun = 0 ;
	pDM->GetSMSStat(vecSMSState);
	int nLen = vecSMSState.size();
	for(int i = 0 ;i < nLen ;i++)
	{
		if(vecSMSState[i].nRun == 1 && vecSMSState[i].nStatus == 201)
		{
			nRun++;
		}
	}

	if(nRun <= 1)
	{
		ret.bEnableIngest =1 ;
		ret.speedLimit = -1;
	}
	else if(nRun == 2)
	{
		ret.bEnableIngest =1 ;
		ret.speedLimit = 20;
	}
	else if(nRun == 3)
	{
		ret.bEnableIngest =1 ;
		ret.speedLimit = 15;
	}
	else if(nRun == 5)
	{
		ret.bEnableIngest =1 ;
		ret.speedLimit = 10;
	}
	else if(nRun >= 6)
	{
		ret.bEnableIngest =1 ;
		ret.speedLimit = 0;
	}
#endif
	return 0;
}

int mons__GetWorkState_USCORECS(struct soap* cSoap, struct mons__WorkStateRes &ret)
{
#if 0
	ret.hall = "tms01";
	ret.state = 1;
	ret.info = "error 0081";
#endif
	return 0;
}

int mons__ExeSwitchTMSToOther(struct soap* cSoap,int &ret)
{
// 	CDataManager *pDM = CDataManager::GetInstance();
// 	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
// 	if(ptr->SwitchTMS())
// 	{	
// 		ret = 0;
// 		return 0;
// 	}
// 	else
// 	{
// 		soap_sender_fault_subcode(cSoap, "mons:1", "Switch Fail", "SwitchTMS");
// 		ret = 1;
// 		return 1;
// 	}
	return 0;
}


int mons__ExeSwitchSMSToOther(struct soap* cSoap,std::string strHallID,int &ret)
{
#if 0
	LOGINFFMT(0,"WS:ExeSwitchSMSToOther(%s)",strHallID.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	int nState;
	if(ptr->SwitchSMS(strHallID,false,nState))
	{	
		ret = nState;
	}
	else
	{
		ret = nState;
	}
#endif
	return 0;
}

int mons__ExeSwitchSMSToOtherDelay(struct soap* cSoap,std::string strHallID,int &ret)
{
#if 0
	LOGINFFMT(0,"WS:ExeSwitchSMSToOtherDelay(%s)",strHallID.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	int nState;
	if(ptr->SwitchSMS(strHallID,true,nState))
	{	
		ret = nState;
	}
	else
	{
		ret = nState;
	}
#endif	
	return 0;
	
}

int mons__ExeCloseSMS(struct soap* cSoap,std::string strHallID,int &ret)
{
#if 0
	LOGINFFMT(0,"WS:ExeCloseSMS(%s)",strHallID.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	if(ptr->CloseSMS(strHallID))
	{	
		ret = 0;
	}
	else
	{
		ret = 1;
	}
#endif
	return 0;
}

int mons__ExeStartSMS(struct soap* cSoap,std::string strHallID,int &ret)
{
#if 0
	LOGINFFMT(0,"WS:ExeStartSMS(%s)",strHallID.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	if(ptr->StartSMS(strHallID))
	{	
		ret = 0;		
	}
	else
	{
		ret = 1;
	}
#endif
	return 0;
}

int mons__ExeDcpHashCheck(struct soap* cSoap,std::string path,std::string PklUuid,std::string& errorInfo)
{
#if 0
	LOGINFFMT(0,"WS:ExeDcpHashCheck(path:%s,uuid:%s)",path.c_str(),PklUuid.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	ptr->DcpHashCheck(path,PklUuid,errorInfo);
#endif
	return 0;
}


int mons__ExeGetHashCheckPercent(struct soap* cSoap,std::string PklUuid,struct mons__HashCheckPercent& stResult)
{
#if 0
	LOGINFFMT(0,"WS:ExeGetHashCheckPercent(uuid:%s)",PklUuid.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	ptr->GetHashCheckPercent(PklUuid,stResult.Result,stResult.nPercent,stResult.errorInfo);
#endif
	return 0;
}

int mons__CopyDcp(struct soap* cSoap,std::string PklUuid,std::string srcPath,std::string desPath,
				  struct mons__FileOperationResult &result)
{
#if 0
	LOGINFFMT(0,"WS:CopyDcp(src:%s,dest:%s,uuid:%s)",srcPath.c_str(),desPath.c_str(),PklUuid.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	ptr->CopyDcp(PklUuid,srcPath,desPath,result.Result,result.errorInfo);
#endif
	return 0;
}

int mons__GetCopyDcpProgress(struct soap* cSoap,std::string PklUuid,struct mons__FileOperationResult &result)
{
#if 0
	LOGINFFMT(0,"WS:GetCopyDcpProgress(uuid:%s)",PklUuid.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	ptr->GetCopyDcpProgress(PklUuid,result.Result,result.errorInfo);
#endif
	return 0;
}

int mons__DeleteDcp(struct soap* cSoap,std::string PklUuid,std::string Path,struct mons__FileOperationResult &result)
{
#if 0
	LOGINFFMT(0,"WS:DeleteDcp(path:%s,uuid:%s)",Path.c_str(),PklUuid.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	ptr->DeleteDcp(PklUuid,Path,result.Result,result.errorInfo);
#endif
	return 0;
}

int mons__GetDeleteDcpProgress(struct soap* cSoap,std::string PklUuid,struct mons__FileOperationResult &result)
{
#if 0
	LOGINFFMT(0,"WS:GetDeleteDcpProgress(uuid:%s)",PklUuid.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	ptr->GetDeleteDcpProgress(PklUuid,result.Result,result.errorInfo);
#endif
	return 0;
}

int mons__SetDBSynchSign(struct soap* cSoap,std::string dbsynch,int &ret)
{
#if 0
	LOGINFFMT(0,"WS:SetDBSynchSign(%s)",dbsynch.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	if(ptr->UpdateDBSynch(dbsynch))
	{
		return 0;
	}
	else
	{
		return 0;
//		soap_sender_fault_subcode(cSoap, "mons:1", "SetDBSynchSign Fail", "SetDBSynchSign");
	}
#endif	
}

int mons__GetSMSPosition(struct soap* cSoap,std::string strHallId,struct mons__SMSPositionInfo &PosInfo)
{
#if 0
	LOGINFFMT(0,"WS:GetSMSPosition(%s)",strHallId.c_str());
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	std::string strPos;
	int nPort;
	if(ptr->GetSMSPosition(strHallId,strPos,nPort))
	{	
		PosInfo.strPos=strPos;
		PosInfo.nPort=nPort;
		return 0;
	}
	else
	{
		soap_sender_fault_subcode(cSoap, "mons:1", "GetSMSPosition Fail", "GetSMSPosition");
		return 1;
	}
#endif
}

int mons__GetDBSynchStatus(struct soap* cSoap,int &state)
{
#if 0
	LOGINFFMT(0,"WS:GetDBSynchStatus");
	CDataManager *pDM = CDataManager::GetInstance();
	int nDBSynch;
	if(pDM->GetDBSynchStatus(nDBSynch))
	{
		state=nDBSynch==0?0:1;
		return 0;
	}
	else
	{
		soap_sender_fault_subcode(cSoap, "mons:1", "GetDBSynchStatus Fail", "GetDBSynchStatus");
		return 1;
	}
#endif
}

int mons__ShutdownServer(struct soap* cSoap,int nType,struct mons__RebootServerResult &result)
{
#if 0
	LOGINFFMT(0,"WS:ShutdownServer(%s)",nType==0 ? "reboot":"shutdown");
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	std::string strDesc;
	int state;
	ptr->ShutdownServer(nType,state,strDesc);
	result.strDesc = strDesc;
	result.state = state;
#endif
	return 0;
}

int mons__TimingRebootServer(struct soap* cSoap,int nDay,int nWeek,int nHour,int nMinute,
	int nRepeat,int nRepeatCnt,struct mons__RebootServerResult &result)
{
#if 0
	LOGINFFMT(0,"WS:TimingRebootServer(%d,%d,%d,%d,%d,%d)",nDay,nWeek,nHour,nMinute,nRepeat,nRepeatCnt);
	CDataManager *pDM = CDataManager::GetInstance();
	CInvoke *ptr = (CInvoke * )pDM->GetInvokerPtr();
	std::string strDesc;
	int state;
	ptr->TimingRebootServer(nDay,nWeek,nHour,nMinute,nRepeat,nRepeatCnt,state,strDesc);
	result.strDesc = strDesc;
	result.state = state;
#endif
	return 0;
}

int mons__AskAboutSlaveRestoreSwitch(struct soap* cSoap,int &nIsSwitch)
{
#if 0
	LOGINFFMT(0,"WS:AskAboutSlaveRestoreSwitch");
	CDataManager *pDM = CDataManager::GetInstance();
	if(pDM->IsRestoreSwitch())
	{
		nIsSwitch = 1;
	}
	else
	{
		nIsSwitch = 0;
	}
#endif
	return 0;
}
#endif
