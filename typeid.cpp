#include <iostream>

using namespace std;

class Base {};
class Derived: public Base {};

int main()
{
  cout << typeid(int).name() << endl
    << typeid(unsigned).name() << endl
    << typeid(long).name() << endl
    << typeid(unsigned char).name() << endl
    << typeid(float).name() << endl
    << typeid(double).name() << endl
    << typeid(string).name() << endl
    << typeid(Base).name() << endl
    << typeid(Derived).name() << endl;
    return 0;
}
