#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int translateNum(int num) {
		string s;
		s = to_string(num);
		int n = s.size();
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];
			if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0')) < 26)
				dp[i] += dp[i - 2];
		}
		return dp[n];
	}
};

//int main() {
//	int num = 25;
//	Solution s;
//	int res = s.translateNum(num);
//}