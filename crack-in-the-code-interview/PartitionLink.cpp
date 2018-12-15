#include <iostream>
#include <cassert>


using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* partition(ListNode* pHead, int x)
{
	// write code here
	assert(NULL != pHead);
	if (!pHead->next && pHead->val == x)
		return pHead;

	ListNode *pMinHead = new ListNode(0);
	ListNode *pMaxHead = new ListNode(0);

	ListNode *pT = pHead;
	ListNode *pMin = pMinHead;
	ListNode *pMax = pMaxHead;
	while (pT) {
		if (pT->val < x) {
			pMin->next = pT;
			pMin = pT;
		}
		else {
			pMax->next = pT;
			pMax = pT;
		}
		pT = pT->next;
	}
	pMax->next = NULL;
	pMin->next = pMaxHead->next;
	return pMinHead->next;
}

// ListNode* insert(int n)
// {
// 	int m;
// 	ListNode *pHead = new ListNode(0);
// 	ListNode *p = pHead;
// 	for (int i = 0; i < n; i ++) {
// 		cin >> m;
// 		ListNode *pIn = new ListNode(m);
// 		p->next = pIn;
// 		p = pIn;
// 	}
// 	return pHead->next;
// }
// 
// void print(ListNode *pHead)
// {
// 	ListNode *p = pHead;
// 	while(p) {
// 		cout << p->val << " ";
// 		p = p->next;
// 	}
// 	cout << endl;
// }

// int main()
// {
// 	ListNode *p = insert(5);
// 	ListNode *p1 = partition(p, 5);
// 
// 	print(p1);
// 
// 	return 0;
// }
