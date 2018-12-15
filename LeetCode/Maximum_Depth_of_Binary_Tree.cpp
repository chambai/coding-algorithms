#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int			val;
	TreeNode*	left;
	TreeNode*	right;
	TreeNode(int x): val(x), left(NULL),right(NULL) {}
};

//采用DFS的思想
int maxDepth(TreeNode *root)
{
	if (NULL == root)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);

	return l > r ? l + 1:r+1;
	//以上这两种方式有一种更简便的方法
	//return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

//采用BFS的方法，引入队列
int maxDepth(TreeNode *root)
{
	if (NULL == root)
		return 0;
	queue <TreeNode *> que;
	int nCount = 1;
	int nDepth = 0;// 记录队列里面每一层上的元素

	que.push(root);
	while(!que.empty()) {
		TreeNode *pTemp = que.front();
		que.pop();
		nCount --;

		if (pTemp->left)
			que.push(pTemp->left);
		if (pTemp->right)
			que.push(pTemp->right);
		
		if (nCount == 0) {
			nDepth ++;
			nCount = que.size();
		}
	}
	return nDepth;
}

int main()
{
	return 0;
}