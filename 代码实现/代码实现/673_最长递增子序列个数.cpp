#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n + 1, 1);
		vector<int> count(n + 1, 1);
		int Max = dp[0], res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i])
					if (dp[j] + 1 > dp[i]) {
						dp[i] = dp[j] + 1;
						count[i] = count[j];
					}
					else {
						if (dp[j] + 1 == dp[i])
							count[i] += count[j];
					}

			}
		}
		for (int i = 0; i < n; i++) {
			if (Max < dp[i])
				Max = dp[i];
		}
		for (int i = 0; i < n; i++) {
			if (dp[i] == Max)
				res+=count[i];
		}
		return res;
	}
};

//int main() {
//	vector<int> test = { 1,3,5,4,7 };
//	Solution s;
//	int res = s.findNumberOfLIS(test);
//	system("pause");
//	return 0;
//
//}