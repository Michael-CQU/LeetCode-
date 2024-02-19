#include<bits/stdc++.h>
using namespace std;

//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		unordered_set<int> result_set; // 存放结果
//		unordered_set<int> nums_set(nums1.begin(), nums1.end());
//		for (int num : nums2) {
//			// 发现nums2的元素 在nums_set里又出现过
//			if (nums_set.find(num) != nums_set.end()) {
//				result_set.insert(num);
//			}
//		}
//		return vector<int>(result_set.begin(), result_set.end());
//	}
//};
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> st;
		unordered_set<int> ans;//注意答案要去重，所以要用set
		for (int i : nums1) {
			st.insert(i);
		}
		for (int i : nums2) {
			if (st.find(i) != st.end()) {
				ans.insert(i);
			}
		}
		return vector<int>(ans.begin(),ans.end());
	}
};
//int main() {
//	vector<int> test1 = { 1,1,2,2 };
//	vector<int> test2 = { 1,2 };
//	Solution s;
//	vector<int> ans = s.intersection(test1, test2);
//	system("pause");
//	return 0;
//}