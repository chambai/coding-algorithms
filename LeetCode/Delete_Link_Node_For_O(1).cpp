#include <iostream>

using namespace std;

/* Delete a node in a list with O(1)
 * input:	pListHead - the head of list
 *			pToBeDeleted - the node to be deleted
 */

struct  ListNode  
{
	int			m_nKey;
	ListNode*	m_pNext;
};

//创建一个链表结点
ListNode* CreateListNode(int n)
{
	ListNode *pHead = new ListNode();
	ListNode *pre = pHead;
	int i = 0;
	int value;
	while (i < n) {
		cin >> value;
		ListNode *pNode=new ListNode();
		pNode->m_nKey=value;
		pre->m_pNext = pNode;
		i ++;
	}
	
	return pHead->m_pNext;

}

//遍历链表中的所有结点
void PrintList(ListNode* pHead)
{
	ListNode *pNode=pHead;
	while(pNode!=NULL)
	{
		cout<<pNode->m_nKey<<" ";
		pNode=pNode->m_pNext;
	}
	cout<<endl;
}

void DeleteNode(ListNode *pListHead, ListNode *pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
		return;
	
	if (pToBeDeleted->m_pNext != NULL) {
		ListNode *pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		pToBeDeleted->m_nKey = pNext->m_nKey;

		delete pNext;
		pNext = NULL;
	}
	else {
		ListNode *pTemp = pListHead;
		while(pTemp->m_pNext != pToBeDeleted) 
			pTemp = pTemp->m_pNext;
		pTemp->m_pNext = NULL;

		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

// int main()
// {
// 	int n;
// 	cin >> n;
// 	ListNode *p = CreateListNode(n);
// 	ListNode *p1 = new ListNode();
// 	p1->m_nKey = 5;
// 	DeleteNode(p, p1);
// 	PrintList(p);
// 
// 	return 0;
// }
