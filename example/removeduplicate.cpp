//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		int i = 1, j = 1, n = nums.size();
//		if (n == 0)
//			return 0;
//		for (i; i < n; i++) {
//			if (nums[i] != nums[i - 1]) {
//				nums[j] = nums[i];
//				j++;
//			}
//		}
//		return j;
//		//return nums.size();
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> nums= {0,0,1,1,1,2,2,3,3,4};
//	int len = s.removeDuplicates(nums);
//	//cout << len << endl;
//	for (auto it = nums.begin(); it != nums.end(); it++)
//		cout << *it << endl;
//	system("pause");
//	return 0;
//}