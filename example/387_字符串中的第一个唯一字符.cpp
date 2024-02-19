#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> mp;
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (mp.find(s[i]) != mp.end()) {
				mp[s[i]] = -1;
			}
			else
			mp[s[i]] = i;
		}
		int i = 0;
		for (; i < s.size(); i++) {
			if (mp[s[i]] != -1) {
				res = i;
				break;
			}
		}
		if (i == s.size())
			res = -1;
		return res;
	}
};

//int main() {
//	string test = "leetcode";
//	Solution s;
//	s.firstUniqChar(test);
//	system("pause");
//	return 0;
//}