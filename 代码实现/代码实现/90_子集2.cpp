#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void generate(vector<vector<int>>& ans, vector<int> nums, vector<int> temp, int begin,vector<int> used) {
		cout << sizeof(nums) << endl;
		ans.push_back(temp);
		for (int i = begin; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]&&!used[i-1])
				continue;

			used[i] = 1;
			temp.push_back(nums[i]);
			generate(ans, nums, temp, i + 1,used);
			temp.pop_back();
			used[i] = 0;
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> temp;
		vector<int> used(nums.size(), 0);
		int begin = 0;
		sort(nums.begin(), nums.end());
		generate(ans, nums, temp, begin,used);
		return ans;
	}
};

//int main() {
//	vector<int> test = { 1,2,2 };
//	Solution s;
//	vector<vector<int>> res = s.subsetsWithDup(test);
//	for (auto i : res) {
//		for (auto j : i)
//			cout << j << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}