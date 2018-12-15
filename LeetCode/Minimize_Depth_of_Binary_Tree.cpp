// #include <iostream>
// #include <vector>
// 
// using namespace std;
// 
// struct TreeNode {
// 	int			val;
// 	TreeNode	*left;
// 	TreeNode	*right;
// 	TreeNode(int x): val(x),left(NULL), right(NULL) {}
// };
// 
// int minDepth(TreeNode *root) 
// {
// 	if (NULL == root)
// 		return 0;
// 	int l = minDepth(root->left);
// 	int r = minDepth(root->right);
// 	if (!l)
// 		return r+1;
// 	if (!r)
// 		return l+1;
// 	return 1+((l<r)?l+1:r+1);
// 	/*return l<r?1+l:r+1;*/
// }