#include <iostream>

using namespace std;

//const int MAX = 9999;

//has the 'end flag'
void MergeWithFlag(int arr[], int left, int mid, int right)
{
	int nLen1 = mid - left + 1;
	int nLen2 = right - mid;
	
	int *arrA = new int[nLen1+1];
	int *arrB = new int[nLen2+1];

	for (int i = 0; i < nLen1; i ++)
		arrA[i] = arr[left + i];
	for (int j = 0; j < nLen2; j ++)
		arrB[j] = arr[mid + 1 + j];
	
	//the 'end flag'
	arrA[nLen1] = INT_MAX;
	arrB[nLen2] = INT_MAX;
	

	int i = 0, j = 0;
	for(int k = left; k <= right; k ++) {
		if (arrA[i] <= arrB[j]) {
			arr[k] = arrA[i];
			i++;
		}
		else {
			arr[k] = arrB[j];
			j ++;
		}
	}
	delete arrA;
	delete arrB;
	arrA = NULL;
	arrB = NULL;
}

void MergeDontFlag(int arr[], int left, int mid, int right)
{
	int nLen1 = mid - left + 1;
	int nLen2 = right - mid;

	int *arrA = new int[nLen1+1];
	int *arrB = new int[nLen2+1];

	for (int i = 0; i < nLen1; i ++)
		arrA[i] = arr[left + i];
	for (int j = 0; j < nLen2; j ++)
		arrB[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = 0;
	for(k= left; i < nLen1 && j < nLen2; k ++) {
		if (arrA[i] <= arrB[j]) {
			arr[k] = arrA[i];
			i++;
		}
		else {
			arr[k] = arrB[j];
			j ++;
		}
	}
	if (i < nLen1) {
		arr[k++] = arrA[i++];
	}
	if (j < nLen2) {
		arr[k++] = arrB[j++];
	}
	delete arrA;
	delete arrB;
	arrA = NULL;
	arrB = NULL;
}

//merge sort 
//note: right is the index of end
void MergeSort(int arr[], int left, int right)
{
	if (left < right){
		int mid = (left + right)/2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergeDontFlag(arr, left, mid, right);
	}
}

//FindAddition
//find (a+b=x) from a array, if can, return true
bool FindAddition(int arr[], int len, int xKey)
{
	if (len == 0 || len == 1)
		return false;
	int iL = 0;
	int iR = len - 1;
	while (iL < iR) {
		if (arr[iL] + arr[iR] < xKey)
			iL ++;
		else if (arr[iL] + arr[iR] > xKey)
			iR --;
		else
			return true;
	}
	return false;
}

// int main()
// {
// 	int arrA[6] = {1,5,3,2,8,7};
// 
// 	//BinaryArrayAdd(arrA, arrB, )
// 	//ReverseArray(arrB, 6);
// 	MergeSort(arrA, 0, 5);
// 	for(int i = 0; i < 6; i ++)
// 		cout << arrA[i] << endl;
// 
// 	bool b = FindAddition(arrA, 6, 2);
// 	cout << b;
// 
// 	return 0;
// }