// #include <iostream>
// #include <cassert>
// #include <cstdlib>
// 
// using namespace std;
// 
// struct ListNode {
// 	int val;
// 	ListNode *next;
// 	ListNode(int x):val(x), next(NULL) {}
// };
// 
// ListNode *GetLists(int n)
// {
// 	ListNode *l = new ListNode(0);
// 	ListNode *pre = l;
// 	int val;
// 	for (int i = 0; i < n; i ++) {
// 		cin >> val;
// 		ListNode *newNode = new ListNode(val);
// 		pre->next = newNode;
// 		pre = pre->next;
// 	}
// 	return l->next;
// }
// 
// ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
// {
// 	assert (NULL != l1 && NULL != l2);
// 	if (NULL == l1 && NULL == l2)
// 		return NULL;
// 	if (NULL == l1 && NULL != l2)
// 		return l2;
// 	if (NULL != l1 && NULL == l2)
// 		return l1;
// 	
// 	ListNode *temp = new ListNode(0);
// 	temp->next = l1;
// 	ListNode *pre = temp;
// 
// 	while(NULL != l1 && NULL != l2) {
// 		if (l1->val > l2->val) { //从小到大排列
// 			ListNode *next = l2->next;
// 			l2->next = pre->next;
// 			pre->next = l2;
// 			l2 = next;
// 		}		
// 		else {
// 			l1 = l1->next;
// 		}
// 		pre = pre->next;
// 	}
// 	if (NULL != l2) {
// 		pre->next = l2;
// 	}
// 	
// 	return temp->next;
// }
// 
// // int main()
// // {
// // 	int n;
// // 	cin >> n;
// // 	ListNode *l1 = GetLists(n);
// // 	ListNode *l2 = GetLists(n);
// // 
// // 	ListNode *l3 = mergeTwoLists(l1, l2);
// // 
// // 
// // 	return 0;
// // }