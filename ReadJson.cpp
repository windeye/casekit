#include <stdio.h>
#include <boost/unordered_map.hpp>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>


#define ERROR perror
#define DEBUG printf 
using namespace std;
struct Plat                                
{
  string name;  /* third part plat name */
  string key;   /* validate key */
  boost::unordered_map<string,int32_t> adapter_map; /*input adapter map*/
  int setAdapter(string&);
};

int Plat::setAdapter(string &adapter)
{
  if( adapter.empty() ){
    ERROR("adapter is empty!\n");
    return -1;
  }
  size_t start = 0;
  string key;
  string value;
  string whole;
  for(;;){
    size_t found = adapter.find( ';', start);
    if( found != string::npos){
      whole = adapter.substr(start,found-start);
      start = found + 1;
      found = whole.find(':');
      if( found != string::npos ){
        key = whole.substr(0,found);
        value = whole.substr(found+1);
        DEBUG("field:%s,value:%s.\n",key.c_str(), value.c_str());
        adapter_map.insert(pair<string,int32_t>(key,atoi(value.c_str())));
      } else {
        ERROR("Wrong Adapter format!\n");
        return -1;
      }
    } else {
      break;
    }
  }
  return 0;
}
struct K_V{
  string key;
  string value;
};
vector<Plat> plats;

inline bool isSpace( char c )
{
  return ( c==' ' || c=='\t' || c=='\n' );
}

int storeAdapter(vector<K_V> &config)
{
  plats.reserve(10);
  Plat plat;
  for(vector<K_V>::iterator it = config.begin(); it != config.end(); ++it)
  {
    DEBUG("Key:%s,Value:%s.\n", it->key.c_str(),it->value.c_str());
    if( it->key == "name")
      plat.name = it->value;
    if( it->key == "key" )
      plat.key = it->value;
    if( it->key == "adapter")
      plat.setAdapter(it->value);
  }
  plats.push_back(plat);
  return 0;
}
int readAdapter(const char *filename)
{
  if( NULL == filename){
    ERROR("Adapter filename is NULL!\n");
    return -1;
  }
  int fd = open(filename,O_RDONLY,0);
  if( fd == -1){
    ERROR("Open Adapter file failed,errno:\n");
    return -1;
  }

  struct stat st;
  if(-1 == fstat(fd, &st)){
    ERROR("fstat Adapter file failed,error:\n");
    return -1;
  }

  off_t file_size = st.st_size;
  DEBUG("file size is %u.",file_size);
  char buf[file_size+10] ;
  int ret = read(fd, buf, file_size);
  if(ret == -1){
    ERROR("read Adapter file failed, error:\n");
    return -1;
  } else if (ret == file_size) {
    DEBUG("read All Adapter file success.\n");                                                                                      
  } else {
    ERROR("What happened?\n");
    return -1;
  }

  uint32_t left = file_size;
  enum {
    PARSE_START,
    PARSE_BLOCK,
    PARSE_KEY,
    AFTER_PARSE_KEY,
    PARSE_VALUE,
    AFTER_PARSE_VALUE,
    AFTER_PARSE_BLOCK,
  } sm;
  struct K_V  kv;

  vector<K_V> config; 
  sm = PARSE_START;
  char *b = NULL;
  char *e = NULL;
  char *s = buf;
  while(left) {
    switch (sm) {
    case PARSE_START:
      if( '{' == (*s++) ){
        sm = PARSE_BLOCK;
      }
      --left;
      break;
    case PARSE_BLOCK:
      if( !isSpace(*s++) ){
        sm = PARSE_KEY;
        b = s -1;
      }
      --left;
      break;
    case PARSE_KEY:
      if( isSpace(*s++) ){
        sm = AFTER_PARSE_KEY;
        e = s - 1;
        kv.key = string(b,e - b);
      }
      --left;
      break;
    case AFTER_PARSE_KEY:
      if( !isSpace(*s++) ){
        sm = PARSE_VALUE;
        b = s -1;
      }
      --left;
      break;
    case PARSE_VALUE:
      if( isSpace(*s++) ){
        sm = AFTER_PARSE_VALUE;
        e = s - 1;
        kv.value = string(b,e - b);
        config.push_back(kv);
      } 
      --left;
      break;
    case AFTER_PARSE_VALUE:
      if( !isSpace(*s++) ) { 
        if( *(s-1) == '}' ) {       
          sm = AFTER_PARSE_BLOCK;
          storeAdapter(config);
          config.clear();
        } else { 
          sm = PARSE_KEY;
          b = s - 1;
        }
        --left;
        break;
      }
    case AFTER_PARSE_BLOCK:
      if( *s++ == '{' ){
        sm = PARSE_BLOCK;
      }
      --left;
      break;
    default:
      break;
    }
  }
  return 0;
}


int main()
{
  readAdapter("./plat.config");
  return 0;
}
