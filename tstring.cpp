#include <string>
#include <stdio.h>

using namespace std;
int main()
{
  string s = "河北省北京市";
  size_t p = s.find("北京");
  if(p != string::npos)
    printf("find it %zu\n",p);
  else 
    printf("404\n");
  return 0;
}
