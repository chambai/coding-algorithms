#include <iostream>
#include <vector>
using namespace std;

int MergeInversion(int arr[], int nLeft, int nRight);
int Merge(int arr[], int p, int q, int r);

//用归并排序找逆序对
int MergeInversion(int arr[], int nLeft, int nRight)
{
	int nInversion = 0;
	if (nLeft < nRight) {
		int nMid = (nLeft+nRight) >> 1;
		nInversion += MergeInversion(arr, nLeft, nMid);
		nInversion += MergeInversion(arr, nMid+1, nRight);
		nInversion += Merge(arr, nLeft, nMid, nRight);
	}
	return nInversion;
}

int Merge(int arr[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *left = new int[n1];
	int *right = new int[n2];

	int i,j;
	for (i = 0; i < n1; i ++)
		left[i] = arr[p+i];
	for (j = 0; j < n2; j ++)
		right[j] = arr[q+1+j];

	i = 0;
	j = 0;
	int k = p;
	int nInverCount = 0; //逆序对的数目

	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) 
			arr[k++] = left[i++];
		else {//假如左边子序列的数大于右子序列，则逆序对数为n1 - i;
			arr[k++] = right[j++];
			nInverCount += (n1 - i);
		}
	}
	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];
	
	delete left;
	left = NULL;
	delete right;
	right = NULL;
	
	return nInverCount;
}



int Merge1(int arr[], int p, int q, int r, int arrTemp[])
{
	int i = p, j = q+1;
	int k = p;
	int nInverCount = 0; //逆序对的数目

	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) 
			arrTemp[k++] = arr[i++];
		else {//假如左边子序列的数大于右子序列，则逆序对数为n1 - i;
			arrTemp[k++] = arr[j++];
			nInverCount += q - i + 1;
		}
	}
	while (i <= q)
		arrTemp[k++] = arr[i++];
	while (j <= r)
		arrTemp[k++] = arr[j++];

	for (int i = p; i <= r; i ++)
		arr[i] = arrTemp[i];

	return nInverCount;
}

int MergeInversion1(int arr[], int nLeft, int nRight, int arrTemp[])
{
	int nInversion = 0;
	if (nLeft < nRight) {
		int nMid = (nLeft+nRight) >> 1;
		nInversion += MergeInversion1(arr, nLeft, nMid, arrTemp);
		nInversion += MergeInversion1(arr, nMid+1, nRight, arrTemp);
		nInversion += Merge1(arr, nLeft, nMid, nRight, arrTemp);
	}
	return nInversion;
}

int main()
{
	int arr[] = {2,3,8,6,1};
	int len = sizeof(arr)/sizeof(arr[0]);

	int *arrT = new int[len];
	

	cout << MergeInversion1(arr, 0, 4, arrT) << endl;
	for (int i = 0; i < 5; i++)
		cout << arrT[i] << " ";
	return 0;
}