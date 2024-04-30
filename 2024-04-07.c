/****************************************************************************
 * 
 * file name: 字符串反向输出.c
 * author   : 123
 * date     : 2024-04-07
 * function : 递归计算输入字符个数。
 * note     : None
 * CopyRight (c)   2024   qwewq   Right Reseverd
 * 
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int func(char *p)
{
    if ('\0' == *p) {
        return 0;
    } else {
        return 1+func(p+1);
    }
    
}

char *func1(char *str)
{
    char *pstr = str;  //备份str字符串首地址。
    int cnt = 0;       //记录字符串字符个数
    char *p = (char *)malloc(128);
    while (*pstr++)
    {
        cnt++;
    }
    
    for (int i = 0; i < cnt; i++)
    {
        *(p+i) = *(str+cnt-1-i);
    }
    

    return p;
}


int main(int argc, char const *argv[])
{
    char *p = NULL;
    int sum = 0;
    p = (char *)calloc(1,100);  //申请堆空间，calloc申请堆空间时已经做了初始化。
    if (NULL == p)  //错误处理
    {
        perror("calloc heap memory failed!");
        return -1;
    }
    /*
    p = (char *)malloc(100);  //请堆空间，malloc申请堆空间时未初始化。
    if (NULL == p)  //错误处理
    {
        perror("calloc heap memory failed!");
        return -1;
    }
    bzero(p,100);  //初始化堆空间
    */
    
    printf("请输入字符串：");
    scanf("%s",p);
    printf("输入字符串个数是：%d\n",func(p));
    printf("字符串长度：%ld\n",strlen(p));
    free(p);
    p = NULL;
    return 0;
}

