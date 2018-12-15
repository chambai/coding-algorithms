### 题目描述


> 大家都知道斐波那契数列， 现在要求输入一个整数n， 请你输出斐波那契数列的第n项。




### 解决

#### 01 递归法

递推公式$f(n) =$：

- $=0, 当n=0$
- $=1, 当n=1$
- $=f(n - 1) + f(n - 2), 其他$ 因此我们马上想到了如下递归代码

```c++
int Fibonacci(int n){
    if(n <= 1){
        return n;
    }
    else{
        return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
}
```



#### 02 递归展开



````c++
#include <iostream>

using namespace std;

class Solution
{

public:
    int Fibonacci(int n) {
        if(n <= 1) {
            return n;
        }
        long one = 0;
        long two = 1;;
        long res = 0;

        for(int i = 2; i <= n; i++) {
            res = one + two;
            one = two;
            two = res;
        }

        return res;
    }
};

int main( )
{
    Solution solu;
    cout <<solu.Fibonacci(3) <<endl;;

    return 0;
}
````

