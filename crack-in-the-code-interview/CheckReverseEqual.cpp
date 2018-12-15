#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//排序比较法
bool checkReverseEqual1(string s1, string s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s1 == s2)
		return true;
	else
		return false;
}

//循环移位法
//s2必定在两个s1组成的字符串上
bool checkReverseEqual2(string s1, string s2)
{
	int n1 = s1.size();
	int n2 = s2.size();

	string s = s1 + s1;
	if (n1 == n2 && s.find(s2) != string::npos)
		return true;
	else
		return false;
}

// int main()
// {
// 	string s1 = "Hello";
// 	string s2 = "ello";
// 	cout << checkReverseEqual1(s1, s2);
// 	cout << checkReverseEqual2(s1, s2);
// 	return 0;
// }