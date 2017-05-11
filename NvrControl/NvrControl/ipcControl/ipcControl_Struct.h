#ifndef IPCCONTROL_STRUCT_H
#define IPCCONTROL_STRUCT_H
#include "ipcControl_Table.h"
#include <vector>

typedef struct _DEV_IPC_INFO
{
	IPC_ITEM_TBL * pipcitem;
}DEV_IPC_INFO;
typedef vector<DEV_IPC_INFO *>DEV_IPC_INFOS;
#endif

