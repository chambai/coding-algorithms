#include <iostream>
#include <vector>

using namespace std;

#include "MinHeap.h"

//merge the k list to a heap;
template<class T>
MinHeap<T>::MinHeap(size_t kSize) 
{
	if (!m_minHeap)
		delete []m_minHeap;
	m_minHeap = new T[kSize+1];
	m_heapSize = 0;
}

//adjust the min heap;
template<class T>
void MinHeap<T>::MinHeapify(const size_t index)
{
	//assert
	int heap_size = GetHeapSize();

	while (true) {
		size_t left = LEFT(index);
		size_t right = RIGHT(index);
		
		size_t smallest;
		if (left < heap_size && HeapCompare(index, left) > 0)
			smallest = left;
		else smallest = index;
		if (right < heap_size && HeapCompare(smallest, right) > 0)
			smallest = right;

		if (smallest != index) {
			Swap(index, smallest);
			index = smallest;
		}
		else break;
	}
}

//insert element
template<class T>
void MinHeap<T>::HeapInsert(const T &element)
{
	m_minHeap[m_heapSize] = element;
	m_heapSize += 1;

	size_t index = m_heapSize-1;

	while (index > 0 && HeapCompare(index, PARENT(index)) < 0) {
		Swap(index, PARENT(index));
		index = PARENT(index);
	}
}

//return and delete the min element
template<class T>
T MinHeap<T>::HeapExtractMin() const
{
	if (IsEmptyHeap())
		throw "Heap is Empty!";
	T minElement = HeapMin();

	int heap_size = GetHeapSize();
	m_minHeap[0] = m_minHeap[heap_size-1];
	m_heapSize -= 1;
	MinHeapify(0);
	return minElement;
}

//return min element;
template<class T>
T	MinHeap<T>::HeapMin() const
{
	return m_minHeap[0];
}

int main()
{
	size_t k = 3;
	vector<int> vecList[k];
	vector<int>::iterator iterList[k];
	vector<int> vecSort;
	vector<int>::iterator iterS;
	
	vector<int>::iterator it;

	MinHeap<vector<int>::iterator> minHeap(k);
	//first list
	vecList[0].push_back(12);
	vecList[0].push_back(24);
	vecList[0].push_back(52);
	cout << "first list:" << endl;
	for ( it = vecList[0].begin();it != vecList[0].end(); ++it) 
		cout << *it << "->";
	cout << "NULL" << endl;

	vecList[1].push_back(9);
	vecList[1].push_back(32);
	
	cout << "second list:" << endl;
	for ( it = vecList[1].begin();it != vecList[1].end(); ++it) 
		cout << *it << "->";
	cout << "NULL" << endl;

	vecList[2].push_back(34);
	vecList[2].push_back(42);
	vecList[2].push_back(78);
	cout << "third list:" << endl;
	for ( it = vecList[2].begin();it != vecList[2].end(); ++it) 
		cout << *it << "->";
	cout << "NULL" << endl;
	
	iterList[0] = vecList[0].begin();
	iterList[1] = vecList[1].begin();
	iterList[2] = vecList[2].begin();

	minHeap.HeapInsert(iterList[0]);
	minHeap.HeapInsert(iterList[1]);
	minHeap.HeapInsert(iterList[2]);

	while(minHeap.GetHeapSize()) {
		it = minHeap.HeapExtractMin();
		vecSort.push_back(*it);
		++it;
		if (it != vecList[0].end()&& it != vecList[1].end() && it != vecList[2].end()) {
			minHeap.HeapInsert(it);
		}
	}

	cout << "meger:" << endl;
	for (iterS = vecSort.begin(); iterS != vecSort.end(); ++ iterS)
		cout << *iterS << "->";
	cout << "NULL" << endl;

	return 0;
}