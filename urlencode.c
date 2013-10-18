#include <stdio.h>
#include <string.h>

static char hexchars[] = "0123456789ABCDEF";

#define visalpha(c) \
  ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define visalnum(c) \
  ((c >= '0' && c <= '9') || visalpha(c))

/*
 * RFC3986:
 * unreserved  = ALPHA / DIGIT / "-" / "." / "_" / "~"
 * 空格不单独处理为+
 */

int url_encode(const char *src, char *dst,int len)
{
  if(src == NULL || dst == NULL)
    return -1;
  while ( *src && (len > 1) ) {
    if (visalnum((unsigned char) *src) || *src == '-' 
        || *src == '.' || *src ==  '_' || *src ==  '~') { 
      *dst++ = *src++;
      len--;
    } else {
      if(len < 4)
        break; //% HEX HEX \0 need 4 bytes
      *dst++ = '%';
      unsigned char foo = *src;
      *dst++ = hexchars[foo >> 4];
      *dst++ = hexchars[*src & 0x0F];
      src++;
      len -= 3;
    }
  }
  if(*src) return -1; //len is not enough
  *dst = '\0'; 
  return 0;
}


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
    return 0;
  }
  /* the nth element error*/
  return srclen-len;
}

int main (int argc, char const* argv[])
{
  char *query = "河北ad=12+3&bc=123 asd&cd=asd#$?a&asd=aaas=.-_~北京长城";
  char encode[256];
  char decode[256];

  int ret;
  ret = url_encode(query,encode,256);
  if(ret)
    printf("error\n");
  else 
    printf("%s\n",encode);
  size_t len = strlen(encode);
  ret = url_decode(decode,encode,len);
  if(ret)
    printf("error\n");
  else 
    printf("%s\n",decode);

  return 0;
}
