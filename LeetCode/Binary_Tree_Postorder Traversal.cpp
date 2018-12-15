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

vector<int> postorderTraversal(TreeNode *root) //非递归的前序遍历(用栈实现)
{
	if (NULL == root) {
		return vector<int>();
	}
	
	stack<TreeNode *> tree_stack;
	vector<int> tree_vector;

	tree_stack.push(root);
	TreeNode *p = NULL;
	while (!tree_stack.empty()) {
		TreeNode *pTemp = tree_stack.top();
		if ((pTemp->left == NULL && pTemp->right == NULL) || ((p != NULL) && (pTemp->left == p || pTemp->right == p))) {
			tree_vector.push_back(pTemp->val);
			tree_stack.pop();
			
			p = pTemp;
		}
		else {
			while(pTemp) {
				if (pTemp->right != NULL) 
					tree_stack.push(pTemp->right);

				if (pTemp->left != NULL)
					tree_stack.push(pTemp->left);
				pTemp = pTemp->left;
			}
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