#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
private:
	unordered_map<char, int>need, window;
public:
	string minWindow(string s, string t) {
		for (char i : t)need[i]++;
		int left = 0, right = 0;
		int valid = 0;
		int start = 0,len = INT_MAX;
		while (right < s.size()) {
			char c = s[right];
			right++;
			if (need.count(c)) {
				window[c]++;
				if (window[c] == need[c])
					valid++;
			}
			while (valid == need.size()) {
				if (right - left < len) {
					start = left;
					len = right - left;
				}
				char d = s[left];
				left++;
				if (need.count(d)) {
					if (window[d] == need[d])
						valid--;
					window[d]--;
				}
			}
		}
		return len == INT_MAX ? "" : s.substr(start, len);
	}
};

//int main() {
//	string test1 = "ADOBECODEBANC";
//	string test2 = "ABC";
//	Solution s;
//	string result = s.minWindow(test1,test2);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}