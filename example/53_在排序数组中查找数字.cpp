#include <bits/stdc++.h>
using namespace std;
//方法一：时间复杂度不太好，因为只用了一次二分查找
//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		int count = 0;
//		if (nums.size() == 0)return count;
//		int left = 0, right = nums.size() - 1;
//		while (left < right) {
//			int pivot = (right - left) / 2 + left;
//			if (nums[pivot] > target)
//				right = pivot;
//			else if (nums[pivot] < target)
//				left = pivot + 1;
//			else {
//				right--;
//			}
//		}
//		while (left<nums.size()&&nums[left] == target) {
//			count++;
//			left++;
//		}
//		return count;
//	}
//};
//方法二：两次二分查找
class Solution {
public:
	int mysearchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int pivot = (right - left) / 2 + left;
			if (nums[pivot] < target) {
				left = pivot + 1;
			}
			else if (nums[pivot] > target) {
				right = pivot;
			}
			else {
				right--;
			}
		}
		return left;
	}
	vector<int> searchRange(vector<int>& nums, int target) {

		int leftIndex = mysearchRange(nums, target);
		int rightIndex = mysearchRange(nums, target + 1);
		if (nums.size() == 0) return{ -1,-1 };//特判条件1：当数组为空时，返回{-1，-1}
		if (nums[nums.size() - 1] < target + 1)//特判条件2：当要找的右边界比数组最后一个值大时（数组最后一个值是target），rightIndex返回的也是target的下标，因此需要对rightIndex++从而让下标到达target的后一位
			rightIndex++;
		if (nums[leftIndex] == target)//特判条件3：二分法返回的是目标值应该在数组中的位置，当target在数组中不存在时，返回的是比target大的第一个值的下标值（如果到达右边界则返回数组最后一个下标nums.size（）-1，到达左边界则返回数组第一个下标0），因此需要对这个下标进行判断看看是不是要找的值
			return{ leftIndex,rightIndex - 1 };
		return{ -1,-1 };
	}
};
//int main() {
//	vector<int> test = {3,7,7,8,8,10};
//	int target = 6;
//	Solution s;
//	vector<int> res = s.searchRange(test,target);
//	for(int i:res)
//	cout << i<< endl;
//	system("pause");
//	return 0;
//}