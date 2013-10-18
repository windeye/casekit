#include <stdio.h>

class A
{
  public:
    int a;
};

class B1 : public A
{
  public:
    int b1;
};

class B2 : public A
{
  public:
    int b2;
};



class C : public B1,public B2 {
  public:
    int c;
};

void foo( A* pa) { pa->a = 1024;}

int main (int argc, char const* argv[])
{
  foo( new A);
  foo (new C);
  return 0;
}
