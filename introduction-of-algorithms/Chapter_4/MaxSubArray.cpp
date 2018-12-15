#include <iostream>
#include <vector>
using namespace std;

/************************************************************************/
/*  暴力法                                                       
/************************************************************************/
void MaxSubArraySum_Force(int arr[], vector<int> &subarr, int len)
{
	if (len == 0)
		return;
	int nMax = INT_MIN;
	int low = 0, high = 0;
	for (int i = 0; i < len; i ++) {
		int nSum = 0;
		for (int j = i; j < len; j ++) {
			nSum += arr[j];
			if (nSum > nMax) {
				nMax = nSum;
				low = i;
				high = j;
			}
		}
	}
	for (int i = low; i <= high; i ++) {
		subarr.push_back(arr[i]);
	}
}

/************************************************************************/
/*	贪心法
	求A[1...j+1]的最大和子数组，有两种情况：
	1)A[1...j]的最大和子数组
	2)某个A[i...j+1]的最大和子数组                                                      
/************************************************************************/
void MaxSubArraySum_Greedy(int arr[], vector<int> &subarr, int len)
{
	if (len == 0)
		return;
	int nMax = INT_MIN;
	int low = 0, high = 0;
	int cur = 0; //一个指针更新子数组的左区间
	int nSum = 0;
	for (int i = 0; i < len; i ++) {
		nSum += arr[i];
		if (nSum > nMax) {
			nMax = nSum;
			low = cur;
			high = i;
		}
		if (nSum < 0) {
			cur += 1;
			nSum = 0;
		}
	}
//	if (nMax > 0) 
	for (int i = low; i <= high; i ++)
		subarr.push_back(arr[i]);
// 	else               //假如数组允许为空
// 		return;
}

/************************************************************************/
/*  动态规划（对应着上面的贪心法看，略有不同）
	求A[1...j+1]的最大和子数组，有两种情况：
		1)A[1...j]+A[j+1]的最大和子数组
		2)A[j+1]
	dp递推式：
		sum[j+1] = max(sum[j] + A[j+1], A[j+1])
/************************************************************************/
int MaxSubArraySum_dp(int arr[], int len)
{
	if (len <= 0)
		exit(-1);
	int nMax = INT_MIN;
	int sum = 0;
	
	for (int i = 0; i < len; i ++) {
		if (sum >= 0) 
			sum += arr[i];
		else
			sum = arr[i];
		if (sum > nMax)
			nMax = sum;
	}
	return nMax;
}

/************************************************************************/
/*	分治法
	最大和子数组有三种情况：
	1)A[1...mid]
	2)A[mid+1...N]
	3)A[i..mid..j]
/************************************************************************/
//find max crossing left and right
int Find_Max_Crossing_Subarray(int arr[], int low, int mid, int high)
{
	const int infinite = -9999;
	int left_sum = infinite;
	int right_sum = infinite;

	int max_left = -1, max_right = -1;

	int sum = 0; //from mid to left;
	for (int i = mid; i >= low; i --) {
		sum += arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;		
		}
	}
	sum = 0;  //from mid to right
	for (int j = mid + 1; j <= high; j ++) {
		sum += arr[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	return (left_sum + right_sum);
}

int Find_Maximum_Subarray(int arr[], int low, int high)
{
	if (high == low) //only one element;
		return arr[low];
	else {
		int mid = (low + high)/2;
		int leftSum = Find_Maximum_Subarray(arr, low, mid);
		int rightSum = Find_Maximum_Subarray(arr, mid+1, high);
		int crossSum = Find_Max_Crossing_Subarray(arr, low, mid, high);

		if (leftSum >= rightSum && leftSum >= crossSum)
			return leftSum;
		else if (rightSum >= leftSum && rightSum >= crossSum)
			return rightSum;
		else 
			return crossSum;
	}
}

int main()
{
	int arr[5] = {-7,-7,-2,-4,-4};
	vector<int> subarr;
	int nmax = MaxSubArraySum_dp(arr, 5);
	cout << nmax;
// 	int len = sizeof(arr)/sizeof(int);
// 	
// 	int maxarr = Find_Maximum_Subarray(arr, 0, 4);
// 	cout << maxarr;
// 	for(vector<int>::iterator it = subarr.begin(); it != subarr.end(); ++it)
// 		cout << *it << " ";
	return 0;
}