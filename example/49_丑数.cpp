#include<bits/stdc++.h>
using namespace std;
//注意此题最后一定只能用if判断，不可用if-else，因为也许有些值既是2的倍数又是3或者5的倍数
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n);
		dp[0] = 1;
		int a = 0, b = 0, c = 0;
		for (int i = 1; i < n; i++) {
			int n1 = dp[a] * 2, n2 = dp[b] * 3, n3 = dp[c] * 5;
			dp[i] = min(n1, min(n2, n3));
			if (dp[i] == n1)
				a++;
			if (dp[i] == n2)
				b++;
			if (dp[i] == n3)
				c++;
		}
		return dp[n - 1];
	}
};