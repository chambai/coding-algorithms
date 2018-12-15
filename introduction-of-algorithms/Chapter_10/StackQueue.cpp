#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

/************************************************************************/
/*	两个栈实现队列
/*	采用C++模板是实现
/************************************************************************/
template<class T>
class StackQueue
{
public:
	StackQueue(){}
	~StackQueue(){}

	void Enqueue(const T& elem);
	T	Dequeue();
	bool Empty() const;

private:
	stack<T>	m_stackA;
	stack<T>	m_stackB;
};

template<class T>
void StackQueue<T>::Enqueue(const T& elem)
{
	if (m_stackA.empty())
		m_stackA.push(elem);
	else {
		while (!m_stackA.empty()) {
			m_stackB.push(m_stackA.top());
			m_stackA.pop();
		}
		m_stackA.push(elem);
	}

	while(!m_stackB.empty()) {
		m_stackA.push(m_stackB.top());
		m_stackB.pop();
	}
}

template<class T>
T StackQueue<T>::Dequeue()
{
	T retElem;
	if (!m_stackA.empty()) {
		retElem = m_stackA.top();
		m_stackA.pop();
	}
	return retElem;
}

template<class T>
bool StackQueue<T>::Empty() const
{
	if (m_stackA.empty())
		return true;
	else
		return false;
}

// int main()
// {
// 	StackQueue<int> SQ;
// 	for (int i = 1; i <= 5; i ++) {
// 		SQ.Enqueue(i);
// 	}
// 
// 	for (int i = 1; i <= 5; i ++) {
// 		cout << SQ.Dequeue();
// 	}
// 	return 0;
// }