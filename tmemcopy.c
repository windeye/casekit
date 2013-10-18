#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char const* argv[])
{
  int a = 1234567;
  unsigned char s[8] = {0};
  memcpy(s,(void *)&a,4);
  printf("%d\n",(int*)s);
  return 0;
}
