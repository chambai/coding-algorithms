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

vector<int> inorderTraversal(TreeNode *root) //非递归的中序遍历(用栈实现)
{
	if (NULL == root) {
		return vector<int>();
	}

	stack<TreeNode *> tree_stack;
	vector<int> tree_vector;

	TreeNode *pTemp = root;
	while (pTemp || !tree_stack.empty()) {
		while (pTemp) {
			tree_stack.push(pTemp);
			pTemp = pTemp->left;
		}
		if (!tree_stack.empty()) {
			pTemp = tree_stack.top();
			tree_vector.push_back(pTemp->val);
			tree_stack.pop();
			pTemp = pTemp->right;
		}
	}
	return tree_vector;
}

// int main()
// {
// 	int n;
// 	cin >> n;
// 	/*TreeNode *pRoot = getTree(n);*/
// 	vector<int> ve = preorderTraversal(pRoot);
// 
// 	return 0;
// }