#include <iostream>
using namespace std;

/***********线性时间求最小值************/
int Minimun(int arr[], int n)
{
	int nMin = arr[0];
	for(int i = 1; i < n; i++)
		//min
		if(nMin > arr[i])
			nMin = arr[i];
		//max
// 		if (nMax < arr[i])
// 			nMax = arr[i];
	return nMin;
}

/***********通过3n/2次比较求最小值和最大值**********/
void MinAndMax(int arr[], int n, int &nMin, int &nMax)
{
	int i;
	//如果n是奇数
	if(n % 2 == 1)
	{
		//将最大值和最小值设置为第一个元素
		nMin = arr[1];
		nMax = arr[1];
		i = 2;
	}
	//如果n是偶数
	else
	{
		//将前两个元素作一次比较，以决定最大值怀最小值的初值
		nMin = min(arr[1], arr[2]);
		nMax = arr[1] + arr[2] - nMin;
		i = 3;
	}
	//成对地处理余下的元素
	for(; i < n; i=i+2)
	{
		//将一对输入元素互相比较
		int a = min(arr[i], arr[i+1]);
		int b = arr[i] + arr[i+1] - a;
		//把较小者与当前最小值比较
		if(a < nMin)
			nMin = a;
		//把较大者与当前最大值比较
		if(b > nMax)
			nMax = b;
	}
}
