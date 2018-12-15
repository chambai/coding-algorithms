### 题目描述

> 输入一个链表，从尾到头打印链表每个节点的值。


### 输入描述

> 输入一个链表，从尾到头打印链表每个节点的值。

### 输出描述

> 输出为需要打印的“新链表”的表头


### 解决

#### 01 递归法

略...

#### 02 利用stack

先进后出



````c++
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode
{
public :
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    vector<int> printListFromTailToHead(struct ListNode* head)
    {
        ListNode *node = head;
        stack<int> st;
        int count = 0;
        while(node != NULL) {
            st.push(node->val);
            count++;
            node = node->next;
        }

        // 为了效率我们静态vector开辟空间
        vector<int> res(count);
        for(int i = 0; i < count && st.empty( ) != true; i++) {
            // 如果静态开辟vector不能使用push_back
            // 否则会在原来数据的基础上增加
            //res.push_back(st.top( ));
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};

int main( )
{
    ListNode list[4];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;

    Solution solu;
    vector<int> res = solu.printListFromTailToHead(list);

    for(int i = 0; i < res.size(); i++) {
        cout <<res[i] <<endl;
    }
    return 0;
}
````

