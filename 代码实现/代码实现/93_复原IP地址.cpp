#include<iostream>
#include <string>
#include <vector>
using namespace std;
//方法一：
//class Solution {
//public:
//	void dfs(string s, string cur, vector<string>& ans, int cnt) {
//		if (cnt == 4 && s.size() == 0) {
//			cur.pop_back();
//			ans.push_back(cur);
//			return;
//		}
//		if (cnt == 4 && s.size()) {
//			return;
//		}
//		for (int i = 1; i <= 3 && i <= s.size(); i++) {
//			string ss = s.substr(0, i);
//			int num = stoi(ss);
//			if (to_string(num).size() != ss.size()) {
//				return;
//			}
//			if (num <= 255 && num >= 0) {
//				string temp = cur;
//				cur += (ss + '.');
//				dfs(s.substr(i), cur, ans, cnt + 1);
//				cur = temp;
//			}
//		}
//	}
//	vector<string> restoreIpAddresses(string s) {
//		vector<string> ans;
//		dfs(s, "", ans, 0);
//		return ans;
//	}
//};
//方法二：（常规思路：掌握）
class Solution {
public:
	vector<string> ans;
	bool isvalid(string& s,int start,int end) {
		if (start > end)return false;
		if (s[start] == '0'&&start != end)return false;
		int sums = 0;
		for (int i = start; i <= end; i++) {
			if (s[i] > '9' || s[i] < '0')return false;
			sums = sums * 10 + (s[i] - '0');
			if (sums > 255)
				return false;
		}
		return true;
	}
	void generate(string& s,int idx,int pointnum) {
		if (pointnum == 3) {
			if (isvalid(s, idx, s.size() - 1)) {
				ans.push_back(s);
			}
			return;
		}
			
			for (int i = idx; i < s.size(); i++) {
				if (isvalid(s, idx, i)) {
					s.insert(s.begin() + i + 1, '.');
					pointnum++;
					generate(s, i + 2, pointnum);
					pointnum--;
					s.erase(s.begin() + i + 1);
				}
				else
					break;
			}
		}
	vector<string> restoreIpAddresses(string s) {
		generate(s, 0, 0);
		return ans;
	}
};
//int main() {
//	string test = "25525511135";
//	Solution s;
//	vector<string> res = s.restoreIpAddresses(test);
//	for (auto i : res)
//		cout << i << endl;
//	system("pause");
//	return 0;
//}