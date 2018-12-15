#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// void reverseWords(string &s)
// {
// 	stack<string> string_stack;
// 	int iSpace = 0;
// 	bool endFlag = true;
// 
// 	while (endFlag) { //×°Èëstack
// 		int iPos = s.find(' ', iSpace);
// 		if (iPos == -1) {
// 			iPos = s.length();
// 			endFlag = false;
// 		}
// 	
// 		int nPos = iPos - iSpace;
// 		string subString = s.substr(iSpace, nPos);
// 		string_stack.push(subString);
// 		iSpace = iPos + 1;
// 	}
// 	
// 	string stringReverse;
// 	while (!string_stack.empty()) {
// 		stringReverse += string_stack.top();
// 		stringReverse += " ";
// 		string_stack.pop();
// 	}
// 	
// 	string	stringPrint = stringReverse.substr(0, s.length());
// 	cout << stringPrint;
// }

// void _reverseWords(istringstream &iss, string &res) {
// 	string word;
// 	if (iss >> word) {
// 		_reverseWords(iss, res);
// 		if (res == "")
// 			res += word;
// 		else 
// 			res += " " + word;
// 	}
// }
// 
// void reverseWords(string &s)
// {
// 	istringstream iss(s);
// 	_reverseWords(iss, s = "");
// }

void reverseWords(string &s)
{
	int i = 0, j = 0;
	string subStr;
	vector<string> vecStr;
	for (j = 0; j != s.length()+1; ++j) {
		if (s[j] == ' '||j == s.length()) { //Ensure that the final substr can be get
			subStr = s.substr(i, j - i);
			if (subStr != "")  //remove the "" from begin and end str
				vecStr.push_back(subStr);
			i = j + 1;
		}
	}
	
	int vecLen = vecStr.size();
	if (vecLen > 0) {  // deal with the s = ""
		string strResult = "";
		for (i = vecLen - 1; i > 0; i --) {
			strResult += vecStr[i] + " ";
		}
		strResult += vecStr[i];
		s = strResult;
	}
	else
		s = "";
}
// class Solution {
// public:
// 	void reverseWords(string & s)
// 	{
// 		string ss;
// 		int i = s.length()-1;
// 		while(i>=0)
// 		{
// 			while(i>=0&&s[i] == ' ')
// 			{
// 				i --;
// 			}
// 			if(i<0) break;
// 			if(ss.length()!=0)
// 				ss.push_back(' ');
// 			string temp ;
// 			for(;i>=0&&s[i]!=' ';i--)
// 				temp.push_back(s[i]);
// 			reverse(temp.begin(),temp.end());
// 			ss.append(temp);
// 		}
// 		s=ss;
// 	}
// };
// int main()
// {
// 	string s = " the sky     is   blue   ";
// 	reverseWords(s);
// 	cout << s << endl;
// 	return 0;
// }