#include<bits/stdc++.h>
using namespace std;
//把a+b转换成非进位和+进位，由于不能用加法，因此要一直转换直到第二个加数变成0。 用递归的写法比循环更容易一下子看懂
//无进位和 与 异或运算 规律相同，进位 和 与运算 规律相同（并需左移一位）
//class Solution {
//public:
//	int add(int a, int b) {
//		while (b != 0)
//		{
//			int c = (unsigned int)(a & b) << 1;//进位：与运算+左移一位
//			a ^= b;//非进位和：异或运算
//			b = c;
//		}
//		return a;
//	}
//};
//递归方法：
class Solution {
public:
	int add(int a, int b) {
		if (b == 0) {
			return a;
		}
		return add(a^b, (unsigned int)(a&b) << 1);//如果不支持负值左移就转成无符号整数
	}
};
//int main() {
//	int a = -1;
//	int b = 2;
//	Solution s;
//	int res = s.add(a, b);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}