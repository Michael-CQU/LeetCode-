//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//
//class Solution {
//public:
//	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//		set<long> st;
//		for (int i = 0; i < nums.size(); i++) {
//			auto lb = st.lower_bound((long)nums[i] - t);//lower_bound获取元素下限
//			if (lb != st.end() && *lb <= (long)nums[i] + t) return 1;
//			st.insert(nums[i]);
//			if (i >= k) st.erase(nums[i - k]);
//		}
//		return 0;
//	}
//};
//
//int main() {
//	
//	system("pause");
//	return 0;
//}