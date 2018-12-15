#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};


ListNode *GetLists(int n)
{
	ListNode *l = new ListNode(0);
	ListNode *pre = l;
	int val;
	for (int i = 0; i < n; i ++) {
		cin >> val;
		ListNode *newNode = new ListNode(val);
		pre->next = newNode;
		pre = pre->next;
	}
	return l->next;
}

ListNode *sortList(ListNode *head) 
{
	assert(NULL != head);
	if (NULL == head)
		return NULL;

	ListNode *p = head;
	int len = 0;		//get the length of link
	while (NULL != p) {
		p = p->next;
		len ++;
	}

	ListNode *temp = new ListNode(0);
	temp->next = head;
	
	int interval = 1;   //合并子列表的长度
	for (; interval <= len; interval *= 2) {
		ListNode *pre = temp;
		ListNode *first = temp->next;  //两段子列表的起始位置
		ListNode *second = temp->next;

		while (NULL != first || NULL != second) {
			int i = 0;
			while (i < interval && NULL != second) {
				second = second->next; //将second移到第二段子列表的起始处
				i ++;
			}

			int fvisit = 0, svisit = 0; //访问子列表的的次数<interval，保证列表中的元素全部能被访问
			while (fvisit < interval && svisit < interval && NULL != first && NULL != second) {
				if (first->val < second->val) {
					pre->next = first;
					pre = first;
					first = first->next;
					fvisit ++;
				}
				else {
					pre->next = second;
					pre = second;
					second = second->next;
					svisit ++;
				}
			}
			while (fvisit < interval && NULL != first) {
				pre->next = first;
				pre = first;
				first = first->next;
				fvisit ++;
			}
			while (svisit < interval && NULL != second) {
				pre->next = second;
				pre = second;
				second = second->next;
				svisit ++;
			}
			pre->next = second;
			first = second;
		}
	}
	ListNode *retResult = temp->next;
	delete temp;
	temp = NULL;
	return retResult;
}

// ListNode *sortList(ListNode *head) {  
// 	// Get length first  
// 	ListNode* p = head;  
// 	int len = 0;  
// 	while (p != NULL)  
// 	{  
// 		p = p->next;  
// 		len++;  
// 	}  
// 	ListNode* fakehead = new ListNode(-1);  
// 	fakehead->next = head;       
// 	for (int interval = 1; interval <= len; interval = interval * 2)  
// 	{  
// 		ListNode* pre = fakehead;  
// 		ListNode* slow = fakehead->next, *fast = fakehead->next;  
// 		while (fast != NULL || slow != NULL)  
// 		{  
// 			int i = 0;  
// 			while (i< interval && fast != NULL)  
// 			{  
// 				fast = fast->next; //move fast pointer ahead 'interval' steps  
// 				i++;  
// 			}  
// 			//merge two lists, each has 'interval' length  
// 			int fvisit = 0, svisit = 0;  
// 			while (fvisit < interval && svisit<interval && fast != NULL && slow != NULL)  
// 			{  
// 				if (fast->val < slow->val)  
// 				{  
// 					pre->next = fast;  
// 					pre = fast;  
// 					fast = fast->next;  
// 					fvisit++;  
// 				}  
// 				else  
// 				{  
// 					pre->next = slow;  
// 					pre = slow;  
// 					slow = slow->next;  
// 					svisit++;  
// 				}  
// 			}  
// 			while (fvisit < interval && fast != NULL)  
// 			{  
// 				pre->next = fast;  
// 				pre = fast;  
// 				fast = fast->next;  
// 				fvisit++;  
// 			}  
// 			while (svisit < interval && slow != NULL)  
// 			{  
// 				pre->next = slow;  
// 				pre = slow;  
// 				slow = slow->next;  
// 				svisit++;  
// 			}  
// 			pre->next = fast;  
// 			slow = fast;  
// 		}  
// 	}  
// 	ListNode* newhead = fakehead->next;  
// 	delete fakehead;  
// 	return newhead;  
// }  

// int main()
// {
// 	int n;
// 	cin >> n;
// 	ListNode *l = GetLists(n);
// 	ListNode *R = sortList(l);
// 	
// 	for (int i = 0; i < n; i ++) {
// 		cout << R->val << " ";
// 		R = R->next;
// 	}
// 
// 	return 0;
// }

