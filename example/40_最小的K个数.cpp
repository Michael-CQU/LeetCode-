#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int myquicksort(vector<int>& arr,int left,int right) {
		if (left > right)return left;
		int pivot = arr[left];
		int i = left, j = right;
		while (i < j) {
			while (arr[j] >= pivot&&i<j)
				j--;
			while (arr[i] <= pivot&&i<j)
				i++;
			swap(arr[i], arr[j]);
		}
		swap(arr[i], arr[left]);
		return i;
	}
		vector<int> getLeastNumbers(vector<int>& arr, int k) {
			vector<int> ans;
			int left = 0, right = arr.size() - 1;
			while (1) {
				int index = myquicksort(arr, left, right);
				if (index == k) {
					for (int i = 0;i<k;i++)
						ans.push_back(arr[i]);
					break;
				}
				if (index < k) {
					left = index + 1;
				}
				if (index > k) {
					right = index - 1;
				}
			}
			return ans;
	}
};

//int main() {
//	vector<int> test = { 0,0,2,3,2,1,1,2,0,4 };
//	Solution s;
//	vector<int> ans = s.getLeastNumbers(test, 10);
//	for (int i : ans) {
//		cout << i << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}