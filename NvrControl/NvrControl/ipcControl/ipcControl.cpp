#include "ipcControl.h"
#include "../myLog/MyLogger.h"
#include "../FileManager/FileManager_linux.h"
#include "../Nvr_Ret.h"
#include "../Nvr_Types.h"
extern MyLogger g_ipc_logwrite;


extern char g_NvrIP[50];
extern char g_NvrPort[50];
extern char g_NvrUserName[50];
extern char g_NvrPassword[50];


void ResolutionSizetoInt(int nResolution, int *nWidth, int *nHeight, int nVideoStandard)
{
    if(nVideoStandard == 0)  //PAL
    {
        switch (nResolution)
        {
        case 0: 			*nWidth = 704;	*nHeight = 576;		break;//D1
        case 1:				*nWidth = 352;	*nHeight = 576;		break;//HD1
        case 2:				*nWidth = 704;	*nHeight = 288;		break;//BCIF
        case 3:				*nWidth = 352;	*nHeight = 288;		break;//CIF
        case 4:				*nWidth = 176;	*nHeight = 144;		break;//QCIF
        case 5:				*nWidth = 640;	*nHeight = 480;		break;//VGA
        case 6:				*nWidth = 320;	*nHeight = 240;		break;//QVGA
        case 7:				*nWidth = 480;	*nHeight = 480;		break;//SVCD
        case 8:				*nWidth = 160;	*nHeight = 128;		break;//QQVGA
        case 9:				*nWidth = 800;  *nHeight = 592;		break;//SVGA
        case 10:			*nWidth = 1024;	*nHeight = 768;		break;//XVGA
        case 11: 			*nWidth = 1280;	*nHeight = 800;		break;//WXGA
        case 12:			*nWidth = 1280;	*nHeight = 1024;	break;//SXGA
        case 13:			*nWidth = 1600;	*nHeight = 1024;	break;//WSXGA
        case 14:			*nWidth = 1600;	*nHeight = 1200;	break;//UXGA
        case 15:			*nWidth = 1920;	*nHeight = 1200;	break;//WUXGA
        case 16:			*nWidth = 240;	*nHeight = 192;		break;//LTF
        case 17:			*nWidth = 1280;	*nHeight = 720;		break;//720
        case 18:			*nWidth = 1920;	*nHeight = 1080;	break;//1080
        case 19:			*nWidth = 1280;	*nHeight = 960;		break;//1_3M
        case 20:			*nWidth = 1872;	*nHeight = 1408;	break;//2M
        case 21:			*nWidth = 3744;	*nHeight = 1408;	break;//5M
        case 22:			*nWidth = 2048;	*nHeight = 1536;	break;//3M
        case 23:			*nWidth = 2432;	*nHeight = 2050;	break;//5_0M
        case 24:			*nWidth = 1216;	*nHeight = 1024;	break;//1_2M
        case 25:			*nWidth = 1408;	*nHeight = 1024;	break;//1408_1024
        case 26:			*nWidth = 3296;	*nHeight = 2472;	break;//8M
        case 27:			*nWidth = 2560;	*nHeight = 1920;	break;//2560_1920
        case 28:			*nWidth = 960;	*nHeight = 576;		break;//960H
        case 29:			*nWidth = 960;  *nHeight = 720;		break;//960_720
        case 30:			*nWidth = 640;	*nHeight = 360;		break;//NHD
        case 31:			*nWidth = 320;	*nHeight = 180;		break;//QNHD
        case 32:			*nWidth = 160;	*nHeight = 90;		break;//QQNHD
        default:					break;
        }
    }		
    else
    {
        switch (nResolution)
        {
        case 0: 			*nWidth = 704;	*nHeight = 480;		break;//D1
        case 1:				*nWidth = 352;	*nHeight = 480;		break;//HD1
        case 2:				*nWidth = 704;	*nHeight = 240;		break;//BCIF
        case 3:				*nWidth = 352;	*nHeight = 240;		break;//CIF
        case 4:				*nWidth = 176;	*nHeight = 120;		break;//QCIF
        case 5:				*nWidth = 640;	*nHeight = 480;		break;//VGA
        case 6:				*nWidth = 320;	*nHeight = 240;		break;//QVGA
        case 7:				*nWidth = 480;	*nHeight = 480;		break;//SVCD
        case 8:				*nWidth = 160;	*nHeight = 128;		break;//QQVGA
        case 9:				*nWidth = 800;  *nHeight = 592;		break;//SVGA
        case 10:			*nWidth = 1024;	*nHeight = 768;		break;//XVGA
        case 11: 			*nWidth = 1280;	*nHeight = 800;		break;//WXGA
        case 12:			*nWidth = 1280;	*nHeight = 1024;	break;//SXGA
        case 13:			*nWidth = 1600;	*nHeight = 1024;	break;//WSXGA
        case 14:			*nWidth = 1600;	*nHeight = 1200;	break;//UXGA
        case 15:			*nWidth = 1920;	*nHeight = 1200;	break;//WUXGA
        case 16:			*nWidth = 240;	*nHeight = 192;		break;//LTF
        case 17:			*nWidth = 1280;	*nHeight = 720;		break;//720
        case 18:			*nWidth = 1920;	*nHeight = 1080;	break;//1080
        case 19:			*nWidth = 1280;	*nHeight = 960;		break;//1_3M
        case 20:			*nWidth = 1872;	*nHeight = 1408;	break;//2M
        case 21:			*nWidth = 3744;	*nHeight = 1408;	break;//5M
        case 22:			*nWidth = 2048;	*nHeight = 1536;	break;//3M
        case 23:			*nWidth = 2432;	*nHeight = 2050;	break;//5_0M
        case 24:			*nWidth = 1216;	*nHeight = 1024;	break;//1_2M
        case 25:			*nWidth = 1408;	*nHeight = 1024;	break;//1408_1024
        case 26:			*nWidth = 3296;	*nHeight = 2472;	break;//8M
        case 27:			*nWidth = 2560;	*nHeight = 1920;	break;//2560_1920
        case 28:			*nWidth = 960;	*nHeight = 480;		break;//960H
        case 29:			*nWidth = 960;  *nHeight = 720;		break;//960_720
        case 30:			*nWidth = 640;	*nHeight = 360;		break;//NHD
        case 31:			*nWidth = 320;	*nHeight = 180;		break;//QNHD
        case 32:			*nWidth = 160;	*nHeight = 90;		break;//QQNHD
        default:					break;
        }
    }
}

