/***************************************************************************
 * 
 * Copyright (c) 2013 izptec.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
/**
 * @file unordered_map.cpp
 * @author Leokmax(xuliwei@izptec.com)
 * @date 2013/07/31 17:04:12
 * @brief 
 **/

#include <string>
#include <boost/unordered_map.hpp>

using namespace std;

class InputCollection;

struct Plat
{
  string name;  /* third part plat name */
  string key;   /* validate key */
  boost::unordered_map<string,int32_t> adapter_map; /*input adapter map*/
  bool input;    /* flag,whether adapt input */
  bool output;   /* flag,whether adapt output */
};

typedef void (*setCommand) (string,InputCollection);

/* k1=v1,parse key,then call this key's set callback */
struct InputAdapter                                                                                                                   
{
  string name;       /* key name */
  setCommand set;    /* callback */
  bool optional;     /* whether optional */
};



















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
