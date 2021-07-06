#include<bits/stdc++.h>
using namespace std;
//区分两个概念：子序列可以是不连续的；子数组（子字符串）需要是连续的；
//动态规划也是有套路的：单个数组或者字符串要用动态规划时，可以把动态规划 dp[i] 定义为 nums[0:i] 中想要求的结果；当两个数组或者字符串要用动态规划时，可以把动态规划定义成两维的 dp[i][j] ，其含义是在 A[0:i] 与 B[0:j] 之间匹配得到的想要的结果。
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int M = text1.size(), N = text2.size();
		vector<vector<int>> dp(M+1, vector<int>(N+1, 0));//dp[i][j]的含义是text1[0:i-1] 和 text2[0:j-1] 的最长公共子序列。dp[i][j] 的定义不是 text1[0:i] 和 text2[0:j] ，是为了方便当 i = 0 或者 j = 0 的时候，dp[i][j]表示的为空字符串和另外一个字符串的匹配，这样 dp[i][j] 可以初始化为 0.
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[M][N];
	}
};

//int main() {
//	string test1 = "ace";
//	string test2 = "bc";
//	Solution s;
//	int res = s.longestCommonSubsequence(test1, test2);
//	cout << res << endl;
//	return 0;
//}