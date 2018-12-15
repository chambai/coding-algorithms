#include <iostream>
#include <vector>
using namespace std;

#include "PriorityQueue.h"

//heap operation
void PriorityQueue::BuildMaxHeap()		//build the max heap
{
	int heap_size = GetHeapSize();
	for (int i = (heap_size-1)/2; i >= 0; i --)
		MaxHeapify(i);
}

void PriorityQueue::MaxHeapify(int index)	//protect the max heap
{
	if (index < 0 || index >= GetHeapSize())
		return;

	int heap_size = GetHeapSize();
	bool isHeapify = true; 

	int largest = -1;
	while (isHeapify && index < heap_size) {
		int left = getLeft(index);
		int right = getRight(index);

		if (left < heap_size && GetQueueElement(left) > GetQueueElement(index) )
			largest = left;
		else
			largest = index;
		if (right < heap_size && GetQueueElement(right) > GetQueueElement(largest) )
			largest = right;

		if (largest != index) {
			Swap(index, largest);
			index = largest;
		}
		else
			isHeapify = false;
	}

}

void PriorityQueue::HeapSort()			//heap sort
{
	BuildMaxHeap();
	int heap_size = GetHeapSize();
	for (int i = heap_size-1; i >= 1; i --) {
		Swap(0, i);
		SetHeapSizeMinus1(); //heap_size--;
		MaxHeapify(0);
	}
}

//priority queue operation
void PriorityQueue::HeapInsert(int key)	//insert key to the priority queue;
{
// 	SetHeapSizePlus1();
// 	int heap_size = GetHeapSize();
	AddQueueElement(INT_MIN);			//add the INT_MIN to the end of heapQueue;
	int heap_size = GetHeapSize();
	HeapIncreaseKey(heap_size-1, key);
}

int PriorityQueue::HeapMaximum()	//return the maximum key from priority queue;
{
	return GetQueueElement(0);		//the first element is max;
}

int PriorityQueue::HeapExtractMax()		//delete and return the maximum key from queue;
{
	if (IsEmptyHeap())
		throw "heap underflow";

	int heap_size = GetHeapSize();
	int maxNum = GetQueueElement(0); 
	SetQueueElement(0, GetQueueElement(heap_size-1)); //A[1] = A[heap_size]
	SetHeapSizeMinus1();
	MaxHeapify(0);    //Max_Heapify()
	return maxNum;
}

void PriorityQueue::HeapIncreaseKey(int srcIndex, int dstKey)	//increasing the srcKey to dstKey
{
	if (dstKey < GetQueueElement(srcIndex))
		throw "new key is smaller than current key!";
	SetQueueElement(srcIndex, dstKey); //x = key
	while(srcIndex > 0 && GetQueueElement(getParent(srcIndex)) < GetQueueElement(srcIndex)) {
		Swap(srcIndex, getParent(srcIndex));
		srcIndex = getParent(srcIndex); //get parent
	}
}

void PriorityQueue::HeapDelete(int key)	//delete key Ï°Ìâ6.5-8
{
	int heap_size = GetHeapSize();
	int index = 0;
	for (;index < heap_size; index ++) {
		if (GetQueueElement(index) == key)
			break;
	}
	SetQueueElement(index, GetQueueElement(heap_size-1));
	SetHeapSizeMinus1();
	MaxHeapify(index);
}

//other assist functions
void PriorityQueue::DisplayQueue()
{
	int nLen = GetArrayLength();
	cout << "------------------------" << endl;
	for (int i = 0; i < nLen; i ++)
		cout << GetQueueElement(i) << " ";
	cout << endl;
}

void PriorityQueue::DisplayHeapQueue()
{
	int heap_size = GetHeapSize();
	cout << "------------------------" << endl;
	for (int i = 0; i < heap_size; i ++)
		cout << GetQueueElement(i) << " ";
	cout << endl;
}

void PriorityQueue::AddQueueElement(int key)
{
	m_vecQueue.push_back(key);
	m_heapSize ++;
	m_length ++;
}


// int main()
// {
// 	//int key, num;
// 	PriorityQueue PQ;
// 
// // 	cout << "the number:" << endl;
// // 	cin >> num;
// 	int arr[] = {10,8,7,16,14,9,3,2,4,1};
// 	cout << "the key:" << endl;
// 	for (int i = 0; i < 10; i ++) {
// 		PQ.AddQueueElement(arr[i]);
// 	}
// 
// 	PQ.BuildMaxHeap();
// 	PQ.DisplayQueue();
// 
// 	//Max
// 	cout << "Max:" << PQ.HeapMaximum() << endl;
// 
// 	//IncreaseKey
// 	cout << "IncreaseKey:" << endl;
// 	PQ.HeapIncreaseKey(0, 18);
// 	PQ.DisplayHeapQueue();
// 	
// 	//InsertKey
// 	cout << "InsertKey:" << endl;
// 	PQ.HeapInsert(20);
// 	PQ.DisplayHeapQueue();
// 
// 	//Extract_Max
// 	cout << "Extract_Max:" << PQ.HeapExtractMax() << endl;
// 	PQ.DisplayHeapQueue();
// 
// 	//Extract_Max
// 	cout << "Extract_Max:" << PQ.HeapExtractMax() << endl;
// 	PQ.DisplayHeapQueue();
// 
// 	return 0;
// }