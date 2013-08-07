#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

int main (int argc, char const* argv[])
{
  char src[] = ",aad,a,ec,da"; 
  char delim[] = "&";
  char *buf = 0;
  buf = strtok(src,delim);
  printf("%s,%p,%p.\n",buf,src,buf);
  while(buf) {
    buf = strtok(NULL,delim);
    printf("%s.\n",buf);
  }
  printf("%s.\n",src);

  char *save = NULL;
  char src1[] = "aad=asd&app=123&asdas=frtsd&asdd=435&daa=";
  char *b = src1;
  char *equal = NULL;
  while ((buf = strtok_r(b,delim,&save)) != NULL){
    printf("%s\n",buf);
    equal = strchr(buf,'=');
    string key = string(buf,equal - buf);
    string value = string(equal+1);
    cout<<"key: "<<key<<" "<<"value: "<<value<<endl;
    b = NULL;
  }

  return 0;
}
