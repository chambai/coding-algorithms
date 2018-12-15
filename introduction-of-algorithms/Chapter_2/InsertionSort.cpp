#include <iostream>
#include <string>
#include <string.h>
using namespace std;

//insertion sort: non-recursive
//from big to small, only just arr[i] > key
void InsertionSort(int arr[], int len)
{
	if (arr == NULL || len == 0)
		return;

	for (int j = 1; j < len; j ++) {
		int key = arr[j];
		int i = j - 1;
		while(i >= 0 && arr[i] < key) {
			arr[i+1] = arr[i];
			i --;
		}
		arr[i+1] = key;
	}
}

void Insertion(int arr[], int len)
{
	if (len > 1) {
		int key = arr[len - 1];
		int i = len - 2;
		while(i >= 0 && arr[i] > key) {
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}
}

//insertion sort: recursive
void InsertionSort_Recursive(int arr[], int len)
{
	if (len > 1) {
		InsertionSort_Recursive(arr, len-1);
		Insertion(arr, len);
	}
}

void ReverseArray(char arrA[], int len)
{
	for(int i = 0; i < len/2; i ++){
		char temp = arrA[i];
		arrA[i] = arrA[len-1-i];
		arrA[len-1-i] = temp;
	}
}

void Swap(int &nA, int &nB)
{
	int nTemp = nA;
	nA = nB;
	nB = nTemp;
}

//selection sort
void SelectionSort(int arr[], int len)
{
	if (arr == NULL || len == 0)
		return;
	
	for (int i = 0; i < len - 1; i ++) {
		int key = arr[i];
		int index = i;
		for (int j = i + 1; j < len; j ++) {
			if (arr[j] < key) {
				key = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = key;
	}
}

//bubble sort
void BubbleSort(int arr[], int len)
{
	if (arr == NULL || len == 0)
		return;
	
	for(int i = 0; i < len; i ++) {
		for (int j = 0; j < len-1-i; j ++) {
			if (arr[j+1] < arr[j]) {
// 				int nTemp = arr[j+1];
// 				arr[j+1] = arr[j];
// 				arr[j] = nTemp;
				Swap(arr[j+1], arr[j]);
			}
		}
	}
}

//binary array addition - 2.1-4
void BinaryArrayAdd(char arrA[], char arrB[], char arrC[], int len) 
{
	if (len == 0)
		return;
	
	ReverseArray(arrA, len);
	ReverseArray(arrB, len);
	int lenC = len + 1;
	
	int flag = 0;
	for (int i = 0; i < len; i ++) {
		int value = arrA[i] + arrB[i] + flag;
		arrC[i] = (arrA[i] + arrB[i]) % 2;
		if (value < 2) //相加>2，表示有进位
			flag = 0;
		else
			flag = 1;
	}
	arrC[lenC] = flag;

	ReverseArray(arrC, lenC);
}

// int main() 
// {
// 	int arrA[6] = {1,5,3,2,8,7};
// 	
// 	//BinaryArrayAdd(arrA, arrB, )
// 	//ReverseArray(arrB, 6);
// 	InsertionSort_Recursive(arrA, 6);
// 	for(int i = 0; i < 6; i ++)
// 		cout << arrA[i] << endl;
// // 	InsertionSort(arrA, 5);
// // 	
// // 	for(int i = 0; i < 5; i ++)
// // 		cout << arrA[i] << endl;
// 	return 0;
// }
