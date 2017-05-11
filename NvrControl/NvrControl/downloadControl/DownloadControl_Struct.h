#ifndef DOWNLOAD_STRUCT_H
#define DOWNLOAD_STRUCT_H
#include "Download_Table.h"
#include <vector>

typedef struct _DOWNLOAD_INFO
{
	DOWNLOAD_ITEM_TBL * pdownloaditem;
}DOWNLOAD_INFO;
typedef vector<DOWNLOAD_INFO *>DOWNLOAD_INFOS;
#endif