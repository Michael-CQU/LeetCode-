#include<bits/stdc++.h>
using namespace std;
//本题和力扣153（数组中无重复数字）/154（数组中有重复数字）题类似

//153数组中没有重复数字
//class Solution {
//public:
//	int minArray(vector<int>& numbers) {
//		int left = 0, right = numbers.size() - 1;
//		while (left < right) {
//			int pivot = (right - left) / 2 + left;
//			//注意如果pivot和left比较的话，就是找的最大值；pivot和right比较的话，就是找的最小值（画图看一下，因为最大值和left在同一支线段上，最小值和right在同一支线段上，而二分查找就是在同一线段上进行的查找）
//			if (numbers[pivot] > numbers[right]) {
//				left = pivot + 1;
//			}
//			else {
//				right = pivot;
//			}
//		}
//		return numbers[left];
//	}
//};
//154数组中有重复数字
class Solution {
public:
	int minArray(vector<int>& numbers) {
		int left = 0, right = numbers.size() - 1;
		while (left < right) {
			int pivot = (right - left) / 2 + left;
			if (numbers[pivot] < numbers[right])
				right = pivot;
			else if (numbers[pivot] > numbers[right])
				left = pivot + 1;
			else
				right--;
			/*
			有重复数组的话，难以判断分界点 pivot 指针区间，例如 [1,0,1,1,1] 和 [1,1,1,0,1] ，在 left = 0, right = 4, mid = 2 时，无法判断 mid 在哪个排序数组中。
			注意这里为数组中有重复值需要注意的地方：此操作不会使数组越界：
			1.因为迭代条件保证了 right > left >= 0；
			2.此操作不会使最小值丢失：假设 nums[right]nums[right] 是最小值，有两种情况：
				若 nums[right]nums[right] 是唯一最小值：那就不可能满足判断条件 nums[mid] == nums[right]，因为 mid < right（left != right 且 mid = (left + right) // 2 向下取整）；
				若 nums[right]nums[right] 不是唯一最小值，由于 mid < right 而 nums[mid] == nums[right]，即还有最小值存在于[left, right - 1][left, right−1] 区间，因此不会丢失最小值。
			*/
		}
		return numbers[left];
	}
};
//int main() {
//	vector<int> test = {7,0,0,1,1,1,1,2,3,4};
//	Solution s;
//	int res = s.minArray(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}