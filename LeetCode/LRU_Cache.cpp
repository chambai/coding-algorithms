#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>

using namespace std;

/************************************************************************/
/* ������汾                                                                    
/************************************************************************/
// struct Node {
// 	int		m_nKey;
// 	int		m_nValue;
// 	Node*	m_pNext;
// };
// 
// class LRUCache {
// public:
// 	LRUCache(int capacity) {
// 		m_nSize		= capacity;
// 		m_nCount	= 0;
// 		m_lruList	= NULL;
// 	}
// 
// 	int get(int key) {
// 		if (NULL == m_lruList) 
// 			return -1;
// 		map<int, Node *>::iterator it = m_lruMap.find(key);
// 		if (it == m_lruMap.end()) //û���ҵ�
// 			return -1;
// 		else {
// 			Node *p = it->second;
// 			//�ѽڵ��Ƶ�����Ŀ�ͷ
// 			pushFront(p);
// 		}
// 		return m_lruList->m_nValue;
// 	}
// 
// 	void set(int key, int value) {
// 		if (NULL == m_lruList) {
// 			m_lruList = new Node();
// 			m_lruList->m_nKey = key;
// 			m_lruList->m_nValue = value;
// 			m_lruList->m_pNext = NULL;
// 			m_nCount ++;
// 			m_lruMap[key] = m_lruList;
// 		}
// 		else {
// 			map<int, Node *>::iterator it = m_lruMap.find(key);
// 			if (it == m_lruMap.end()){ //û������,����������һ���ڵ�ɾ��
// 				if (m_nSize == m_nCount) { //cache����
// 					Node *pHead = m_lruList;
// 					Node *pTemp = pHead;
// 					while(pHead->m_pNext != NULL) {
// 						pTemp = pHead;
// 						pHead = pHead->m_pNext;
// 					}
// 					m_lruMap.erase(pHead->m_nKey);
// 					m_nCount --;
// 					if (pHead == pTemp) //ֻ��һ���ڵ�
// 						pHead = NULL;
// 					else
// 						pTemp->m_pNext = NULL;
// 				}
// 				Node *p = new Node(); //�����µĽڵ���ͷ��
// 				p->m_nKey = key;
// 				p->m_nValue = value;
// 				p->m_pNext = m_lruList;
// 				m_lruList = p;
// 				m_lruMap[key] = m_lruList;
// 				m_nCount ++;
// 			}
// 			else { //���У��򽫸����еĽڵ���������ͷ��
// 				Node *pCur = it->second;
// 				pCur->m_nValue = value;
// 				pushFront(pCur);
// 			}
// 		}
// 	}
// 
// 	void pushFront(Node *pCur) {  //�ѽڵ��ƶ�������ͷ����ʱ�临�Ӷ�O(n)
// 		if (NULL == pCur) 
// 			return;
// 		if (m_nCount == 1 || pCur == m_lruList) 
// 			return;
// 		Node *pHead = m_lruList;
// 		while (pHead->m_pNext != pCur) 
// 			pHead = pHead->m_pNext;
// 		pHead->m_pNext = pCur->m_pNext;
// 		pCur->m_pNext = m_lruList;
// 		m_lruList = pCur;
// 	}
// 
// 	void printCache() {
// 		Node *p = m_lruList;
// 		while (p) {
// 			cout << p->m_nKey << ":" << p->m_nValue << " ";
// 			p = p->m_pNext;
// 		}
// 	}
// 
// private:
// 	int					m_nSize;
// 	int					m_nCount;
// 	map<int, Node *>	m_lruMap;
// 	Node*				m_lruList;
// };

