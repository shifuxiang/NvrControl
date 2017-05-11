#include "Download_Table.h"

COLUMN_VALUE_MAP g_download_column_value_map[]=
{
	{"id",NULL},
	{"cinemaName",NULL},
	{"HallNo",NULL},
	{"IPCPosotion",NULL},
	{"state",NULL},
	{"startTime",NULL},
	{"endTime",NULL},
	{"ipcIp",NULL},
	{"DownLoadID",NULL},
	{"filename",NULL},
	{"mp4filename",NULL},
	{"covertstate",NULL},
	{"avifilename",NULL},
	{"loginHandle",NULL},
};

downloadtable::downloadtable()
{
	CopyMapArray(m_download_column_value_map,g_download_column_value_map,sizeof(g_download_column_value_map)/sizeof(g_download_column_value_map[0]));
}
downloadtable::~downloadtable()
{

}


int downloadtable::insertDownloadInfo(DOWNLOAD_ITEM_TBL * pItem)
{
	int nRet = 0;
	char sql[BUFF_SIZE_2048] = {'\0'};
	int column_count = 0;
	int column_index = 0;
	MYSQL *conn = NULL;
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;
	nRet = Connect(&conn);
	if(nRet != 0)
	{
		return nRet;
	}
	memset(&sql,0,sizeof(sql));
	sprintf(sql,"insert into downLoad (cinemaName,HallNo,IPCPosotion,state,startTime,endTime,ipcIp,DownLoadID,filename,mp4filename,covertstate,avifilename,loginHandle) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')",
		pItem->cinemaName,
		pItem->HallNo,
		pItem->IPCPosition,
		pItem->state,
		pItem->starttime,
		pItem->endtime,
		pItem->ipcIP,
		pItem->downloadID,
		pItem->filename,
		pItem->mp4filename,
		pItem->covertstate,
		pItem->avifilename,
		pItem->loginHandle);
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	nRet = DisConnected(&conn);
	return nRet;
}

int downloadtable::updateDownloadInfoByDownloadID(string columnName,string columnValue,long long downloadID)
{
	int nRet = 0;
	char sql[BUFF_SIZE_255] = {'\0'};
	int column_count = 0;
	int column_index = 0;
	MYSQL *conn = NULL;
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;
	nRet = Connect(&conn);
	if(nRet != 0)
	{
		return nRet;
	}
	memset(&sql,0,sizeof(sql));
	sprintf(sql,"update downLoad set  %s = '%s' where DownLoadID = '%lld'",columnName.c_str(),columnValue.c_str(),downloadID);
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	nRet = DisConnected(&conn);
	return nRet;
}

int downloadtable::updateDownloadInfoByid(int id,string columnName,string columnValue)
{
	int nRet = 0;
	char sql[BUFF_SIZE_255] = {'\0'};
	int column_count = 0;
	int column_index = 0;
	MYSQL *conn = NULL;
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;
	nRet = Connect(&conn);
	if(nRet != 0)
	{
		return nRet;
	}
	memset(&sql,0,sizeof(sql));
	sprintf(sql,"update downLoad set `%s`='%s' where `id`='%d'",columnName.c_str(),columnValue.c_str(),id);
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	nRet = DisConnected(&conn);
	return nRet;
}

int downloadtable::GetDownloadInfoBystate(DOWNLOAD_ITEMS_TBL & downloadinfos)
{
	int nRet = 0;
	char sql[BUFF_SIZE_255] = {'\0'};
	int column_count = 0;
	int column_index = 0;
	MYSQL *conn = NULL;
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;
	nRet = Connect(&conn);
	if(nRet != 0)
	{
		return nRet;
	}
	memset(&sql,0,sizeof(sql));
	//sprintf(sql,"select * from downLoad where state = 'end' and  covertstate = '0'");
	sprintf(sql,"select * from downLoad where state = 'end' and  ipcIp = ' '");
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	pres = MysqlUseResult(conn);
	column_count = sizeof(m_download_column_value_map) / sizeof(m_download_column_value_map[0]);
	while((row = MysqlFetchRow(pres)) != NULL)
	{
		//MapItemVarToArray(pIpc);
		DOWNLOAD_ITEM_TBL * downloadItem = NULL;
		NewSpaceDownload(&downloadItem);
		MapItemVarToArray(downloadItem);
		for(column_index = 0;column_index < column_count;column_index++)
		{
			if(NULL != row[column_index])
			{
				strcpy(m_download_column_value_map[column_index].pvalue_var,(char *)row[column_index]);
			}
		}
		downloadinfos.push_back(downloadItem);
	}

	MysqlFreeResult(pres);	
	nRet = DisConnected(&conn);
	return nRet;
}


