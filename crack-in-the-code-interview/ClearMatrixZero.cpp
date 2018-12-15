#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int> > clearZero(vector<vector<int> > mat, int n)
{
	vector<int> row(n,0), col(n,0);
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (mat[i][j] == 0) {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (row[i] == 1 || col[j] == 1) 
				mat[i][j] = 0;
		}
	}

	return mat;
}

int main()
{
	int m1[] = {1,2,3}, m2[] = {0,1,2}, m3[] = {0,0,1};
	vector<int> v1(m1,m1+3);
	vector<int> v2(m2,m2+3);
	vector<int> v3(m3,m3+3);

	vector<vector<int> > vm;
	vm.push_back(v1);
	vm.push_back(v2);
	vm.push_back(v3);
	vector<vector<int> > vr = clearZero(vm, 3);
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++)
			cout << vm[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++)
			cout << vr[i][j] << " ";
		cout << endl;
	}
	return 0;
}
