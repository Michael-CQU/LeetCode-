#include <iostream>
#include <vector>
using namespace std;

//���ݷ����ѣ����Եó����н�
//class Solution {
//public:
//	vector<vector<int>> ans;
//	vector<int> temp;
//	int sum = 0;
//	void mygenerate(vector<int>& nums,int target) {
//		if (sum > target)
//			return;
//		if (sum == target) {
//			ans.push_back(temp);
//			for(int i:temp)
//				cout << i << " ";
//			cout << endl;
//			return;
//		}
//		for (int i = 0; i < nums.size(); i++) {
//			sum += nums[i];
//			temp.push_back(nums[i]);
//			mygenerate(nums, target);
//			temp.pop_back();
//			sum -= nums[i];
//		}
//	}
//	int combinationSum4(vector<int>& nums, int target) {
//		mygenerate(nums,target);
//		int res = ans.size();
//		return res;
//	}
//};
//�������Ҫ����ж�����⣬���ö�̬�滮��һЩ
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int n = nums.size();
		vector<int> dp(target+1,0);
		dp[0] = 1;
		for (int i = 0; i <= target; i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (i-nums[j]>=0&&dp[i]+dp[i-nums[j]]<INT_MAX)
					dp[i] += dp[i - nums[j]];
			}
		}
		return dp[target];
	}
};

//int main() {
//	int n,target;
//	cin >> n>> target;
//	vector<int> test(n);
//	for (int i = 0; i < n; i++) {
//		cin >> test[i];
//	}
//	Solution s;
//	int res = s.combinationSum4(test, target);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}