/************************************************************************/
/* ˫����汾                                                                   
/************************************************************************/
// struct Node {
// 	int		m_nKey;
// 	int		m_nValue;
// 	Node*	m_pNext;
// 	Node*   m_pPre;
// };
// 
// class LRUCache {
// public:
// 	LRUCache(int capacity) {
// 		m_nSize			= capacity;
// 		m_nCount		= 0;
// 		m_lruListHead	= NULL;
// 		m_lruListTail	= NULL;
// 	}
// 
// 	int get(int key) {
// 		if (NULL == m_lruListHead) 
// 			return -1;
// 		map<int, Node *>::iterator it = m_lruMap.find(key);
// 		if (it == m_lruMap.end()) //û���ҵ�
// 			return -1;
// 		else {
// 			Node *p = it->second;
// 			//�ѽڵ��Ƶ�����Ŀ�ͷ
// 			pushFront(p);
// 		}
// 		return m_lruListHead->m_nValue;
// 	}
// 
// 	void set(int key, int value) {
// 		if (NULL == m_lruListHead) {
// 			m_lruListHead = new Node();
// 			m_lruListHead->m_nKey = key;
// 			m_lruListHead->m_nValue = value;
// 			m_lruListHead->m_pNext = NULL;
// 			m_lruListHead->m_pPre = NULL;
// 			m_lruListTail = m_lruListHead;
// 			m_nCount ++;
// 			m_lruMap[key] = m_lruListHead;
// 		}
// 		else {
// 			map<int, Node *>::iterator it = m_lruMap.find(key);
// 			if (it == m_lruMap.end()){ //û������,����������һ���ڵ�ɾ��
// 				if (m_nSize == m_nCount) { //cache����
// 					if (m_lruListHead == m_lruListTail) {//ֻ��һ���ڵ�
// 						m_lruMap.erase(m_lruListHead->m_nKey);
// 						m_lruListHead->m_nKey = key;
// 						m_lruListHead->m_nValue = value;
// 						m_lruMap[key] = m_lruListHead;
// 					}
// 					else {
// 						Node *p = m_lruListTail;
// 						m_lruListTail->m_pPre->m_pNext = NULL;
// 						m_lruListTail = m_lruListTail->m_pPre;
// 						m_lruMap.erase(p->m_nKey);
// 
// 						p->m_nKey = key;
// 						p->m_nValue = value;
// 						p->m_pNext = m_lruListHead;
// 						p->m_pPre = NULL;
// 						m_lruListHead->m_pPre = p;
// 						m_lruListHead = p;
// 						m_lruMap[key] = m_lruListHead;
// 					}
// 				}
// 				else {
// 					Node *p = new Node(); //�����µĽڵ���ͷ��
// 					p->m_nKey = key;
// 					p->m_nValue = value;
// 					p->m_pNext = m_lruListHead;
// 					p->m_pPre = NULL;
// 					m_lruListHead->m_pPre = p;
// 					m_lruListHead = p;
// 					m_lruMap[key] = m_lruListHead;
// 					m_nCount ++;
// 				}
// 			}
// 			else { //���У��򽫸����еĽڵ���������ͷ��
// 				Node *pCur = it->second;
// 				pCur->m_nValue = value;
// 				pushFront(pCur);
// 			}
// 		}
// 	}
// 
// 	void pushFront(Node *pCur) {  //�ѽڵ��ƶ�������ͷ����ʱ�临�Ӷ�O(1)
// 		if (NULL == pCur) 
// 			return;
// 		if (m_nCount == 1 || pCur == m_lruListHead) 
// 			return;
// 		if (pCur == m_lruListTail) { //������β�ڵ�
// 			pCur->m_pPre->m_pNext = NULL;
// 			pCur->m_pNext = m_lruListHead;
// 			m_lruListTail = pCur->m_pPre;
// 			m_lruListHead->m_pPre = pCur;
// 			m_lruListHead = pCur;
// 		}
// 		else {
// 			pCur->m_pPre->m_pNext = pCur->m_pNext;
// 			pCur->m_pNext->m_pPre = pCur->m_pPre;
// 
// 			pCur->m_pNext = m_lruListHead;
// 			m_lruListHead->m_pPre = pCur;
// 			m_lruListHead = pCur;
// 		}
// 	}
// 
// 	void printCache() {
// 		Node *p = m_lruListHead;
// 		while (p) {
// 			cout << p->m_nKey << ":" << p->m_nValue << " ";
// 			p = p->m_pNext;
// 		}
// 	}
// 
// private:
// 	int					m_nSize;
// 	int					m_nCount;
// 	map<int, Node *>	m_lruMap;
// 	Node*				m_lruListHead;
// 	Node*				m_lruListTail;
// };

