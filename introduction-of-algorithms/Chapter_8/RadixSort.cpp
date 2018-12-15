#include <iostream>

using namespace std;

//return the number of a number contains;
int GetNumD(int nNum)
{
	int nCount = 1;
	while (nNum/10) {
		nCount ++;
		nNum = nNum/10;
	}
	return nCount;
}

void RadixSort(int arrA[], int arrB[], int len, int d)
{
	int *arrC = new int[10]; //most 10 numbers;
	
	int radix = 1; 
	for (int k = 1; k <= d; k ++) {
		//using CountingSort for every bit;
		for (int i = 0; i < 10; i ++)
			arrC[i] = 0;
		
		for (int i = 0; i < len; i ++) {
			int temp = (arrA[i]/radix) % 10; //find every bit of a number
			arrC[temp] = arrC[temp] + 1;
		}
		for (int i = 1; i < 10; i ++)
			arrC[i] = arrC[i] + arrC[i-1];
		
		for (int j = len-1; j >= 0; j --) {
			int temp = (arrA[j]/radix) % 10;
			arrB[arrC[temp] - 1] = arrA[j];
			arrC[temp] = arrC[temp] - 1;
		}
		radix *= 10; //another bit;
		memcpy(arrA, arrB, len * sizeof(int)); //note this line;
	}
}


// int main()
// {
// 	int arrA[7] = {329, 457, 657, 839, 436, 720, 355};
// 	int arrB[7] = {0};
// 	//RadixSort(arrA, arrB, 7, 3);
// // 	for (int i = 0; i < 7; i ++)
// // 		cout << arrB[i] << " ";
// 	char ch[] = "ABC";
// 	int a[3] = {0};
// 	for (int i = 0; i < 3; i ++)
// 		a[i] = ch[i] - 64;
// 	for (int i = 0; i < 3; i++)
// 		cout << a[i];
// 	return 0;
// }