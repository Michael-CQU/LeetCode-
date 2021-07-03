#include <bits/stdc++.h>
using namespace std;
/*
C++运算符优先级
9	==  !=	等于/不等于
10	&	按位与
11	^	按位异或
12	|	按位或
13  &&  与
14  ||  或
*/
//分组异或，使得：1.两个只出现一次的数字在不同的组中；2.相同的数字会被分到相同的组中。那么对两个组分别进行异或操作，即可得到答案的两个数字。
//分组过程：先对所有数字进行一次异或，得到两个出现一次的数字的异或值。在异或结果中找到任意为 1 的位。根据这一位对所有的数字进行分组。在每个组内进行异或操作，得到两个数字。
class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int res = 0;//0与任何数异或都不变，值仍然是任何数的值
		for (int i : nums)
			res ^= i;
		int div = 1, a = 0, b = 0;
		while ((res&div) == 0)
			div <<= 1;
		for (int i : nums) {
			if (i&div) {//注意分清什么时候用位与&，什么时候用位异或^
				a ^= i;
			}
			else {
				b ^= i;
			}
		}
		return{ a,b };
	}
};

//int main() {
//	vector<int> test = { 1,2,10,4,1,4,3,3 };
//	Solution s;
//	vector<int> res = s.singleNumbers(test);
//	for (int i : res)
//		cout << i << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}