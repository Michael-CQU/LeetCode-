#include <bits/stdc++.h>
using namespace std;
//自我实现快速幂，时间复杂度为O（logk）
class Solution {
public:
	double myPow(double x, int n) {
		long long k = n;
		if (k < 0) {
			k = -k;
			x = 1 / x;
		}
		double res = 1;
		while (k) {
			if (k & 1)
				res = res*x;
			k >>= 1;
			x = x*x;
		}
		return res;
	}
};
//迭代法
//class Solution {
//public:
//	double myPow(double x, int n) {
//		if (x == 0)return 0;//防止除数为0
//		long long b = n;
//		double res = 1;
//		if (b < 0) {
//			x = 1 / x;
//			b = -b;
//		}
//		while (b > 0) {//将幂计算分成计算n的二进制与x=x^2的操作就是快速幂算法
//			if ((b & 1) == 1)res *= x;//如果此时对应的二进制位为1的话，就进行相乘操作（res为最终的相乘结果）；如果此时对应的二进制位为0，则此位不管是x的任何次方，都是1.
//			x *= x;//计算x^1,x^2,x^4,...,x^2^m-1次方
//			b /= 2;//也可以进行移位操作b>>=1
//		}
//		return res;
//	}
//};
//迭代法
//class Solution {//此题要思考边界条件，以及特殊的测试样例
//public:
//	double myPow(double x, int n) {
//		if (n == INT_MIN)return(x == 1 || x == -1) ? 1 : 0;//特判条件，当n的值为最小值时，无法进行计算，可以将n转换成long long形式或者用此方法特判
//		if (n == 0)
//			return 1;
//		if (n < 0)
//			return myPow(1 / x, -n);
//		if (n % 2 == 1)
//			//return myPow(x, n - 1)*x;
//			return myPow(x*x, n / 2)*x;
//		else
//			return myPow(x*x, n / 2);
//	}
//};//每次递归都会使得指数减少一半，因此递归的层数为O（logn）
//int main() {
//	double x = 1.0;
//	int n = INT_MIN;
//	Solution s;
//	double res = s.myPow(x,n);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}