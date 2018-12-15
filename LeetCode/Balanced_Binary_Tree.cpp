#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int			val;
	TreeNode	*left;
	TreeNode	*right;
	TreeNode(int x): val(x),left(NULL), right(NULL) {}
};

int maxTreeDepth(TreeNode *root) //先求树的深度
{
	if (NULL == root)
		return 0;
	int lval = maxTreeDepth(root->left);
	int rval = maxTreeDepth(root->right);
	return 1 + (lval > rval ? lval:rval);
}
bool isBalanced(TreeNode *root)//根据树的深度再来判断是否是平衡树
{
	if(NULL == root)
		return true;
	int diff = maxTreeDepth(root->left) - maxTreeDepth(root->right);
	if (diff < -1 || diff > 1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
	return 0;
}