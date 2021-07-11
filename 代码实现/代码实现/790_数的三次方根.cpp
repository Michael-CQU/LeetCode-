#include<iostream>
#include<iomanip>
using namespace std;
const int Size = 10000;
class Solution {
public:
	double threesqrt(double x) {
		double left = -1* Size, right = Size;
		while (right - left > 1e-8) {
			double mid = (right - left) / 2 + left;
			if (mid*mid*mid <= x)
				left = mid;
			else
				right = mid;
		}
		return left;
	}
};

//int main() {
//	double x;
//	cin >> x;
//	Solution s;
//	double res = s.threesqrt(x);
//	cout << fixed<<setprecision(6)<<res << endl;
//	system("pause");
//	return 0;
//}