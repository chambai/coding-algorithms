#include <iostream>
#include <cassert>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * insertNodes(int n)
{
	ListNode *pNode = new ListNode(0);
	ListNode *p = pNode;
	int i = 0; 
	int m;
	while(i < n) {
		cin >> m;
		ListNode *pIn = new ListNode(m);
		p->next = pIn;
		p = pIn;

		i++;
	}
	return pNode->next;
}

void Print(ListNode *p) 
{
	ListNode *pT = p;
	while(NULL != pT) {
		cout << pT->val << " ";
		pT = pT->next;
	}
}

// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
// {
// 	assert(NULL != l1);
// 	assert(NULL != l2);
// 
// 	ListNode *pRetNode = new ListNode(0);
// 	ListNode *p = pRetNode;
// 	
// 	int div = 0;
// 	int nSumVal;
// 	while (NULL != l1 && NULL != l2) {
// 		nSumVal = l1->val + l2->val + div;
// 		div = nSumVal/10;
// 		ListNode *pT = new ListNode(nSumVal%10);
// 		p->next = pT;
// 		p = pT;
// 		
// 		l1 = l1->next;
// 		l2 = l2->next;
// 	}
// 	
// 	if (div != 0 ) {
// 		while (NULL != l1) {
// 			nSumVal = div + l1->val;
// 			div = nSumVal/10;
// 			ListNode *pT = new ListNode(nSumVal%10);
// 			p->next = pT;
// 			p = pT;
// 			l1 = l1->next;
// 		}
// 		while (NULL != l2) {
// 			nSumVal = div + l2->val;
// 			div = nSumVal/10;
// 			ListNode *pT = new ListNode(nSumVal%10);
// 			p->next = pT;
// 			p = pT;
// 			l2 = l2->next;
// 		}
// 		if (div != 0){
// 			ListNode *pT = new ListNode(div%10);
// 			p->next = pT;
// 			p = pT;
// 		}
// 	}
// 	if (div==0) {
// 		if (NULL != l1)
// 			p->next = l1;
// 		if (NULL != l2)
// 			p->next = l2;
// 	}
// 	return pRetNode->next;
// }

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	assert(NULL != l1);
	assert(NULL != l2);

	ListNode *pRetNode = new ListNode(0);
	ListNode *p = pRetNode;

	int div = 0;
	int nSumVal;
	while (NULL != l1 || NULL != l2) {
		int val1 = 0, val2 = 0;
		if (NULL != l1) {
			val1 = l1->val;
			l1 = l1->next;
		}
		if (NULL != l2) {
			val2 = l2->val;
			l2 = l2->next;
		}
		nSumVal = val1 + val2 + div;
		div = nSumVal/10;
		ListNode *pT = new ListNode(nSumVal%10);
		p->next = pT;
		p = pT;
	}
	if (div) {
		p->next = new ListNode(div);
	}
	return pRetNode->next;
}


// int main()
// {
// 	ListNode *p1 = insertNodes(1);
// 	ListNode *p2 = insertNodes(4);
// 	ListNode *p = addTwoNumbers(p1,p2);
// 	Print(p);
// 	return 0;
// }