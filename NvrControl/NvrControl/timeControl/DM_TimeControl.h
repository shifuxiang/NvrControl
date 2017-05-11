#ifndef TIMECONTROL_H
#define TIMECONTROL_H
#include <iostream>
#include "../so/dhnetsdk.h"
#include "../Nvr/Nvr_Control.h"
#include "../Nvr_Types.h"
#include "../Nvr_Ret.h"
using namespace std;


typedef struct timeStruct
{
	unsigned int unYear;
	unsigned int unMonth;
	unsigned int unDay;
	unsigned int unHour;
	unsigned int unMinute;
	unsigned int unSecond;
}timeStruct;
class timeControl
{
public:
	timeControl();
	~timeControl();
	/*******************************************************\
	函数功能：查询设备当前时间(该函数用于设置系统时间前获取系统时间)
	参数1：查询到的当前时间
	返回值：成功返回0，失败返回其他值
	\*******************************************************/
	 int GetSystemTime(timeStruct & timeInfo);

	 /******************************************************\
	 函数功能：设置设备时间
	 参数1：时间信息
	 返回值成功返回0,失败返回其他值
	 \******************************************************/
	 int SetSystemTime(timeStruct  timeInfo);

	 /******************************************************\
	 函数功能：初始化操作
	 \******************************************************/
	 int DM_Init();
	 /******************************************************\
	 函数功能：释放操作
	 \******************************************************/
	 int DM_Release();

	/*******************************************************\
	函数功能：设置NTP
	参数1：使能开关
	参数2：IP地址或网络名	
	参数3：端口号
	参数4：更新周期
	返回值：成功返回0，失败返回其他值
	\*******************************************************/
	int SetNvtServer(bool isOK,string ip,int port,int updatePeriod);
public:
	int GetTimeControlErrorString(int errorcode,REPORT_STATUS *preportstatus);
protected:
private:
	NvrControl m_nvrcontrol;

};


#endif