int downloadtable::GetAllDownloadInfo(DOWNLOAD_ITEMS_TBL & downloadinfos)
{
	int nRet = 0;
	char sql[BUFF_SIZE_255] = {'\0'};
	int column_count = 0;
	int column_index = 0;
	MYSQL *conn = NULL;
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;
	nRet = Connect(&conn);
	if(nRet != 0)
	{
		return nRet;
	}
	memset(&sql,0,sizeof(sql));
	//sprintf(sql,"select * from downLoad where state = 'end' and  covertstate = '0'");
	sprintf(sql,"select * from downLoad");
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	pres = MysqlUseResult(conn);
	column_count = sizeof(m_download_column_value_map) / sizeof(m_download_column_value_map[0]);
	while((row = MysqlFetchRow(pres)) != NULL)
	{
		//MapItemVarToArray(pIpc);
		DOWNLOAD_ITEM_TBL * downloadItem = NULL;
		NewSpaceDownload(&downloadItem);
		MapItemVarToArray(downloadItem);
		for(column_index = 0;column_index < column_count;column_index++)
		{
			if(NULL != row[column_index])
			{
				strcpy(m_download_column_value_map[column_index].pvalue_var,(char *)row[column_index]);
			}
		}
		downloadinfos.push_back(downloadItem);
	}

	MysqlFreeResult(pres);	
	nRet = DisConnected(&conn);
	return nRet;
}

int downloadtable::GetLatestInsertId(int &id)
{
	int nRet = 0;
	char sql[512] = {'\0'};
	MYSQL *conn = NULL;			
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;
	int column_count = 0;
	int column_index = 0;


	nRet = Connect(&conn);
	if( 0 != nRet)
	{
		return nRet;
	}
	memset(sql,0,512);
	//sprintf(sql,"SELECT LAST_INSERT_ID()");
	sprintf(sql,"select max(id) from downLoad");
	if (MysqlQuery(&conn,sql)) 
	{
        DisConnected(&conn);
		return -1;
	}
	pres = MysqlUseResult(conn);

	if ((row = MysqlFetchRow(pres)) != NULL)
	{

		if(NULL != row[0])
		{
			//strcpy(m_logs_column_value_map[0].column_name,(char *)row[0]);
			id = atoi((char *)row[0]);
		}
	}

	MysqlFreeResult(pres);
	nRet = DisConnected(&conn);
	return nRet;
}

int downloadtable::GetDownloadInfoBySql(string sql,DOWNLOAD_ITEMS_TBL & downloadinfos)
{
	int nRet = 0;
	char sql_temp[BUFF_SIZE_255] = {'\0'};
	int column_count = 0;
	int column_index = 0;
	MYSQL *conn = NULL;
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;
	nRet = Connect(&conn);
	if(nRet != 0)
	{
		return nRet;
	}
	memset(&sql_temp,0,sizeof(sql_temp));
	//sprintf(sql,"select * from downLoad where state = 'end' and  covertstate = '0'");
	sprintf(sql_temp,"%s",sql.c_str());
	if(MysqlQuery(&conn,sql_temp))
	{
		DisConnected(&conn);
		return -1;
	}
	pres = MysqlUseResult(conn);
	column_count = sizeof(m_download_column_value_map) / sizeof(m_download_column_value_map[0]);
	while((row = MysqlFetchRow(pres)) != NULL)
	{
		//MapItemVarToArray(pIpc);
		DOWNLOAD_ITEM_TBL * downloadItem = NULL;
		NewSpaceDownload(&downloadItem);
		MapItemVarToArray(downloadItem);
		for(column_index = 0;column_index < column_count;column_index++)
		{
			if(NULL != row[column_index])
			{
				strcpy(m_download_column_value_map[column_index].pvalue_var,(char *)row[column_index]);
			}
		}
		downloadinfos.push_back(downloadItem);
	}

	MysqlFreeResult(pres);	
	nRet = DisConnected(&conn);
	return nRet;
}

