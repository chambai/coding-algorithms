#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

class BinarySearchTree 
{
private:
	struct _Node {
		int		m_nValue;
		_Node	*m_pParent;
		_Node	*m_pLeft;
		_Node	*m_pRight;
	};

public:
	BinarySearchTree(_Node *pRoot = NULL):m_pRoot(pRoot){}

	~BinarySearchTree();

	//@brief 插入元素
	//@return 是否插入成功
	bool Insert(const int new_value);

	//递归
	_Node * Insert_Recur(_Node *&node, const int new_value);

	//@brief 删除元素
	//@return 是否删除成功
	bool Delete(const int delete_value);

	//@brief 查找元素
	//@return 是否查找成功
	bool Search(const int search_value) const;

	//@brief 使用dot描述当前二叉查找树
	void Display() const;
	
	//@brief 树的遍历
	void Inorder() const {Inorder_Tree_Walk(m_pRoot);}
	void Preorder() const {Preorder_Tree_Walk(m_pRoot);}
	void Postorder() const {Postorder_Tree_Walk(m_pRoot);}
	

private:
	//@brief 真正的删除操作
	void _DeleteNode(_Node *delete_node);
	void _Delete_Transplant(_Node *unode, _Node *vnode);

	//@brief 得到以node为根节点的子树中的最大关键字节点
	_Node * _GetMaximum(_Node *node) const;

	//@brief 得到以node为根节点的子树中的最小关键字节点
	_Node * _GetMinimum(_Node *node) const;

	//@brief 得到一个同时存在左右子树的节点node的前驱
	_Node * _GetPredecessor(_Node *node) const;

	//@brief 得到一个同时存在左右子树的节点node的后继
	_Node * _GetSuccessor(_Node *node) const;

	//@brief 真正的查找操作
	//非递归查找
	_Node * _Search(_Node *node, const int search_value) const;

	//@brief 显示一棵二叉搜索树
	void _Display(/*iostream &ss, */_Node *node) const;

	//@brief 递归释放节点
	void _RecursiveReleaseNode(_Node *node);

	void ShowGraphvizViaDot(const string &dot) const;

	//@brief 树的遍历
	void Inorder_Tree_Walk(_Node *node) const;
	void Preorder_Tree_Walk(_Node *node) const;
	void Postorder_Tree_Walk(_Node *node) const;

private:
	_Node	*m_pRoot;
};

#endif//_BINARY_SEARCH_TREE_