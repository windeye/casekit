/***************************************************************************
 * 
 * Copyright (c) 2013 izptec.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
/**
 * @file const.cpp
 * @author Leokmax(xuliwei@izptec.com)
 * @date 2013/07/24 11:12:10
 * @brief 
 **/

#include <stdio.h>
#include <stdlib.h>

class A
{
  public:
    int a;
    const int b;
    int& c;
    static int d;
    char ch[10];
    A(int c0):a(3),b(10),c(c0)
    {}
    const int  getA() const
    {
      printf("cosnt get\n");
      return a;
    }
    int& getA()
    {
      printf("non cosnt get\n");
      return a;
    }
    char getC() const
    {
      printf("cosnt get ch\n");
      return ch[0];
    }
    char& getC()
    {
      printf("non cosnt get ch\n");
      return ch[0];
    }
    void setA(int a1) const
    {
      d = a1;
    }
};

int A::d;
int main()
{
  int e;
  const A va(e);
  va.setA(10);
  va.getA();
  printf("a:%d\n", va.getA());
  printf("a:%d\n", va.getA());
  return 0;
}

