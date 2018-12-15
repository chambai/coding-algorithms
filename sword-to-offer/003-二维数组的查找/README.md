### 题目描述

> 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。


### 输入描述

> array： 待查找的二维数组 target：查找的数字

### 输出描述

> 查找到返回true，查找不到返回false


### 解决

#### 01 分治法

比如在下面的数组中查找 7：

![](./find7.jpg)

从右上角的数据开始出发: 

- 比他小的数必定在它的左侧，就往左找
- 比他大的数必定在它的下侧，就往下找



````c++
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    bool Find(vector<vector<int> > array,int target)
    {
        bool res = false;
        int row = array.size( );
        int col = array[0].size( );

        //  我们从右上角的元素找起来
        //  如果查找的元素比当前位置元素小, 就向左走
        //  如果查找的元素比当前位置元素大, 就向下走
        for(int i = 0, j = col -1;
            (i >=0 && i < row) && (j >= 0 && j < col);) {
            if(target == array[i][j]) {
                res = true;
                break;
            }
            else if(target < array[i][j]) {    // 小的元素在当前位置左侧
                j--;
            }
            else {
                i++;
            }
        }
        return res;
    }
};

int main()
{
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector< vector<int> > array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    Solution solu;
    cout <<solu.Find(array, 7) <<endl;
    return 0;
}
````

