#include <string>
#include <stdio.h>
#include <sys/time.h>

using namespace std;


class Ade4mpPushLog 
{
public:
	Ade4mpPushLog():m_nPid(0),m_sAdKind("4MP"),m_sAdPlat("ADE"),m_nAdID(0),m_nAdType(0),m_nStuffID(0)
                    ,m_sAdprice(""),m_nAdResSize(0),m_nSpid(0),m_nAreaID(0),m_nLogID(0)
	{}

    void clear()
    {
      uint64_t m_nPid = 0; 			    //广告推送ID 
      string m_sTime = "";					//当前时间
      string m_sAdKind = "";
      string m_sAdPlat = "";
      string m_sAdMedia = "";
      string m_sAdService = "";            //业务编码
      int m_nAdID = 0;					//广告ID
      string m_sGroupId = "";
      string m_sPlanId = "";               //广告投放所属订单号
      string m_sAdverId = "";              //广告主ID
      string m_sDomainId = "";		    	//Ad域ID
      int m_nAdType = 0;   				//广告类型 C8 & 64 & 96
      int m_nStuffID = 0;	     			//广告素材ID
      string m_sChargeType = "";           //交易类型 cpm/cpc...
      string  m_sAdprice = "";             //广告价格
      string m_sWebsiteID = "";   			//网站ID
      string m_sChannelID = "";   			//广告所属频道ID
      string m_sAdSpaceID = "";	    	//广告位ID
      int m_nAdResSize= 0;	    		//广告位大小
      uint64_t m_nSpid=0;				//广告位推送ID
      string m_sHost="";					//网站HOST
      string m_sUrl="";					//网站URL
      string m_sReferer="";

      string m_sIp="";					//用户IP地址
      string m_sCookieID="";				//Cookie ID
      int m_nAreaID=0;				    //地域ID
      string m_sMobile="";
      string m_sAdCateKeyWord=""; 		//广告兴趣组ID或者关键字 & 策略ID(IDCLICKS)
      uint64_t m_nLogID=0;				//广告的logID
    }
public:
	uint64_t m_nPid; 			    //广告推送ID 
	string m_sTime;					//当前时间
    string m_sAdKind;
    string m_sAdPlat;
    string m_sAdMedia;
    string m_sAdService;            //业务编码
	int m_nAdID;					//广告ID
    string m_sGroupId;
    string m_sPlanId;               //广告投放所属订单号
    string m_sAdverId;              //广告主ID
	string m_sDomainId;		    	//Ad域ID
	int m_nAdType;   				//广告类型 C8 & 64 & 96
	int m_nStuffID;	     			//广告素材ID
    string m_sChargeType;           //交易类型 cpm/cpc...
    string  m_sAdprice;             //广告价格
	string m_sWebsiteID;   			//网站ID
	string m_sChannelID;   			//广告所属频道ID
	string m_sAdSpaceID;	    	//广告位ID
	int m_nAdResSize;	    		//广告位大小
	uint64_t m_nSpid;				//广告位推送ID
	string m_sHost;					//网站HOST
	string m_sUrl;					//网站URL
	string m_sReferer;

	string m_sIp;					//用户IP地址
	string m_sCookieID;				//Cookie ID
	int m_nAreaID;				    //地域ID
    string m_sMobile;
	string m_sAdCateKeyWord; 		//广告兴趣组ID或者关键字 & 策略ID(IDCLICKS)
	uint64_t m_nLogID;				//广告的logID
};
int createlog()
{
    Ade4mpPushLog push;
    return 0;
}
int main (int argc, char const* argv[])
{

  struct timeval begin, end;
  gettimeofday(&begin,NULL);
  Ade4mpPushLog push;
  for(int i =0;i<100000;i++){
    //push.clear();
    createlog();
  }
  gettimeofday(&end,NULL);

  printf("time use :%ums.\n",(end.tv_sec -begin.tv_sec)*1000 + (end.tv_usec - begin.tv_usec)/1000);
  return 0;
}
