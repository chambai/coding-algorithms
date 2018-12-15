#include <iostream>
#include <ctime>

using namespace std;

void QuickSort(int arr[], int left, int right);
void Hoare_QuickSort(int arr[], int left, int right);
void Random_QuickSort(int arr[], int left, int right);

int Hoare_Partition(int arr[], int left, int right);
int Partitioin(int arr[], int left, int right);
void Swap(int &a, int &b);


void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Hoare_Partition(int arr[], int left, int right)
{
	int temp = arr[left];
	int i = left;
	int j = right;

	while(i < j) {
		while (arr[j] >= temp && i < j) //from right to left
			j --;
		while (arr[i] <= temp && i < j) //from left to right
			i ++;
		Swap(arr[i], arr[j]);
	} 
	Swap(arr[left], arr[i]);
	return i;
}

int Partition(int arr[], int left, int right)
{
	int temp = arr[right];
	int i = left - 1;
	
	for (int j = left; j <= right-1; j ++) {
		if (arr[j] <= temp) {
			i ++;
			Swap(arr[i], arr[j]);
		}
	}
	Swap(arr[right], arr[i+1]); //!!!note: can't use temp:local variable
	return i+1;
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right) {
		int mid = Partition(arr, left, right);
		QuickSort(arr, left, mid-1);
		QuickSort(arr, mid+1, right);
	}
}

void Hoare_QuickSort(int arr[], int left, int right)
{
	if (left < right) {
		int mid = Hoare_Partition(arr, left, right);
		Hoare_QuickSort(arr, left, mid-1);
		Hoare_QuickSort(arr, mid+1, right);
	}
}

//get random num between m and n;
int Random(int m, int n)
{
	srand((unsigned int)time(0));
	int ret = m + rand() % (n-m+1);
	return ret;
}

//get mid num of a,b,c;
int MidNum(int a, int b, int c)
{
	if ((a-b)*(a-c) <= 0)
		return a;
	else if ((b-a)*(b-c) <= 0)
		return b;
	else if ((c-a)*(c-b) <= 0)
		return c;
}

void Random_QuickSort(int arr[], int left, int right)
{
	int index = Random(left, right);

	Swap(arr[index], arr[right]);
	QuickSort(arr, left, right);
}

void Tail_Recursive_QuickSort(int arr[], int left, int right)
{
	while (left < right) { //use while not if
		int mid = Partition(arr, left, right);
		Tail_Recursive_QuickSort(arr, left, mid-1);
		left = mid + 1;
	}
}

void Tail_Recursive_QuickSort_Optimize(int arr[], int left, int right)
{
	while(left < right) {
		int mid = Partition(arr, left, right);
		if (mid-left < right-mid) {
			Tail_Recursive_QuickSort_Optimize(arr, left, mid-1);
			left = mid + 1;
		}
		else {
			Tail_Recursive_QuickSort_Optimize(arr, mid+1, right);
			right = mid - 1;
		}
	}
}

int main()
{
	int arr[] = {3,2,8,7,4,2,10,45,23,12,14};
	Tail_Recursive_QuickSort_Optimize(arr, 0, 10);
	//Random_QuickSort(arr, 0, 10);
	for (int i = 0; i < 11; i ++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	int a = Random(0,10);
	int b = Random(0,10);
	int c = Random(0,10);

	int d = MidNum(a,b,c);
	cout << a << " " << b << " " << c << " " << d;
	return 0;
}