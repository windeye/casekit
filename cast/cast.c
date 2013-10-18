/***************************************************************************
 * 
 * Copyright (c) 2013 izptec.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
/**
 * @file cast.c
 * @author Leokmax(xuliwei@izptec.com)
 * @date 2013/08/10 15:27:55
 * @brief 
 **/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const* argv[])
{
  const int a =10;
  const int *c = &a;
  int *b = (int*)c;
  int d = (int)a;
  return 0;
}



















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
