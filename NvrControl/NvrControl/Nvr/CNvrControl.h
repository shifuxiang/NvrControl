#ifndef _C_NVRCONTROL_H
#define _C_NVRcONTROL_H
#include "INvrControl.h"


class CNvrControl
{
public:
	CNvrControl();
	~CNvrControl();
public:
	int CreateControl(int type);
	int DM_InitSDK();
	int DM_Login(char *NvrIP,WORD Port,char *UserName,char *Password);
	int DM_Logout(LLONG lLoginID);
	void DM_Cleanup();
protected:
private:
	INvrControl * m_PNvrControl;
};

#endif