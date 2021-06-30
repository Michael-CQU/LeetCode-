#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size(), ans = 1;
		if (n == 0)return 0;
		vector<int> dp(n, 1);
		unordered_map<char, int> dis;
		dis[s[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (i - dis[s[i - 1]] > dp[i - 1])
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = i - dis[s[i - 1]];
			dis[s[i - 1]] = i;
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};
//int main() {
//	string s = "abcabcbb";
//	Solution s1;
//	int ans = s1.lengthOfLongestSubstring(s);
//	return 0;
//}