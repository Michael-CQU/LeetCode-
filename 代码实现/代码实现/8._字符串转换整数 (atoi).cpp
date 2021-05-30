//#include<iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//	int myAtoi(string s) {
//		string res;
//		int result = 0,i = 0;
//		bool symble = true;
//		{
//			while (s[i] == ' ')
//				i++;
//			if (s[i] == '-') {
//				symble = false;
//				i++;
//			}
//			else if (s[i] == '+')
//				i++;
//			while (s[i] >= '0'&&s[i] <= '9')
//				res.push_back(s[i++]);
//		}
//		if (symble == false) {
//			int j = 0;
//			for (int j = 0; j < res.length(); j++) {
//				if (result > INT_MIN / 10||(result == INT_MIN/10&&(res[j]-'0'<9)))
//					result = result * 10 - (res[j] - '0');
//				else
//					return INT_MIN;
//			}
//		}
//		else {
//			int j = 0;
//			for (int j = 0; j < res.length(); j++) {
//				if (result < INT_MAX / 10||(result == INT_MAX/10&&(res[j]-'0'<8)))
//					result = result * 10 + (res[j] - '0');
//				else
//					return INT_MAX;
//			}
//		}
//		return result;
//	}
//};
//
//int main() {
//	string test = "-91283472332";
//	Solution s;
//	int result = s.myAtoi(test);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}