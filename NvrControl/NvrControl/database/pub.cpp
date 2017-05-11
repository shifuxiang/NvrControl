#include "./pub.h"
#include <stdlib.h>

extern char g_db_ip[50];
extern char g_db_username[50];
extern char g_db_password[50];
extern char g_db_dbname[50];

typedef struct _COLUMN_VALUE_MAPA
{
	char column_name[BUFF_SIZE_50];
	char *pvalue_var;
}COLUMN_VALUE_MAPA;
extern ec_config g_config;

PubFun::PubFun()
{
}

PubFun::~PubFun()
{
}


int PubFun::FillSqlBufferByCondition(char* sql ,VEC_QUERY_VALUE sql_value,SQL_CONDITION_RULE sql_rule)
{
    int ret = 0;
	char  temp_sql[BUFF_SIZE_2048];
	char  sub_sql[BUFF_SIZE_2048];
	memset(temp_sql, 0, BUFF_SIZE_2048);
	memset(sub_sql, 0, BUFF_SIZE_2048);
	int vec_first_position = 0;
	int last_condistion_site =  sql_value.size() - 1;
	for(int i = vec_first_position; sql_value.size() > i; i++)
	{
		if (i == vec_first_position)
		{

            if(strcmp(sql, "") == 0  && strcmp(sql_value[vec_first_position].table_name, "") != 0)
			{
				sprintf(sql, "select * from %s  where", sql_value[vec_first_position].table_name);

			}
            else
            {
                ret = -1;
            }

		}

      //  if (sql_value[i].cloume_value2 != '\0' && sql_value[i].cloume_value2 != '\0')
        if(strcmp(sql_value[i].cloume_value1, "" ) != 0  &&  strcmp(sql_value[i].cloume_value2, "") != 0 )
        {
			sprintf(temp_sql, " (`%s` ", sql_value[i].cloume_name);
            strcat(sub_sql, temp_sql);
			sprintf(temp_sql, " %s", sql_value[i].cloume_condition1);
			strcat(sub_sql, temp_sql);
			sprintf(temp_sql, " \"%s\"", sql_value[i].cloume_value1);
			strcat(sub_sql, temp_sql);
			sprintf(temp_sql, " %s", sql_value[i].inside_relation);
			strcat(sub_sql, temp_sql);
			sprintf(temp_sql, " `%s`", sql_value[i].cloume_name);
			strcat(sub_sql, temp_sql);
			sprintf(temp_sql, " %s", sql_value[i].cloume_condition2);
			strcat(sub_sql, temp_sql);
			sprintf(temp_sql, " \"%s\" )", sql_value[i].cloume_value2);
			strcat(sub_sql, temp_sql);
			if(last_condistion_site != i)
			{
				sprintf(temp_sql, " %s", sql_value[i].outside_relation);
				strcat(sub_sql, temp_sql);
			}
		}
	}
    if (sql_rule.order_cloume[0] !=  '\0' && sql_rule.order != '\0')
	{
		sprintf(temp_sql, " order by `%s` %s ", sql_rule.order_cloume, sql_rule.order);
		strcat(sub_sql, temp_sql);
	}
    if(sql_rule.limit_max[0] != '\0' && sql_rule.limit_min[0] != '\0')
	{
		sprintf(temp_sql, " limit %s , %s ", sql_rule.limit_min, sql_rule.limit_max);
		strcat(sub_sql, temp_sql);
	}
	strcat(sql, sub_sql);	
	char temp_sql_test[2048] = {0};
	sprintf(temp_sql_test, "select * from log ");
	return 0;
}

int PubFun::FillSqlBufferByStr(char *sql, char* str)
{
	int ret = 0;

    if(str != NULL &&  sql != NULL)
    {
        strcat(sql, str);
    }

	return ret;
}

