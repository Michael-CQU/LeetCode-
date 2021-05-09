//#include <iostream>
//#include <vector>
//using namespace std;
//
////class Solution {
////public:
////	bool isSubsequence(string s, string t) {
////		int count = 0, pre = 0;
////		for (int i = 0; i < s.size(); i++) {
////			for (int j = pre; j < t.size(); j++) {
////				if (s[i] == t[j])
////				{
////					pre = j+1; count++; break;
////				}
////			}
////		}
////		if (count == s.size())
////			return true;
////		return false;
////	}
////};
//
//class Solution {
//public:
//	bool isSubsequence(string s, string t) {
//		int n = s.size(), m = t.size();
//		//dp定义：dp[i][j]表示字符串t中从位置i开始往后字符j第一次出现的位置
//		vector<vector<int> > f(m + 1, vector<int>(26, 0));//初始化动态规划数组
//		for (int i = 0; i < 26; i++) {
//			f[m][i] = m;
//		}
//
//		for (int i = m - 1; i >= 0; i--) {//逆序从后往前递推dp数组
//			for (int j = 0; j < 26; j++) {
//				if (t[i] == j + 'a')
//					f[i][j] = i;
//				else
//					f[i][j] = f[i + 1][j];
//			}
//		}
//		int add = 0;
//		for (int i = 0; i < n; i++) {
//			if (f[add][s[i] - 'a'] == m) {//t中没有s[i]则返回false
//				return false;
//			}
//			add = f[add][s[i] - 'a'] + 1;//否则直接跳到t中s[i]第一次出现的位置之后一位
//		}
//		return true;
//	}
//};
//
//int main() {
//	Solution solution;
//	string s = "aaaaaa";
//	string t = "bbaaaa";
//	bool result = solution.isSubsequence(s, t);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}