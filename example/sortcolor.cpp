//#include <iostream>
//#include <vector>
//using namespace std;
//
////µ•÷∏’Î
////class Solution {
////public:
////	void sortColors(vector<int>& nums) {
////		int n = nums.size(),ptr = 0;
////		for (int i = 0; i < n; i++)
////		{
////			if (nums[i] == 0)
////				swap(nums[ptr++], nums[i]);
////		}
////		for (int i = ptr; i < n; i++)
////		{
////			if (nums[i] == 1)
////				swap(nums[ptr++], nums[i]);
////		}
////	}
////};
//
////À´÷∏’Î
//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		int n = nums.size();
//		int p0 = 0, p1 = 0;
//		for (int i = 0; i < n; ++i) {
//			if (nums[i] == 1) {
//				swap(nums[i], nums[p1]);
//				++p1;
//			}
//			else if (nums[i] == 0) {
//				swap(nums[i], nums[p0]);
//				if (p0 < p1) {
//					swap(nums[i], nums[p1]);
//				}
//				++p0;
//				++p1;
//			}
//		}
//	}
//};
//
//int main() {
//	vector<int> nums = { 0,1,0,1,2,0,1,1,0 };
//	Solution s;
//	s.sortColors(nums);
//	for (int b : nums)
//		cout << b;
//	cout << endl;
//	system("pause");
//	return 0;
//
//}
