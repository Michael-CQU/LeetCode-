#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void generate(vector<vector<int>>& ans, vector<int> nums, vector<int> temp, int begin) {
		ans.emplace_back(temp);
		for (int i = begin; i < nums.size(); i++) {
			temp.emplace_back(nums[i]);
			generate(ans, nums, temp, i+1);
			temp.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> temp;
		int begin = 0;
		generate(ans, nums, temp, begin);
		return ans;
	}
};

//int main() {
//	vector<int> test = {1,2,3};
//	Solution s;
//	vector<vector<int>> res = s.subsets(test);
//	for (auto i : res) {
//		for (auto j : i)
//			cout << j << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}