#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static inline int hex_to_int(char c)
{
  if (c >= '0' && c <= '9')
    return (c - '0');
  else if (c >= 'A' && c <= 'F')
    return (c - 'A' + 10);
  else if (c >= 'a' && c <= 'f')
    return (c - 'a' + 10);
  return (-1);
}

int url_decode( char *dst, const char *src, size_t len)
{
  if( src == NULL ){
    fprintf(stderr, "url_decode input string is null!\n");
    return -1;
  }
  const char *e = NULL;
  int h, l;
  int percent = 0;
  size_t srclen = len;
  while ( e == NULL && len--) {
    if (percent == 0) {
      switch(*src) {
        case '%':
          percent = 1;
          src++;
          break;
        case '+':
          *dst++ = ' ';
          src++;
          break;
        default:
          *dst++ = *src++;
          break;
      }
    } else if (percent == 1) {
      h = hex_to_int(*src++);
      if (h < 0)
        e = src;
      percent = 2;
    } else if (percent == 2) {
      l = hex_to_int(*src++);
      if (l < 0)
        e = src;
      *dst++ = (char) ((h << 4) | l);
      percent = 0;
    }
  }
  *dst = '\0';
  /* no error */
  if(e == NULL){
    fprintf(stderr,"%d\n",len);
    return 0;
  }
  /* the nth element error*/
  return srclen-len;
}

int main()
{
  char *src="adad%g6ad%3d23%26ads%3d123+d%26a%3d6";
  size_t len = strlen(src);
  fprintf(stderr," size is %u\n",len);
  char dst[len+1];
  int n = url_decode(dst,src,len);
  fprintf(stderr,"dst is %s,ret %d\n",dst,n);
  return 0;
}

















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
