#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>
using namespace std;

#include "red_black_tree.h"

//静态成员变量初始化
template<typename TKey, typename TValue>
typename RBTree<TKey, TValue>::RBTreeNode * RBTree<TKey, TValue>::m_pNil = NULL;

template<typename TKey, typename TValue>
RBTree<TKey, TValue>::RBTree() 
{
	if ( !m_pNil ) {
		//叶结点是一个特殊的黑结点
		m_pNil = new RBTreeNode();
		m_pNil->Color = BLACK;
	}
	m_pRoot = m_pNil;
}

template<typename TKey, typename TValue>
RBTree<TKey, TValue>::~RBTree()
{
	_RecursiveReleaseNode( m_pRoot );
}

template<typename TKey, typename TValue>
void RBTree<TKey, TValue>::_RecursiveReleaseNode( RBTreeNode *node )
{
	if ( node->isValid() ) {
		_RecursiveReleaseNode( node->Left );
		_RecursiveReleaseNode( node->Right );
		delete node;
	}
}

template<typename TKey, typename TValue>
bool RBTree<TKey, TValue>::Empty()
{
	return !(m_pRoot->isValid());
}

//左旋
template<typename TKey, typename TValue> 
void RBTree<TKey, TValue>::_LeftRotate( RBTreeNode *x_node )
{
	//assert
	if ( !(x_node->isValid() && x_node->Right->isValid()) )
		throw exception( "左旋操作要求对非哨兵进行操作，并且要求右孩子也不是哨兵" );

	RBTreeNode *y_node = x_node->Right;

	//以下三步的宗旨是用 y 替换 x，注意将 x 的Parent、Left、Right都换成 y 的
	// 1) x 和 y 分离 (补)
	x_node->Right = y_node->Left;
	if (y_node->Left != m_pNil)
		y_node->Left->Parent = x_node;
	
	// 2) 设置y->Parent (提)
	y_node->Parent = x_node->Parent;
	if (x_node->Parent == m_pNil)
		m_pRoot = y_node;
	else if (x_node->Parent->Left == x_node)
		x_node->Parent->Left = y_node;
	else
		x_node->Parent->Right = y_node;

	// 3) 设置y->Left (降)
	y_node->Left = x_node;
	x_node->Parent = y_node;
}

//右旋
template<typename TKey, typename TValue> 
void RBTree<TKey, TValue>::_RightRotate( RBTreeNode *x_node )
{
	//assert
	if ( !(x_node->isValid() && x_node->Left->isValid()) )
		throw exception( "右旋操作要求对非哨兵进行操作，并且要求左孩子也不是哨兵" );
	RBTreeNode *y_node = x_node->Left;

	//以下三步的宗旨是用 y 替换 x，注意将 x 的Parent、Left、Right都换成 y 的
	// 1) x 和 y 分离 (补)
	x_node->Left = y_node->Right;
	if (y_node->Right != m_pNil)
		y_node->Right->Parent = x_node;

	// 2) 设置y->Parent (提)
	y_node->Parent = x_node->Parent;
	if (x_node->Parent == m_pNil)
		m_pRoot = y_node;
	else if (x_node->Parent->Right == x_node)
		x_node->Parent->Right = y_node;
	else
		x_node->Parent->Left = y_node;

	// 3) 设置y->Left (降)
	y_node->Right = x_node;
	x_node->Parent = y_node;
}

//搜索
template<typename TKey, typename TValue> 
typename RBTree<TKey, TValue>::RBTreeNode* RBTree<TKey, TValue>::Search( TValue const &value )
{
	RBTreeNode *node = m_pRoot;
	while( node != m_pNil && node->Value != value )
		node = ((value < node->Value) ? node->Left:node->Right);
	return node;
}

//插入
template<typename TKey, typename TValue> 
bool RBTree<TKey, TValue>::Insert( TKey key, TValue value )
{
	if ( Search(value)->isValid() )
		//value 重复，添加失败
		return false;
	else {
		//新添加的节点为红结点，left=right=nil
		RBTreeNode *new_node = new RBTreeNode();
		new_node->Key = key;
		new_node->Value = value;
		new_node->Color = RED;
		new_node->Left = new_node->Right = m_pNil;
	
		//插入
		_InsertRBTree(new_node);
		//修复
		_InsertFixup(new_node);
		return true;
	}
}