int PubFun::FillCondition(VEC_QUERY_VALUE query,char* tablename, char* cloumename, char* condition1, char* value1, char *conditon2, char* value2, char* in_relation, char* out_relation
												, char*  order_name, char* order, char* limitemin, char* limitemax)
{
	int ret = 0;	
	SQL_CONDITION_VALUE str_value;
	SQL_CONDITION_RULE str_rule;
	memset(&str_value, 0, sizeof(SQL_CONDITION_RULE));
	memset(&str_rule, 0, sizeof(SQL_CONDITION_VALUE));
	sprintf(str_value.table_name, tablename);
	sprintf(str_value.cloume_name, cloumename);
	sprintf(str_value.cloume_condition1, condition1);
	sprintf(str_value.cloume_value1, value1);
	sprintf(str_value.cloume_condition2, conditon2);
	sprintf(str_value.cloume_value2, value2);
	sprintf(str_value.inside_relation, in_relation);
	sprintf(str_value.outside_relation, out_relation);

	if(strcmp(order_name, "") != 0 || strcmp(order, "") != 0)
	{
		sprintf(str_rule.order_cloume, order_name);
		sprintf(str_rule.order, order);
	}

	if(strcmp(limitemin, "") != 0 || strcmp(limitemax, "") != 0)
	{
		sprintf(str_rule.limit_min, limitemin);
		sprintf(str_rule.limit_max, limitemax);
	}
		
	query.push_back(str_value);
	return ret;
}

int PubFun::GetDataBaseInfoFromConfigFile(char *pdbname,
												char *pipaddress,
												char *pusername,
												char *ppassword)
{
	int ret = 0;
	
	char sec_name[BUFF_SIZE_50];
	char configfilepath[BUFF_SIZE_255];
	memset(sec_name,0,sizeof(sec_name));
	memset(configfilepath,0,sizeof(configfilepath));
	sprintf(sec_name,"DB_INFO");
	sprintf(configfilepath,"./NvrControl.ini");
	g_config.readvalue(sec_name,"db_name",pdbname,configfilepath);
	sprintf(g_db_dbname,"%s",pdbname);
	g_config.readvalue(sec_name,"db_ip",pipaddress,configfilepath);
	sprintf(g_db_ip,"%s",pipaddress);
	//g_config.readvalue(sec_name,"db_port",pdbname,configfilepath);
	g_config.readvalue(sec_name,"db_username",pusername,configfilepath);
	sprintf(g_db_username,"%s",pusername);
	g_config.readvalue(sec_name,"db_password",ppassword,configfilepath);
	sprintf(g_db_password,"%s",ppassword);
	return ret;
}

int PubFun::MysqlQuery(MYSQL **conn,const char *psql)
{
	int ret = 0;
	int istry_ok = 0;
	int retry_counter = 30;
	int index = 0;
	int sql_len = 0;
	char *prompt_buff_1 = NULL;
	char prompt_buff[BUFF_SIZE_2048]={'\0'};
	//sms_timeconvert timeconvert;
	//CFileManager filemanager;

	sql_len = strlen(psql);

	if(sql_len>(BUFF_SIZE_2048-512))
	{
		prompt_buff_1 = new char[sql_len+512];
		memset(prompt_buff_1,0,sql_len+512);
	}
	//else
	//{
	//	memset(prompt_buff,0,sizeof(prompt_buff));
	//}

	//if(!g_iscanconnected_database)
	//{
		//return DB_CONNECTED_ERROR;
	//}


	for(int index = 0; index < retry_counter; index++)
	{
		if(NULL == *conn)
		{
			if(sql_len>(BUFF_SIZE_2048-512))
			{
#if 0
				memset(prompt_buff_1,0,sql_len+512);
				sprintf(prompt_buff_1,"error:\n");
				sprintf(prompt_buff_1,"%s database ip:%s\n",prompt_buff_1,g_database_ip);
				sprintf(prompt_buff_1,"%s database name:%s\n",prompt_buff_1,g_database_dbname);
				sprintf(prompt_buff_1,"%s database username:%s\n",prompt_buff_1,g_database_username);
				sprintf(prompt_buff_1,"%s database password:%s\n",prompt_buff_1,g_database_password);
				sprintf(prompt_buff_1,"%s conn is null,query database error:%u: %s,trycounter:%d/%d\n",prompt_buff_1,mysql_errno(*conn), mysql_error(*conn),index,retry_counter);
				sprintf(prompt_buff_1,"%s sql:%s\n",prompt_buff_1,psql);
				g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff_1);
#endif
			}
			else
			{
#if 0
				memset(prompt_buff,0,sizeof(prompt_buff));
				sprintf(prompt_buff,"error:\n");
				sprintf(prompt_buff,"%s database ip:%s\n",prompt_buff,g_database_ip);
				sprintf(prompt_buff,"%s database name:%s\n",prompt_buff,g_database_dbname);
				sprintf(prompt_buff,"%s database username:%s\n",prompt_buff,g_database_username);
				sprintf(prompt_buff,"%s database password:%s\n",prompt_buff,g_database_password);
				sprintf(prompt_buff,"%s conn is null,query database error:%u: %s,trycounter:%d/%d\n",prompt_buff,mysql_errno(*conn), mysql_error(*conn),index,retry_counter);
				sprintf(prompt_buff,"%s sql:%s\n",prompt_buff,psql);
				g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff);
#endif

			}



			DisConnected(conn);
			sleep(1);
			Connect(conn);

			if(NULL == *conn)
			{
				sleep(1);
				continue;
			}

		}


		if (mysql_query(*conn, psql))
		{
			if(sql_len>(BUFF_SIZE_2048-512))
			{
#if 0
				memset(prompt_buff_1,0,sql_len+512);
				sprintf(prompt_buff_1,"error:\n");
				sprintf(prompt_buff_1,"%s database ip:%s\n",prompt_buff_1,g_database_ip);
				sprintf(prompt_buff_1,"%s database name:%s\n",prompt_buff_1,g_database_dbname);
				sprintf(prompt_buff_1,"%s database username:%s\n",prompt_buff_1,g_database_username);
				sprintf(prompt_buff_1,"%s database password:%s\n",prompt_buff_1,g_database_password);
				sprintf(prompt_buff_1,"%s query database error:%u: %s,trycounter:%d/%d\n",prompt_buff_1,mysql_errno(*conn), mysql_error(*conn),index,retry_counter);
				sprintf(prompt_buff_1,"%s sql:%s\n",prompt_buff_1,psql);
				g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff_1);
#endif
			}
			else
			{
#if 0
				memset(prompt_buff,0,sizeof(prompt_buff));
				sprintf(prompt_buff,"error:\n");
				sprintf(prompt_buff,"%s database ip:%s\n",prompt_buff,g_database_ip);
				sprintf(prompt_buff,"%s database name:%s\n",prompt_buff,g_database_dbname);
				sprintf(prompt_buff,"%s database username:%s\n",prompt_buff,g_database_username);
				sprintf(prompt_buff,"%s database password:%s\n",prompt_buff,g_database_password);
				sprintf(prompt_buff,"%s query database error:%u: %s,trycounter:%d/%d\n",prompt_buff,mysql_errno(*conn), mysql_error(*conn),index,retry_counter);
				sprintf(prompt_buff,"%s sql:%s\n",prompt_buff,psql);
				g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff);
