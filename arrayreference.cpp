#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
typedef string s2[2];
void fun(string (&str)[2])
{
  str[0] = "123";
  str[1] = "abc";
}

int main (int argc, char const* argv[])
{
  string s[2];
  fun(s);
  cout<<s[0]<<endl;
  cout<<s[1]<<endl;
  return 0;
}
