#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkSam(string stringA, string stringB) 
{
	sort(stringA.begin(), stringA.end());
	sort(stringB.begin(), stringB.end());
	if (stringA == stringB)
		return true;
	else
		return false;
}

// int main()
// {
// 	string s1 = "Here you are";
// 	string s2 = "Are you here";
// 	cout << checkSam(s1, s2);
// 	return 0;
// }