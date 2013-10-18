#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string>
#include <iostream>
#include <arpa/inet.h>

using namespace std;
#define UINT8   unsigned char
#define INT8   char
#define INT32   int 
#define UINT32  unsigned int
#define INT64   long long
#define UINT64  unsigned long long

#define ADE_PUSH_ID_LEN_BYTE        16
#define ADE_PUSH_ID_LEN_BYTE_OFFSET 4
#define ADE_PUSH_ID_LEN_BIT         128

#define DEBUG printf
int convertStr2PushID(std::string pidStr, UINT8* pushid)
{
	int i = 0;
	int len = pidStr.size();
	UINT8 tmp[3] = {0};
	UINT8 ptr = 0x00;
	
	memset(pushid, 0x00, ADE_PUSH_ID_LEN_BYTE + ADE_PUSH_ID_LEN_BYTE_OFFSET);

	for(i = 0; i < len; i += 2)
	{
		ptr = strtoul(pidStr.substr(i, 2).c_str(), NULL, 16);
		pushid[i/2] = ptr;
	}
	return 0;
}

int convertPushID2Str(UINT8* pushid, std::string& pidStr)
{
	if(NULL == pushid)
	{
		DEBUG("AdeUtility::convertPushID2Str:error");
		return -1;
	}
	pidStr.clear();
	INT8 ptr[ADE_PUSH_ID_LEN_BYTE * 2 + ADE_PUSH_ID_LEN_BYTE_OFFSET] = {0};
	snprintf(ptr, ADE_PUSH_ID_LEN_BYTE * 2 + ADE_PUSH_ID_LEN_BYTE_OFFSET, 
        "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
		pushid[0], pushid[1], pushid[2], pushid[3], pushid[4], pushid[5], pushid[6], pushid[7], 
		pushid[8], pushid[9], pushid[10], pushid[11], pushid[12], pushid[13], pushid[14], pushid[15]);
	pidStr = std::string(ptr);

	DEBUG("push id with std::string:%s", pidStr.c_str());
	return 0;
}
int getPushId128(unsigned char* pushid, UINT32 userip, UINT32 adid)
{
	// | random (24 bits) | IP (32 bits) | AdID (32 bits)  | time (40 bits)  |
	unsigned char pushid_source[18] = {0};
	memset(pushid, 0x00, ADE_PUSH_ID_LEN_BYTE + ADE_PUSH_ID_LEN_BYTE_OFFSET);
	UINT64 randomNum = rand() & 0xFFFFFF;
    struct timeval g_current_time;
    gettimeofday(&g_current_time,NULL);
	UINT64 currentTime = g_current_time.tv_sec * 1000000 + g_current_time.tv_usec;
	currentTime = currentTime&0xFFFFFFFFFF;

	/* random 3 byte */
	memcpy(pushid_source, (void*)&randomNum, 3);
	/* adid 4 byte */
	memcpy(pushid_source + 3, (void*)&adid, 4);
	/* ip 4 byte */
	memcpy(pushid_source + 7, (void*)&userip, 4);
	/* time 5 byte */
	memcpy(pushid_source + 11, (void*)&currentTime, 5);

	memcpy(pushid, pushid_source, ADE_PUSH_ID_LEN_BYTE);

	return 0;
}

int checkPushId128(UINT8* pushid, UINT32 pidLen, UINT32 userip, UINT32 adid)
{
	// | random (24 bits) | AdID (32 bits) | IP (32 bits)  | time (40 bits)  |

	UINT8 str[ADE_PUSH_ID_LEN_BYTE + ADE_PUSH_ID_LEN_BYTE_OFFSET] = {0};
	unsigned char pPushid[ADE_PUSH_ID_LEN_BYTE + ADE_PUSH_ID_LEN_BYTE_OFFSET] = {0};
	if(pidLen != ADE_PUSH_ID_LEN_BYTE * 2)
	{
		DEBUG("AdePushID_Tanx::checkPushID::pid error");
		return -1;
	}
	convertStr2PushID(std::string((char*)pushid), pPushid);

	UINT32 pAdid = 0x00;
	UINT32 pIp = 0x00;
	long int pTime = 0x00;

	/* adid 4 byte*/
	memcpy((void*)(&pAdid), pPushid + 3, 4);
	/* ip 4 byte*/
	memcpy((void*)(&pIp), pPushid + 7, 4);
	/* time 4 byte*/
	memcpy((void*)(&pTime), pPushid + 11, 5);


    struct timeval g_current_time;
    gettimeofday(&g_current_time,NULL);
	UINT64 currentTime = g_current_time.tv_sec * 1000000 + g_current_time.tv_usec;
	currentTime = currentTime&0xFFFFFFFFFF;

	DEBUG("Check PID-->adid: %08x %08x\n",  pAdid, adid);
	DEBUG("Check PID-->ip  : %08x %08x\n",  pIp, userip);
	DEBUG("Check PID-->time: %012x\n", pTime);
                
	if(pIp != userip)
	{
		return 1;
	}
	if(pAdid != adid)
	{
		return 2;
	}
	if(currentTime - pTime > 120000)
	{
		return 3;
	}
    return 0;
}

int checkPushId(std::string pushid, UINT32 userip, UINT32 adid)
{
  int ret = checkPushId128((unsigned char*)pushid.c_str(), pushid.size(), userip, adid);
  return ret;
}
int getPushId(std::string& pushid, UINT32 userip, UINT32 adid)
{
  INT32 ret = 0;
  pushid.clear();
  UINT8 push_id[ADE_PUSH_ID_LEN_BYTE + ADE_PUSH_ID_LEN_BYTE_OFFSET] = {0}; 
  getPushId128(push_id, userip, adid);
  convertPushID2Str(push_id, pushid);
}


int main (int argc, char const* argv[])
{
  string pid;
  getPushId(pid, inet_addr("10.0.2.23"),23);  
  cout<<endl<<"pid:"<<pid<<endl;
  //check
  int ret = checkPushId(pid,inet_addr("10.0.2.23"), 23);
  cout<<ret<<endl;
  ret = checkPushId(pid,inet_addr("10.0.2.23"),21);
  cout<<ret<<endl;
  ret = checkPushId(pid,inet_addr("10.0.2.21"),23);
  cout<<ret<<endl;

  sleep(15);
  ret = checkPushId(pid,0x0a000323,23);
  cout<<ret<<endl;
  return 0;
}
