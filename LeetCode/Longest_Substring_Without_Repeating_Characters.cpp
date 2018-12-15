#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	size_t j = 1;
	if (s.size() <= 1)
		return s.size();

	int len = 1, nMaxLen = 0;
	string subStr;
	subStr.push_back(s[0]);
	while (j < s.size()) {
		if (subStr.find(s[j]) == string::npos) {
			subStr.push_back(s[j]);
		}
		else {
			if (len > nMaxLen)
				nMaxLen = len;
			while (subStr.find(s[j]) != string::npos) {
				subStr.erase(0,1);
				len --;
			}
			subStr.push_back(s[j]);
		}
		len ++;
		j ++;
	}
	if (len > nMaxLen)
		nMaxLen = len;
	return nMaxLen;
}

// int main()
// {
// 	string s = "auaf";
// 	cout << lengthOfLongestSubstring(s);
// 	return 0;
// }