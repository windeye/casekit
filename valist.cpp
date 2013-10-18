#include <stdio.h>
#include <stdarg.h>

void test(const char *format,...)
{
  va_list v;
  va_start(format,v);

}
int main (int argc, char const* argv[])
{
  test("%d,%s",12,"12"); 
  return 0;
}
