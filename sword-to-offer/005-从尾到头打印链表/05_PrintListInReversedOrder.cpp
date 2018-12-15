#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
using namespace std;

//�����ӡ����
struct ListNode {
	int			m_nKey;
	ListNode	*m_pNext;
};

//������
void PrintListReversingly_Iteratively(ListNode *pHead) 
{
	assert( NULL != pHead );
	if (NULL == pHead)
		return;

	stack<int> slink;
	//��ջ
	while ( pHead ) {
		slink.push( pHead->m_nKey );
		pHead = pHead->m_pNext;
	}
	//��ջ
	while ( !slink.empty() ) {
		cout << slink.top();
		slink.pop();
	}
}

//�ݹ鷨
void PrintListReversingly_Recursively(ListNode *pHead)
{
	assert( NULL != pHead );
	if (NULL == pHead)
		return;

	if ( pHead != NULL ) {
		if ( pHead->m_pNext != NULL ) {
			PrintListReversingly_Recursively( pHead->m_pNext );
		}
		cout << pHead->m_nKey;
	}
}

ListNode* InsertNode( int num )
{
	ListNode *pHead = new ListNode();
	ListNode *pTemp = pHead;

	for (int i = 1; i <= num; i ++) {
		ListNode *node = new ListNode();
		node->m_nKey = i;
		node->m_pNext = NULL;
		pTemp->m_pNext = node;
		pTemp = pTemp->m_pNext;
	}
	return pHead->m_pNext;
}

int main()
{
	int n;
	cin >> n;
	ListNode *pH = InsertNode(n);
	PrintListReversingly_Recursively(pH);
	cout << endl;
	PrintListReversingly_Iteratively(pH);
	return 0;
}