int ResolutionInttoSize(int nWidth, int nHeight, int nVideoStandard)
{
	int nResolution = 0;

	if(nVideoStandard == 0)  //PAL
	{
		if (nWidth == 704 && nHeight == 576)
		{
			nResolution = 0;
		}
		else if (nWidth == 352 && nHeight == 576)
		{
			nResolution = 1;
		}
		else if (nWidth == 704 && nHeight == 288)
		{
			nResolution = 2;
		}
		else if (nWidth == 352 && nHeight == 288)
		{
			nResolution = 3;
		}
		else if (nWidth == 176 && nHeight == 144)
		{
			nResolution = 4;
		}
		else if (nWidth == 640 && nHeight == 480)
		{
			nResolution = 5;
		}
		else if (nWidth == 320 && nHeight == 240)
		{
			nResolution = 6;
		}
		else if (nWidth == 480 && nHeight == 480)
		{
			nResolution = 7;
		}
		else if (nWidth == 160 && nHeight == 128)
		{
			nResolution = 8;
		}
		else if (nWidth == 800 && nHeight == 592)
		{
			nResolution = 9;
		}
		else if (nWidth == 1024 && nHeight == 768)
		{
			nResolution = 10;
		}
		else if (nWidth == 1280 && nHeight == 800)
		{
			nResolution = 11;
		}
		else if (nWidth == 1280 && nHeight == 1024)
		{
			nResolution = 12;
		}
		else if (nWidth == 1600 && nHeight == 1024)
		{
			nResolution = 13;
		}
		else if (nWidth == 1600 && nHeight == 1200)
		{
			nResolution = 14;
		}
		else if (nWidth == 1920 && nHeight == 1200)
		{
			nResolution = 15;
		}
		else if (nWidth == 240 && nHeight == 192)
		{
			nResolution = 16;
		}
		else if (nWidth == 1280 && nHeight == 720)
		{
			nResolution = 17;
		}
		else if (nWidth == 1920 && nHeight == 1080)
		{
			nResolution = 18;
		}
		else if (nWidth == 1280 && nHeight == 960)
		{
			nResolution = 19;
		}
		else if (nWidth == 1872 && nHeight == 1408)
		{
			nResolution = 20;
		}
		else if (nWidth == 3744 && nHeight == 1408)
		{
			nResolution = 21;
		}
		else if (nWidth == 2048 && nHeight == 1536)
		{
			nResolution = 22;
		}
		else if (nWidth == 2432 && nHeight == 2050)
		{
			nResolution = 23;
		}
		else if (nWidth == 1216 && nHeight == 1024)
		{
			nResolution = 24;
		}
		else if (nWidth == 1408 && nHeight == 1024)
		{
			nResolution = 25;
		}
		else if (nWidth == 3296 && nHeight == 2472)
		{
			nResolution = 26;
		}
		else if (nWidth == 2560 && nHeight == 1920)
		{
			nResolution = 27;
		}
		else if (nWidth == 960 && nHeight == 576)
		{
			nResolution = 28;
		}
		else if (nWidth == 960 && nHeight == 720)
		{
			nResolution = 29;
		}
		else if (nWidth == 640 && nHeight == 360)
		{
			nResolution = 30;
		}
		else if (nWidth == 320 && nHeight == 180)
		{
			nResolution = 31;
		}
		else if (nWidth == 160 && nHeight == 90)
		{
			nResolution = 32;
		}
	}
	else
	{
		if (nWidth == 704 && nHeight == 480)
		{
			nResolution = 0;
		}
		else if (nWidth == 352 && nHeight == 480)
		{
			nResolution = 1;
		}
		else if (nWidth == 704 && nHeight == 240)
		{
			nResolution = 2;
		}
		else if (nWidth == 352 && nHeight == 240)
		{
			nResolution = 3;
		}
		else if (nWidth == 176 && nHeight == 120)
		{
			nResolution = 4;
		}
		else if (nWidth == 640 && nHeight == 480)
		{
			nResolution = 5;
		}
		else if (nWidth == 320 && nHeight == 240)
		{
			nResolution = 6;
		}
		else if (nWidth == 480 && nHeight == 480)
		{
			nResolution = 7;
		}
		else if (nWidth == 160 && nHeight == 128)
		{
			nResolution = 8;
		}
		else if (nWidth == 800 && nHeight == 592)
		{
			nResolution = 9;
		}
		else if (nWidth == 1024 && nHeight == 768)
		{
			nResolution = 10;
		}
		else if (nWidth == 1280 && nHeight == 800)
		{
			nResolution = 11;
		}
		else if (nWidth == 1280 && nHeight == 1024)
		{
			nResolution = 12;
		}
		else if (nWidth == 1600 && nHeight == 1024)
		{
			nResolution = 13;
		}
		else if (nWidth == 1600 && nHeight == 1200)
		{
			nResolution = 14;
		}
		else if (nWidth == 1920 && nHeight == 1200)
		{
			nResolution = 15;
		}
		else if (nWidth == 240 && nHeight == 192)
		{
			nResolution = 16;
		}
		else if (nWidth == 1280 && nHeight == 720)
		{
			nResolution = 17;
		}
		else if (nWidth == 1920 && nHeight == 1080)
		{
			nResolution = 18;
		}
		else if (nWidth == 1280 && nHeight == 960)
		{
			nResolution = 19;
		}
		else if (nWidth == 1872 && nHeight == 1408)
		{
			nResolution = 20;
		}
		else if (nWidth == 3744 && nHeight == 1408)
		{
			nResolution = 21;
		}
		else if (nWidth == 2048 && nHeight == 1536)
		{
			nResolution = 22;
		}
		else if (nWidth == 2432 && nHeight == 2050)
		{
			nResolution = 23;
		}
		else if (nWidth == 1216 && nHeight == 1024)
		{
			nResolution = 24;
		}
		else if (nWidth == 1408 && nHeight == 1024)
		{
			nResolution = 25;
		}
		else if (nWidth == 3296 && nHeight == 2472)
		{
			nResolution = 26;
		}
		else if (nWidth == 2560 && nHeight == 1920)
		{
			nResolution = 27;
		}
		else if (nWidth == 960 && nHeight == 480)
		{
			nResolution = 28;
		}
		else if (nWidth == 960 && nHeight == 720)
		{
			nResolution = 29;
		}
		else if (nWidth == 640 && nHeight == 360)
		{
			nResolution = 30;
		}
		else if (nWidth == 320 && nHeight == 180)
		{
			nResolution = 31;
		}
		else if (nWidth == 160 && nHeight == 90)
		{
			nResolution = 32;
		}
	}

	return nResolution;
}


