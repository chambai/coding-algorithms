#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

// 思路：用两个指针来指向字数组的头尾
int maxProduct(int A[], int n)
{
	assert(n > 0);
	int subArrayProduct = -32768; 
	
	for (int i = 0; i != n; ++ i) {
		int nTempProduct = 1;
		for (int j = i; j != n; ++ j) {
			if (j == i)
				nTempProduct = A[i];
			else
				nTempProduct *= A[j];
			if (nTempProduct >= subArrayProduct)
 				subArrayProduct = nTempProduct;
// 			else 
// 				break; //为了少计算后面的乘积
		}
	}
	return subArrayProduct;
}

int maxProduct1(int A[], int n)
{
	assert(n > 0);
	if (n <= 0)
		return 0;

	if (n == 1)
		return A[0];
	int max_local = A[0];
	int min_local = A[0];

	int global = A[0];
	for (int i = 1; i != n; ++ i) {
		int max_copy = max_local;
		max_local = MAX(MAX(A[i] * max_local, A[i]), A[i] * min_local);
		min_local = MIN(MIN(A[i] * max_copy, A[i]), A[i] * min_local);
		global = MAX(global, max_local);
	}
	return global;
}

int maxSubArray(int A[], int n)
{
	assert(n > 0);
	if (n <= 0)
		return 0;
	int global = A[0];
	int local = A[0];
	
	for(int i = 1; i != n; ++ i) {
		local = MAX(A[i], local + A[i]);
		global = MAX(local, global);
	}
	return global;
}

// int main()
// {
// 	int A[5] = {2,3,-2,-5,6};
// 	cout << maxSubArray(A, 5);
// 	cout << maxProduct1(A, 5);
// 	return 0;
// }