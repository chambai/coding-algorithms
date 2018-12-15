#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int caculate(int x1, int x2, string s) 
{
	int result;
	if (s == "+")
		result = x1 + x2;
	else if (s == "-") 
		result = x1 - x2;
	else if (s == "*")
		result = x1 * x2;
	else {
		if (x1 >= x2)
			result = x1 / x2;
		else
			result = x2 / x1;
	}
	return result;
}

int evalRPN(vector<string> &tokens)
{
	stack<int> stokens;
	for (int i = 0; i < tokens.size(); ++ i) {
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
			int x1 = stokens.top();
			stokens.pop();
			int x2 = stokens.top();
			stokens.pop();
			int x3 = caculate(x1, x2, tokens[i]);
			stokens.push(x3);
		}
		else {
			stokens.push(atoi(tokens[i].c_str()));
		}
	}
	return stokens.top();
}

// int main()
// {
// 	string s[] = {"4", "13", "5", "/", "+"};
// 
// 	vector<string> svector(s, s + 5);
// 
// 	cout << evalRPN(svector);
// // 	for (vector<string>::iterator it = svector.begin(); it != svector.end(); ++ it) {
// // 		cout << *it;
// // 	}
// 
// 	return 0;
// }