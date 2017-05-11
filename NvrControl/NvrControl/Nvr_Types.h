#ifndef NVR_TYPES_H
#define NVR_TYPES_H
#include <iostream>

typedef struct _REPORT_STATUS
{
	char status[20];
	char level[20];
	char module[50];
	char error_code_str[50];
	char message[1024];
	char message_la[1024];
}REPORT_STATUS;
#endif 