int ipccontrol::DM_SetIpcInfo(int nAudiNU,int nDevicePo,int nChannelId)
{
	int nRet = 0;
	IpcTable ipctable;
	IPC_ITEM_TBL * ipcitemtable = NULL;

	ipctable.NewSpaceIpc(&ipcitemtable);
	sprintf(ipcitemtable->HallNo,"%d",nAudiNU);
	sprintf(ipcitemtable->ipcPosition,"%d",nDevicePo);
	sprintf(ipcitemtable->channelID,"%d",nChannelId);
	nRet = ipctable.InsertIpcInfo(ipcitemtable);
	if(nRet != 0)
	{
		nRet = URL_IPCCONTROL_SETIPCINFO_ERROR;
	}
	ipctable.DeleteSpaceIpc(&ipcitemtable);
	return nRet;
}

int ipccontrol::DM_GetIpcInfo(int nAudiNU,int nDevicePo,int &nChannelID)
{
	int nRet = 0;
	IpcTable ipctable;
	IPC_ITEM_TBL * ipcitemtable = NULL;
	ipctable.NewSpaceIpc(&ipcitemtable);
	nRet = ipctable.GetIpcInfoByHallNoAndPosition(nAudiNU,nDevicePo,ipcitemtable);
	if(!strcmp(ipcitemtable->id,""))
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "get ipc info by audiNu and devicepo failed");
		g_ipc_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		//nRet = -1;
		nRet = URL_IPCCONTROL_GETIPCINFO_ERROR;
	}
	if(nRet == 0)
	{
		nChannelID = atoi(ipcitemtable->channelID);
	}
	ipctable.DeleteSpaceIpc(&ipcitemtable);
	return nRet;
}