#endif
			}


			DisConnected(conn);
			sleep(1);
			
			ret = Connect(conn);
			if(0 != ret)
			{
				istry_ok = 0;
				return ret;
			}
			
			//return DB_COMMAND_QUERY_ERROR;

		}
		else
		{
			istry_ok = 1;
			break;
		}
	}

	if(NULL != prompt_buff_1)
	{
		delete [] prompt_buff_1;
		prompt_buff_1 = NULL;
	}

	if(!istry_ok)
	{
		return -1;
	}

	return ret;
}

MYSQL_RES *PubFun::MysqlUseResult(MYSQL *conn)
{
	int ret = 0;
	MYSQL_RES *pres = NULL;
	pres = mysql_use_result(conn);
	return pres;
}

MYSQL_ROW PubFun::MysqlFetchRow(MYSQL_RES *pres)
{
	return mysql_fetch_row(pres);
}

int PubFun::MysqlFreeResult(MYSQL_RES *pres)
{
	int ret = 0;
	mysql_free_result(pres);
	return ret;
}

int PubFun::Connect(MYSQL **conn)
{
	int ret = 0;
#if 0
	char server[BUFF_SIZE_255];
	char username[BUFF_SIZE_255];
	char password[BUFF_SIZE_255];
	char dbname[BUFF_SIZE_255];	
#endif
	char prompt_buff[BUFF_SIZE_1024]={'\0'};
	//sms_timeconvert timeconvert;
	int istry_ok = 0;
	int retry_counter = 30;
	int index = 0;

	//if(!g_iscanconnected_database)
	//{
		//return DB_CONNECTED_ERROR;
	//}

	istry_ok = 0;

	/// 初始化连接对象
	for(index = 0; index < retry_counter; index++)
	{

		*conn = mysql_init(NULL);

		if( NULL == *conn)
		{
#if 0
			memset(prompt_buff,0,sizeof(prompt_buff));
			sprintf(prompt_buff,"error:\n");
			sprintf(prompt_buff,"%s database ip:%s\n",prompt_buff,g_database_ip);
			sprintf(prompt_buff,"%s database name:%s\n",prompt_buff,g_database_dbname);
			sprintf(prompt_buff,"%s database username:%s\n",prompt_buff,g_database_username);
			sprintf(prompt_buff,"%s database password:%s\n",prompt_buff,g_database_password);
			sprintf(prompt_buff,"%s init connect database error:%u:%s,trycounter:%d/%d\n", prompt_buff,mysql_errno(*conn), mysql_error(*conn),index,retry_counter);
			DisConnected(conn);
			g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff);
#endif
			//msleep(1000);
			continue;
			//return DB_INIT_ERROR;
		}

		/// 连接数据库
		if (!mysql_real_connect(*conn, 
								g_db_ip,
								g_db_username,
								g_db_password,
								g_db_dbname, 
								0, 
								NULL, 
								0)) 
		{
#if 0
			memset(prompt_buff,0,sizeof(prompt_buff));
			sprintf(prompt_buff,"error:\n");
			sprintf(prompt_buff,"%s database ip:%s\n",prompt_buff,g_database_ip);
			sprintf(prompt_buff,"%s database name:%s\n",prompt_buff,g_database_dbname);
			sprintf(prompt_buff,"%s database username:%s\n",prompt_buff,g_database_username);
			sprintf(prompt_buff,"%s database password:%s\n",prompt_buff,g_database_password);
			sprintf(prompt_buff,"%s connect database error:%u: %s,trycounter:%d/%d\n", prompt_buff,mysql_errno(*conn), mysql_error(*conn),index,retry_counter);
			DisConnected(conn);
			g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff);
#endif
			//msleep(1000);
			//return DB_CONNECTED_ERROR;
		}
		else
		{
			if ( mysql_set_character_set( *conn, "utf8" )  != 0 )
			{
#if 0
				memset(prompt_buff,0,sizeof(prompt_buff));
				sprintf(prompt_buff,"error:\n");
				sprintf(prompt_buff,"%s database ip:%s\n",prompt_buff,g_database_ip);
				sprintf(prompt_buff,"%s database name:%s\n",prompt_buff,g_database_dbname);
				sprintf(prompt_buff,"%s database username:%s\n",prompt_buff,g_database_username);
				sprintf(prompt_buff,"%s database password:%s\n",prompt_buff,g_database_password);
				sprintf(prompt_buff,"%s failed to set character set to utf8:%u: %s\n", prompt_buff,mysql_errno(*conn), mysql_error(*conn));
				DisConnected(conn);
				g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff);
				//fprintf ( error_detail , "错误, %s/n" , mysql_error( *conn) ) ;
#endif
			}
			istry_ok = 1;
			break;
		}

	}

	if(!istry_ok)
	{
		ret = -1;
	}
	
	return ret;
}

