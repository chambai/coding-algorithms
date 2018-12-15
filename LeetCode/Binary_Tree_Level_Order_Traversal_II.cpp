#include <iostream>
#include <queue>
#include <vector>
#include <cassert>

using namespace std;

struct TreeNode {
	int			val;
	TreeNode*	left;
	TreeNode*	right;
	TreeNode():val(0),left(NULL),right(NULL){}
	TreeNode(int x): val(x), left(NULL),right(NULL) {}
};

vector<vector<int> > levelOrderTraversalII(TreeNode *root) //�ǵݹ���������(��ջʵ��)
{

	queue<TreeNode *> tree_queue;
	vector<vector<int> > tree_vector, tree_rvector;
	vector<int> svector;
	int nCount = 0;

	if (NULL == root) {
		return tree_vector;
	}
	TreeNode *pTemp = root;
	tree_queue.push(root);
	tree_queue.push(NULL); //the end of one level.

	while (true) {
		TreeNode *pTemp = tree_queue.front();
		tree_queue.pop();

		if (!pTemp) { //get the null, put vector<> to vector<vector<>>
			tree_vector.push_back(svector);
			nCount ++;
			svector.clear();
			if (tree_queue.empty())
				break;
			tree_queue.push(NULL);
		}
		else {
			svector.push_back(pTemp->val);
			if (pTemp->left) 
				tree_queue.push(pTemp->left);
			if (pTemp->right)
				tree_queue.push(pTemp->right);
		}
	}
	while (nCount > 0){
		svector = tree_vector.at(nCount - 1);
		tree_rvector.push_back(svector);
		nCount --;
	}
	return tree_rvector;
}

// TreeNode* Create() //����һ�ö�����
// {
// 	char ch;
// 	cin >> ch;
// 	TreeNode *root;
// 	if (ch == '#')
// 		return NULL;
// 	else {
// 		root = new TreeNode;
// 		root->val = ch;
// 		root->left = Create();
// 		root->right = Create();
// 		return root;
// 	}
// }
// 
// void PrintTreeNode(TreeNode *root) //��ӡһ�ö�����
// {
// 	TreeNode *pTemp = root;
// 	while (pTemp) {
// 		cout << pTemp->val;
// 		PrintTreeNode(pTemp->left);
// 		PrintTreeNode(pTemp->right);
// 	}
// }
// 
// int main()
// {
// 	
// 	TreeNode *pRoot = Create();
// 	vector<vector<int>> vec;
// 	vec = levelOrderTraversalII(pRoot);
// 	for (unsigned int i = 0; i < vec.size(); i ++) {
// 		for (unsigned int j = 0; j < vec.at(i).size(); j ++) {
// 			cout << vec.at(i).at(j);
// 		}
// 		cout << " ";
// 	}
// 
// 	return 0;
// }