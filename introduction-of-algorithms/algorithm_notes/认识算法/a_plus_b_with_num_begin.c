#include <stdio.h>

int main()
{
	int num;
	int n, sum, i;

	while (scanf("%d", &num)) {
		if (num == 0) 
			break;
        sum = 0;
		for (i = 0; i < num; i ++) {
			scanf("%d", &n);
			sum += n;
		}
		printf ("%d\n", sum);
	}
	return 0;
}
