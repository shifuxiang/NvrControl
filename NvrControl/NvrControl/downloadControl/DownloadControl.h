#ifndef DOWNLOAD_CONTROL_H
#define DOWNLOAD_CONTROL_H
#include <iostream>
#include <vector>
#include "../so/dhnetsdk.h"
#include "../so/dhplay.h"
//#include "Download_Table.h"
#include "DownloadControl_Struct.h"
//#include "../Nvr/Nvr_Control.h"
#include"../Nvr_Ret.h"
#include"../Nvr_Types.h"
typedef struct DM_DownLoadInfo
{
	int id;
	std::string cinemaName;
	std::string HallNo;
	int pos;
	std::string state;
	std::string start_time;
	std::string end_time;
	std::string ipcIP;

}DM_DownLoadInfo;
typedef std::vector<DM_DownLoadInfo > * PDM_DownLoadInfos;
typedef std::vector<DM_DownLoadInfo > DM_DownLoadInfos;
//class NvrControl;
class downLoad
{
public:
	downLoad();
	~downLoad();
	/***************************************************\
	�������ܣ�����ָ��Nvr�������ٶ�
	����1��Nvr��id
	����ֵ���ɹ�����0,ʧ�ܷ�������ֵ
	\***************************************************/
	int DM_SetNvrDownloadSpeed(int id,bool isOK);

	/***************************************************\
	�������ܣ���ʱ������ָ��Nvr��ָ������ͷ��¼�Ƶ���Ƶ�ļ�
	����1��ָ��Nvr��id
	����2��Ӱ����
	����3������ͷλ�ã�0��ʾǰ�ã�1��ʾ����
	����4����ʼ����ʱ��
	����5����������ʱ��
	����6: ����·��
	����ֵ���ɹ�����0��ʧ�ܷ�������ֵ
	\***************************************************/
	int DM_DownLoadByTime(int id,int nAudiNU,int nDevicePo,NET_TIME tmStart,NET_TIME  tmEnd,string storePath,string mp4name);

	/***************************************************\
	�������ܣ���ȡȫ�����ؼ�¼
	����1�����ؼ�¼��Ϣ
	����ֵ���ɹ�����0��ʧ�ܷ�������ֵ
	\***************************************************/
	int DM_GetDownLoadInfo(DOWNLOAD_INFOS * downloadInfos);
	/***************************************************\
	�������ܣ���ʱ���ȡ���ؼ�¼
	����1����ʼʱ��
	����2������ʱ��
	����3�����ؼ�¼��Ϣ
	����ֵ���ɹ�����0��ʧ�ܷ�������ֵ
	\***************************************************/
	int DM_GetDownLoadInfo(std::string start_time,std::string end_time,DOWNLOAD_INFOS * downloadInfo);

	/****************************************************\
	�������ܣ�����״̬��ȡ������Ϣ
	����1��������Ϣ
	����ֵ���ɹ�����0��ʧ�ܷ�������ֵ
	\****************************************************/
	int DM_GetDownloadInfoByState(DOWNLOAD_INFOS *pDownloadInfos);

	/****************************************************\
	ת������
	ת����������ݿ�
	\****************************************************/
	int DM_Convert();

	/****************************************************\
	�������ܣ���ȡ��ǰ�������ص�ԭʼ�ļ�������
	����1����ǰ��������ԭʼ�ļ�������
	����ֵ���ɹ�����0��ʧ�ܷ�������ֵ
	\****************************************************/
	int DM_GetDownLoadInfoCountByStateAndIpcIP(int &count);

	/****************************************************\
	�������ܣ�ͨ��sql����ȡ������Ϣ
	����1��sql���
	����2��������Ϣ
	����ֵ���ɹ�����0��ʧ�ܷ�������ֵ
	\****************************************************/
	int DM_GetDownloadInfoBySql(string sql,DOWNLOAD_INFO *pDownloadInfo);


	/***************************************************\
	�������ܣ�����Nvr����״̬��������״̬Ϊ��ʱ����
			��ǰ�������ص�����Ϊfailed
	��������
	����ֵ���ɹ�����0��ʧ�ܷ�������ֵ��
	add by sfx modify if  net is disconnect set download state to failed 2017.6.6
	\***************************************************/
	int DM_SetState();

	int DM_GetErrorString();
public:
	int NewSpaceDeviceDownloadInfo(DOWNLOAD_INFO **pDownloadInfo);
	//
	int DeleteSpaceDeviceDownloadInfo(DOWNLOAD_INFO **pDownloadInfo);
	//
    int ZeroSpaceDeviceDownloadInfo(DOWNLOAD_INFO * pDownloadInfo);
	//
	int DeleteSpaceDownloadInfos(DOWNLOAD_INFOS *pDownloadInfos);
	//
	int ZeroSpaceDownloadInfos(DOWNLOAD_INFOS *pDownloadInfos);
	long long m_downloadID;

public:
	int GetDownloadErrorString(int errorcode,REPORT_STATUS *preportstatus);
private:
	//NvrControl m_nvrcontrol;
	//NvrControl m_nvrcontrol1;
	bool isOK1;
	bool isOK2;
	//DOWNLOAD_ITEM_TBL * pDownloadItem;
	downloadtable downloadTable;

	
	
#if 0
	int m_ChannelID;
	int m_DownloadID;
	LPNET_TIME m_start_time;
	LPNET_TIME m_end_time;
#endif
};


#endif