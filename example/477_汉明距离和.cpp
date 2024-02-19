#include<bits/stdc++.h>
using namespace std;
//若长度为n的数组nums的所有元素二进制的第i位共有c个1,n−c个0,则些元素在二进制的第i位上的汉明距离之和为c*(n−c)。一个数在此位的汉明距离为（n-c），则c个数汉明和为c*(n-c)。
class Solution {
public:
	int totalHammingDistance(vector<int> &nums) {
		int ans = 0, n = nums.size();
		for (int i = 0; i < 30; ++i) {//因为10的9次方小于2的30次方
			int c = 0;
			for (int val : nums) {
				c += (val >> i) & 1;
			}
			ans += c * (n - c);
		}
		return ans;
	}
};

//int main() {
//	vector<int> test = {4,14,2};
//	Solution s;
//	int res = s.totalHammingDistance(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}