int ipccontrol::DM_GetIpcResoluRatio(int nAudiNU,int nDevicePo,ResoluRatios & resoluratios)
{
	int nRet = 0;
	int nRetLen = 0;
	NvrControl nvrcontrol;
	nRet = nvrcontrol.DM_InitSDK();

	int isping_ok;
	CFileManager filemanger;
	filemanger.PingIsOk(g_NvrIP,&isping_ok);
	if(!isping_ok )
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "ping nvr ip failed ");
		g_ipc_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		nRet = URL_NVRIPCANNOTPING_ERROR;
		//return -1;
		return nRet;
	}
	else
	{
		//test
		string ip = g_NvrIP;
		string username = g_NvrUserName;
		string password = g_NvrPassword;
		nRet = nvrcontrol.DM_Login(ip,atoi(g_NvrPort),username,password);
		//test
		//nRet = nvrcontrol.DM_Login(g_NvrIP,atoi(g_NvrPort),g_NvrUserName,g_NvrPassword);
	}

	char *rsName[32] =  {"D1",      "HD1",       "BCIF",   "CIF",       "QCIF",   "VGA",     "QVGA",  "SVCD", 
                         "QQVGA",   "SVGA",      "XVGA",   "WXGA",      "SXGA",   "WSXGA",   "UXGA",  "WUXGA",
                         "LFT",     "720",       "1080",   "1_3M",      "2M",     "5M",      "3M",    "5_0M",
                         "1_2M",    "1408_1024", "8M",     "2560_1920", "960H",   "960_720", "NHD" ,  "QNHD"}; 
    DWORD dwImageSizeMask = 0;

	DHDEV_DSP_ENCODECAP  stDspInfo = {0};
	nRet = CLIENT_QueryDevState(nvrcontrol.m_lLoginHandle, DH_DEVSTATE_DSP, (char*)&stDspInfo, sizeof(DHDEV_DSP_ENCODECAP), &nRetLen, 3000);

    if (TRUE != nRet)
    {
        cout << "Failed to get CFG_CMD_VIDEOWIDGET config! Press any key to continue..." << endl;
        //return -6;
		nRet = URL_IPCCONTROL_GETIPCRESOLURATIO_ERROR;
		return nRet;
    }

    dwImageSizeMask = stDspInfo.dwImageSizeMask;

    for (unsigned int nSupportImage = 0; nSupportImage < 32; nSupportImage++)
    {
        if (0 != (dwImageSizeMask & (0x01<<nSupportImage)))
        {
            //cout << "支持分辨率:" << rsName[nSupportImage] <<endl;
			resoluratios.push_back(rsName[nSupportImage]);
        }
    }

	nRet = nvrcontrol.DM_Logout(nvrcontrol.m_lLoginHandle);
	nvrcontrol.DM_Cleanup();
	return nRet;
}


