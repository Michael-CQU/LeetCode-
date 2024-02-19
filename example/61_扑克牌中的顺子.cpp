#include<bits/stdc++.h>
using namespace std;
//成立的条件：1.数组中没有重复的值。2.最大值与最小值得差不超过5
//方法一：用set来判断是否重复
//class Solution {
//public:
//	bool isStraight(vector<int>& nums) {
//		unordered_set<int> st;
//		int mymax = 0, mymin = 14;
//		for (auto i : nums) {
//			if (i == 0)continue;
//			mymax = max(mymax, i);
//			mymin = min(mymin, i);
//			if (st.find(i) != st.end())
//				return false;
//			st.insert(i);
//		}
//		return mymax - mymin <= 5;
//	}
//};
//方法二：通过排序来找到最大最小值
class Solution {
public:
	bool isStraight(vector<int>& nums) {
		int index = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] == 0) {
				index++;
				continue;
			}
			if (nums[i + 1] == nums[i])
				return false;
		}
		return nums[nums.size() - 1] - nums[index] < 5;
	}
};
//int main() {
//	vector<int> test = {0,0,1,4,5};
//	Solution s;
//	bool res = s.isStraight(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}