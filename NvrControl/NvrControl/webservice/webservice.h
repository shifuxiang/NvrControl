#import "stlvector.h"

#include <vector>
#include <iostream>

struct mons__get1
{
	int i;
};
int mons__GetoneInfos(struct mons__get1 &ret);
struct mons__SetDLSpeedResponse
{
	bool isTrue;
};
int mons__SetDlSpeed(bool isOK,struct mons__SetDLSpeedResponse &ret);

struct mons__DownloadTime
{
	unsigned int dwYear;
	unsigned int dwMonth;
	unsigned int dwDay;
	unsigned int dwHour;
	unsigned int dwMinute;
	unsigned int dwSecond;
};
struct mons__DownloadTimeResponse
{
	//long long downloadID;
	int id;
	std::string fileNameMp4;
	bool isOK;
};
int mons__DownLoadByTime(int id,int nAudiNU,int nDevicePo,struct mons__DownloadTime tmStart,
							struct mons__DownloadTime  tmEnd,std::string storePath,std::string mp4name,
							struct mons__DownloadTimeResponse &ret);

struct mons__IPCINFO
{
	int HallNo;
	int ipcPo;
	int channelID;
};
struct mons__SetIpcInfoRes
{
	bool isOK;
};
int mons__SetIpcInfo(int HallNo,int ipcPo,int channelID,struct mons__SetIpcInfoRes &ret);

struct mons__GetSystemTimeRes
{
	unsigned int unYear;
	unsigned int unMonth;
	unsigned int unDay;
	unsigned int unHour;
	unsigned int unMinute;
	unsigned int unSecond;
};
int mons__GetSystemTimeInfo(struct mons__GetSystemTimeRes &ret);

struct mons__SetSystemtimeInfo
{
	unsigned int unYear;
	unsigned int unMonth;
	unsigned int unDay;
	unsigned int unHour;
	unsigned int unMinute;
	unsigned int unSecond;
};
struct mons__SetSystemInfoRes
{
	bool isOK;
};
int mons__SetSystemTime(struct mons__SetSystemtimeInfo timeInfos,struct mons__SetSystemInfoRes &ret);

struct mons__InitRes
{
	bool isOK;
};
int mons__DInit(struct mons__InitRes &ret);

struct mons__ReleaseRes
{
	bool isOK;
};
int mons__DRelease(struct mons__ReleaseRes &ret);

//get ipc support resolving power
struct mons__GetIpcResoluRatioInfo
{
	std::vector<std::string> ResoluRatios;
};
int mons__GetIpcResoluRatio(int nAudiNU,int nDevicePo,struct mons__GetIpcResoluRatioInfo &ret);

//get ipc vedio quailty
struct mons__GetIpcVedioQualityInfo
{
	std::string ResoluRatio;
	int frame;
	std::string CodeMode;
	int stream;
};
struct mons__GetIpcVedioQualityInfoRes
{
	struct mons__GetIpcVedioQualityInfo vedioQuality;
};
int mons__GetIpcVedioQuality(int nAudiNU,int nDevicePo,struct mons__GetIpcVedioQualityInfoRes &ret);

struct mons__SetIpcVedioQualityInfo
{
	std::string ResoluRatio;
	int frame;
	std::string CodeMode;
	int stream;
};

struct mons__SetIpcVedioQualityInfoRes
{
	bool isOK;
};
int mons__SetIpcVedioQuality(int nAudiNU,int nDevicePo,struct mons__SetIpcVedioQualityInfo vedioInfo,struct mons__SetIpcVedioQualityInfoRes &ret);





