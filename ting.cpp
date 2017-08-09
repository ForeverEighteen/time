
//
// Created by Tsing on 7/24/2017.
//

/*
* -----------------------------------------------------------
*  Copyright (c) 2014 IECAS All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  Tsing
*      创建时间：  7/24/2017 2:36:26 PM
*        文件名：  mycpp
*		   版本：  V1.0
*
*
*		 修改者：           时间：
*	   修改说明：
*
*/

// OpensslEnvironmentTestconsole.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
//#include <openssl/aes.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include<time.h>
#include <windows.h>
#define TIMES 100
#define SIZE 1024
typedef unsigned long long __u64;
typedef unsigned long  __u32;


//inline unsigned __int64 GetCycleCount()
//{
//    __asm _emit 0x0F
//    __asm _emit 0x31
//}typedef int bool;







UINT64 myfunction1()
{
    UINT64 i;
    char *p = NULL;
    for (i = 0; i<TIMES; i++)
    {
        //        p = (char*)malloc(SIZE*sizeof(char));
        //        if(p)
        //        {
        //            free(p);
        //        }
        //        else
        //        {
        //            printf("malloc failed when i = %d\n",i);
        //        }
        Sleep(100);
    }
    return 0;
}
int test_rdtsc()
{
    //    __u64 begin;
    //    __u64 end;
    UINT64 begin;
    UINT64 end;
    //    int end;
    LARGE_INTEGER Stime1,Etime1;
    QueryPerformanceCounter(&Stime1);
    //myfunction();
    //Sleep(10000);
    for (int i = 0; i < 1000; i++) {

    }
    QueryPerformanceCounter(&Etime1);
    printf("myfunction cost %llu CPU cycles\n", Etime1.QuadPart - Stime1.QuadPart);
    return 0;
}

int main3()
{

    test_rdtsc();
    return 0;
}