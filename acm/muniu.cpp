/***************************************************************************
 * 
 * Copyright (c) 2013 izptec.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
/**
 * @file muniu.cpp
 * @author Leokmax(xuliwei@izptec.com)
 * @date 2013/07/25 11:58:23
 * @brief 
 **/

#include<iostream>
#include<fstream>
using namespace std;
int func(int year)
{
  if(year<4)  
  {
    return 1;
  }
  else  
  {
    // func(year-3) 是老母牛1头 因为前三年只有1头母牛 func(year-1)第二代牛数量没1年产1头
    return (func(year-4)+func(year-1)); 
  }
}
int main(int argc, char* argv[])
{
  int n = 20;
  cout<<  func(n)<<endl;

  return 0;
}

