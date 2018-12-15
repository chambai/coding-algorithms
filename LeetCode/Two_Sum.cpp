#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//方法一：排序法
struct SNode {
	int value;
	int pos;
};

bool cmp(SNode a, SNode b)
{
	return a.value < b.value;
}

vector<int> twoSum(vector<int>& nums, int target) {
	int n = nums.size();
	
	vector<int> vecRet;
	vector<SNode> vecNode;
	
	for (int i=0; i < n; i ++) {
		SNode temp;
		temp.value = nums[i];
		temp.pos = i+1;
		vecNode.push_back(temp);
	}
	sort(vecNode.begin(),vecNode.end(), cmp);

	int i = 0, j = n-1;
	while(i < j) {
		int sum = vecNode[i].value + vecNode[j].value;
		if (sum == target) {
			if(vecNode[i].pos < vecNode[j].pos){
				vecRet.push_back(vecNode[i].pos);
				vecRet.push_back(vecNode[j].pos);
				break;
			}
			if (vecNode[i].pos > vecNode[j].pos) {
				vecRet.push_back(vecNode[j].pos);
				vecRet.push_back(vecNode[i].pos);
				break;
			}
		}
		else if (sum > target)
			j--;
		else
			i ++;
	}
	return vecRet;
}

//方法二：hashtable法
vector<int> twoSum1(vector<int>& nums, int target) 
{
	int i, sum;
	vector<int> results;
	map<int, int> hmap;
	for(i=0; i<nums.size(); i++){
		if(!hmap.count(nums[i])){
			hmap.insert(pair<int, int>(nums[i], i));
		}
		if(hmap.count(target-nums[i])){
			int j=hmap[target-nums[i]];
			if(j<i){
				results.push_back(j+1);
				results.push_back(i+1);
				return results;
			}
		}
	}
	return results;
}
int main()
{
	int arr[] = {2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> nums(arr, arr+n);
	vector<int> ret;
	ret = twoSum1(nums, 6);
	for(vector<int>::iterator it = ret.begin(); it!=ret.end(); ++it)
		cout << *it;
	return 0;
}