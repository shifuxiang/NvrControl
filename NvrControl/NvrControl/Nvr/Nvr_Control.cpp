#include "Nvr_Control.h"
#include "../myLog/MyLogger.h"
#include <string.h>
#include "../Nvr_Ret.h"
extern int g_LoginHandle;
extern MyLogger g_nvr_logwrite;

void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
        cout <<"device disconn" <<endl;
}
int NvrControl::DM_InitSDK()
{
	int nRet = 0;
	nRet = CLIENT_Init(DisConnectFunc,0);
	return nRet;
}

//int NvrControl::DM_Login(char *NvrIP,WORD Port,char *UserName,char *Password)
int NvrControl::DM_Login(string NvrIP,WORD Port,string UserName,string Password)
{
	int nRet = 0;
	int nError = 0;
	NET_DEVICEINFO stDevInfo = {0};
	m_lLoginHandle = CLIENT_Login(NvrIP.c_str(),Port,UserName.c_str(),Password.c_str(),&stDevInfo,&nError);
	m_nStDevInfoNu = stDevInfo.byChanNum;
	g_LoginHandle = m_lLoginHandle;
	if(0 == m_lLoginHandle)
	{
		nRet = URL_NVRLOGIN_ERROR;
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "login failed");
		g_nvr_logwrite.PrintLog(MyLogger::INFO,"%s,error num is: %d",buff_temp,nRet);
		cout << "loin failed!"<<endl;
		//nRet = -1;
		
	}
	else
	{
		nRet = 0;
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "login success");
		g_nvr_logwrite.PrintLog(MyLogger::INFO,"%s,error num is:%d",buff_temp,nRet);
		cout << "login success !"<<endl;
	}
	return nRet;
}

int NvrControl::DM_Logout(LLONG lLoginID)
{
	int nRet = 0;
	nRet = CLIENT_Logout(m_lLoginHandle);
	if(nRet <= 0)
	{
		//nRet = -1;
		nRet = URL_NVRLOGOUT_ERROR;
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "logout failed");
		g_nvr_logwrite.PrintLog(MyLogger::INFO,"%s,error num is:%d",buff_temp,nRet);
		cout<<"logout failed!"<<endl;
	}
	else
	{
		nRet = 0;
		char buff_temp[255] = {'\0'};
		memset(buff_temp, 0, sizeof(buff_temp));
		sprintf(buff_temp, "logout success");
		g_nvr_logwrite.PrintLog(MyLogger::INFO,"%s,error num is:%d",buff_temp,nRet);
		cout << "logout successful!"<<endl;
	}
	return nRet;
}

void NvrControl::DM_Cleanup()
{
	CLIENT_Cleanup();
}


int NvrControl::GetNvrErrorString(int errorcode,REPORT_STATUS *preportstatus)
{
	int nRet = 0;
	memset(preportstatus,0,sizeof(preportstatus));
	sprintf(preportstatus->status,"failed");
	sprintf(preportstatus->error_code_str,"%d",errorcode);
	sprintf(preportstatus->level,"error");
	sprintf(preportstatus->module,"nvr");
	switch(errorcode)
	{
	case URL_NVRLOGIN_ERROR:
		sprintf(preportstatus->message,"nvr module,login nvr error!");
		sprintf(preportstatus->message_la,"nvr Ä£¿é,µÇÂ¼nvrÊ§°Ü!");
		break;
	case URL_NVRLOGOUT_ERROR:
		sprintf(preportstatus->message,"nvr module,logout nvr error!");
		sprintf(preportstatus->message_la,"nvr Ä£¿é£¬µÇ³önvrÊ§°Ü!");
		break;
	default:
		sprintf(preportstatus->status,"successful");
		sprintf(preportstatus->error_code_str,"%d",errorcode);
		sprintf(preportstatus->message,"is successful");
		sprintf(preportstatus->message_la,"successful!");
		sprintf(preportstatus->level,"successful");
		sprintf(preportstatus->module,"nvr");
		break;
	}
	return nRet;
}