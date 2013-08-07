#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const* argv[])
{
  off_t a = 12;
  size_t b =22;
  ssize_t c = 21;
  printf("a:%u,b:%u,c:%d\n",a,b,c);
  return 0;
}
