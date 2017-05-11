#include <iostream>
#include <unistd.h>
#include <string>
#include "./database/CppMySQL3DB.h"
#include "./threadManage/C_CS.h"
#include "./threadManage/C_ThreadData.h"
#include "./threadManage/C_ThreadManage.h"
//#include "./webservice/stdsoap2.h"
//#include "./webservice/stlvector.h"
//#include "./webservice/webservice.h"
//#include "./webservice/C_SoapServer.h"

using namespace std;
string g_NVRIP;
string g_NVRUserName;
string g_NVRPassword;
string g_NVRPort;

int main(int argc,char ** argv)
{
	int nRet = 0;
	
	C_ThreadManage *pThreadMessage = C_ThreadManage::GetInstance();
	nRet = pThreadMessage->InitThreadData();
	nRet = pThreadMessage->InitWebserviceThread();
	if(nRet != 0)
	{
		return nRet;
	}
	
	


	while(true)
	{
		sleep(60);
	}
	
	C_ThreadManage::DestoryInstance();
	cout << "jjjjjjjjjjjjjjjjjjjjjjjjjjj"<<endl;
	return nRet;
}
