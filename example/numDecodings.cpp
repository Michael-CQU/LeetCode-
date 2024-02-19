//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std; 
//class Solution {
//public:
//	int numDecodings(string s) {
//		int n = s.size();
//		s = " " + s;//做个哨兵，从而方便判断边界问题，由于题目存在前导零，而前导零属于无效项，追加空格既可以避免讨论前导零，也能使下标从 1 开始，简化 f[i-1] 等负数下标的判断。
//		cout << s << endl;
//		vector<int> f(n + 1);
//		f[0] = 1;
//		for (int i = 1; i <= n; ++i) {
//			if (1 <= (s[i] - '0')&& (s[i] - '0') <= 9) {
//				f[i] = f[i - 1];
//			}
//			if (10 <= ((s[i - 1] - '0') * 10 + (s[i] - '0'))&& ((s[i - 1] - '0') * 10 + (s[i] - '0')) <= 26) {
//				f[i] += f[i - 2];
//			}
//		}
//		return f[n];
//	}
//};
//
//int main() {
//	string str = "226";
//	Solution s;
//	int result = s.numDecodings(str);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}