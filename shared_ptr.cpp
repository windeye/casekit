#include <boost/shared_ptr.hpp>
#include <string>
#include <iostream>

using namespace std;

int main (int argc, char const* argv[])
{
  boost::shared_ptr<string> ps1(new string("hello world")); 
  cout<<*ps1<<endl;
  cout<<ps1.unique()<<endl;
  boost::shared_ptr<string> ps2 = ps1;
  cout<<ps1.unique()<<endl;
  ps2.reset();
  cout<<ps1.unique()<<endl;
  cout<<ps1.use_count()<<endl;
  return 0;
}
