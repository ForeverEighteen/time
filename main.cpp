#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <windows.h>
#include <time.h>
#include <fstream>
//#inlcude <iostream>
using namespace std;
//#include <openssl/aes.h>
#define TIMES 100
#define LEN1 131072
#define LEN 131072
#define m 2560
#define SIZE 1024
typedef unsigned long long __u64;
typedef unsigned long  __u32;

UINT64 Stime[LEN];
UINT64 Etime[LEN];
char array[LEN]={0};
__u64 rdtsc()
{
    __u32 lo,hi;

    __asm__ __volatile__
    (
    "rdtsc":"=a"(lo),"=d"(hi)
    );
    return (__u64)hi<<32|lo;
}
//inline unsigned __int64 GetCycleCount()
//{
//    __asm _emit 0x0F
//    __asm _emit 0x31
//}typedef int bool;

UINT64 myfunction(UINT64 *Stime)
{

    int ml;
    char *p=array;
    UINT64 START,END;
    for (int i = 0; i< LEN1; i = i + 64)
    {
        srand((unsigned)time(NULL));
        START= rdtsc();
        ml = rand() % 64;
        *(p + ml) ='a';
        END= rdtsc();
           *(Stime+(i / 64))=START-END;
         p = p + 64;

    }
    return 0;
}
int test_rdtsc1()
{
//    __u64 begin;
//    __u64 end;

//    int end;

//    begin = rdtsc();
    myfunction(Stime);
    Sleep(1000);
    myfunction(Etime);
    fstream fp("H:\\example4.csv", ios::app&ios::app);
    for (int i = 1; i< LEN; i = i + 1)
    {

        //加密前后访问时间记录
        fp << i << "," << Stime[i] << "," << Etime[i];
        fp << endl;


    }
//    end = rdtsc();
//    printf("myfunction cost %llu CPU cycles\n",end-begin);
    return 0;
}

int main()
{
    test_rdtsc1();
    return 0;
}