//#include<bits/stdc++.h>
//using namespace std;
//
//int res = 0;
//class Solution {
//public:
//	int myshoot(int target,int num) {
//		if (target<0||target>10*num)
//			return 0;
//		if (num == 0) {
//			res++;
//			return res;
//		}
//		for (int i = 0; i <= 10; i++) {
//			myshoot(target - i, num - 1);
//		}
//		return res;
//	}
//};
//int main() {
//	Solution s;
//	int ans = s.myshoot(70,10);
//	cout << ans << endl;
//	system("pause");
//	return 0;
//}