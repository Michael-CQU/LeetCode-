#include<bits/stdc++.h>
using namespace std;
//此题简单方法为通过哈希表来查重，但是需要额外的哈希表空间
//另一种方法是数组的原地操作，相当于字典方法（序号和数值对应情况），如下：
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int i = 0;
		while(i<nums.size()) {
			if (nums[i] == i) {
				i++;//注意i的增加要由nums[i] == i来控制
				continue;
			}
			if (nums[i] == nums[nums[i]]) {
				return nums[i];
			}
			swap(nums[i], nums[nums[i]]);
		}
		return -1;
	}
};
//int main() {
//	vector<int> test = {0,3,1,2,5,2,7};
//	Solution s;
//	int res = s.findRepeatNumber(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}