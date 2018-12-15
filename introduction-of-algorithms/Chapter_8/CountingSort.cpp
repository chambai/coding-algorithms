#include <iostream>

using namespace std;

//¼ÆÊıÅÅĞò
void CountingSort(int arrA[], int arrB[], int len, int k)
{
	int *arrC = new int[k+1];
	for (int i = 0; i <= k; i ++)
		arrC[i] = 0;
	
	for (int i = 0; i < len; i ++)
		arrC[arrA[i]] = arrC[arrA[i]] + 1;//arrC[i] contains the number of elements equal to i.

	for (int i = 1; i <= k; i ++)
		arrC[i] = arrC[i] + arrC[i-1]; //arrC[i] contains the number of elements less than or equal to i.

	//(1)
	for (int j = len-1; j >=0; j --) {
		arrB[arrC[arrA[j]]-1] = arrA[j]; //index start from 0
		arrC[arrA[j]] = arrC[arrA[j]] - 1;
	}
	//(2) 
// 	for (int j = 0; j < len; j ++) {
// 		arrB[arrC[arrA[j]]-1] = arrA[j];
// 		arrC[arrA[j]] = arrC[arrA[j]] - 1;
// 	}
}

// int main()
// {
// 	int arrA[] = {2,5,3,0,2,3,0,3};
// 	int arrB[8] = {0};
// 	
// 	int len = sizeof(arrA)/sizeof(int);
// 	CountingSort(arrA, arrB, len, 5);
// 
// 	for (int i = 0; i < len; i ++)
// 		cout << arrB[i] << " ";
// 	return 0;
// }