#ifndef __RED_BLACK_TREE_
#define __RED_BLACK_TREE_

//使用模板类
template< typename TKey, typename TValue >
class RBTree 
{
/************************************************************************/
/* 红黑树结点属性                                                               
/************************************************************************/
public:
	//结点的颜色-枚举
	enum RBTreeNodeColor {
		RED,	//红色
		BLACK	//黑色
	};

	//结点的属性
	struct RBTreeNode {
		TKey				Key;
		TValue				Value;
		RBTreeNodeColor		Color;
		RBTreeNode			*Parent;
		RBTreeNode			*Left;
		RBTreeNode			*Right;
		
		//@brief 红黑树中的哨兵结点T.nil实际上是空结点，为无效结点
		//@return 返回某个结点是否为无效结点
		//@retval = true 非nil结点
		//@retval = false nil结点
		inline bool isValid() const {
			return ( this != m_pNil );
		}
	};

/************************************************************************/
/* 红黑树公有属性                                                          
/************************************************************************/
public:
	RBTree();	//构造函数
	~RBTree();	//析构函数

	//@brief 插入一个结点
	bool Insert( TKey key, TValue value );

	//@brief 删除一个结点
	bool Delete( TKey key );

	//@brief 搜索一个结点
	RBTreeNode * Search( TValue const &value );

	//@brief 判断红黑树是否为空
	bool Empty();

	//@brief 显示当前红黑树
	void Display() const;

/************************************************************************/
/* 红黑树私有属性                                                          
/************************************************************************/
private:
	//@brief 递归删除所有结点
	void _RecursiveReleaseNode ( RBTreeNode *node );
	
	//@brief 显示
	void _Display( RBTreeNode *node ) const;
	
	//@brief 真正的插入函数
	void _InsertRBTree( RBTreeNode *node ); 

	//@brief 对插入操作的修复
	void _InsertFixup( RBTreeNode *node );

	//@brief 左旋
	void _LeftRotate( RBTreeNode *node );

	//@brief 右旋
	void _RightRotate( RBTreeNode *node );

	//@brief 真正的删除操作
	void _Delete( RBTreeNode *node );

	//@brief 专属红黑树的替换操作
	void _RB_Transplant( RBTreeNode *unode, RBTreeNode *vnode );
	
	//@brief 对删除操作的修复
	void _DeleteFixup( RBTreeNode *node );

	//@brief 后继
	RBTreeNode * _Successor( RBTreeNode *node );

	//@brief 前驱
	RBTreeNode * _Predecessor( RBTreeNode *node );

	//@brief Maximum
	RBTreeNode * _Maximum( RBTreeNode *node );
	
	//@brief Minimum
	RBTreeNode * _Minimum( RBTreeNode *node );


private:
	//红黑树的数据成员
	RBTreeNode	*m_pRoot;	//根结点
	static RBTreeNode	*m_pNil;	//哨兵空结点
};
#endif//__RED_BLACK_TREE_