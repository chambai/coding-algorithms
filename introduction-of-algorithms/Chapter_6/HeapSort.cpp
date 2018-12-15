#include <iostream>

using namespace std;


//#include "HeapSort.h"

#define PARENT(x) ((x-1)/2)	//求 x 父节点的下标
#define LEFT(x) ((x)*2+1)	//求 x 左孩子的下标
#define RIGHT(x) ((x)*2+2)	//求 x 右孩子的下标

void MaxHeapify(int arr[], int heap_size, int index);		//维护最大堆的性质
void MaxHeapify_Recur(int arr[], int heap_size, int index); //递归
void BuildMaxHeap(int arr[], int heap_size);					//从一个无序的数组中构造一个最大堆
void HeapSort(int arr[], int length);							//堆排序
void Swap(int &a, int &b);

void MaxHeapify(int arr[], int heap_size, int index)
{
	if (index < 0 && index >= heap_size)
		return;
	
	bool isHeapify = true; //标识最大堆是否处理完
	while (isHeapify && index < heap_size) {
		int left = LEFT(index);
		int right = RIGHT(index);
		int largest;

		if (left < heap_size && arr[left] > arr[index]) 
			largest = left;
		else 
			largest = index;

		if (right < heap_size && arr[right] > arr[largest])
			largest = right;

		if (largest != index) {
			Swap(arr[index], arr[largest]);
			index = largest;
		}
		else
			isHeapify = false;
	}
}

void MaxHeapify_Recur(int arr[], int heap_size, int index)
{
	if (index <=0 && index >= heap_size)
		return;

	int left = LEFT(index);
	int right = RIGHT(index);
	int largest;

	if (left < heap_size && arr[left] > arr[index])
		largest = left;
	else 
		largest = index;

	if (right < heap_size && arr[right] > arr[largest])
		largest = right;

	if (largest != index) {
		Swap(arr[index], arr[largest]);
		MaxHeapify_Recur(arr, heap_size, largest);
	}
}

void BuildMaxHeap(int arr[], int heap_size)
{
	if (heap_size == 0)
		return;
	
	for (int i = (heap_size-1)/2; i >= 0; i--)
		MaxHeapify(arr, heap_size, i);
}

void HeapSort(int arr[], int length)
{
	if (length == 0)
		return;

	int heap_size = length;
	BuildMaxHeap(arr, heap_size);
	for (int i = length-1; i >= 1; i --) {
		Swap(arr[0], arr[i]);
		heap_size --;
		MaxHeapify(arr, heap_size, 0);
	}
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// int main()
// {
// 	int arr[10] = {10,14,16,8,7,9,3,2,4,1};
// 	HeapSort(arr, 10);
// 	for (int i = 0; i < 10; i ++)
// 		cout << arr[i] << " ";
// 	return 0;
// }