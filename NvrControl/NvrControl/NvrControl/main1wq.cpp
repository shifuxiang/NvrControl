#include <iostream>
#include <unistd.h>
#include <string>
#include "../database/CppMySQL3DB.h"
#include "../threadManage/C_CS.h"
#include "../threadManage/C_ThreadData.h"
#include "../threadManage/C_ThreadManage.h"

string g_NVRIP;
string g_NVRUserName;
string g_NVRPassword;
string g_NVRPort;



using namespace std;

int main(int argc,char ** argv)
{
	int nRet = 0;
	C_ThreadManage *pThreadMessage = C_ThreadManage::GetInstance();
	nRet = pThreadMessage->InitWebserviceThread();
	if(nRet != 0)
	{
		return nRet;
	}
	
	


	while(true)
	{
		sleep(60);
	}
	

	return nRet;
}