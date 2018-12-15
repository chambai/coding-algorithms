#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int			val;
	TreeNode	*left;
	TreeNode	*right;
	TreeNode(int x): val(x),left(NULL), right(NULL) {}
};

typedef vector<int>::iterator Iter;

TreeNode *buildTreeFromInorderPostorder(vector<int> &inorder, vector<int> &postorder)
{
	return buildBinaryTreeResur(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}

TreeNode *buildBinaryTreeResur(Iter istart, Iter iend, Iter pstart, Iter pend)
{
	if (istart == iend || pstart == pend)
		return NULL;
	int ival = *(pend-1);
	Iter ptemp = find(istart, iend, ival);
	TreeNode *res = new TreeNode(ival);
	res->left = buildBinaryTreeResur(istart, ptemp, pstart, pstart+(ptemp-istart));
	res->right = buildBinaryTreeResur(ptemp+1, iend, pstart+(ptemp-istart), pend-1);
	return res;
}

int main()
{
	return 0;
}