//真正的插入:与二叉搜索树几乎一样
template<typename TKey, typename TValue> 
void RBTree<TKey, TValue>::_InsertRBTree( RBTreeNode *new_node )
{
	RBTreeNode *current_node = m_pNil;
	RBTreeNode *next_node = m_pRoot;

	//找到插入点
	while ( next_node != m_pNil ) {
		current_node = next_node;
		next_node = ( new_node->Value < next_node->Value )? next_node->Left: next_node->Right;
	}

	new_node->Parent = current_node;
	if ( current_node == m_pNil ) //空树
		m_pRoot = new_node;
	else if ( new_node->Value < current_node->Value )
		current_node->Left = new_node; //插入左子树
	else
		current_node->Right = new_node; //插入右子树

	//设置new_node-left-right = nil, color = red
	new_node->Left = m_pNil;
	new_node->Right = m_pNil;
	new_node->Color = RED;	//插入结点为红色
}

//插入修复
//new_node -> z, uncle_node -> y;
template<typename TKey, typename TValue> 
void RBTree<TKey, TValue>::_InsertFixup( RBTreeNode *new_node )
{
//////////////////////////////////////////////////////////////////////////
//啰嗦的写法
/*
	while ( new_node->Parent->Color == RED ) {
		RBTreeNode *uncle_node = new RBTreeNode();
		if ( new_node->Parent == new_node->Parent->Parent->Left ) { //new的父结点为祖父结点的左孩子
			uncle_node = new_node->Parent->Right; //uncle结点在右边

			if ( uncle_node->Color == RED ) { //case1: new 的叔结点为红色
				new_node->Color = BLACK;
				uncle_node->Color = BLACK;
				new_node->Parent->Color = RED;
				new_node = new_node->Parent->Parent;
			}

			else if ( uncle_node->Color == BLACK && new_node->Parent->Right )  //case2: new 叔结点为黑色且new是一个右孩子
				_LeftRotate( new_node->Parent ); 

			new_node->Parent->Color = BLACK;	//case3: new 叔结点为黑色且new是左孩子
			new_node->Parent->Parent->Color = RED;
			_RightRotate( new_node->Parent->Parent ); 
		}
		else { //和上面对称的相同操作
			///
		}	
	}
*/
//////////////////////////////////////////////////////////////////////////
//精炼的写法
	while ( new_node->Parent->Color == RED ) {

		//标识new的父结点是否是祖父结点的左孩子
		bool parent_is_left_child_flag = ( new_node->Parent == new_node->Parent->Parent->Left );
		RBTreeNode *uncle_node = ( parent_is_left_child_flag ? new_node->Parent->Parent->Right: new_node->Parent->Parent->Left );

		if ( uncle_node->Color == RED ) { //case1: new 的叔结点为红色
			new_node->Parent->Color = BLACK;  //!!!
			uncle_node->Color = BLACK;
			new_node->Parent->Parent->Color = RED; //!!!这两个地方写错了，tmd,还得老子改了大半天
			new_node = new_node->Parent->Parent;
		}

		else {
			if ( new_node == ( parent_is_left_child_flag ? new_node->Parent->Right: new_node->Parent->Left ) ) {//case2: new 叔结点为黑色且new是一个右孩子
				new_node = new_node->Parent;
				parent_is_left_child_flag ? _LeftRotate( new_node ):_RightRotate( new_node );
			}

			new_node->Parent->Color = BLACK;	//case3: new 叔结点为黑色且new是左孩子
			new_node->Parent->Parent->Color = RED;
			parent_is_left_child_flag ? _RightRotate( new_node->Parent->Parent ): _LeftRotate( new_node->Parent->Parent );
		}
	}
	m_pRoot->Color = BLACK;
}

//删除
template<typename TKey, typename TValue> 
bool RBTree<TKey, TValue>::Delete( TKey key )
{
	//没有找到该结点
	RBTreeNode *delete_node = Search( key );
	if ( !(delete_node->isValid()) ) //!isValid()
		return false;
	else {
		_Delete( delete_node );
		return true;
	}
}

