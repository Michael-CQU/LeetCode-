#include <bits/stdc++.h>
using namespace std;
//·ÇµÝ¹é
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)return -1;
		int left = 0, right = nums.size();
		while (left<right) {
			int mid = (right - left) / 2 + left;
			if (nums[mid]<target)
				left = mid + 1;
			else
				right = mid;
		}
		if (nums[left] == target)
			return left;
		else
			return -1;
	}
};
//µÝ¹é
//class Solution {
//public:
//	int diguisearch(vector<int>& nums, int left, int right, int target) {
//		if (left==right&&nums[left] == target)
//			return left;
//		if (left >= right)return -1;
//		int mid = (right - left) / 2 + left;
//		if (nums[mid]<target)
//			return diguisearch(nums, mid + 1, right, target);
//		else
//			return diguisearch(nums, left, mid, target);
//	}
//	int search(vector<int>& nums, int target) {
//		if (nums.size() == 0)return -1;
//		return diguisearch(nums, 0, nums.size() - 1, target);
//	}
//};