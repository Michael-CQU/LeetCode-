#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int presum(vector<int> nums,int left,int right) {
		int n = nums.size();
		int res = 0;
		vector<int> ans(n+1,0);
		for (int i = 1; i <= n; i++) {
			ans[i] = ans[i - 1] + nums[i-1];
		}
		res = ans[right] - ans[left-1];
		return res;
	}
};

//int main() {
//  ios::sync_with_stdio(false);//提高cin的速度
//	int n = 0, m = 0;
//	cin >> n >> m;
//	vector<int> test(n);
//	for (int i = 0; i < n; i++) {
//		cin >> test[i];
//	}
//	Solution s;
//	while (m--) {
//		int left = 0, right = 0;
//		cin >> left >> right;
//		int res = s.presum(test, left, right);
//		cout << res << endl;
//	}
//	system("pause");
//	return 0;
//}