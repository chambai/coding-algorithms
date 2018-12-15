### 题目描述

> 请实现一个函数，将一个字符串中的空格替换成“%20”。 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
>
> We Are Happy
>
> We%20Are%20Happy
>




### 解决

#### 01 暴力法

略...

#### 02 先记录空格数，再替换

- 遍历一遍字符串， 统计字符出现的数目, 计算替换后的字符串长度
- 再遍历一遍字符串，完成替换



````c++
#include <iostream>

using namespace std;

class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        int i, j;
        int count = 0;
        int len = length;
        for(int i = 0; i < length; i++) {
            if(str[i] == ' ') {
                count++;
            }
        }

        len = length + count * 2;
        for(i = length - 1, j = len - 1; i >= 0 && j >= 0;) {
            if(str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            }
            else {
                str[j--]  = str[i--];
            }
        }
        str[len] = '0';
    }
};


int main( )
{
    char str[10 + 1] = "a b c d";

    Solution solu;
    solu.replaceSpace(str, 10);

    cout << str << endl;

    return 0;
}
````