/************************************************************************/
/* hashmap + list(STL�Դ���)                                                                     
/************************************************************************/

struct Node {
	int		m_nKey;
	int		m_nValue;
	Node*	m_pNext;
};

class LRUCache {
public:
	LRUCache(int capacity) {
		m_nSize		= capacity;
		m_nCount	= 0;
		m_lruList	= NULL;
	}

	int get(int key) {
		if (NULL == m_lruList) 
			return -1;
		map<int, Node *>::iterator it = m_lruMap.find(key);
		if (it == m_lruMap.end()) //û���ҵ�
			return -1;
		else {
			Node *p = it->second;
			//�ѽڵ��Ƶ�����Ŀ�ͷ
			pushFront(p);
		}
		return m_lruList->m_nValue;
	}

	void set(int key, int value) {
		if (NULL == m_lruList) {
			m_lruList = new Node();
			m_lruList->m_nKey = key;
			m_lruList->m_nValue = value;
			m_lruList->m_pNext = NULL;
			m_nCount ++;
			m_lruMap[key] = m_lruList;
		}
		else {
			map<int, Node *>::iterator it = m_lruMap.find(key);
			if (it == m_lruMap.end()){ //û������,����������һ���ڵ�ɾ��
				if (m_nSize == m_nCount) { //cache����
					Node *pHead = m_lruList;
					Node *pTemp = pHead;
					while(pHead->m_pNext != NULL) {
						pTemp = pHead;
						pHead = pHead->m_pNext;
					}
					m_lruMap.erase(pHead->m_nKey);
					m_nCount --;
					if (pHead == pTemp) //ֻ��һ���ڵ�
						pHead = NULL;
					else
						pTemp->m_pNext = NULL;
				}
				Node *p = new Node(); //�����µĽڵ���ͷ��
				p->m_nKey = key;
				p->m_nValue = value;
				p->m_pNext = m_lruList;
				m_lruList = p;
				m_lruMap[key] = m_lruList;
				m_nCount ++;
			}
			else { //���У��򽫸����еĽڵ���������ͷ��
				Node *pCur = it->second;
				pCur->m_nValue = value;
				pushFront(pCur);
			}
		}
	}

	void pushFront(Node *pCur) {  //�ѽڵ��ƶ�������ͷ����ʱ�临�Ӷ�O(n)
		if (NULL == pCur) 
			return;
		if (m_nCount == 1 || pCur == m_lruList) 
			return;
		Node *pHead = m_lruList;
		while (pHead->m_pNext != pCur) 
			pHead = pHead->m_pNext;
		pHead->m_pNext = pCur->m_pNext;
		pCur->m_pNext = m_lruList;
		m_lruList = pCur;
	}

	void printCache() {
		Node *p = m_lruList;
		while (p) {
			cout << p->m_nKey << ":" << p->m_nValue << " ";
			p = p->m_pNext;
		}
	}

private:
	int					m_nSize;
	int					m_nCount;
	map<int, Node *>	m_lruMap;
	Node*				m_lruList;
};

// int main()
// {
// 	LRUCache lru(3);
// 	lru.set(2,4);
// 	//lru.printCache();
// 	lru.set(1,5);
// 	lru.set(1,6);
// 	lru.set(3,6);
// 	lru.set(4,6);
// 	lru.printCache();
// 	return 0;
// }
