#include <bits/stdc++.h>
using namespace std;

class Solution {
	unordered_set<char> st;
public:
	int countPalindromicSubsequence(string s) {
		int ans = 0;
		int n = s.size();
		for (int i = 0; i < n - 1; i++) {
			int j = i + 1;
			while (s[j] != s[i]&&j < n) {
				j++;
			}
			int m = i + 1;
			while (m<=n-1&&j!=n) {
				if (st.find(s[m]) == st.end()&&m!=j) {
					ans++;
					st.insert(s[m]);
				}
				m++;
			}
		}
			return ans;
	}
};

//int main() {
//	string test = "bbcbaba";
//	Solution s;
//	int res = s.countPalindromicSubsequence(test);
//	system("pause");
//	return 0;
//}