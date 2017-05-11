Nvr_Control: main.o C_ThreadManage.o CppMySQL3DB.o CppMySQLQuery.o stdsoap2.o C_SoapFunction.o C_SoapServer.o LogManage.o C_LogManage.o C_Task.o \
		C_TaskList.o C_Task.o C_Para.o C_RunPara.o ec_config.o soapC.o soapServer.o C_AdditionalLog.o C_Time.o C_LocalTime.o Nvr_Control.o \
		FileManager_linux.o DownloadControl.o ipcControl.o ipcControl_Table.o pub.o Download_Table.o DM_TimeControl.o MyLogger.o
	g++ -o Nvr_Control main.o C_ThreadManage.o CppMySQL3DB.o CppMySQLQuery.o stdsoap2.o C_SoapFunction.o C_SoapServer.o LogManage.o \
		 C_LogManage.o C_Task.o C_TaskList.o ec_config.o C_RunPara.o C_Para.o soapC.o soapServer.o C_AdditionalLog.o  \
		C_LocalTime.o C_Time.o FileManager_linux.o Nvr_Control.o DownloadControl.o ipcControl_Table.o ipcControl.o pub.o  Download_Table.o\
		DM_TimeControl.o MyLogger.o \
		-lpthread -lmysqlclient -lgsoap++ -ldhnetsdk -ldhconfigsdk -ldhplay  -lm -lz  -lavcodec  -lavformat -lavfilter -llog4cxx
main.o:main.cpp
	g++ -g -o main.o -c main.cpp -I/usr/include/mysql -lmysqlclient
C_ThreadManage.o:./threadManage/C_ThreadManage.cpp
	g++ -g -o C_ThreadManage.o -c ./threadManage/C_ThreadManage.cpp
CppMySQL3DB.o:./database/CppMySQL3DB.cpp
	g++ -g -o CppMySQL3DB.o -c ./database/CppMySQL3DB.cpp  -I/usr/include/mysql
CppMySQLQuery.o:./database/CppMySQLQuery.cpp
	g++ -g -o CppMySQLQuery.o -c ./database/CppMySQLQuery.cpp -I/usr/include/mysql
stdsoap2.o:./webservice/stdsoap2.cpp
	g++ -g -o stdsoap2.o -c ./webservice/stdsoap2.cpp 
C_SoapFunction.o:./webservice/C_SoapFunction.cpp
	g++ -g -o C_SoapFunction.o -c ./webservice/C_SoapFunction.cpp -I/usr/include/mysql
C_SoapServer.o:./webservice/C_SoapServer.cpp
	g++ -g -o C_SoapServer.o -c ./webservice/C_SoapServer.cpp
soapC.o:./webservice/soapC.cpp
	g++ -g -o soapC.o -c ./webservice/soapC.cpp
soapServer.o:./webservice/soapServer.cpp
	g++ -g -o soapServer.o -c ./webservice/soapServer.cpp
LogManage.o:./log/LogManage.cpp
	g++ -g -o LogManage.o -c ./log/LogManage.cpp
C_LogManage.o:./log/C_LogManage.cpp
	g++ -g -o C_LogManage.o -c ./log/C_LogManage.cpp
C_AdditionalLog.o:./log/C_AdditionalLog.cpp
	g++ -g -o C_AdditionalLog.o -c ./log/C_AdditionalLog.cpp
C_Task.o:./timeTask/C_Task.cpp
	g++ -g -o C_Task.o -c ./timeTask/C_Task.cpp
C_TaskList.o:./timeTask/C_TaskList.cpp
	g++ -g -o C_TaskList.o -c ./timeTask/C_TaskList.cpp
ec_config.o:./para/ec_config.cpp
	g++ -g -o ec_config.o -c ./para/ec_config.cpp -I/usr/include/mysql
C_RunPara.o:./para/C_RunPara.cpp
	g++ -g -o C_RunPara.o -c ./para/C_RunPara.cpp -I/usr/include/mysql
C_Para.o:./para/C_Para.cpp
	g++ -g -o C_Para.o -c ./para/C_Para.cpp
C_LocalTime.o:./utility/C_LocalTime.cpp
	g++ -g -o C_LocalTime.o -c ./utility/C_LocalTime.cpp
C_Time.o:./utility/C_Time.cpp
	g++ -g -o C_Time.o -c ./utility/C_Time.cpp
FileManager_linux.o:./FileManager/FileManager_linux.cpp
	g++ -g -o FileManager_linux.o -c ./FileManager/FileManager_linux.cpp
Nvr_Control.o:./Nvr/Nvr_Control.cpp
	g++ -g -o Nvr_Control.o -c ./Nvr/Nvr_Control.cpp
DownloadControl.o:./downloadControl/DownloadControl.cpp
	g++ -g -o DownloadControl.o -c ./downloadControl/DownloadControl.cpp  -D__STDC_FORMAT_MACROS  -I/usr/include/mysql
ipcControl.o:./ipcControl/ipcControl.cpp
	g++ -g -o ipcControl.o -c ./ipcControl/ipcControl.cpp  -I/usr/include/mysql
ipcControl_Table.o:./ipcControl/ipcControl_Table.cpp
	g++ -g -o ipcControl_Table.o -c ./ipcControl/ipcControl_Table.cpp -I/usr/include/mysql
pub.o:./database/pub.cpp
	g++ -g -o pub.o -c ./database/pub.cpp -I/usr/include/mysql -I/usr/local/mysql/include
Download_Table.o:./downloadControl/Download_Table.cpp
	g++ -g -o Download_Table.o -c ./downloadControl/Download_Table.cpp -I/usr/include/mysql -I/usr/local/mysql/include
DM_TimeControl.o:./timeControl/DM_TimeControl.cpp
	g++ -g -o DM_TimeControl.o -c ./timeControl/DM_TimeControl.cpp
MyLogger.o:./myLog/MyLogger.cpp
	g++ -g -o MyLogger.o -c ./myLog/MyLogger.cpp -I./loglib/log4cxx/include
clean:
	rm -rf *.o Nvr_control