int PubFun::DisConnected(MYSQL **conn)
{
	int ret = 0;
	//char prompt_buff[BUFF_SIZE_1024]={'\0'};

	if(NULL != *conn)
	{
		/// 断开数据库连接
		mysql_close(*conn);
		*conn = NULL;
	}
	return ret;
}

int PubFun::GetCountsBySql(char	*count, char *sqlbuffer)
{
    int ret=0;
    char sql[BUFF_SIZE_2048]={'\0'};
    int column_count = 0;
    int column_index = 0;
	MYSQL *conn = NULL;			
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;


   
    /// 连接数据库
    ret = Connect(&conn);
    if( 0 != ret)
    {
        return ret;
    }

    memset(sql,0,sizeof(sql));
    strcat(sql, sqlbuffer);

    /// 发送查询命令
	if (MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}

	pres = MysqlUseResult(conn);

	while((row = MysqlFetchRow(pres)) != NULL)
	{		
        //strcpy(count, (char *)row[0]);
        column_count++;
	}
    //itoa(column_count, count, 10);
    /// 释放结果
    MysqlFreeResult(pres);

    /// 断开数据库连接
    ret = DisConnected(&conn);
    return ret;
}

int PubFun::GetTableState(const char *tablename,int *pstate,char *pstata_desc,int maxlen_desc)
{
	int ret = 0;
	char sql[BUFF_SIZE_2048]={'\0'};
	int column_count = 0;
	int column_index = 0;
	MYSQL *conn = NULL;			
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;

	if( NULL == tablename ||
		(!strcmp(tablename,"")) ||
		NULL == pstate ||
		NULL == pstata_desc ||
		maxlen_desc <= 0)
	{
		return -1;
	}

	*pstate = 1;

	/// 连接数据库
	ret = Connect(&conn);
	if( 0 != ret)
	{
		return ret;
	}

	memset(sql,0,sizeof(sql));
	sprintf(sql,"check table %s fast quick",tablename);

	/// 发送查询命令
	if (MysqlQuery(&conn,sql))
	{
        
        DisConnected(&conn);
		return -1;
	}

	/// 获取结果
	pres = MysqlUseResult(conn);
	
	/// 获取结果中各信息项
	char table_column[BUFF_SIZE_50];
	char op_column[BUFF_SIZE_50];
	char msg_type[BUFF_SIZE_50];
	char msg_text[BUFF_SIZE_50];

	memset(table_column,0,sizeof(table_column));
	memset(op_column,0,sizeof(op_column));
	memset(msg_type,0,sizeof(msg_type));
	memset(msg_text,0,sizeof(msg_text));

	while ((row = MysqlFetchRow(pres)) != NULL)
	{		

		strcpy(table_column,(char *)row[0]);
		strcpy(op_column,(char *)row[1]);
		strcpy(msg_type,(char *)row[2]);
		strcpy(msg_text,(char *)row[3]);

		break;

	}

	memset(pstata_desc,0,maxlen_desc);
	sprintf(pstata_desc,"%s:%s:%s:%s",table_column,op_column,msg_type,msg_text);

	if((!strcmp(msg_text,"OK")) ||
		(!strcmp(msg_text,"Table is already up to date")))
	{
		*pstate = 0;
		/// 释放结果
		MysqlFreeResult(pres);

		/// 断开数据库连接
		ret = DisConnected(&conn);

		return 0;
	}
	
	/// 释放结果
	MysqlFreeResult(pres);
	
	
	/// 断开数据库连接
	ret = DisConnected(&conn);


	return -1;
}

