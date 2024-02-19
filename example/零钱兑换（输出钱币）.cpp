#include<bits/stdc++.h>
using namespace std;
//dp[j] = min(dp[j-coins[i]]++1,dp[j]);
//int main() {
//	vector<int> qian = { 1,2,5 };
//	int x = 10;
//	vector<vector<int>> nums(11, vector<int>());
//	for (int i = 1; i <= x; i++) {
//		int k = INT_MAX;
//		int pos = 0;
//		for (int j = 0; j < 3; j++) {
//			if (i - qian[j] >= 0) {
//				if (nums[i - qian[j]].size() < k) {
//					pos = i - qian[j];
//					k = nums[i - qian[j]].size();
//				}
//			}
//		}
//		nums[i] = nums[pos];
//		nums[i].push_back(i - pos);
//	}
//	for(auto i :nums[x])
//	cout << i << endl;
//	system("pause");
//}