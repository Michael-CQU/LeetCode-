#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int n1 = s.size(), n2 = p.size();
		vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
		dp[0][0] = true;
		for (int j = 1; j <= n2; j++) {
			if (p[j - 1] == '*')
				dp[0][j] = true;
			else
				break;
		}
		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n2; j++) {
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
				}
			}
		}
		return dp[n1][n2];
	}
};

//int main() {
//	string s = "aab";
//	string p = "c*a*b";
//	Solution s1;
//	bool result = s1.isMatch(s, p);
//	system("pause");
//	return 0;
//}