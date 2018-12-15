#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

template<typename T>
class UniversalHashTable {
public:
	UniversalHashTable () {
		p = 101;	//一个足够大的质数
		m = 10;		//槽的个数
		_item.resize(m, NULL);

		for (int i = 0; i < m; i ++) {
			_item[i] = new _Node();
			_item[i]->m_pNext = NULL;
		}

		a = rand() % (p - 1) + 1;
		b = rand() % p;
	}
	
	~UniversalHashTable() {
		for (int i = 0; i < m; i ++) {
			_Node *pT = _item[i]->m_pNext;
			while (pT) {
				_Node *p = pT->m_pNext;
				delete pT;
				pT = p;
			}
		}
	}

	//向散列表中插入一个元素
	void Insert(T const &new_value) {
		//始终插入在键表的头，头结点之后的第一个位置
		_Node *new_item = new _Node();
		new_item->m_nItem = new_value;
		new_item->m_pNext = NULL;

		int hash_value = _HashFunction(new_value);

		new_item->m_pNext = _item[hash_value]->m_pNext;
		_item[hash_value]->m_pNext = new_item;
	}

	//从散列表中删除一个元素
	//@return 是否删除成功的这样的元素
	bool Delete(T const &delete_value) {
		int hash_value = _HashFunction(delete_value);
		_Node *root = _item[hash_value];

		while (root->m_pNext) {
			if (root->m_pNext->m_nItem == delete_value) {
				_Node *temp = root->m_pNext;
				root->m_pNext = root->m_pNext->m_pNext;
				delete temp;
				temp = NULL;
				return true;
			}
			else
				root = root->m_pNext;
		}
		return false;
	}

	//在散列表中搜索一个元素
	T * Search(T const &search_value) {
		int hash_value = _HashFunction(search_value);
		_Node *root = _item[hash_value]->m_pNext;

		while(root) {
			if (root->m_nItem == search_value) {
				return &(root->m_nItem);
			}
			else
				root = root->m_pNext;
		}
		return NULL;
	}

	//将散列表中所有元素显示在输出流中
	void Display(){
		for (int i = 0; i < m; i ++) {
			_Node *item = _item[i]->m_pNext; //跳过头结点
			cout << "槽[" << setw( 3 ) << i << setw( 3 ) << "]";
			while(item) {
				cout << " -> " << item->m_nItem;
				item = item->m_pNext;
			}
			cout << endl;
		}
	}

private:
	struct _Node{
		T		m_nItem;
		_Node	*m_pNext;
	};

	//全域散列函数
	//h(a,b,k) = ((a*k+b) mod p) mod m
	int _HashFunction(T key) {
		return static_cast<int>(a * key + b) % p % m;
	}
	
	//除法散列
	int _HashFunctionMul(T key) {
		return static_cast<int> key % m;
	}

	//乘法散列
	//floor表示下取整
	int _HashFunctionDiv(T key) {
		return static_cast<int> floor(m * (a * key % 1))
	}

	int p, m, a, b;
	vector<_Node *> _item; //用单链表作为散列槽
};

int main() 
{
	UniversalHashTable<int> table;
	cout << "往UniversalHashtable里添加内容[0,50):" << endl;
	for (int i = 0; i < 50; i ++) {
		table.Insert(i);
	}
	table.Display();

	cout << "开始删除内容[0,5):" << endl;
	for (int i = 0; i < 5; i ++) {
		table.Delete(i);
	}
	table.Display();
	for (int i = 0; i < 10; i ++) {
		int *finded = table.Search(i);
		cout << "开始检索节点[ " << i << " ]:";
		if (finded) 
			cout << *finded << endl;
		else
			cout << "未找到" << endl;
	} 
	return 0;
}
