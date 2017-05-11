#ifndef _I_NVRCONTROL_H
#define _I_NVRCONTROL_H
#include <iostream>
#include <stdlib.h>
#include "../so/dhnetsdk.h"
using namespace std;

class INvrControl
{
public:
	virtual ~iNvrControl(){};

public:
	virtual int DM_InitSDK() = 0;
	virtual int DM_Login(char * ipaddress,
						long port,
						char * username,
						char * password)=0;

	virtual int DM_Logout(LLONG lLoginID)=0;
	virtual void DM_CleanUp();

protected:

private:
};

#endif