int ipccontrol::DM_GetIpcVedioQuality(int nAudiNU,int nDevicePo,string &ResoluRatio,int &frame,string &CodeMode,int &stream)
{
	int nRet = 0;
	int nError = 0;
	NvrControl nvrcontrol;
	DWORD dwTempLen = 50*1024;
	char *pTemp = new char[dwTempLen];
	int nChannelID = 0;
	nRet = DM_GetIpcInfo(nAudiNU,nDevicePo,nChannelID);
	nRet = nvrcontrol.DM_InitSDK();

	char *rsName[32] =  {"D1",      "HD1",       "BCIF",   "CIF",       "QCIF",   "VGA",     "QVGA",  "SVCD", 
                         "QQVGA",   "SVGA",      "XVGA",   "WXGA",      "SXGA",   "WSXGA",   "UXGA",  "WUXGA",
                         "LFT",     "720",       "1080",   "1_3M",      "2M",     "5M",      "3M",    "5_0M",
                         "1_2M",    "1408_1024", "8M",     "2560_1920", "960H",   "960_720", "NHD" ,  "QNHD"}; 
	char * compression[10] = {"MPEG4","MS_MPEG4","MPEG2",
							  "MPEG1","H263","MJPG",
								"FCC_MPEG4","H264","H265",
								"SVAC"};
	int isping_ok;
	CFileManager filemanger;
	filemanger.PingIsOk(g_NvrIP,&isping_ok);
	if(!isping_ok )
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "ping nvr ip failed ");
		g_ipc_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		return -1;
	}
	else
	{
		//test
		string ip = g_NvrIP;
		string username = g_NvrUserName;
		string password = g_NvrPassword;
		nRet = nvrcontrol.DM_Login(ip,atoi(g_NvrPort),username,password);
		//test
		//nRet = nvrcontrol.DM_Login(g_NvrIP,atoi(g_NvrPort),g_NvrUserName,g_NvrPassword);
	}

	DHDEV_SYSTEM_ATTR_CFG sysConfigInfo = {0};
    DWORD  dwRetLen = 0;
    int nVideoStandard = 0;
	int bRet = CLIENT_GetDevConfig(nvrcontrol.m_lLoginHandle, DH_DEV_DEVICECFG,nChannelID, &sysConfigInfo, sizeof(DHDEV_SYSTEM_ATTR_CFG), &dwRetLen, 3000);
	
    if (bRet && dwRetLen == sizeof(DHDEV_SYSTEM_ATTR_CFG))
    {
        nVideoStandard = sysConfigInfo.byVideoStandard;
    }
	CFG_ENCODE_INFO *pstEncode = new CFG_ENCODE_INFO;
    memset(pstEncode, 0, sizeof(CFG_ENCODE_INFO));
	BOOL bSuccess = CLIENT_GetNewDevConfig(nvrcontrol.m_lLoginHandle, CFG_CMD_ENCODE, nChannelID, pTemp, dwTempLen, &nError, 5000);		
    if (bSuccess)
    {
        int nRetLen = 0;
        
        //解析
        nRet  = CLIENT_ParseData(CFG_CMD_ENCODE, (char *)pTemp, pstEncode, sizeof(CFG_ENCODE_INFO), &nRetLen);
        if (TRUE != nRet)
        {
            cout << "解析视频通道数据失败" << endl;
        }
		if(nRet == 0)
		{
			nRet = -1;
		}
		else
		{
			nRet = 0;
		}
    }
    else
    {
        cout << "获取视频通道配置失败" << endl;
    }

    int nHign = 0;
    int nWidth = 0;
    nHign = pstEncode->stuMainStream->stuVideoFormat.nHeight;
    nWidth = pstEncode->stuMainStream->stuVideoFormat.nWidth;

    // 算出当前的分辨率
    int nCurResolution = ResolutionInttoSize(nWidth, nHign, nVideoStandard);
	ResoluRatio = rsName[nCurResolution];
	frame =pstEncode->stuMainStream->stuVideoFormat.nFrameRate;
	int nCurcompression = pstEncode->stuMainStream->stuVideoFormat.emCompression;
	CodeMode = compression[nCurcompression];
	stream = pstEncode->stuMainStream->stuVideoFormat.nBitRate;
	nvrcontrol.DM_Logout(nvrcontrol.m_lLoginHandle);
	nvrcontrol.DM_Cleanup();

	return nRet;
}

