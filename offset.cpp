#include <stdio.h>
#include <string>

using namespace std;

class InputAdapter;
class test {
public:
  int a;
  uint32_t b;
  string c;
  uint32_t d;
};

typedef void (*setCommand) (string&, test&, InputAdapter &Adapter);

class InputAdapter
{
public:
  string name;
  setCommand set;
  char test::* offset;
};


void setInt32(string &Value, test &Target, InputAdapter &Adapter)
{
  (&Target)->*((int test::*)Adapter.offset) = strtol(Value.c_str(),NULL,10);
}

void setUint32(string &Value, test &Target, InputAdapter &Adapter)
{
  (&Target)->*((uint32_t test::*)Adapter.offset) = strtoul(Value.c_str(),NULL,10);
}

void setStlString(string &Value, test &Target, InputAdapter &Adapter)
{
  (&Target)->*((string test::*)Adapter.offset) = Value;
}

struct InputAdapter Adapters[] = {
  {
    string("a"),
    InputAdapter::setInt32,
    (char test::*)&test::a,
  },
  {
    string("b"),
    InputAdapter::setUint32,
    (char test::*)&test::b,
  },
  {
    string("c"),
    InputAdapter::setString,
    (char test::*)&test::c,
  },
  {
    string("d"),
    InputAdapter::setUint32,
    (char test::*)&test::d,
  },
  {string(""),NULL,0,}
};

int main()
{
  test T;
  string A = "10";
  string B = "20";
  string C = "30123123$%^&@~!";
  string D = "1000";
  /*
  Adapters[0].set(A, T, Adapters[0]);
  Adapters[1].set(B, T, Adapters[1]);
  Adapters[2].set(C, T, Adapters[2]);
  Adapters[3].set(D, T, Adapters[3]);
  */
  Adapters[0].set(A, T);
  Adapters[1].set(B, T);
  Adapters[2].set(C, T);
  Adapters[3].set(D, T);
  printf("T.a %d\n",T.a);
  printf("T.b %u\n",T.b);
  printf("T.c %s\n",T.c.c_str());
  printf("T.d %u\n",T.d);
  return 0;
}
