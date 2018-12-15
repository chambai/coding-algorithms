#include <stdio.h>

int main()
{
	int n;
	int num, x;
	int sum, i;

	scanf("%d", &n);
	while (n > 0) {
		sum = 0;
		scanf("%d", &num);
		for (i = 0; i < num; i ++) {
			scanf("%d", &x);
			sum += x;
		}
		printf("%d\n", sum);
		n --;
	}
	return 0;
}