#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool checkDifferent(string iniString) {
	// write code here
	sort(iniString.begin(),iniString.end());
	for(size_t i=0;i<iniString.size();++i){
		if(i<iniString.size()-1&&iniString[i]==iniString[i+1])
			return false;
	}
	return true; 
// 	int size=iniString.size();  
// 	if(size>256)  
// 		return false;  
// 	bool *isDifferent=new bool[256]();  
// 	for(unsigned char i=0;i<size;i++)  
// 	{  
// 		if(isDifferent[i])  
// 			return false;  
// 		isDifferent[i]=true;  
// 	}  
// 	return true;  

// 	size_t i = 0;
// 	sort(iniString.begin(), iniString.end());
// 	while (i < iniString.size()) {
// 		if (iniString[i] == iniString[i+1])
// 			return false;
// 		i ++;
// 	}
// 	return true;
}

int main()
{
	string s = "D-5H0F6T%Z?QM9,\72:[A8X! ;YJ#";
	cout << checkDifferent(s);
	cout << s;
	return 0;
}
