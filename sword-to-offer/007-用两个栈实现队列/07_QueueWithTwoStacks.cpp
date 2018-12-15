#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
	CQueue(void){}
	~CQueue() {}

	void Push(const int& value){
		stack1.push(value);
	}
	int Pop() {
		if (stack2.size() <= 0) {
			while (stack1.size() > 0) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.size() == 0)
			throw new exception("queue is empty");

		int retVal = stack2.top();
		stack2.pop();
		return retVal;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	//往空的队列里添加和删除元素
	CQueue cq;
	cq.Push(4);
	cq.Push(5);
	cout << cq.Pop();
	cout << cq.Pop();
	cout << cq.Pop();
	
	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}