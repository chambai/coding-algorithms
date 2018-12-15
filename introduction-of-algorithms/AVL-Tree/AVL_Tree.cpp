#include <iostream>
#include <algorithm>
using namespace std;

#include "AVL_Tree.h"

bool AVLTree::Search( const int search_value ) const
{
	return _SearchNode( m_pRoot, search_value ) != NULL;
}

AVLTree::AVLNode * AVLTree::_SearchNode( AVLNode *node, const int search_value ) const
{
	while ( node && search_value != node->m_nValue ) {
		if ( search_value < node->m_nValue )
			node = node->Left;
		else
			node = node->Right;
	}
	return node;
}

bool AVLTree::Insert( const int value )
{
	//该值已存在
	if ( Search( value ) )
		return false;
	else {
		_InsertNode( value );
		return true;
	}
}

void AVLTree::_InsertNode( const int insert_value )
{
	AVLNode *node = m_pRoot;
	AVLNode *temp_node = NULL;

	//先找到待插入节点的位置
	while ( node ) {
		temp_node = node;
		node = ( insert_value < node->m_nValue )?node->Left:node->Right;
	}

	AVLNode *insert_node = new AVLNode();
	insert_node->m_nValue = insert_value;

	insert_node->Parent = temp_node;

	//空树
	if ( temp_node == NULL )
		m_pRoot = insert_node;
	else {
		if ( insert_value < temp_node->m_nValue )//左子树
			temp_node->Left = insert_node;
		else
			temp_node->Right = insert_node; //右子树
	}
	
	//更新插入节点的高度和平衡节点
	while ( insert_node ) {
		_UpdateHeight( insert_node );
		_BalanceNode( insert_node );
		insert_node = insert_node->Parent;
	}
}

bool AVLTree::Delete( const int delete_value )
{
	AVLNode *delete_node = _SearchNode( m_pRoot, delete_value );

	//节点不存在
	if ( delete_node == NULL )
		return false;
	else {
		_DeleteNode( delete_node );
		return true;
	}
}

void AVLTree::_DeleteNode( AVLNode *delete_node )
{
	if ( delete_node->Left == NULL )
		_Delete_Transplant( delete_node, delete_node->Right );
	else if ( delete_node->Right == NULL )
		_Delete_Transplant( delete_node, delete_node->Left );
	else {
		AVLNode *min_node = Minimum( delete_node->Right );
		if ( min_node->Parent != delete_node ) {
			_Delete_Transplant( min_node, min_node->Right );
			min_node->Right = delete_node->Right;
			min_node->Right->Parent = min_node;
		}
		_Delete_Transplant( delete_node, min_node );
		min_node->Left = delete_node->Left;
		min_node->Left->Parent = min_node;
	}

	//更新结点的高度和平衡节点
	while ( delete_node ) {
		_UpdateHeight( delete_node );
		_BalanceNode( delete_node );
		delete_node = delete_node->Parent;
	}
}

void AVLTree::_Delete_Transplant( AVLNode *unode, AVLNode *vnode )
{
	if ( unode->Parent == NULL )
		m_pRoot = vnode;
	else if ( unode == unode->Parent->Left )
		unode->Parent->Left = vnode;
	else
		unode->Parent->Right = vnode;
	if ( vnode )
		vnode->Parent = unode->Parent;
}

AVLTree::AVLNode* AVLTree::Minimum( AVLNode *node )
{
	while ( node->Left )
		node = node->Left;
	return node;
}

//树高
int AVLTree::_Height( AVLNode *node )
{
	return node->m_nHeight;
}

//平衡因子(左右子树的高度差)
int AVLTree::_GetBalanceFactor( AVLNode *node )
{
	AVLNode *l = node->Left, *r = node->Right;

	if ( l && r )
		return l->m_nHeight - r->m_nHeight;
	else if ( l )
		return l->m_nHeight + 1;
	else if ( r )
		return -r->m_nHeight - 1;
	else return 0;
}

