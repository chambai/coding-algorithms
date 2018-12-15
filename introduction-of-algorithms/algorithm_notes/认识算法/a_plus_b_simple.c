/******************************************************************************
 *	File Name: a_plus_b_simple.c
 *	Author: 公众号: CloudDeveloper
 *	Created Time: Tue 18 Sep 2018 11:07:59 PM CST
 *****************************************************************************/


#include<stdio.h>

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        printf("%d\n", a+b);
    }
    return 0;
}
