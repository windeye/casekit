/***************************************************************************
 * 
 * Copyright (c) 2013 izptec.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file main.cpp
 * @author YAO LU(luyao@izptec.com)
 * @date 2013/06/19 14:07:48
 * @version 1.0 
 * @brief 
 *
 *  
 **/

#include <stdlib.h>
#include <stdio.h>

int main()
{
  unsigned char u = 0xEF;
  unsigned short s = (~0xE0 & u)<<12;
  printf("%u\n",s);
  return 0;
}




















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