void AVLTree::_UpdateHeight( AVLNode *node )
{
	AVLNode *l = node->Left, *r = node->Right;

	if ( l && r )
		node->m_nHeight = max( l->m_nHeight, r->m_nHeight ) + 1;
	else if ( l )
		node->m_nHeight = l->m_nHeight + 1;
	else if ( r )
		node->m_nHeight = r->m_nHeight + 1;
	else node->m_nHeight = 0;
}

//////////////////////////////////////////////////////////////////////////
//		a	a	a	a
//	   /   /     \   \
//    b   b       b   b
//   /     \     /     \
//  c       c   c       c
// LL       LR  RL      RR
//////////////////////////////////////////////////////////////////////////
void AVLTree::_BalanceNode( AVLNode *node )
{
	int nBlance = _GetBalanceFactor( node );
	if ( nBlance > 1 ) { //L
		//(1)
		//if ( _GetBalanceFactor( node->Left ) < 0 ) //LR 
		//	_LeftRightRotation( node ); //双旋
		//else _RightRotation( node ); //LL //单旋

		//(2)
		if ( _GetBalanceFactor( node->Left ) < 0 )
			_LeftRotation( node->Left );
		_RightRotation( node );
	}
	if ( nBlance < -1 ) { //R
		if ( _GetBalanceFactor( node ) > 0 ) { //RL
			_RightRotation( node->Right );
		}
		_LeftRotation( node );
	}
}

//单旋
//左旋
void AVLTree::_LeftRotation( AVLNode *node )
{
	if ( node->Right == NULL )
		return;

	AVLNode *temp_node = node->Right;
	
	//补
	node->Right = temp_node->Left;
	if ( temp_node->Left )
		temp_node->Left->Parent = node;
	
	//提
	temp_node->Parent = node->Parent;
	if ( node->Parent == NULL )
		m_pRoot = temp_node;
	else if ( node == node->Parent->Left )
		node->Parent->Left = temp_node;
	else node->Parent->Right = temp_node;

	//降
	temp_node->Left = node;
	node->Parent = temp_node;

	_UpdateHeight( node );
	_UpdateHeight( temp_node );
}

//右旋
void AVLTree::_RightRotation( AVLNode *node )
{
	if ( node->Left == NULL )
		return;

	AVLNode *temp_node = node->Left;

	//补
	node->Left = temp_node->Right;
	if ( temp_node->Right )
		temp_node->Right->Parent = node;

	//提
	temp_node->Parent = node->Parent;
	if ( node->Parent == NULL )
		m_pRoot = temp_node;
	else if ( node == node->Parent->Left )
		node->Parent->Left = temp_node;
	else node->Parent->Right = temp_node;

	//降
	temp_node->Right = node;
	node->Parent = temp_node;

	_UpdateHeight( node );
	_UpdateHeight( temp_node );
}

//双旋
//LR
void AVLTree::_LeftRightRotation( AVLNode *node )
{
	_LeftRotation( node->Left );
	_RightRotation( node );
}

//RL
void AVLTree::_RightLeftRotation( AVLNode *node )
{
	_RightRotation( node->Right );
	_RightRotation( node );
}

void AVLTree::Print() const
{
	_Print(m_pRoot);
}
//打印
void AVLTree::_Print ( AVLNode *node ) const
{
	if ( node->Parent == NULL )
		cout << "root: " << node->m_nValue << endl;
	else if ( node == node->Parent->Left ) 
		cout << "left: " << node->m_nValue << ", parent: " << node->Parent->m_nValue << endl;
	else cout << "right: " << node->m_nValue << ", parent: " << node->Parent->m_nValue << endl;
	if ( node->Left )
		_Print( node->Left );
	if ( node->Right )
		_Print( node->Right );
}

int main()
{
	AVLTree al;
	for (int i = 1; i < 10; i ++) {
		al.Insert(i);
		
	}
	al.Print();
	for (int i = 1; i < 10; i += 2) {
		al.Delete(i);
		al.Print();
	}
	return 0;
}