//真正的删除
//形如二叉搜索树的删除，只不过需要记录待删除节点的右孩子的颜色值
//delete_node -> z; min_node -> y; temp_node -> x
template<typename TKey, typename TValue> 
void RBTree<TKey, TValue>::_Delete( RBTreeNode *delete_node )
{
	RBTreeNode *temp_node = delete_node;
	int color = delete_node->Color; //记录待删除结点原来的颜色

	if ( delete_node->Left == m_pNil ) { //左孩子为空
		temp_node = delete_node->Right;
		_RB_Transplant( delete_node, delete_node->Right );
	}
	else if ( delete_node->Right == m_pNil ) {//右孩子为空
		temp_node = delete_node->Left;
		_RB_Transplant( delete_node, delete_node->Left );
	}
	else {
		RBTreeNode *min_node = _Minimum( delete_node->Right ); //delete的后继结点min_node
		temp_node = min_node->Right;
		color = min_node->Color; //更新color

		if ( min_node->Parent == delete_node )
			temp_node->Parent = min_node;

		else {
			_RB_Transplant( min_node, min_node->Right );
			min_node->Right = delete_node->Right;
			min_node->Right->Parent = min_node;
		}
		_RB_Transplant( delete_node, min_node );
		min_node->Left = delete_node->Left;
		min_node->Left->Parent = min_node;
		min_node->Color = delete_node->Color;
	}
	if ( color == BLACK )
		_DeleteFixup( temp_node ); //template_node x
}

//删除修复
template<typename TKey, typename TValue> 
void RBTree<TKey, TValue>::_DeleteFixup( RBTreeNode *node )
{
	while ( node != m_pRoot && node->Color == BLACK ) {
		//标识node是否是其父结点的左孩子
		bool node_is_left_child_flag = ( node == node->Parent->Left );
		//node的兄弟节点
		RBTreeNode *brother = ( node_is_left_child_flag ? node->Parent->Right : node->Parent->Left );
		
		//case1 node的兄弟结点为红色，一次旋转操作变成case2
		if ( brother->Color == RED ) { 
			node->Parent->Color = RED;
			brother->Color = BLACK;
			node_is_left_child_flag ? _LeftRotate( node->Parent ):_RightRotate( node->Parent );
			
			//更新brother结点
			brother = ( node_is_left_child_flag ? node->Parent->Right : node->Parent->Left );
		}

		//case2 node 的兄弟结点为黑色，且brother两个孩子结点皆为黑色
		if ( brother->Left->Color == BLACK && brother->Right->Color == BLACK ) { 
			brother->Color = RED;
			node = node->Parent; //node更新为上一层
		}
		
		//case3 node的兄弟结点为黑色，且brother的左孩子为红色，右孩子为黑色
		else {
			if ( ( node_is_left_child_flag ? brother->Right->Color : brother->Left->Color ) == BLACK ) { 
				brother->Color = RED;
				//注意左右的不同
				( node_is_left_child_flag ? brother->Left->Color : brother->Right->Color ) = BLACK;
				node_is_left_child_flag ? _RightRotate( brother ):_LeftRotate( brother );
				brother = ( node_is_left_child_flag ? node->Parent->Right:node->Parent->Left ); //更新brother结点 -> 变成case4
			}
			
			//case4 node结点的兄弟结点为黑色，且brother 结点的右孩子为红色
			brother->Color = /*node->Parent->Color*/RED; 
			node->Parent->Color = BLACK;
			
			( node_is_left_child_flag ? brother->Right->Color : brother->Left->Color ) = BLACK;
			node_is_left_child_flag ? _LeftRotate( node->Parent ):_RightRotate( node->Parent );
			
			node = m_pRoot; //最后赋给root
		}
	}
	//最后只需要简单置x为黑结点就可以，_root的改变已经由左右旋自动处理了
	node->Color = BLACK;
}

//RB替换操作
template<typename TKey, typename TValue> 
void RBTree<TKey, TValue>::_RB_Transplant( RBTreeNode *unode, RBTreeNode *vnode )
{
	if ( unode->Parent == m_pNil )
		m_pRoot = vnode;
	else if ( unode->Parent->Left == unode )
		unode->Parent->Left = vnode;
	else
		unode->Parent->Right = vnode;
	vnode->Parent = unode->Parent; //!!!别漏了
}

