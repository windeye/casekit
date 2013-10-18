#include <stdio.h>

int main (int argc, char const* argv[])
{
  void *d[] = {10,'a',"abcd"};
  printf("%d\n",d[0]);
  printf("%c\n",d[1]);
  printf("%s\n",d[2]);

  return 0;
}
