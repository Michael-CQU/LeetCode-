#include <bits/stdc++.h>
using namespace std;
/*
异或：
如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为0。
1. 归零律：a^a = 0
2. 恒等律：a^0 = a
3. 交换律：a^b = b^a
4. 结合律：a^b^c = a^c^b
5. 自反：a^b^a = b
*/
//方法一：遍历统计（先统计各进制位上1的个数，然后将各进制位对m取余并恢复到res上）关键两步
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int counts[32] = { 0 };
		for (int num : nums) {
			for (int i = 0; i < 32; i++) {
				counts[i] += num & 1;//记录所有数字各二进制位的1出现次数
				num >>= 1;
			}
		}
		int res = 0, m = 3;//关键：只需要修改求余数值m，即可实现解决 除了一个数字以外，其余数字都出现m次的通用问题
		for (int i = 31; i >= 0; i--) {
			res <<= 1;
			res |= counts[i] % m;//如果后左移(res<<=1放在这句话的下边的话)，最后一轮的 最后一个操作变成了左移，那么最右一位 永远是 0 了，这样就不对了（这句话可以得到只出现一次的那个数字的各个二进制位的值，并恢复到res上）
		}
		return res;
	}
};
//方法二:有限状态自动机（没有通用性，要熟练方法一）
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int ones = 0, twos = 0;//因为有三个相同的数，因此对3余数为0,1,2，因此用两位二进制来表示状态
//		for (int num : nums) {
//			ones = ones ^ num & ~twos;//推算进制位的状态
//			twos = twos ^ num & ~ones;
//		}
//		return ones;//因为最后取余的结果只会为0或者1，因此只返回ones位的值即可
//	}
//};
//int main() {
//	vector<int> test = { 1,3,3,3,4,4,4 };
//	Solution s;
//	int res = s.singleNumber(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}