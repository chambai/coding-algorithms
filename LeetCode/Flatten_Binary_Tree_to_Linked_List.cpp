#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int			val;
	TreeNode*	left;
	TreeNode*	right;
	TreeNode(int x): val(x), left(NULL),right(NULL) {}
};

// void flatten(TreeNode *root)
// {
// 	if (NULL == root)
// 		return;
// 	TreeNode *pre = root;
// 	stack<TreeNode *> treestack;
// 
// 	TreeNode *pTreeList = new TreeNode(0);
// 	TreeNode *pNext = pTreeList;
// 
// 	treestack.push(pre);
// 	while(!treestack.empty()) {
// 		TreeNode *pTemp = treestack.top();
// 		treestack.pop();
// 		
// 		pNext->right = pTemp;
// 		pNext = pNext->right;
// 		pNext->left = NULL;
// 
// 		if (pTemp->right)
// 			treestack.push(pTemp->right);
// 		if (pTemp->left)
// 			treestack.push(pTemp->left);
// 	}
// 	root = pTreeList->right;
// }


void flatten(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (root == NULL) return;

	TreeNode* left = root->left;
	TreeNode* right = root->right;      // the original right child

	if (left) {
		root->right = left;
		root->left = NULL;

		TreeNode* rightmost = left;
		while(rightmost->right) {
			rightmost = rightmost->right;

		}
		rightmost->right = right; // point to the original right child
	}

	flatten(root->right);    
}

TreeNode *getBinaryTree()
{
	char ch;
	cin >> ch;
	if ('#' == ch)
		return NULL;
	else {
		TreeNode *pTreeNode = new TreeNode(ch);
		pTreeNode->left = getBinaryTree();
		pTreeNode->right = getBinaryTree();
		return pTreeNode;
	}
}

int main()
{
	TreeNode *root = getBinaryTree();
	flatten(root);
	return 0;
}