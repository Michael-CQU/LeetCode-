//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums) {
//		int n = nums.size();
//		for (int i = 0; i < n; i++) {
//			//注意while循环里，对某个值在不在其固定位置必须用nums[i] != nums[nums[i] - 1]，不可以用nums[i]!=i+1,因为如果存在{1,1}的情况就会导致死循环。
//			while (nums[i] > 0 && nums[i] <= n&&nums[i] != nums[nums[i] - 1]) {
//				swap(nums[i], nums[nums[i] - 1]);
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			if (nums[i] != i + 1)
//				return i + 1;
//		}
//		return n + 1;
//	}
//};