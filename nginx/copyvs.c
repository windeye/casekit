#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void copy_timeuse(char *dst, char *src,size_t n)
{
  struct timeval begin,end;
  gettimeofday(&begin,NULL);
  while(n){
    *dst++ = *src++;
    n--;
  }
  gettimeofday(&end,NULL);
  printf("strcopy timeuse:%u.\n",end.tv_usec - begin.tv_usec);
}

void memcpy_timeuse(char *dst, char *src,size_t n)
{
  struct timeval begin,end;
  gettimeofday(&begin,NULL);
  memcpy(dst,src,n);
  gettimeofday(&end,NULL);
  printf("memcpy timeuse:%u.\n",end.tv_usec - begin.tv_usec);
}
int main()
{
  char * str17less = "1234567890abcdef";
  char * str17more = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char dst[96] = {0};
  printf("str17less:\n");
  copy_timeuse(dst,str17less,strlen(str17less));
  memcpy_timeuse(dst,str17less,strlen(str17less));
  printf("str17more:\n");
  copy_timeuse(dst,str17more,strlen(str17more));
  memcpy_timeuse(dst,str17more,strlen(str17more));
  return 0;
}
