/******************************************************************************
 *	File Name: input_str_with_space.c
 *	Author: 公众号: CloudDeveloper
 *	Created Time: Wed 19 Sep 2018 12:27:50 AM CST
 *****************************************************************************/
#include <stdio.h>
#include <string.h>

#define MIN_STR_LINE 20
#define MAX_STR_LINE 200

int shift(char str[])
{
	int i;
	for (i = 0; i < strlen(str); i ++) {
		if (str[i] >= 'F' && str[i] <= 'Z') {
			str[i] = str[i] - 5;
		}
		else if (str[i] >= 'A' && str[i] <='E') {
			str[i] = str[i] + 21;
		}
		else if (str[i] == ' ' || str[i] == ',') {
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;
}

int main() 
{
	char str[MAX_STR_LINE];
	char str_flag[MIN_STR_LINE];

	while (1) {
		gets(str_flag); // start
		if (!strcmp(str_flag, "ENDOFINPUT")) {
			break;
		}
		gets(str); // str
		shift(str);
		gets(str_flag); // end
		puts(str);
	}
	return 0;
}