//显示
template<typename TKey, typename TValue> 
void RBTree<TKey, TValue>::Display() const
{
	_Display( m_pRoot );
	std::cout << std::endl;
}

template<typename TKey, typename TValue> 
void RBTree<TKey, TValue>::_Display( RBTreeNode *node ) const
{
// 	if ( node->isValid() ) {
// 		cout << node->Value << " ";
// 		if (node->Left->isValid())
// 			_Display(node->Left);
// 		if (node->Right->isValid())
// 			_Display(node->Right);
// 	}
	if ( node->Parent == m_pNil ) 
		cout << "root: " << node->Value << "( " << node->Color << " )" << endl;
	else if ( node->Parent->Left == node )
		cout << "left: " << node->Value << "( " << node->Color << " )" << " " << "parent: " << node->Parent->Value << "( " << node->Parent->Color << " )" << endl;
	else cout << "right: " << node->Value << "( " << node->Color << " )" << " " << "parent: " << node->Parent->Value << "( " << node->Parent->Color << " )" << endl;
	if ( node->Left->isValid() )
		_Display(node->Left);
	if ( node->Right->isValid() )
		_Display(node->Right);
}

//@brief 后继
template<typename TKey, typename TValue> 
typename RBTree<TKey, TValue>::RBTreeNode * RBTree<TKey, TValue>::_Successor( RBTreeNode *node )
{
	if(node->m_pRight)
		return _GetMaximum(node);

	_Node *pTemp = node->m_pParent;
	while (pTemp && node == pTemp->m_pRight ) {
		node = pTemp;
		pTemp = pTemp->m_pParent;
	}
	return pTemp;
}

//@brief 前驱
template<typename TKey, typename TValue> 
typename RBTree<TKey, TValue>::RBTreeNode * RBTree<TKey, TValue>::_Predecessor( RBTreeNode *node )
{
	if (node->m_pLeft)
		return _GetMinimum(node);

	_Node *pTemp = node->m_pParent;
	while (pTemp && node == pTemp->m_pLeft) {
		node = pTemp;
		pTemp = pTemp->m_pParent;
	}
	return pTemp;
}

//@brief Maximum
template<typename TKey, typename TValue> 
typename RBTree<TKey, TValue>::RBTreeNode * RBTree<TKey, TValue>::_Maximum( RBTreeNode *node )
{
	while( node->Right != m_pNil ) {
		node = node->Right;
	}
	return node;
}

//@brief Minimum
template<typename TKey, typename TValue> 
typename RBTree<TKey, TValue>::RBTreeNode * RBTree<TKey, TValue>::_Minimum( RBTreeNode *node )
{
	while( node->Left != m_pNil ) {
		node = node->Left;
	}
	return node;
}

int main()
{
	srand((unsigned)time(NULL));
	RBTree<int, int> rbt;
	int ninsert[] = {12, 1, 9, 2, 0, 11, 7, 19, 4, 15, 18, 5, 14, 13, 10, 16, 6, 3, 8, 17};
	//int ninsert[] = {3,7,12,10,14,15,16,17,21,19,20,23,26,41,30,28,38,35,39,47};
	int n = sizeof(ninsert)/sizeof(ninsert[0]);

	//用随机值生成一棵二叉查找树
	for ( int i = 0; i < n; ++i )
	{
		//int v = rand() % 100;
		rbt.Insert( ninsert[i], ninsert[i] );
		//rbt.Insert( i, i );
	}
	rbt.Display();
	
// 	for ( int i = 0; i < n; i ++)
// 		rbt.Delete( ninsert[i] );

// 	删除所有的小奇数
	for ( int i = 1; i < n; ++i )
	{
		if ( i % 2 == 1 /*&& i < 50*/ )
		{
			if ( rbt.Delete( i ) )
			{
				cout << "Deleted [" << i << "]" << endl;
			}
		}
	}
	rbt.Display();
// 		//删除所有的大偶数
// 		for ( int i = 0; i < 100; ++i )
// 		{
// 			if ( i % 2 == 0 && i > 50 )
// 			{
// 				if ( rbt.Delete( i ) )
// 				{
// 					cout << "Deleted [" << i << "]" << endl;
// 				}
// 			}
// 		}
// 		rbt.Display();

	return 0;
}