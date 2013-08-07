#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <boost/unordered_map.hpp>
#include <string>

using namespace std; 

int main()
{
  FILE *fp = fopen("iptable","r+");
  if(fp == NULL){
    return -1;
  }
  int ret = 0;
  char buf[128] = {0};
  char ip[64] = {0};
  int adid = 0;
  typedef boost::unordered_map<string,int> Ipmap;
  Ipmap iptable;
  while(!feof(fp)){
    if(NULL != fgets(buf, 128, fp))
    {
      ret = sscanf(buf, "%s %d\n", ip, &adid);
      if(ret == 2 && strlen(ip) > 0 && strlen(ip) < 16){
        fprintf(stdout,"%s,%d,ret = %d.\n", ip,adid,ret);
        string ipstr(ip);
        iptable.insert(Ipmap::value_type(ipstr,adid));
      }
    }
  }
  fclose(fp);
  Ipmap::iterator iter = iptable.find("127.0.0.1");
  if(iter != iptable.end())
  {
    fprintf(stdout, "adid:%d\n",iter->second);
  }else {
    fprintf(stdout, "404 not found\n");
  }
  return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
