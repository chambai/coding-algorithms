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

void Swap(vector<int> &ivec)
{
	int temp = 0;
	int len = ivec.size();
	for (int i = 0; i < len/2; i ++) {
		temp = ivec.at(i);
		ivec.at(i) = ivec.at(len-1-i);
		ivec.at(len-1-i) = temp;
	}
}

vector<vector <int> > zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int> > tree_vector;
	vector<int> ivec;
	queue<TreeNode *> tree_queue;
	if (NULL == root)
		return tree_vector;

	tree_queue.push(root);
	tree_queue.push(NULL);
	int nLevelCount = 1;
	while (true) {
		TreeNode *pTemp = tree_queue.front();
		tree_queue.pop();
		if (pTemp == NULL) {
			if (nLevelCount%2 == 0) { //if the num of level is odd, swap the ivec;
				Swap(ivec);
			}
			tree_vector.push_back(ivec);
			ivec.clear();
			if (tree_queue.empty())
				break;
			tree_queue.push(NULL);
			nLevelCount ++;
		}
		else {
			ivec.push_back(pTemp->val);
			if (pTemp->left)
				tree_queue.push(pTemp->left);
			if (pTemp->right)
				tree_queue.push(pTemp->right);
		}
	}
	return tree_vector;
}


int main()
{
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(4);
	//ivec.push_back(5);
	Swap(ivec);
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++ it)
		cout << *it << " ";
	return 0;
}