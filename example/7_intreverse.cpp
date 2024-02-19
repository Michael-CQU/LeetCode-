//#include <iostream>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	int reverse(int x) {
//		int rev = 0;
//		while (x != 0) {
//			if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
//				return 0;
//			}
//			int digit = x % 10;
//			x /= 10;
//			rev = rev * 10 + digit;
//		}
//		return rev;
//	}
//};
//
//int main() {
//	Solution s;
//	int x = 2147483647;
//	int result = s.reverse(x);
//	cout << result << endl;
//	//cout << INT_MAX << endl;
//	system("pause");
//	return 0;
//}
