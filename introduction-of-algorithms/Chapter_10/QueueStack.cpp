#include <iostream>
#include <queue>

using namespace std;

/************************************************************************/
/*	两个队列实现一个栈
/*	使用C++模板的形式
/************************************************************************/
template<class T>
class QueueStack {
public:
	QueueStack(){}
	~QueueStack(){}
	
	void Push(const T& elem);
	void Pop();
	T Top() const;

private:
	queue<T>	m_queueA;
	queue<T>	m_queueB;
};

template<class T>
void QueueStack<T>::Push(const T& elem)
{
	if (m_queueA.empty())
		m_queueA.push(elem);
	else {
		while (!m_queueA.empty()) {
			m_queueB.push(m_queueA.front());
			m_queueA.pop();
		}
		m_queueA.push(elem);
	}
	while (!m_queueB.empty()) {
		m_queueA.push(m_queueB.front());
		m_queueB.pop();
	}
}

template<class T>
void QueueStack<T>::Pop()
{
	if (!m_queueA.empty())
		m_queueA.pop();
}

template<class T>
T QueueStack<T>::Top() const
{
	T nElem;
	if (!m_queueA.empty())
		nElem = m_queueA.front();
	return nElem;
}

// int main()
// {
// 	QueueStack<int> QS;
// 	for (int i = 1; i <= 5; i ++) {
// 		QS.Push(i);
// 	}
// 
// 	for (int i = 1; i <= 5; i ++) {
// 		cout << QS.Top();
// 		QS.Pop();
// 	}
// 	return 0;
// }