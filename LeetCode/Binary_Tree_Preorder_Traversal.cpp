#include <iostream>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

struct TreeNode {
	int			val;
	TreeNode*	left;
	TreeNode*	right;
	TreeNode(int x): val(x), left(NULL),right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root) //非递归的前序遍历(用栈实现)
{
	if (NULL == root) {
		cout << "tree is empty!" << endl;
		exit(0);
	}

	TreeNode *pre = root;
	//TreeNode *pTemp = pre;
	stack<TreeNode *> tree_stack;
	vector<int> tree_vector;
	
	tree_stack.push(pre);
	while (!tree_stack.empty()) {
		TreeNode *pTemp = tree_stack.top();
		tree_stack.pop();

		tree_vector.push_back(pTemp->val);
		if (pTemp->right != NULL) 
			tree_stack.push(pTemp->right);
		if (pTemp->left != NULL)
			tree_stack.push(pTemp->left);
	}
	return tree_vector;
}

TreeNode *getTree(int n)
{
	int value;
	int i = 1;
	TreeNode *pRoot = new TreeNode(0);
	TreeNode *pre = pRoot;
	while(i <= n) {
		cin >> value;
		TreeNode *p = new TreeNode(value);
		if (i%2) 
			pre->left = p;
		else
			pre->right = p;
		pre = pre->left;
		i ++;
	}
	return pRoot;
}

// int main()
// {
// 	int n;
// 	cin >> n;
// 	TreeNode *pRoot = getTree(n);
// 	vector<int> ve = preorderTraversal(pRoot);
// 
// 	return 0;
// }