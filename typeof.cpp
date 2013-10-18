#include <stdio.h>
#include <iostream>

using namespace std;

int main (int argc, char const* argv[])
{
  int a;
  typeof(a) b;
  cout << typeid(b).name() <<endl;
  return 0;
}
