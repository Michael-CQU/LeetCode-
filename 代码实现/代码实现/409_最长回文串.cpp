#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> mp;
		int ans = 1;
		for (int i = 0; i < s.size(); i++) {
			mp[s[i]]++;
		}
		for (auto it : mp) {
			int temp = it.second;
				ans += temp/2*2;
				if (temp % 2 == 1 && ans % 2 == 0)
					ans++;
		}
		return ans;
	}
};
//int main() {
//	string test = "abccccdd";
//	Solution s;
//	int res = s.longestPalindrome(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}