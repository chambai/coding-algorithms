#include <iostream>

using namespace std;

bool BinaryFind(int arr[], int len, int key)
{
	if (len == 0)
		return false;
	int nLeft = 0;
	int nRight = len - 1;

	while (nLeft <= nRight) {
		int nMid = nLeft + (nRight - nLeft) / 2; //!!!±ÜÃâÒç³ö
		if (key < arr[nMid])
			nRight = nMid - 1;
		else if (key > arr[nMid])
			nLeft = nMid + 1;
		else
			return true;
	}
	return false;
}

int main()
{
	int arr[4] = {1,2,3,4};
	bool b = BinaryFind(arr, 4, 0);
	cout << b;
	return 0;
}