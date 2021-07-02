#include <bits/stdc++.h>
using namespace std;
//用哈希集进行查找的时间复杂度为n，不推荐
//class Solution {
//public:
//	int missingNumber(vector<int>& nums) {
//		unordered_set<int> st;
//		for (int i : nums) {
//			st.insert(i);
//		}
//		for (int i = 0; i <= nums.size(); i++) {
//			if (st.find(i) == st.end())
//				return i;
//		}
//		return -1;
//	}
//};
//用二分法实现时间复杂度为log（n）的查找
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int pivot = (right - left) / 2 + left;
			if (nums[pivot] == pivot)
				left = pivot + 1;
			else
				right = pivot;
		}
		if (left == nums[nums.size() - 1])//特判一下，当数组最后一个值和对应的下标相等时候，说明缺少的就是nums.size()的那个值
			return left + 1;
		return left;
	}
};

//int main() {
//	vector<int> test = {0,1,2,3,4,5,6,7,8};
//	Solution s;
//	int res = s.missingNumber(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}