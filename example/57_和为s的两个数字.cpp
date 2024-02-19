#include<bits/stdc++.h>
using namespace std;
//双指针法
/*
初始化： 双指针 i , j 分别指向数组 nums 的左右两端 （俗称对撞双指针）。
循环搜索： 当双指针相遇时跳出；
计算和 s = nums[i]+nums[j] ；
若 s > target，则指针 j 向左移动，即执行j=j−1 ；
若 s < target，则指针 i 向右移动，即执行i=i+1 ；
若 s = target，立即返回数组[nums[i],nums[j]] ；
若循环结束，则返回空数组，代表无和为target 的数字组合。
注意链接里的图，根据图来想i，j左右移动不会漏掉答案（此题的前提是有序数组）
https://leetcode-cn.com/leetbook/read/illustration-of-algorithm/58qpje/
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int sum = nums[left] + nums[right];
			if (sum > target)
				right--;
			else if (sum < target)
				left++;
			else
				return{ nums[left],nums[right] };
		}
		return{ -1,-1 };
	}
};

//int main() {
//	vector<int> test = { 2,7,11,15 };
//	int target = 9;
//	Solution s;
//	vector<int> res = s.twoSum(test,target);
//	for (int i : res)
//		cout << i << endl;
//	system("pause");
//	return 0;
//}