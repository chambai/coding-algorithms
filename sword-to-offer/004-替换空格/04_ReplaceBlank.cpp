#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

//字符串替换空格
//从后往前 O(N)时间
//length为字符数组str的总容量
void ReplaceBlank( char str[], int length )
{
	assert( NULL != str );
	if ( NULL == str || length <= 0 )
		return;

	//记录空格的数量
	int nBlankCount = 0;
	//原始字符串的长度
	int nOriginalLength = 0;
	int i = 0;
	while ( str[i] != '\0' ) {
		nOriginalLength ++;
		if ( str[i] == ' ' ) 
			nBlankCount ++;
		i ++;
	}
 
	//新字符串的长度
	int nNewLength = nOriginalLength + nBlankCount * 2;
	if ( nNewLength > length )
		return;

	//两个指针分别控制字符的移动和字符的替换
	int nIndex1 = nOriginalLength;
	int nIndex2 = nNewLength;

	while ( nIndex1 < nIndex2 ) {
		if ( str[nIndex1] != ' ' )
			str[nIndex2--] = str[nIndex1];
		else {
			str[nIndex2--] = '0';
			str[nIndex2--] = '2';
			str[nIndex2--] = '%';
		}
		nIndex1 --;
	}
}

int main()
{
	char str1[] = "hello world";
	char str2[] = " hello world";
	char str3[] = "hello world ";
	char str4[] = "helloworld";
	char str5[] = "";
	char str6[] = " ";
	char str7[] = "     ";
	
	//test1
	ReplaceBlank(str1, 20);
	int i = 0; 
	while (str1[i]!='\0') {
		cout << str1[i];
		i ++;
	}
	cout << endl;

	ReplaceBlank(str2, 20);
	i = 0; 
	while (str2[i]!='\0') {
		cout << str2[i];
		i++;
	}
	cout << endl;

	ReplaceBlank(str3, 20);
	i = 0; 
	while (str3[i]!='\0') {
		cout << str3[i];
		i ++;
	}
	cout << endl;

	ReplaceBlank(str4, 20);
	i = 0; 
	while (str4[i]!='\0'){
		cout << str4[i];
		i++;
	}
	cout << endl;

	ReplaceBlank(str5, 20);
	i = 0; 
	while (str5[i]!='\0'){
		cout << str5[i];
		i ++;
	}
	cout << endl;

	ReplaceBlank(str6, 20);
	i = 0; 
	while (str6[i]!='\0'){
		cout << str6[i];
		i ++;
	}
	cout << endl;

	ReplaceBlank(str7, 20);
	i = 0; 
	while (str7[i]!='\0'){
		cout << str7[i];
		i++;
	}
	cout << endl;

	ReplaceBlank(NULL, 20);

// 	char str1[] = "hello world";
// 	char str2[] = "hello world";
// 
// 	char *str3 = "hello world";
// 	char *str4 = "hello world";
// 
// 	if (str1 == str2)
// 		cout << "str1 and str2 same!" << endl;
// 	else
// 		cout << "str1 and str2 not same!" << endl;
// 	
// 	if (str3 == str4)
// 		cout << "str3 and str4 same!" << endl;
// 	else
// 		cout << "str3 and str4 not same!" << endl;

	return 0;
}