BOOL JudgeResolution(char *pcResolution, int nLen, int *nWidth, int *nHeight, int nVideoStandard)
{
    if (0 == strncmp(pcResolution, "D1", nLen))
    {
        ResolutionSizetoInt(0, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "HD1", nLen))
    {
        ResolutionSizetoInt(1, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "BCIF", nLen))
    {
        ResolutionSizetoInt(2, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "CIF", nLen))
    {
        ResolutionSizetoInt(3, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "QCIF", nLen))
    {
        ResolutionSizetoInt(4, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "VGA", nLen))
    {
        ResolutionSizetoInt(5, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "QVGA", nLen))
    {
        ResolutionSizetoInt(6, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "SVCD", nLen))
    {
        ResolutionSizetoInt(7, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "QQVGA", nLen))
    {
        ResolutionSizetoInt(8, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "SVGA", nLen))
    {
        ResolutionSizetoInt(9, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "XVGA", nLen))
    {
        ResolutionSizetoInt(10, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "WXGA", nLen))
    {
        ResolutionSizetoInt(11, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "SXGA", nLen))
    {
        ResolutionSizetoInt(12, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "WSXGA", nLen))
    {
        ResolutionSizetoInt(13, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "UXGA", nLen))
    {
        ResolutionSizetoInt(14, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "WUXGA", nLen))
    {
        ResolutionSizetoInt(15, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "LFT", nLen))
    {
        ResolutionSizetoInt(16, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "720", nLen))
    {
        ResolutionSizetoInt(17, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "1080", nLen))
    {
        ResolutionSizetoInt(18, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "1_3M", nLen))
    {
        ResolutionSizetoInt(19, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "2M", nLen))
    {
        ResolutionSizetoInt(20, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "5M", nLen))
    {
        ResolutionSizetoInt(21, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "3M", nLen))
    {
        ResolutionSizetoInt(22, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "5_0M", nLen))
    {
        ResolutionSizetoInt(23, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "1_2M", nLen))
    {
        ResolutionSizetoInt(24, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "1408_1024", nLen))
    {
        ResolutionSizetoInt(25, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "8M", nLen))
    {
        ResolutionSizetoInt(26, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "2560_1920", nLen))
    {
        ResolutionSizetoInt(27, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "960H", nLen))
    {
        ResolutionSizetoInt(28, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "960_720", nLen))
    {
        ResolutionSizetoInt(29, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "NHD", nLen))
    {
        ResolutionSizetoInt(30, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }
    if (0 == strncmp(pcResolution, "QNHD", nLen))
    {
        ResolutionSizetoInt(31, nWidth, nHeight, nVideoStandard);
        return TRUE;
    }

    return FALSE;
}

int ipccontrol::DM_SetIpcVedioQuality(int nAudiNU,int nDevicePo,string ResoluRatio,int frame,string CodeMode,int stream)
{
	int nRet = 0;
	char szCurReslution[64] = {0};
	///自动设置下帧率最小默认值为5.0
	float fFrameRate = 5.0;
	int nWidth = 0;
	int nHeight = 0;
	int nError = 0;
	NvrControl nvrcontrol;
	DWORD dwTempLen = 50*1024;
	char *pTemp = new char[dwTempLen];
	CFG_ENCODE_INFO *pstEncode = new CFG_ENCODE_INFO;
    memset(pstEncode, 0, sizeof(CFG_ENCODE_INFO));
	NET_DEVICEINFO stDevInfo = {0};
	int nChannelID = 0;
	nRet = DM_GetIpcInfo(nAudiNU,nDevicePo,nChannelID);
	nRet = nvrcontrol.DM_InitSDK();
	int isping_ok;
	CFileManager filemanger;
	filemanger.PingIsOk(g_NvrIP,&isping_ok);
	if(!isping_ok )
	{
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "ping nvr ip failed ");
		g_ipc_logwrite.PrintLog(MyLogger::INFO,"%s",buff_temp);
		return -1;
	}
	else
	{
		//test
		string ip = g_NvrIP;
		string username = g_NvrUserName;
		string password = g_NvrPassword;
		nRet = nvrcontrol.DM_Login(ip,atoi(g_NvrPort),username,password);
		//test
		//nRet = nvrcontrol.DM_Login(g_NvrIP,atoi(g_NvrPort),g_NvrUserName,g_NvrPassword);
	}


	int len = 0;
	BOOL  b3GProtocol = FALSE;
	DH_DEV_ENABLE_INFO stDevEn = {0};
	BOOL bRet = CLIENT_QuerySystemInfo(nvrcontrol.m_lLoginHandle, ABILITY_DEVALL_INFO, (char*)&stDevEn, sizeof(DH_DEV_ENABLE_INFO), &len);
	if (bRet&&len == sizeof(DH_DEV_ENABLE_INFO))
	{
		if (stDevEn.IsFucEnable[EN_JSON_CONFIG]!=0 || stDevInfo.byChanNum> 32)
		{       
			b3GProtocol = TRUE;
		}
		else
		{       
			b3GProtocol = FALSE;
		}
	}
	int nChannelCount = stDevInfo.byChanNum;
	cout << nChannelCount <<endl;
	DHDEV_CHANNEL_CFG *pChannelInfo = new DHDEV_CHANNEL_CFG[nChannelCount];
	if(b3GProtocol == true)
	{

		DHDEV_SYSTEM_ATTR_CFG sysConfigInfo = {0};
		DWORD  dwRetLen = 0;
		int nVideoStandard = 0;
		int bRet = CLIENT_GetDevConfig(nvrcontrol.m_lLoginHandle, DH_DEV_DEVICECFG,nChannelID, &sysConfigInfo, sizeof(DHDEV_SYSTEM_ATTR_CFG), &dwRetLen, 3000);
	
		if (bRet && dwRetLen == sizeof(DHDEV_SYSTEM_ATTR_CFG))
		{
			nVideoStandard = sysConfigInfo.byVideoStandard;
		}
		//szCurReslution = ResoluRatio.c_str();
		memset(szCurReslution,0,sizeof(szCurReslution));
		sprintf(szCurReslution,"%s",ResoluRatio.c_str());
		nRet = JudgeResolution(szCurReslution, 64, &nWidth, &nHeight, nVideoStandard);
		if(nRet == 0)
		{
			nRet = -1;
		}
		else
		{
			nRet = 0;
		}
		char * compression[10] = {"MPEG4","MS_MPEG4","MPEG2",
								  "MPEG1","H263","MJPG",
									"FCC_MPEG4","H264","H265",
									"SVAC"};
		pstEncode->stuMainStream->stuVideoFormat.nHeight = nHeight;
		pstEncode->stuMainStream->stuVideoFormat.nWidth = nWidth;
		fFrameRate = frame;
		pstEncode->stuMainStream->stuVideoFormat.nFrameRate = fFrameRate;
		pstEncode->stuMainStream->stuVideoFormat.abBitRate = stream;
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MPEG4"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_MPEG4;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MS_MPEG4"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_MS_MPEG4;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MPEG2"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_MPEG2;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MPEG1"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_MPEG1;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_H263"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_H263;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MJPG"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_MJPG;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_FCC_MPEG4"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_FCC_MPEG4;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_H264"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_H264;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_H265"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_H265;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_SVAC"))
		{
			pstEncode->stuMainStream->stuVideoFormat.emCompression = VIDEO_FORMAT_SVAC;
		}


		bRet = CLIENT_PacketData(CFG_CMD_ENCODE, pstEncode, sizeof(CFG_ENCODE_INFO), pTemp, dwTempLen);
		if (TRUE != bRet)
		{
			cout << "封装通道配置报文失败" << endl;
		}

		int bRestart = 0;
		bRet = CLIENT_SetNewDevConfig(nvrcontrol.m_lLoginHandle, CFG_CMD_ENCODE, nChannelID, pTemp, dwTempLen, &nError, &bRestart, 3000);
		if(bRet != true)
		{
			cout << "set ipc vedio quality failed!"<<endl;
			nRet = -1;
		}
	}
	else
	{
		DWORD dwRetLen = 0;
		if (pChannelInfo == NULL)
		{
			goto _out;
		}
		memset(pChannelInfo, 0, nChannelCount*sizeof(DHDEV_CHANNEL_CFG));
		BOOL bSuccess = CLIENT_GetDevConfig(nvrcontrol.m_lLoginHandle, DH_DEV_CHANNELCFG, -1, pChannelInfo, nChannelCount * sizeof(DHDEV_CHANNEL_CFG), &dwRetLen);
		if (!(bSuccess&&dwRetLen == nChannelCount * sizeof(DHDEV_CHANNEL_CFG)))
		{
			printf("CLIENT_GetDevConfig: DH_DEV_CHANNELCFG failed!\n");                                                                                                          
		}

		pChannelInfo[nChannelID].stMainVideoEncOpt[0].byFramesPerSec = frame;//修改帧率
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MPEG4"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_MPEG4;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MS_MPEG4"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_MS_MPEG4;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MPEG2"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_MPEG2;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MPEG1"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_MPEG1;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_H263"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_H263;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_MJPG"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_MJPG;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_FCC_MPEG4"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_FCC_MPEG4;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_H264"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_H264;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_H265"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_H265;
		}
		if(!strcmp(CodeMode.c_str(),"VIDEO_FORMAT_SVAC"))
		{
			pChannelInfo[nChannelID].stMainVideoEncOpt[0].byEncodeMode = VIDEO_FORMAT_SVAC;
		}

		memset(szCurReslution,0,sizeof(szCurReslution));
		sprintf(szCurReslution,"%s",ResoluRatio.c_str());
		//nRet = JudgeResolution(szCurReslution, 64, &nWidth, &nHeight, nVideoStandard);
		pChannelInfo[nChannelID].stMainVideoEncOpt[0].byImageSize  = CAPTURE_SIZE_D1;
		pChannelInfo[nChannelID].stMainVideoEncOpt[0].wLimitStream = stream;

		bSuccess = CLIENT_SetDevConfig(nvrcontrol.m_lLoginHandle, DH_DEV_CHANNELCFG,nChannelID, pChannelInfo, nChannelCount * sizeof(DHDEV_CHANNEL_CFG));
		if (bSuccess == FALSE)
		{
			printf("CLIENT_SetDevConfig: DH_DEV_CHANNELCFG failed!\n");
		}
		delete []pChannelInfo;
	}
