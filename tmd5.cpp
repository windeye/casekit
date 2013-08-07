#include <stdio.h>
#include<openssl/md5.h>
#include<string>
#include <sys/time.h>

using namespace std;

inline string md5_crypt(const string &input)
{
  unsigned char md[16];
  MD5((const unsigned char *)input.c_str(), input.size(), md);
  char buf[33];
  for (int i=0; i<16; i++)
    sprintf(buf + i * 2, "%02x", md[i]);
  buf[32]=0;
  return std::string(buf);
}

int main (int argc, char const* argv[])
{
  string input = string("asdg0aalpdksa90ifasldfkokadsaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaafffffffffffffffffffffffffffffffffasdasddddd");
  struct timeval start,end;
  gettimeofday(&start,NULL);
  string result = md5_crypt(input);
  gettimeofday(&end,NULL);
  printf("usec:%u.\n",end.tv_usec-start.tv_usec);
  printf("R:%s.\n",result.c_str());
  return 0;
}
