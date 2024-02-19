#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
	vector<vector<int>> ans;
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0)break;
			if (i > 0 && nums[i] == nums[i - 1]) {//去重
				continue;
			}
			int L = i + 1;
			int R = nums.size() - 1;
			while (L < R) {
				if (nums[i] + nums[L] + nums[R] == 0) {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[L]);
					temp.push_back(nums[R]);
					ans.push_back(temp);
					while (L<R&&nums[L] == nums[L + 1]) {//去重
						L++;
					}
					while (L<R&&nums[R] == nums[R - 1]) {//去重
						R--;
					}
					L++;
					R--;
				}
				else if (nums[i] + nums[L] + nums[R] > 0) {
					R--;
				}
				else if (nums[i] + nums[L] + nums[R] < 0) {
					L++;
				}
			}
		}
		return ans;
	}
};
/*
首先对数组进行排序，排序后固定一个数 nums[i]，再使用左右指针指向 nums[i]后面的两端，数字分别为 nums[L] 和 nums[R]，计算三个数的和 sum 判断是否满足为 0，满足则添加进结果集
如果 nums[i]大于 0，则三数之和必然无法等于 0，结束循环
如果 nums[i] == nums[i−1]，则说明该数字重复，会导致结果重复，所以应该跳过(去重1)
当 sum == 0 时，nums[L] == nums[L+1] 则会导致结果重复，应该跳过，L++（去重2）
当 sum == 0 时，nums[R] == nums[R−1] 则会导致结果重复，应该跳过，R−−（去重3）
*/
//int main() {
//	vector<int> nums = { 0,0,0 };
//	Solution s;
//	vector<vector<int>> ans = s.threeSum(nums);
//	system("pause");
//	return 0;
//}