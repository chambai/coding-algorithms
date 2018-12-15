#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

int* K_Select(int arr[], int nLen, int k);
int Select(int arr[], int nLeft, int nRight, int nMin);
int Partition(int arr[], int p, int r);
void Swap(int &n, int &m);

int* K_Select(int arr[], int nLen, int k)
{
	assert(k <= nLen);
	
	int *pDis = new int[nLen-1]; //the distance of every bit and median
	int *pDis_cpy = new int[nLen-1];
	int *pKArr = new int[k]; //return k_array

	int nMedian = Select(arr, 0, nLen-1, nLen/2); //get the median of arr
	int iMedian;
	int nDLen = 0;
	for (int i = 0; i < nLen; i ++) {
		if (arr[i] != nMedian)
			pDis[nDLen++] = abs(arr[i]-nMedian); //get the distance using abs()
		else
			iMedian = i; //get the index of median
	}
	memcpy(pDis_cpy, pDis, sizeof(int)*(nLen-1)); //copy the distance	
	int nKMedian = Select(pDis_cpy, 0, nDLen-1, k); //get the k-th minimum distance between median and every bit
	
	delete pDis_cpy;
	pDis_cpy = NULL;

	int ik = 0;
	for (int i = 0; ik < k && i < nDLen; i ++) {
		if (pDis[i] <= nKMedian) {
			if (i < iMedian) //judge the index of array and the index of median
				pKArr[ik++] = nMedian - pDis[i];
			else
				pKArr[ik++] = nMedian + pDis[i];
		}
	}

	delete pDis;
	pDis = NULL;

	return pKArr;
}

int Select(int arr[], int nLeft, int nRight, int nMin)
{
	assert(nLeft <= nRight);
	assert(nMin <= nRight-nLeft+1);

	if (nLeft == nRight)
		return arr[nLeft];
	int nMid = Partition(arr, nLeft, nRight);
	int k = nMid - nLeft + 1;
	if (k == nMin)
		return arr[nMid];
	else if (k > nMin)
		return Select(arr, nLeft, nMid-1,nMin);
	else
		return Select(arr, nMid+1, nRight, nMin-k);
}

int Partition(int arr[], int p, int r)
{
	assert(p <= r);

	int nTemp = arr[r];
	int i = p - 1, j = p;
	while(j < r) {
		if (arr[j] <= nTemp) {
			Swap(arr[i+1], arr[j]);
			i ++;
		}
		j ++;
	}
	Swap(arr[i+1], arr[r]);
	return i+1;
}

void Swap(int &n, int &m)
{
	int t = n;
	n = m;
	m = t;
}

int main()
{
	int arr[] = {5,7,10,3,6,2,8,9,4,1,11,12};
	int *karr = K_Select(arr, 12, 4);
	for (int i=0; i < 4; i ++)
		cout << karr[i] << " ";
	return 0;
}