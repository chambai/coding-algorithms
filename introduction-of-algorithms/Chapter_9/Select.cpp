#include <iostream>
#include <cassert>
using namespace std;

void Swap(int &m , int &n);
int Partition(int arr[], int nLeft, int nRight, int nMedian);
int Find(int arr[], int nLeft, int nRight);
int Insert(int arr[], int nLeft, int nRight);
int Select(int arr[], int nLeft, int nRight, int nMin);

int Select(int arr[], int nLeft, int nRight, int nMin)
{
	assert(nLeft <= nRight);
	assert(nMin <= (nRight-nLeft+1));

	if (nLeft == nRight)
		return arr[nLeft];

	int nMedian = Find(arr, nLeft, nRight);
	int nMid = Partition(arr, nLeft, nRight, nMedian);

	int k = nMid - nLeft + 1;
	if (k == nMin)
		return arr[nMid];
	else if (k > nMin)
		return Select(arr, nLeft, nMid - 1, nMin);
	else 
		return Select(arr, nMid + 1, nRight, nMin-k);
}

//找到数组中中位数的中位数
int Find(int arr[], int nLeft, int nRight)
{
	int nLen = nRight - nLeft + 1;
	
	int *pMedian = new int[nLen/5+1];
	
	int nStart, nEnd;
	int j = 0; //表示有几个组
	for (int i = 0; i < nLen; i ++) {
		if (i%5 == 0)
			nStart = nLeft + i;
		if ((i+1)%5 == 0 || i == nLen - 1) {
			nEnd = nLeft + i;
			j ++;
			int nRet = Insert(arr, nStart, nEnd);
			pMedian[j-1] = nRet;
		}
	}
	int nMedian = Select(pMedian, 0, j-1, (j-1)/2);
	return nMedian;
}

//对每组5个元素的数组进行插入排序，找到每组的中位数
int Insert(int arr[], int nLeft, int nRight)
{
	int nLen = nRight - nLeft + 1;

	for (int j = 1; j < nLen; j ++) {
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key) {
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}
	return arr[nLen/2];
}

//略作修改过的Partition函数
int Partition(int arr[], int nLeft, int nRight, int nMedian)
{
	//把中位数与看做主元，与最后一个元素交换
	for (int i = nLeft; i <= nRight; i++) {
		if (arr[i] == nMedian){
			Swap(arr[i], arr[nRight]);
			break;
		}
	}

	int nTemp = arr[nRight];
	int i = nLeft-1;
	int j = nLeft;

	while (j < nRight) {
		if (arr[j] <= nTemp) {
			Swap(arr[i+1], arr[j]);
			i ++;
		}
		j ++;
	}
	Swap(arr[i+1], arr[nRight]);
	return i + 1;
}

void Swap(int &m , int &n)
{
	int t = m;
	m = n;
	n = t;
}

int main()
{
	int arr[] = {7,4,6,9,2,1,5,8,3,0,12,23,78};
	cout << Select(arr, 0, 12, 11) << endl;
	return 0;
}