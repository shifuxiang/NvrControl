#include "ipcControl_Table.h"
#include "../Nvr_Ret.h"

IpcTable::IpcTable()
{

}
IpcTable::~IpcTable()
{

}

int IpcTable::GetIPCInfos(IPC_ITEMS_TBL * pIpcs)
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
	sprintf(sql,"select * from ipc");
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	pres = MysqlUseResult(conn);
	column_count = sizeof(m_ipc_column_value_map) / sizeof(m_ipc_column_value_map[0]);
	while((row = MysqlFetchRow(pres)) != NULL)
	{
		//MapItemVarToArray(pIpc);
		for(column_index = 0;column_index < column_count;column_index++)
		{
			if(NULL != row[column_index])
			{
				strcpy(m_ipc_column_value_map[column_index].pvalue_var,(char *)row[column_index]);
			}
		}
	}

	MysqlFreeResult(pres);	
	nRet = DisConnected(&conn);
	return nRet;
}

int IpcTable::GetIpcInfoByHallNoAndPosition(int HallNO,int position,IPC_ITEM_TBL * pIpcInfo)
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
	sprintf(sql,"select * from ipc where HallNo = '%d' and ipcPosition = '%d' ",HallNO,position);
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	pres = MysqlUseResult(conn);
	column_count = sizeof(m_ipc_column_value_map) / sizeof(m_ipc_column_value_map[0]);
	while((row = MysqlFetchRow(pres)) != NULL)
	{
		//MapItemVarToArray(pIpc);
		//IPC_ITEM_TBL *pIpcItemTable = NULL;
		NewSpaceIpc(&pIpcInfo);
		MapItemVarToArray(pIpcInfo);
		for(column_index = 0;column_index < column_count;column_index++)
		{
			if(NULL != row[column_index])
			{
				strcpy(m_ipc_column_value_map[column_index].pvalue_var,(char *)row[column_index]);
			}

		}

	}

	MysqlFreeResult(pres);	
	nRet = DisConnected(&conn);

	return nRet;
}

int IpcTable::GetIpcInfoById(int id,IPC_ITEM_TBL * pIpcInfo)
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
	sprintf(sql,"select * from ipc where id = '%d' ",id);
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	pres = MysqlUseResult(conn);
	column_count = sizeof(m_ipc_column_value_map) / sizeof(m_ipc_column_value_map[0]);
	while((row = MysqlFetchRow(pres)) != NULL)
	{
		//MapItemVarToArray(pIpc);
		for(column_index = 0;column_index < column_count;column_index++)
		{
			if(NULL != row[column_index])
			{
				strcpy(m_ipc_column_value_map[column_index].pvalue_var,(char *)row[column_index]);
			}
		}
	}

	MysqlFreeResult(pres);	
	nRet = DisConnected(&conn);
	return nRet;
}

int IpcTable::InsertIpcInfo(IPC_ITEM_TBL* ipcinfo)
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
	sprintf(sql,"insert into ipc (cinemaName,HallNo,ipcPosition,frameRate,CBR,resolvingRate,decodeMode,ip,username,password,mode,port,channelID) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')",
		ipcinfo->cinemaName,
		ipcinfo->HallNo,
		ipcinfo->ipcPosition,
		ipcinfo->frameRate,
		ipcinfo->CBR,
		ipcinfo->resolvingRate,
		ipcinfo->decodeMode,
		ipcinfo->ip,
		ipcinfo->username,
		ipcinfo->password,
		ipcinfo->mode,
		ipcinfo->port,
		ipcinfo->channelID);
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	nRet = DisConnected(&conn);
	return nRet;
}

int IpcTable::UpdateIpcInfo(int id,string columnName,string coumnValue)
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
	sprintf(sql,"update ipc set  %s = '%s' where id = '%d'",columnName.c_str(),coumnValue.c_str(),id);
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	nRet = DisConnected(&conn);
	return nRet;
}

int IpcTable::DeleteIpcInfoByHallNoAndPosition(int HallNo,int position)
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
	sprintf(sql,"delete from ipc where HallNo = '%d' and position = '%d'",HallNo,position);
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	return nRet;
}

int IpcTable::DeleteIpcInfoById(int id)
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
	sprintf(sql,"delete from ipc where id = '%d'",id);
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	return nRet;
}

int IpcTable::DeleteAllIpc()
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
	sprintf(sql,"delete from ipc");
	if(MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}
	return nRet;
}

void IpcTable::NewSpaceIpc(IPC_ITEM_TBL**ipcinfo)
{
	if((*ipcinfo) != NULL)
	{
		return ;
	}
	*ipcinfo = new IPC_ITEM_TBL;
	(*ipcinfo)->id = (char *)new char[11];
	(*ipcinfo)->cinemaName = (char *)new char[255];
	(*ipcinfo)->HallNo = (char *)new char[11];
	(*ipcinfo)->ipcPosition = (char *)new char[11];
	(*ipcinfo)->frameRate = (char *)new char[11];
	(*ipcinfo)->CBR = (char *)new char[11];
	(*ipcinfo)->resolvingRate = (char *)new char[255];
	(*ipcinfo)->decodeMode = (char *)new char[255];
	(*ipcinfo)->ip = (char *)new char[255];
	(*ipcinfo)->port	    = (char *)new char[255];
	(*ipcinfo)->username = (char *)new char[255];
	(*ipcinfo)->password	    = (char *)new char[255];
	(*ipcinfo)->mode = (char *)new char[255];
	(*ipcinfo)->channelID = (char *)new char[11];

	ZeroSpaceIpc(*ipcinfo);	
}

