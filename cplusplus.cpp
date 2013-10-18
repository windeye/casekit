#include <stdio.h>

#if __cplusplus < 1L
#error "should use c++11"
#endif

int main (int argc, char const* argv[])
{
  printf("%u\n", __cplusplus);
  return 0;
}