int downloadtable::GetDownloadInfoBySql(string sql,DOWNLOAD_ITEM_TBL *downloadinfo)
{
	int nRet = 0;
	char sql_temp[BUFF_SIZE_255] = {'\0'};
	int column_count = 0;
	int column_index = 0;
	MYSQL *conn = NULL;
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;
	nRet = Connect(&conn);
	if(nRet != 0)
	{
		return nRet;
	}
	memset(&sql_temp,0,sizeof(sql_temp));
	sprintf(sql_temp,"%s",sql.c_str());
	if(MysqlQuery(&conn,sql_temp))
	{
		DisConnected(&conn);
		return -1;
	}
	pres = MysqlUseResult(conn);
	column_count = sizeof(m_download_column_value_map) / sizeof(m_download_column_value_map[0]);
	while((row = MysqlFetchRow(pres)) != NULL)
	{
		NewSpaceDownload(&downloadinfo);
		MapItemVarToArray(downloadinfo);
		for(column_index = 0;column_index < column_count;column_index++)
		{
			if(NULL != row[column_index])
			{
				strcpy(m_download_column_value_map[column_index].pvalue_var,(char *)row[column_index]);
			}
		}
	}
	MysqlFreeResult(pres);	
	nRet = DisConnected(&conn);
	return nRet;
}

int downloadtable::MapItemVarToArray(DOWNLOAD_ITEM_TBL *pItem)
{
	int ret = 0;
	if(NULL != pItem)
	{
		m_download_column_value_map[0].pvalue_var = pItem->id;
		m_download_column_value_map[1].pvalue_var = pItem->cinemaName;
		m_download_column_value_map[2].pvalue_var = pItem->HallNo;
		m_download_column_value_map[3].pvalue_var = pItem->IPCPosition;
		m_download_column_value_map[4].pvalue_var = pItem->state;
		m_download_column_value_map[5].pvalue_var = pItem->starttime;
		m_download_column_value_map[6].pvalue_var = pItem->endtime;
		m_download_column_value_map[7].pvalue_var = pItem->ipcIP;
		m_download_column_value_map[8].pvalue_var = pItem->downloadID;
		m_download_column_value_map[9].pvalue_var = pItem->filename;
		m_download_column_value_map[10].pvalue_var = pItem->mp4filename;
		m_download_column_value_map[11].pvalue_var = pItem->covertstate;
		m_download_column_value_map[12].pvalue_var = pItem->avifilename;
		m_download_column_value_map[13].pvalue_var = pItem->loginHandle;
	}
	return ret;
}
void downloadtable:: NewSpaceDownload(DOWNLOAD_ITEM_TBL**downloadinfo)
{
	if((*downloadinfo) != NULL)
	{
		return ;
	}
	*downloadinfo = new DOWNLOAD_ITEM_TBL;
	(*downloadinfo)->cinemaName = (char *)new char[255];
	(*downloadinfo)->covertstate = (char *)new char[11];
	(*downloadinfo)->downloadID = (char *)new char[11];
	(*downloadinfo)->endtime = (char *)new char[255];
	(*downloadinfo)->filename = (char *)new char[255];
	(*downloadinfo)->HallNo = (char *)new char[255];
	(*downloadinfo)->id = (char *)new char[11];
	(*downloadinfo)->ipcIP = (char *)new char[255];
	(*downloadinfo)->IPCPosition = (char *)new char[11];
	(*downloadinfo)->mp4filename  = (char *)new char[255];
	(*downloadinfo)->starttime = (char *)new char[255];
	(*downloadinfo)->state	    = (char *)new char[255];
	(*downloadinfo)->avifilename = (char *)new char[255];
	(*downloadinfo)->loginHandle = (char *)new char[11];
	ZeroSpaceDownload(*downloadinfo);	
}

