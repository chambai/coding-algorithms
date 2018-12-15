#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

//二维数组中的查找
bool Find(int *matrix, int rows, int columns, int number)
{
	assert( NULL != matrix );
	
	bool isFound = false; //是否找到
	if ( matrix && rows > 0 && columns > 0 ) {
		int row = 0, col = columns - 1;
		while ( row < rows && col >= 0 ) {
			if ( matrix[row*columns+col] == number ) {
				isFound = true;
				break;
			}
			else if ( matrix[row*columns+col] > number )
				-- col;
			else
				++ row;
		}
	}
	return isFound;
}

//test1 yes
void Test1() {
	int mat[] = {1,2,8,2,4,9,4,7,10,6,8,11};
	//find max
	cout << Find(mat, 4, 3, 11) << endl;
	//find min
	cout << Find(mat, 4, 3, 1) << endl;
	//find between
	cout << Find(mat, 4, 3, 7) << endl;
}

//test2 no
void Test2(){
	int mat[] = {1,2,8,2,4,9,4,7,10,6,8,11};
	//find max
	cout << Find(mat, 4, 3, 12) << endl;
	//find min
	cout << Find(mat, 4, 3, 0) << endl;
	//find between
	cout << Find(mat, 4, 3, 5) << endl;
}

//test3 null
void Test3() {
	cout << Find(NULL, 4,3, 2);
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
