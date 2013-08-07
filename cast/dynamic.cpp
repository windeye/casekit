/***************************************************************************
 * 
 * Copyright (c) 2013 izptec.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
/**
 * @file dynamic.cpp
 * @author Leokmax(xuliwei@izptec.com)
 * @date 2013/07/23 16:15:17
 * @brief 
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string>

class A {
  public:
  A():a(1){};
  virtual void f(){};
  virtual ~A(){};
  int a;  
};
class B:public A
{
  public:
  B():b(2){};
  virtual void f(){};
  int b;
  virtual ~B(){};
};

int main() {
  A* pa = new B;
  B* pb = static_cast<B*>(pa);   // fails at runtime, not safe;
  if (!pb){
    printf("null\n");
  } else{
    printf("a: %d, b: %d\n", pb->a, pb->b);
    printf("pa: %p, pb: %p\n", pa, pb);
    printf("paa: %p, pba: %p\n", &pa->a, &pb->a);
    printf("pbb: %p\n", &pb->b);
    printf("void* size: %lu\n", sizeof(void *));
    printf("long size: %lu\n", sizeof(long));
    printf("int size: %lu\n", sizeof(int));
    printf("double size: %lu\n", sizeof(double));
    printf("float size: %lu\n", sizeof(float));
  }
  return 0;
}



















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
