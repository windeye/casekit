#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  struct hostent *hptr;
  char **pptr;
  char hostname[32];
  char str[32];

  if( gethostname(hostname,sizeof(hostname)) )
  {
    printf("gethostname calling error\n");
    return 1;
  }
  printf("localhost name:%s\n",hostname);

  return 0;
}
