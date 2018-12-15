#include <iostream>
#include <string>

using namespace std;

string reverseString(string iniString) 
{
	int left = 0, right = iniString.size()-1;
	while (left < right) {
		char t = iniString[left];
		iniString[left] = iniString[right];
		iniString[right] = t;

		left ++;
		right --;
	}
	return iniString;
}

// int main()
// {
// 	string s = reverseString("dfjskd");
// 	cout << s;
// 	return 0;
// }