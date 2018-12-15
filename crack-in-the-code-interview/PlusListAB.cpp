#include <iostream>
#include <cassert>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* plusAB(ListNode* a, ListNode* b) 
{
	assert(NULL != a);
	assert(NULL != b);

	ListNode *pHead = new ListNode(0);
	ListNode *p = pHead;

	int div = 0; //³ýÊý
	while (a || b) {
		int val1 = (a ? a->val:0);
		int val2 = (b ? b->val:0);
		int val = val1 + val2 + div;
		ListNode *pA = new ListNode(val%10);

		div = val/10;
		p->next = pA;
		p = pA;

		if (a) 
			a = a->next;
		if (b) 
			b = b->next;
	}
	if (div == 1) {
		ListNode *pA = new ListNode(div);
		p->next = pA;
	}
	return pHead->next;
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
// 
// int main()
// {
// 	ListNode *p1 = insert(3);
// 	ListNode *p2 = insert(4);
// 	ListNode *p = plusAB(p1,p2);
// 	print(p);
// 	return 0;
// }