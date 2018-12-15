#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����һ��������ת
vector<vector<int> > transformImage1(vector<vector<int> > mat, int n) {
	// write code here
	//�ȴζԽ��߷�ת
	for (int i = 0; i < n-1; i ++) {
		for (int j = 0; j < n-1-i; j ++) {
			int temp = mat[i][j];
			mat[i][j] = mat[n-j-1][n-i-1];
			mat[n-j-1][n-i-1] = temp;
		}
	}
	//�ٵ�i���n-1-i����۷�ת
	for (int i = 0; i <= (n-1)/2; i ++) {
		for (int j = 0; j < n; j ++) {
			int temp = mat[i][j];
			mat[i][j] = mat[n-1-i][j];
			mat[n-1-i][j] = temp;
		}
	}
	return mat;
}

//��������һ����ת:��->�ң���->�£���->����->��
vector<vector<int> > transformImage2(vector<vector<int> > mat, int n) 
{
	int layer = 0; //�����һ����һ��һ�������
	for (; layer <= (n-1)/2; layer ++) {
		int first = layer;
		int last = n - 1- layer;
		for (int i = first; i < last; i ++) {
			int k = i - first; //!!!
			//get top;
			int top = mat[first][i];
			//��->��
			mat[first][i] = mat[last-k][first];
			//��->��
			mat[last-k][first] = mat[last][last-k];
			//��->��
			mat[last][last-k] = mat[i][last];
			//��->��
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