_out:
	nvrcontrol.DM_Logout(nvrcontrol.m_lLoginHandle);
	nvrcontrol.DM_Cleanup();
	return nRet;
}

int ipccontrol::NewSpaceDeviceIPCInfo(DEV_IPC_INFO **pdeviceipcinfo)
{
	int nRet = 0;
	IpcTable iTable;
	if(NULL != *pdeviceipcinfo)
	{
		return nRet;
	}
	*pdeviceipcinfo = new DEV_IPC_INFO;
	(*pdeviceipcinfo)->pipcitem = NULL;
	iTable.NewSpaceIpc(&((*pdeviceipcinfo)->pipcitem));
	return nRet;
}

int ipccontrol::DeleteSpaceDeviceIPCInfo(DEV_IPC_INFO **pdeviceipcinfo)
{
	int nRet = 0;
	IpcTable iTable;
	if(NULL == (*pdeviceipcinfo))
	{
		return nRet;
	}
	iTable.DeleteSpaceIpc(&((*pdeviceipcinfo)->pipcitem));
	if(NULL != (*pdeviceipcinfo))
	{
		delete (*pdeviceipcinfo);
		*pdeviceipcinfo = NULL;
	}
	return nRet;
}

int ipccontrol::ZeroSpaceDeviceIPCInfo(DEV_IPC_INFO * pdeviceipcinfo)
{
	int nRet = 0;
	IpcTable iTable;
	if(NULL == pdeviceipcinfo)	
	{
		return nRet;
	}
	iTable.ZeroSpaceIpc(pdeviceipcinfo->pipcitem);
	return nRet;
}

