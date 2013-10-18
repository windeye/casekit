#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sys/time.h>

using namespace std;

void print(pair<string,uint32_t> it)
{
  printf("%s %u\n",it.first.c_str(),it.second);
}


struct KV{
  string key;
  uint32_t value;
  KV(string k,uint32_t v)
  {
    key = k;
    value = v;
  }
};

bool cmp(KV kv1,KV kv2)
{
  return kv1.key < kv2.key;
}

int main()
{
  struct timeval start,end;
  map<string,uint32_t> maplala;
  for(int i =100; i; i--){
    gettimeofday(&start,NULL);
    maplala.insert(map<string,uint32_t>::value_type("xfabcd",1));
    maplala.insert(map<string,uint32_t>::value_type("vdfbcdef",2));
    maplala.insert(map<string,uint32_t>::value_type("cdefg",3));
    maplala.insert(map<string,uint32_t>::value_type("defgh",4));
    maplala.insert(map<string,uint32_t>::value_type("efghijk",5));
    maplala.insert(map<string,uint32_t>::value_type("uffghijk",5));
    maplala.insert(map<string,uint32_t>::value_type("ghijkia",5));
    maplala.insert(map<string,uint32_t>::value_type("hijkii",5));
    maplala.insert(map<string,uint32_t>::value_type("asdijkasd",5));
    maplala.insert(map<string,uint32_t>::value_type("jkasdfs",5));
    maplala.insert(map<string,uint32_t>::value_type("kasd",5));
    maplala.insert(map<string,uint32_t>::value_type("lmnopq",5));
    maplala.insert(map<string,uint32_t>::value_type("mnopqrst",5));
    maplala.insert(map<string,uint32_t>::value_type("npadsdd",5));
    maplala.insert(map<string,uint32_t>::value_type("rstera",5));
    maplala.insert(map<string,uint32_t>::value_type("trpsdpa",5));
    maplala.insert(map<string,uint32_t>::value_type("pasdper",5));
    maplala.insert(map<string,uint32_t>::value_type("zxfdsfc",5));
    maplala.insert(map<string,uint32_t>::value_type("ysddfa",5));
    //for_each(maplala.begin(),maplala.end(),print);
    for(map<string,uint32_t>::iterator it = maplala.begin(); it != maplala.end();it++)
    {
      //printf("%s %u\n",it->first.c_str(),it->second);
    }
    maplala.clear();
    gettimeofday(&end,NULL);
    printf("map sec:%u,usec:%u.\n",end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec);
  }


  vector<KV> vkv;
  vkv.reserve(20);
  for(int j=100; j; j--){
    gettimeofday(&start,NULL);
    vkv.push_back(KV(string("zxfdsfc"),5));
    vkv.push_back(KV(string("ysddfa"),5));
    vkv.push_back(KV(string("xfabcd"),1));
    vkv.push_back(KV(string("vdfbcdef"),1));
    vkv.push_back(KV(string("uffghijk"),5));
    vkv.push_back(KV(string("trpsdpa"),5));
    vkv.push_back(KV(string("rstera"),5));
    vkv.push_back(KV(string("pasdper"),5));
    vkv.push_back(KV(string("npadsdd"),5));
    vkv.push_back(KV(string("mnopqrst"),5));
    vkv.push_back(KV(string("lmnopq"),5));
    vkv.push_back(KV(string("kasd"),5));
    vkv.push_back(KV(string("jkasdfs"),5));
    vkv.push_back(KV(string("hijkii"),5));
    vkv.push_back(KV(string("ghijkia"),5));
    vkv.push_back(KV(string("efghijk"),5));
    vkv.push_back(KV(string("defgh"),4));
    vkv.push_back(KV(string("cdefg"),3));
    vkv.push_back(KV(string("asdijkasd"),5));
    sort(vkv.begin(),vkv.end(),cmp);

    vector<KV>::iterator it;
    for(it = vkv.begin(); it != vkv.end(); it++)
    {
      //printf("key:%s,value:%u.\n",it->key.c_str(),it->value);
    }
    vkv.clear();
    gettimeofday(&end,NULL);
    printf("vector sec:%u,usec:%u.\n",end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec);
  }
  return 0;
}

