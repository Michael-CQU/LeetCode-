#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> s2t;
		unordered_map<char, char> t2s;
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			char x = s[i], y = t[i];
			if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
				return false;
			}
			s2t[x] = y;
			t2s[y] = x;
		}
		return true;
	}
};

//int main() {
//	string s = "foo";
//	string t = "bar";
//	Solution s1;
//	s1.isIsomorphic(s, t);
//	system("pause");
//	return 0;
//}