#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

/************************************************************************/
/*	priority queue                                                                   
/************************************************************************/
class PriorityQueue {
public:
	PriorityQueue() { m_heapSize = 0; m_length = 0; }
	~PriorityQueue() {}
	
	//inline
	int getParent(int index) { return (index-1)/2; }
	int getLeft(int index) { return 2*index + 1; }
	int getRight(int index) { return 2*index + 2; }

	//heap operation
	void BuildMaxHeap();		//build the max heap
	void MaxHeapify(int index);	//protect the max heap
	void HeapSort();			//heap sort
	
	//priority queue operation
	void HeapInsert(int key);	//insert key to the priority queue;
	int HeapMaximum();			//return the maximum key from priority queue;
	int HeapExtractMax();		//delete and return the maximum key from queue;
	void HeapIncreaseKey(int srcIndex, int dstKey);	//increasing the srcKey to dstKey
	
	void HeapDelete(int key);	//delete key 习题6.5-8
	
	//other assist functions
	void AddQueueElement(int key);
	void DisplayQueue();
	void DisplayHeapQueue();

public:
	
	
private:
	int GetQueueElement(int index) { return m_vecQueue[index]; }
	void SetQueueElement(int index, int key) { m_vecQueue[index] = key; }
	void Swap(int i, int j) { 
		int temp = m_vecQueue[i]; 
		m_vecQueue[i] = m_vecQueue[j]; 
		m_vecQueue[j] = temp; 
	}
	int GetHeapSize() { return m_heapSize; }
	int GetArrayLength() { return m_length; }
	void SetHeapSizeMinus1() { m_heapSize = m_heapSize - 1; }
	void SetHeapSizePlus1() { m_heapSize = m_heapSize + 1; }

	bool IsEmptyHeap() { return (m_heapSize > 1 ? false : true); }

private:
	vector<int>		m_vecQueue;
	int				m_heapSize;	//堆元素个数
	int				m_length;	//数组元素个数
	
};


#endif//_PRIORITY_QUEUE_H_