int ipccontrol::DeleteSpaceIPCInfos(DEV_IPC_INFOS *pipcinfos)
{
	int ret = 0;
	if(NULL == pipcinfos)
	{
		return ret;
	}
	if(pipcinfos->size() > 0)
	{
		for(int i = 0; i<pipcinfos->size(); i++)
		{
			DEV_IPC_INFO *ptemp = (DEV_IPC_INFO *)((*pipcinfos)[i]);
			DeleteSpaceDeviceIPCInfo(&ptemp);
		}
		pipcinfos->clear();
	}
	return ret;
}

int ipccontrol::ZeroSpaceIPCInfos(DEV_IPC_INFOS *pipcinfos)
{
	int ret = 0;
	if(NULL == pipcinfos)
	{
		return ret;
	}

	if(pipcinfos->size() > 0)
	{
		for(int i = 0; i<pipcinfos->size(); i++)
		{
			DEV_IPC_INFO *ptemp = (DEV_IPC_INFO *)((*pipcinfos)[i]);
			ZeroSpaceDeviceIPCInfo(ptemp);
		}
	}
	return ret;
}

int ipccontrol::GetIPCErrorString(int errorcode,REPORT_STATUS *preportstatus)
{
	int nRet = 0;
	memset(preportstatus,0,sizeof(preportstatus));
	sprintf(preportstatus->status,"failed");
	sprintf(preportstatus->error_code_str,"%d",errorcode);
	sprintf(preportstatus->level,"error");
	sprintf(preportstatus->module,"nvr");
	switch(errorcode)
	{
	case URL_IPCCONTROL_SETIPCINFO_ERROR:
		sprintf(preportstatus->message,"ipc module,set ipc info error!");
		sprintf(preportstatus->message_la,"ipc 模块,设置ipc信息失败!");
		break;
	case URL_IPCCONTROL_GETIPCINFO_ERROR:
		sprintf(preportstatus->message,"ipc module,get ipc info error!");
		sprintf(preportstatus->message_la,"ipc 模块，获取ipc信息失败!");
		break;
	default:
		sprintf(preportstatus->status,"successful");
		sprintf(preportstatus->error_code_str,"%d",errorcode);
		sprintf(preportstatus->message,"is successful");
		sprintf(preportstatus->message_la,"successful!");
		sprintf(preportstatus->level,"successful");
		sprintf(preportstatus->module,"ipc");
		break;
	}
	return nRet;
}