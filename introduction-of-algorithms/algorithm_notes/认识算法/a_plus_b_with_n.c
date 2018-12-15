/******************************************************************************
 *	File Name: a_plus_b_with_n.c
 *	Author: 公众号: CloudDeveloper
 *	Created Time: Tue 18 Sep 2018 11:27:23 PM CST
 *****************************************************************************/

#include<stdio.h>

int main()
{
    int n;
    int a, b;
    scanf("%d", &n);
    while (n > 0) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
        n --;
    }
    return 0;
}
