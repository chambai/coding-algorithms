### 题目描述

> 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。




### 解决

始终维护s1作为**输入栈**，以s2作为**输出栈**

- 入队时，将元素压入s1。
- 出队时，判断s2是否为空，如不为空，则直接弹出顶元素；如为空，则将s1的元素逐个“倒入”s2，把最后一个元素弹出并出队。 这个思路，避免了反复“倒”栈，仅在需要时才“倒”一次。但在实际面试中很少有人说出，可能是时间较少的缘故吧。



````c++
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stackIn.push(node);
    }

    int pop() {
        int node = -1;

        //  两个栈都是NULL的时候，整个队列为空
        if(this->empty( ) == true) {
            return -1;
        }
        else {
            //  否则队列中有元素
            //  此时分两种情况，
            //  当输出栈不为空的时候, 直接将输出栈中元素弹出即可
            //  当输出栈为NULL, 但是输入栈不为空的时候，需要将输入栈的元素全部倒入输出栈中

            if(stackOut.empty() == true) {    //  此时输出栈为空, 输入栈必不为空
                //  此时缓冲栈（输出栈）中没有元素
                //  需要将输入栈中的元素倒入输出栈
                // 看输入栈中有没有元素

                //  否则将元素从输入栈导入输出栈
                while(stackIn.empty( ) != true) {
                    node = stackIn.top( );
                    stackIn.pop( );
                    stackOut.push(node);
                }
            }

            node = stackOut.top( );
            stackOut.pop( );
        }

        return node;
    }

    bool empty( ) {
        return (stackIn.empty() == true && stackOut.empty() == true);
    }

private:
    stack<int> stackIn;
    stack<int> stackOut;
};


int main( )
{
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);

    int node;
    while(solu.empty() != true) {
        cout <<solu.pop( );
    }

    return 0;
}
````

