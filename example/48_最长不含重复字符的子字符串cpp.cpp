#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//����Ĺؼ��ǿ����ַ�s[i]�����ַ���dp[j-1]�������߻������
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size(), ans = 1;
		if (n == 0)return 0;
		vector<int> dp(n + 1, 1);
		unordered_map<char, int> dis;
		int first = 0;
		for (int i = 1; i <= n; i++) {
			if (dis.find(s[i - 1]) != dis.end()) {
				first = dis[s[i - 1]];
			}
			if (i - first > dp[i - 1])//ע�����ﲻ���õ��ں�
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = i - first;
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