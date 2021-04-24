#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int j = 0, n = nums.size();
		for (int i = 0; i < n; i++) {
			j = (nums[i]-1) % n;
			cout << j << " ";
			nums[i] = j+n;
			cout << nums[i] << " ";
			cout << endl;
		}
		vector<int> result(n);
		int m = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] <= n) {
				cout << i <<" ";
				result[m++] = nums[i];
				cout << result[m] << endl;
			}
		}
		return result;
	}
};
int main() {
	Solution s;
	vector<int> nums = {4,3,2,7,8,2,3,1};
	vector<int> num = s.findDisappearedNumbers(nums);
	system("pause");
	return 0;
}