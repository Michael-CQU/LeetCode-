#include<bits/stdc++.h>
using namespace std;
//力扣343.整数拆分
//方法一：动态规划
class Solution {
public:
	int cuttingRope(int n) {
		vector<int> dp(n + 1);
		dp[0] = dp[1] = 0;
		for (int i = 1; i <= n; i++) {
			int temp = 0;
			for (int j = 1; j < i; j++) {
				temp = max(temp, max(j*(i - j) % 1000000007, j*dp[i - j] % 1000000007));
			}
			dp[i] = temp;
		}
		return dp[n];
	}
};

//int main() {
//	int n = 880;
//	Solution s;
//	int res = s.cuttingRope(n);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}