int PubFun::GetOneRowBySql(char	*row_buffer, char *sqlbuffer)
{
    int ret=0;
    char sql[BUFF_SIZE_2048]={'\0'};
    int column_count = 0;
    int column_index = 0;
	MYSQL *conn = NULL;			
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;


   
    /// 连接数据库
    ret = Connect(&conn);
    if( 0 != ret)
    {
        return ret;
    }

    memset(sql,0,sizeof(sql));
    strcat(sql, sqlbuffer);

    /// 发送查询命令
	if (MysqlQuery(&conn,sql))
	{
		DisConnected(&conn);
		return -1;
	}

	pres = MysqlUseResult(conn);

	while((row = MysqlFetchRow(pres)) != NULL)
	{		
        strcpy(row_buffer, (char *)row[0]);
        
	}
    /// 释放结果
    MysqlFreeResult(pres);

    /// 断开数据库连接
    ret = DisConnected(&conn);
	
    return ret;
}

int PubFun::UpdateColumnValue(int id,const char *ptable,const char *pcolumn,const char *pvalue)
{
	int ret=0;
	char sql[BUFF_SIZE_2048]={'\0'};
	MYSQL *conn = NULL;			
	MYSQL_RES *pres = NULL;
	MYSQL_ROW row;

	if( id <=0 ||
		NULL == ptable ||
		(!strcmp(ptable,"")) ||
		NULL == pcolumn ||
		(!strcmp(pcolumn,"")) ||
		NULL == pvalue ||
		(!strcmp(pvalue,"")) )
	{
		return -1;
	}

	/// 连接数据库
	ret = Connect(&conn);
	if( 0 != ret)
	{
		return ret;
	}


	memset(sql,0,sizeof(sql));

	sprintf(sql,"update %s set `%s`='%s' where `id` = '%d'",
				ptable,
				pcolumn,
				pvalue,
				id);


	/// 发送查询命令
	if (MysqlQuery(&conn,sql)) 
	{
		
		DisConnected(&conn);
		return -1;
	}

	/// 断开数据库连接
	ret = DisConnected(&conn);

	return ret;
}

int PubFun::CopyMapArray(COLUMN_VALUE_MAP column_map_dest[],COLUMN_VALUE_MAP column_map_src[],int column_count)
{
	int ret;

	for(int i = 0;i<column_count;i++)
	{
		memset(column_map_dest[i].column_name,0,sizeof(column_map_dest[i].column_name));
		strcpy(column_map_dest[i].column_name,column_map_src[i].column_name);
		column_map_dest[i].pvalue_var = column_map_src[i].pvalue_var;
	}


	return ret;
}

