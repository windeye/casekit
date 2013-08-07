#include <iostream>
using namespace std;

class CNullPointCall
{
  public:
    static void Test1();
    void Test2();
    void Test3(int iTest);
    void Test4();

  private:
    static int m_iStatic;
    int m_iTest;
};

int CNullPointCall::m_iStatic = 0;

void CNullPointCall::Test1()
{
  cout << m_iStatic << endl;
}

void CNullPointCall::Test2()
{
  cout << "Very Cool!" << endl; 
}

void CNullPointCall::Test3(int iTest)
{
  cout << iTest << endl; 
}

void CNullPointCall::Test4()
{
  cout << m_iTest << endl; 
}
int main (int argc, char const* argv[])
{
  CNullPointCall *pNull = NULL; // 没错，就是给指针赋值为空
  pNull->Test1(); // call 1
  pNull->Test2(); // call 2
  pNull->Test3(13); // call 3
  pNull->Test4(); // call 4
  return 0;
}
