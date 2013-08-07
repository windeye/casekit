#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <assert.h>
using namespace std;

void test_write()
{
  const int TEST_SIZE = 1000000000 ;
  const char* c_plus_write_file = "/home/xuliwei/c_plus_write_file.txt";
  const char* c_write_file = "/home/xuliwei/c_write_file.txt";

  cout<<"Test size :" << TEST_SIZE <<endl;
  ofstream of(c_plus_write_file);
  assert(of);
  time_t start, end;
  start =  time(NULL);
  for(int i=0; i < TEST_SIZE; ++i)
  {
    char tmp[1];
    tmp[0] = char(i);
    of << tmp[0];
  }
  end = time(NULL);
  of.close();
  cout<<"C++ style: "<<end - start <<" ms"<<endl;
  FILE* fp = fopen(c_write_file, "w");
  start =  time(NULL);
  for(int i=0; i < TEST_SIZE; ++i)
  {
    char tmp[1];
    tmp[0] = char(i);
    fwrite( tmp, 1, 1, fp);
  }
  end = time(NULL);
  fclose(fp);
  cout<<"C style: "<<end - start <<" ms"<<endl;
}



int main()
{
  test_write();
  return 1;
}