#if 0
/// mysql 数据库链接池
Connection_T PubFun::ConnectionPool_getConnection_pool(ConnectionPool_T mysql_pool)
{
    Connection_T conn = NULL;
	char prompt_buff[BUFF_SIZE_1024]={'\0'};
	sms_timeconvert timeconvert;
    int i=0;

    conn = ConnectionPool_getConnection(mysql_pool);

    while(NULL == conn)
    {
        conn = ConnectionPool_getConnection(mysql_pool);

		printf("======================================================\n");
		memset(prompt_buff,0,sizeof(prompt_buff));
		sprintf(prompt_buff,"error:\n");
		sprintf(prompt_buff,"%s database ip:%s\n",prompt_buff,g_database_ip);
		sprintf(prompt_buff,"%s database name:%s\n",prompt_buff,g_database_dbname);
		sprintf(prompt_buff,"%s database username:%s\n",prompt_buff,g_database_username);
		sprintf(prompt_buff,"%s database password:%s\n",prompt_buff,g_database_password);
		sprintf(prompt_buff,"%s ConnectionPool_getConnection retry counter:%d,con:%08X\n", prompt_buff,i++,conn);
		g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff);

		printf("======================================================\n");
		sleep(1);
    }
    return conn;
}
ResultSet_T PubFun::Connection_executeQuery_pool(Connection_T con,const char *psql)
{
    ResultSet_T prset = NULL;
	char prompt_buff[BUFF_SIZE_2048]={'\0'};
	int retry_counter=0;
	int sql_len = 0;
	char *prompt_buff_1= NULL;
	sms_timeconvert timeconvert;
	CFileManager filemanager;

	sql_len = strlen(psql);

	if(sql_len>(BUFF_SIZE_2048-512))
	{
		prompt_buff_1 = new char[sql_len+512];
		memset(prompt_buff_1,0,sql_len+512);
	}
	//else
	//{
	//	memset(prompt_buff,0,sizeof(prompt_buff));
	//}


#if ENABLE_RECORD_SQL_TO_DBLOGFILE

	if(strcmp(g_database_logfile_fullpath,""))
	{
		g_database_logwrite.PrintLog(MyLogger::INFO,"%s",psql);
	}
#endif


	prset = Connection_executeQuery(con,psql);

    while(NULL == prset)
    {
        prset = Connection_executeQuery(con,psql);

		printf("---------------------------\n");


		if(sql_len>(BUFF_SIZE_2048-512))
		{
			memset(prompt_buff_1,0,sql_len+512);
			sprintf(prompt_buff_1,"error:\n");
			sprintf(prompt_buff_1,"%s database ip:%s\n",prompt_buff_1,g_database_ip);
			sprintf(prompt_buff_1,"%s database name:%s\n",prompt_buff_1,g_database_dbname);
			sprintf(prompt_buff_1,"%s database username:%s\n",prompt_buff_1,g_database_username);
			sprintf(prompt_buff_1,"%s database password:%s\n",prompt_buff_1,g_database_password);
			sprintf(prompt_buff_1,"%s Connection_executeQuery retry counter:%d,rset:%08X\n", prompt_buff_1,retry_counter++,prset);
			g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff_1);
		}
		else
		{
			memset(prompt_buff,0,sizeof(prompt_buff));
			sprintf(prompt_buff,"error:\n");
			sprintf(prompt_buff,"%s database ip:%s\n",prompt_buff,g_database_ip);
			sprintf(prompt_buff,"%s database name:%s\n",prompt_buff,g_database_dbname);
			sprintf(prompt_buff,"%s database username:%s\n",prompt_buff,g_database_username);
			sprintf(prompt_buff,"%s database password:%s\n",prompt_buff,g_database_password);
			sprintf(prompt_buff,"%s Connection_executeQuery retry counter:%d,rset:%08X\n", prompt_buff,retry_counter++,prset);
			g_database_logwrite.PrintLog(MyLogger::INFO,"%s",prompt_buff);
		}

		printf("---------------------------\n");
        sleep(1);
    }

	if(NULL != prompt_buff_1)
	{
		delete [] prompt_buff_1;
		prompt_buff_1 = NULL;
	}

    return prset;
}
void PubFun::Connection_close_pool(Connection_T con)
{
    if(NULL != con)
    {
        Connection_close(con);
    }
}
int PubFun::ResultSet_next_pool(ResultSet_T rset)
{
	return ResultSet_next(rset);
}
const char *PubFun::ResultSet_getString_pool(ResultSet_T rset,int column_index)
{
	return ResultSet_getString(rset,column_index);
}
void PubFun::assert_pool(void *pvoid)
{
	assert(pvoid);
}
#endif