void IpcTable::DeleteSpaceIpc(IPC_ITEM_TBL**ipcinfo)
{
	if((*ipcinfo) == NULL)
	{
		return;
	}
	ZeroSpaceIpc(*ipcinfo);
	if((*ipcinfo)->id != NULL)
	{
		delete[] (*ipcinfo)->id;
		(*ipcinfo)->id = NULL;
	}
	if((*ipcinfo)->CBR != NULL)
	{
		delete[] (*ipcinfo)->CBR;
		(*ipcinfo)->CBR = NULL;
	}
	if((*ipcinfo)->cinemaName != NULL)
	{
		delete[] (*ipcinfo)->cinemaName;
		(*ipcinfo)->cinemaName = NULL;
	}
	if((*ipcinfo)->decodeMode != NULL)
	{
		delete [] (*ipcinfo)->decodeMode;
		(*ipcinfo)->decodeMode = NULL;
	}
	if((*ipcinfo)->frameRate != NULL)
	{
		delete[] (*ipcinfo)->frameRate;
		(*ipcinfo)->frameRate = NULL;
	}
	if((*ipcinfo)->HallNo != NULL)
	{
		delete[] (*ipcinfo)->HallNo;
		(*ipcinfo)->HallNo = NULL;
	}
	if((*ipcinfo)->ip != NULL)
	{
		delete[] (*ipcinfo)->ip;
		(*ipcinfo)->ip = NULL;
	}
	if((*ipcinfo)->ipcPosition != NULL)
	{       
		delete[] (*ipcinfo)->ipcPosition;
		(*ipcinfo)->ipcPosition = NULL;
	}
	if((*ipcinfo)->mode != NULL)
	{
		delete[] (*ipcinfo)->mode;
		(*ipcinfo)->mode = NULL;
	}
	if((*ipcinfo)->password != NULL)
	{
		delete[] (*ipcinfo)->password;
		(*ipcinfo)->password = NULL;
	}
	if((*ipcinfo)->port != NULL)
	{
		delete[] (*ipcinfo)->port;
		(*ipcinfo)->port = NULL;
	}
	if((*ipcinfo)->resolvingRate != NULL)
	{
		delete[] (*ipcinfo)->resolvingRate;
		(*ipcinfo)->resolvingRate = NULL;
	}
	if((*ipcinfo)->username != NULL)
	{
		delete[] (*ipcinfo)->username;
		(*ipcinfo)->username = NULL;
	}
	if((*ipcinfo)->channelID != NULL)
	{
		delete[] (*ipcinfo)->channelID;
		(*ipcinfo)->channelID = NULL;
	}
	if(*ipcinfo != NULL)
	{
		delete[] *ipcinfo;
		*ipcinfo = NULL;
	}

}

void IpcTable::ZeroSpaceIpc(IPC_ITEM_TBL*pipcinfo)
{
	if((pipcinfo)->CBR != NULL)
	{
		memset(pipcinfo->CBR,0,11);
	}
	if((pipcinfo)->cinemaName != NULL)
    {
		memset((pipcinfo)->cinemaName,0,255);
    }
	if((pipcinfo)->decodeMode != NULL)
    {
		memset((pipcinfo)->decodeMode,0,255);
    }
	if((pipcinfo)->frameRate != NULL)
    {
		memset((pipcinfo)->frameRate,0,11);
    }
	if((pipcinfo)->HallNo != NULL)
    {       
		memset((pipcinfo)->HallNo,0,11);
    }
	if((pipcinfo)->id != NULL)
    {
		memset((pipcinfo)->id,0,11);
    }
	if((pipcinfo)->ip != NULL)
    {
		memset((pipcinfo)->ip,0,255);
    }
	if((pipcinfo)->ipcPosition != NULL)
    {
		memset((pipcinfo)->ipcPosition ,0,11);
    }
	if((pipcinfo)->mode != NULL)
    {
		memset((pipcinfo)->mode ,0,255);
    }
	if((pipcinfo)->password != NULL)
	{
		memset((pipcinfo)->password,0,255);
	}
	if((pipcinfo)->port != NULL)
    {
		memset((pipcinfo)->port ,0,255);
    }
	if((pipcinfo)->resolvingRate != NULL)
    {
		memset((pipcinfo)->resolvingRate ,0,255);
    }
	if((pipcinfo)->username != NULL)
	{
		memset((pipcinfo)->username,0,255);
	}
	if((pipcinfo)->channelID != NULL)
	{
		memset((pipcinfo)->channelID,0,11);
	}
}

int IpcTable::MapItemVarToArray(IPC_ITEM_TBL *pItem)
{
	int ret = 0;
	if(NULL != pItem)
	{
		m_ipc_column_value_map[0].pvalue_var = pItem->id;
		m_ipc_column_value_map[1].pvalue_var = pItem->cinemaName;
		m_ipc_column_value_map[2].pvalue_var = pItem->HallNo;
		m_ipc_column_value_map[3].pvalue_var = pItem->ipcPosition;
		m_ipc_column_value_map[4].pvalue_var = pItem->frameRate;
		m_ipc_column_value_map[5].pvalue_var = pItem->CBR;
		m_ipc_column_value_map[6].pvalue_var = pItem->resolvingRate;
		m_ipc_column_value_map[7].pvalue_var = pItem->decodeMode;
		m_ipc_column_value_map[8].pvalue_var = pItem->ip;
		m_ipc_column_value_map[9].pvalue_var = pItem->username;
		m_ipc_column_value_map[10].pvalue_var = pItem->password;
		m_ipc_column_value_map[11].pvalue_var = pItem->mode;
		m_ipc_column_value_map[12].pvalue_var = pItem->port;
		m_ipc_column_value_map[13].pvalue_var = pItem->channelID;
	}
	return ret;
}