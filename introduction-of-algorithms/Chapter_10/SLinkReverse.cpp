#include <iostream>

using namespace std;
#define N 3 
#define Y(n) ((N+1)*n)  

template<class T>
class Node 
{
public:
	template<class T> friend class SingleLink;

	//Node(Node *pNext = NULL):m_pNext(pNext) {}
	Node(T key = (T)0, Node *pNext = NULL):m_key(key), m_pNext(pNext) {}
	~Node(){}

private:
	T m_key;
	Node *m_pNext;
};

template<class T>
class SingleLink
{
public:
	SingleLink(Node<T> *pHead = NULL):m_pHead(pHead) {}
	~SingleLink(){}

	void Insert(const T& );
	void Delete(const T& );

	void Reverse();

	void Print();

private:
	Node<T> *m_pHead;
};

//”––Úµÿ≤Â»Î
template<class T>
void SingleLink<T>::Insert(const T& key)
{
	Node<T> *pInsert = new Node<T>(key);
	if (NULL == m_pHead)
		m_pHead = pInsert; 
	else {
		Node<T> *pTemp = m_pHead;
		Node<T> *qTemp = NULL;
		while (pTemp) {
			if (pTemp->m_key <= key) {
				qTemp = pTemp;
				pTemp = pTemp->m_pNext;
			}
			else break;
		}
		pInsert->m_pNext = pTemp;
		qTemp->m_pNext = pInsert;
	}
}

template<class T>
void SingleLink<T>::Delete(const T& key)
{
	if (NULL == m_pHead)
		return;

	if (m_pHead->m_key == key)
		m_pHead = NULL;
	else {
		Node<T> *pTemp = m_pHead;
		Node<T> *pDelete = m_pHead->m_pNext;
		while (pDelete) {
			if (pDelete->m_key != key) {
				pTemp = pDelete;
				pDelete = pDelete->m_pNext;
			}
			else {
				pTemp->m_pNext = pDelete->m_pNext;
				break;
			}
		}
	}
}

template<class T>
void SingleLink<T>::Reverse()
{
	//only one element
	if (NULL == m_pHead || NULL == m_pHead->m_pNext)
		return;
	
	//p->q->r
	Node<T> *p = NULL, *q = m_pHead, *r = NULL;
	while (true) {
		r = q->m_pNext;
		q->m_pNext = p;
		
		if (NULL == r) {
			m_pHead = q;		
			break;
		}
		p = q;
		q = r;
	}
}

template<class T>
void SingleLink<T>::Print()
{
	Node<T> *pTemp = m_pHead;
	while (pTemp) {
		cout << pTemp->m_key << " ";
		pTemp = pTemp->m_pNext;
	}
	cout << endl;
}

int main()
{
	SingleLink<int> SL;
	for (int i = 1; i <= 5; i ++)
		SL.Insert(i);
	SL.Print();
	SL.Insert(9);
	SL.Insert(7);
	SL.Print();
	SL.Delete(7);
	SL.Print();
	SL.Delete(6);
	SL.Print();
	SL.Reverse();
	SL.Print();
	return 0;
}