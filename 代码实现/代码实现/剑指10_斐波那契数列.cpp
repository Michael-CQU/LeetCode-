//#include <iostream>
//#include <vector>
//using namespace std;
////用一个记录册记录，相当于“剪枝”操作
//class Solution {
//public:
//	int fib(int n) {
//		if (n < 1) return 0;
//		vector<int> memo(n + 1, 0);
//		return helper(memo, n);
//	}
//	int helper(vector<int> &memo, int n) {
//		if (n == 1 || n == 2) return 1;
//		if (memo[n] != 0)return memo[n];
//		memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
//		return memo[n];
//	}
//};
////dp数组迭代方法
//int fib(int N) {
//	vector<int> dp(N + 1, 0);
//	// base case
//	dp[1] = dp[2] = 1;
//	for (int i = 3; i <= N; i++)
//		dp[i] = dp[i - 1] + dp[i - 2];
//	return dp[N];
//}
//int main() {
//	//测试输出
//	//{
//	//int a[5] = { 1,2,3,4,5 };
//	//int *ptr = (int*)(&a + 1);
//	//cout << "&a: " << (int)&a << endl;
//	//cout << "(&a+1): " << (int)(&a + 1) << endl;
//	//cout << "&a+1: " << (int)&a + 1 << endl;
//	//cout << "ptr: " << (int)ptr << endl;
//	//cout << "(ptr-1): " << (int)(ptr - 1) << endl;
//	////printf("%d,%d", *(a + 1), *(ptr - 1));
//	//}
//	system("pause");
//	return 0;
//}