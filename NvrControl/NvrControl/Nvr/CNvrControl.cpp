#include "CNvrControl.h"
#include "Nvr_Control.h"

CNvrControl::CNvrControl()
{
	m_PNvrControl = NULL;
}

CNvrControl::~CNvrControl()
{
}

int CNvrControl::CreateControl(int type)
{
	int nRet = 0;
	if(type == 1)
	{
		m_PNvrControl = new NvrControl();
	}
	return nRet;
}

int CNvrControl::DM_InitSDK()
{
	int nRet = 0;
	nRet = m_PNvrControl->DM_InitSDK();
	return nRet;
}

int CNvrControl::DM_Login(char *NvrIP,WORD Port,char *UserName,char *Password)
{
	int nRet = 0;

	nRet = m_PNvrControl->DM_Login(NvrIP,Port,UserName,Password);
	return nRet;
}

int CNvrControl::DM_Logout(LLONG lLoginID)
{
	int nRet = 0;
	nRet = m_PNvrControl->DM_Logout(lLoginID);
	return nRet;
}

void CNvrControl::DM_Cleanup()
{
	m_PNvrControl->DM_CleanUp();
}