void downloadtable::DeleteSpaceDownload(DOWNLOAD_ITEM_TBL**downloadinfo)
{
	if((*downloadinfo) == NULL)
	{
		return;
	}
	//ZeroSpaceCp850(*pcp850info);
	ZeroSpaceDownload(*downloadinfo);
	if((*downloadinfo)->cinemaName != NULL)
	{
		delete[] (*downloadinfo)->cinemaName;
		(*downloadinfo)->cinemaName = NULL;
	}
	if((*downloadinfo)->covertstate != NULL)
	{
		delete[] (*downloadinfo)->covertstate;
		(*downloadinfo)->covertstate = NULL;
	}
	if((*downloadinfo)->downloadID != NULL)
	{
		delete[] (*downloadinfo)->downloadID;
		(*downloadinfo)->downloadID = NULL;
	}
	if((*downloadinfo)->endtime != NULL)
	{
		delete [] (*downloadinfo)->endtime;
		(*downloadinfo)->endtime = NULL;
	}
	if((*downloadinfo)->filename != NULL)
	{
		delete[] (*downloadinfo)->filename;
		(*downloadinfo)->filename = NULL;
	}
	if((*downloadinfo)->HallNo != NULL)
	{
		delete[] (*downloadinfo)->HallNo;
		(*downloadinfo)->HallNo = NULL;
	}
	if((*downloadinfo)->id != NULL)
	{
		delete[] (*downloadinfo)->id;
		(*downloadinfo)->id = NULL;
	}
	if((*downloadinfo)->ipcIP != NULL)
	{       
		delete[] (*downloadinfo)->ipcIP;
		(*downloadinfo)->ipcIP = NULL;
	}
	if((*downloadinfo)->IPCPosition != NULL)
	{
		delete[] (*downloadinfo)->IPCPosition;
		(*downloadinfo)->IPCPosition = NULL;
	}
	if((*downloadinfo)->mp4filename != NULL)
	{
		delete[] (*downloadinfo)->mp4filename;
		(*downloadinfo)->mp4filename = NULL;
	}
	if((*downloadinfo)->starttime != NULL)
	{
		delete[] (*downloadinfo)->starttime;
		(*downloadinfo)->starttime = NULL;
	}
	if((*downloadinfo)->state != NULL)
	{
		delete[] (*downloadinfo)->state;
		(*downloadinfo)->state = NULL;
	}
	if((*downloadinfo)->avifilename != NULL)
	{
		delete[] (*downloadinfo)->avifilename;
		(*downloadinfo)->avifilename = NULL;
	}
	if((*downloadinfo)->loginHandle != NULL)
	{
		delete[] (*downloadinfo)->loginHandle;
		(*downloadinfo)->loginHandle = NULL;
	}
	if((*downloadinfo) != NULL)
	{
		delete [] *downloadinfo;
		*downloadinfo = NULL;
	}
}

void downloadtable::ZeroSpaceDownload(DOWNLOAD_ITEM_TBL*downloadinfo)
{
	if((downloadinfo)->cinemaName != NULL)
	{
		memset(downloadinfo->cinemaName,0,255);
	}
	if((downloadinfo)->covertstate != NULL)
    {
		memset((downloadinfo)->covertstate,0,11);
    }
	if((downloadinfo)->downloadID != NULL)
    {
		memset((downloadinfo)->downloadID,0,11);
    }
	if((downloadinfo)->endtime != NULL)
    {
		memset((downloadinfo)->endtime,0,255);
    }
	if((downloadinfo)->filename != NULL)
    {       
		memset((downloadinfo)->filename,0,255);
    }
	if((downloadinfo)->HallNo != NULL)
    {
		memset((downloadinfo)->HallNo,0,255);
    }
	if((downloadinfo)->id != NULL)
    {
		memset((downloadinfo)->id,0,11);
    }
	if((downloadinfo)->ipcIP != NULL)
    {
		memset((downloadinfo)->ipcIP ,0,255);
    }
	if((downloadinfo)->IPCPosition != NULL)
    {
		memset((downloadinfo)->IPCPosition ,0,11);
    }
	if((downloadinfo)->mp4filename!= NULL)
	{
		memset((downloadinfo)->mp4filename,0,255);
	}
	if((downloadinfo)->starttime != NULL)
    {
		memset((downloadinfo)->starttime ,0,255);
    }
	if((downloadinfo)->state != NULL)
    {
		memset((downloadinfo)->state ,0,255);
    }
	if((downloadinfo)->avifilename != NULL)
	{
		memset((downloadinfo)->avifilename,0,255);
	}
	if((downloadinfo)->loginHandle != NULL)
	{
		memset((downloadinfo)->loginHandle,0,11);
	}
}

void downloadtable::DeleteSpaceDownloads(DOWNLOAD_ITEMS_TBL * downloadinfos)
{
	if(NULL == downloadinfos)
	{
		return ;
	}
	if(downloadinfos->size() > 0)
	{
		for(int i = 0; i<downloadinfos->size(); i++)
		{
			DOWNLOAD_ITEM_TBL *pItem = (DOWNLOAD_ITEM_TBL *)((*downloadinfos)[i]);
			DeleteSpaceDownload(&pItem);
		}
		downloadinfos->clear();
	}
}