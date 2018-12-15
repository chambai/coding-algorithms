#ifndef __AVL_TREE_H_
#define __AVL_TREE_H_

class AVLTree 
{
private:
	struct AVLNode {
		AVLNode		*Parent;
		AVLNode		*Left;
		AVLNode		*Right;
		int			m_nHeight;
		int			m_nValue;
	};
public:
	AVLTree(AVLNode *root = NULL):m_pRoot(root) {}
	~AVLTree() {
		_RecursiveDeleteNode(m_pRoot);
	}

	bool Search( const int search_value ) const;
	bool Insert( const int value );
	bool Delete( const int delete_value );

	void Print() const;

private:
	void _RecursiveDeleteNode(AVLNode *node) {
		if ( node ) {
			_RecursiveDeleteNode( node->Left );
			_RecursiveDeleteNode( node->Right );
			delete node;
		}
		node = NULL;
	}

	void _DeleteNode( AVLNode *delete_node );
	void _Delete_Transplant( AVLNode *unode, AVLNode *vnode );
	void _InsertNode( const int insert_value );
	AVLNode * _SearchNode( AVLNode *node, const int search_value ) const;

	//单旋
	void _LeftRotation( AVLNode *node );
	void _RightRotation( AVLNode *node );

	//双旋
	void _LeftRightRotation( AVLNode *node );
	void _RightLeftRotation( AVLNode *node );

	AVLNode* Minimum( AVLNode *node );

	//树高
	int _Height ( AVLNode *node );
	void _UpdateHeight( AVLNode *node );
	//平衡因子
	int _GetBalanceFactor( AVLNode *node );
	//平衡失去平衡的节点
	void _BalanceNode( AVLNode *node );

	void _Print ( AVLNode *node ) const;

private:
	AVLNode *m_pRoot;

};
#endif//__AVL_TREE_H_