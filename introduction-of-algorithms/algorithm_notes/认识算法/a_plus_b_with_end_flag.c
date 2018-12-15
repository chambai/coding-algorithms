/******************************************************************************
 *	File Name: a_plus_b_with_end_flag.c
 *	Author: 公众号: CloudDeveloper
 *	Created Time: Tue 18 Sep 2018 11:35:19 PM CST
 *****************************************************************************/

#include<stdio.h>

int main()
{
    int a, b;
    while(1) {
        scanf("%d %d", &a, &b);
        if (!a && !b) {
            break;
        }
        else {
            printf("%d\n", a + b);
        }
    }
    return 0;
}
