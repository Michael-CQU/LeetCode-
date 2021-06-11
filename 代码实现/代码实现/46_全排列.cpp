#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)return res;
		vector<int> temp;
		vector<int> used(nums.size(), 0);
		int usedNum = 0;
		generate(res, nums, temp, used, 0);
		return res;
	}
	void generate(vector<vector<int>>& res, vector<int>& nums, vector<int>& temp, vector<int>& used, int usedNum) {
		if (usedNum == nums.size()) {
			res.push_back(temp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (used[i] == 0) {
				used[i] = 1;
				temp.push_back(nums[i]);

				cout << "µÝ¹éÇ°£º";
				for (auto i : temp) {
					cout << i << " ";
				}
				cout << endl;

				generate(res, nums, temp, used, usedNum + 1);

				cout << "µÝ¹éÖÐ£º";
				for (auto i : temp) {
					cout << i << " ";
				}
				cout << endl;

				used[i] = 0;
				temp.pop_back();

				cout << "µÝ¹éºó£º";
				for (auto i : temp) {
					cout << i << " ";
				}
				cout << endl;

			}
		}
		return;
	}
};

//int main() {
//	vector<int> nums = {1,2,3};
//	Solution s;
//	vector<vector<int>> ans = s.permute(nums);
//	system("pause");
//	return 0;
//}