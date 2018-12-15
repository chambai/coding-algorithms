#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

string num2str(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

string zipString(string iniString) {
	// write code here
	int n = iniString.size();
	string retString;
	int i = -1, j = 0;
	int count = 0;
	while(j <= n) {
		if (iniString[i+1] == iniString[j]) {
			count++;
			j++;
		}
		else {
			retString.push_back(iniString[i+1]);
			string str = num2str(count);
			size_t k = 0;
			while (k < str.size()) {
				retString.push_back(str[k]);
				k++;
			}
			i = j-1;
			count = 0;
		}
	}
	if (iniString.size() < retString.size()) 
		retString = iniString;
	return retString;
}

// int main()
// {
// 	string str = "jjjjjjjjjjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF";
// 	string s = zipString(str);
// 	cout << s;
// 	return 0;
// }
