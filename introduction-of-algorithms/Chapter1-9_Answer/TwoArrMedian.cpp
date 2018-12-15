#include <iostream>
#include <cassert>
using namespace std;

int SelectMedian(int *arrA, int *arrB, int left, int right)
{
	assert(NULL != arrA);
	assert(NULL != arrB);
	
	int nLen = right-left+1;

	while (left <= right) {
		int mid = (left+right)/2;

		if (mid == nLen-1 && arrA[mid] <= arrB[0]) //only one element
			return arrA[mid];
		else if (mid < nLen-1) {
			if(arrA[mid] <= arrB[nLen-mid] && arrA[mid] > arrB[nLen-1-mid]) //K = nLen-1-K note:from 0 index
				return arrA[mid];
			else if (arrA[mid] <= arrB[nLen-1-mid]) //if the element is small, find it in right region.
				left = mid + 1;
			else		 //if the element is big, find it in left region.
				right = mid - 1;
		}
	}
	return -1;
}

//find the median of two array: arrA and arrB
//return the median of two array
void TwoArrMedian(int *arrA, int *arrB, int nLen)
{
	assert(NULL != arrA);
	assert(NULL != arrB);
	
	int nMedian;
	if (SelectMedian(arrA, arrB, 0, nLen-1) == -1) //not find
		nMedian = SelectMedian(arrB, arrA, 0, nLen-1);
	
	cout << nMedian << endl;
}

int main()
{
	int a[] = {1,2,3,4,8,9,13};
	int b[] = {2,5,6,7,10,11,12};

	TwoArrMedian(a, b, 7);
	return 0;
}