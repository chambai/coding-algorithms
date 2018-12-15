#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//方法一：两步翻转
vector<vector<int> > transformImage1(vector<vector<int> > mat, int n) {
	// write code here
	//先次对角线翻转
	for (int i = 0; i < n-1; i ++) {
		for (int j = 0; j < n-1-i; j ++) {
			int temp = mat[i][j];
			mat[i][j] = mat[n-j-1][n-i-1];
			mat[n-j-1][n-i-1] = temp;
		}
	}
	//再第i层和n-1-i层对折翻转
	for (int i = 0; i <= (n-1)/2; i ++) {
		for (int j = 0; j < n; j ++) {
			int temp = mat[i][j];
			mat[i][j] = mat[n-1-i][j];
			mat[n-1-i][j] = temp;
		}
	}
	return mat;
}

//方法二：一步翻转:上->右，右->下，下->左，左->上
vector<vector<int> > transformImage2(vector<vector<int> > mat, int n) 
{
	int layer = 0; //像洋葱一样，一层一层往里剥
	for (; layer <= (n-1)/2; layer ++) {
		int first = layer;
		int last = n - 1- layer;
		for (int i = first; i < last; i ++) {
			int k = i - first; //!!!
			//get top;
			int top = mat[first][i];
			//左->上
			mat[first][i] = mat[last-k][first];
			//下->左
			mat[last-k][first] = mat[last][last-k];
			//右->下
			mat[last][last-k] = mat[i][last];
			//上->右
			mat[i][last] = top;
		}
	}
	return mat;
}	

// int main()
// {
// 	//int m[][] = {{1,2,3},{4,5,6},{7,8,9}};
// 	int m1[] = {1,2,3,10}, m2[] = {4,5,6,11}, m3[] = {7,8,9,12}, m4[] = {13,14,15,16};
// 	vector<int> v1(m1,m1+4);
// 	vector<int> v2(m2,m2+4);
// 	vector<int> v3(m3,m3+4);
// 	vector<int> v4(m4,m4+4);
// 	vector<vector<int> > vm;
// 	vm.push_back(v1);
// 	vm.push_back(v2);
// 	vm.push_back(v3);
// 	vm.push_back(v4);
// 	vector<vector<int> > vr = transformImage2(vm, 4);
// 	for (int i = 0; i < 4; i ++) {
// 		for (int j = 0; j < 4; j ++)
// 			cout << vm[i][j] << " ";
// 		cout << endl;
// 	}
// 	cout << endl;
// 	for (int i = 0; i < 4; i ++) {
// 		for (int j = 0; j < 4; j ++)
// 			cout << vr[i][j] << " ";
// 		cout << endl;
// 	}
// 	return 0;
// }