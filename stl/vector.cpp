#include <vector>
#include <iostream>
using namespace std;
int main()
{
  vector<string> vs(2,"vector");
  vector<string>::iterator vi1 = vs.begin();
  cout<<*vi1<<endl;
  vs.resize(100);
  vi1 = vs.begin();
  cout<<*vi1<<endl;
  return 0;
}
