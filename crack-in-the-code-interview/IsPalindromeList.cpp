#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* pHead) 
{
	assert(NULL != pHead);
	ListNode *p = pHead;
	vector<int> vec;

	while(p) {
		vec.push_back(p->val);
		p = p->next;
	}
	int i = 0, j = vec.size()-1;
	while (i < j) {
		if (vec[i] != vec[j])
			return false;
		i ++;
		j --;
	}
	return true;
}

ListNode* insert(int n)
{
	int m;
	ListNode *pHead = new ListNode(0);
	ListNode *p = pHead;
	for (int i = 0; i < n; i ++) {
		cin >> m;
		ListNode *pIn = new ListNode(m);
		p->next = pIn;
		p = pIn;
	}
	return pHead->next;
}

void print(ListNode *pHead)
{
	ListNode *p = pHead;
	while(p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

// int main()
// {
// 	ListNode *p1 = insert(6);
// 	cout << isPalindrome(p1);
// 	//print(p);
// 	return 0;
// }
