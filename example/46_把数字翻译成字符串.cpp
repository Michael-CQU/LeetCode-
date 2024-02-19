#include<iostream>
#include <string>
#include <vector>
using namespace std;
//循环的次数是num的位数，因此时间渐进复杂度为O（logn）
class Solution {
public:
	int translateNum(int num) {
		string s;
		s = to_string(num);
		int n = s.size();
		vector<int> dp(n + 1);
		dp[0] = 1;//注意此无数字的情况是由dp[2]如果是组成的值在10-25之间，则要求dp[0]+dp[1] = 2推导而来
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];
			if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0')) < 26)
				dp[i] += dp[i - 2];
		}
		return dp[n];
	}
};
//注意因为dp[i]只与dp[i-1]、dp[i-2]有关，因此可以用三个变量简化动态规划数组，也就是让三个变量组成滚动数组。

//int main() {
//	int num = 25;
//	Solution s;
//	int res = s.translateNum(num);
//}