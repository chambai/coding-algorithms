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