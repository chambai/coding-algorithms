#include <iostream>

using namespace std;

#include "BinaryTree.h"

BinaryTreeNode * Construct(int *preorder, int *inorder, int length);
BinaryTreeNode * ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);

// struct BinaryTreeNode {
// 	int val;
// 	BinaryTreeNode *left;
// 	BinaryTreeNode *right;
// 	//BinaryTreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

BinaryTreeNode * Construct(int *preorder, int *inorder, int length)
{
	if (NULL == preorder || NULL == inorder || length <= 0)
		return NULL;

	//the core fun of building the binary tree
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode * ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
	//get the root value
	int rootValue = startPreorder[0];
	//new the root
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	//check the case of only one element
	if (startPreorder == endPreorder) {
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else throw std::exception("Invalid input!");
	}

	//find the rootValue in inorder
	int *rootInorder = startInorder;
	while (rootInorder < endInorder && *rootInorder != rootValue)
		++ rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input!");

	int leftLength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftLength;
	//return the left tree
	if (leftLength > 0) {
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}

	//return the right tree
	if (leftLength < endInorder - startInorder) {
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

///////////////////测试代码//////////////////
void Test(char* testName, int* preorder, int* inorder, int length)
{
	if(testName != NULL)
		cout << testName << endl;

	cout << "The preorder sequence is: ";
	for(int i = 0; i < length; ++ i)
		cout << preorder[i] << " " ;
	cout << endl;

	cout << "The inorder sequence is: ";
	for(int i = 0; i < length; ++ i)
		cout << inorder[i] << " ";
	cout << endl;

	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintTree(root);
		
		cout << endl;
		DestroyTree(root);
	}
	catch(std::exception& exception)
	{
		cout << "Invalid Input.\n";
	}
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	const int length = 8;
	int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

	Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	const int length = 5;
	int preorder[length] = {1, 2, 3, 4, 5};
	int inorder[length] = {5, 4, 3, 2, 1};

	Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	const int length = 5;
	int preorder[length] = {1, 2, 3, 4, 5};
	int inorder[length] = {1, 2, 3, 4, 5};

	Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
	const int length = 1;
	int preorder[length] = {1};
	int inorder[length] = {1};

	Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	const int length = 7;
	int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
	int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

	Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
	Test("Test6", NULL, NULL, 0);
}

// 输入的两个序列不匹配
void Test7()
{
	const int length = 7;
	int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
	int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

	Test("Test7: for unmatched input", preorder, inorder, length);
}

// int main()
// {
// 	Test1();
// 	Test2();
// 	Test3();
// 	Test4();
// 	Test5();
// 	Test6();
// 	Test7();
// 
// 	return 0;
// }

