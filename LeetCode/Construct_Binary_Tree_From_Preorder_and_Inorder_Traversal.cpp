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
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
{
	return buildTreeRecur(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

TreeNode *buildTreeRecur(Iter pstart, Iter pend, Iter istart, Iter iend)
{
	if(pstart == pend || istart == iend)
		return NULL;
	int ival = *pstart;
	Iter ipos = find(istart, iend, ival);
	TreeNode *res = new TreeNode(ival);
	res->left = buildTreeRecur(pstart + 1, pstart+1+(ipos-istart), istart, ipos);
	res->right = buildTreeRecur(pstart+1+(ipos-istart), pend, ipos+1, iend);
	return res;
}

int main()
{
	return 0;
}