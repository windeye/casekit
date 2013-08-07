/***************************************************************************
 * 
 * Copyright (c) 2013 izptec.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
/**
 * @file geteuid.c
 * @author Leokmax(xuliwei@izptec.com)
 * @date 2013/07/10 11:13:37
 * @brief 
 **/

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>

int main()
{
    unsigned int euid = geteuid();
    unsigned int uid = getuid();
    printf("euid:%u,uid:%u\n",euid,uid);
    return 0;
}


















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
