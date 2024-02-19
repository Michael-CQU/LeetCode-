#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		int l = 0, r = nums.size() - 1;
		while (left < right) {
			int mid = (right - left) / 2 + left;
			if (nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		if (nums[left] != target)
			return{ -1,-1 };
		else {
			while (l < r) {
				int mid = (r - l + 1) / 2 + l;
				if (nums[mid] <= target)
					l = mid;
				else
					r = mid - 1;
			}
		}
		return{ left,l };
	}
};

//int main() {
//	int n = 0, m = 0;
//	cin >> n >> m;
//	vector<int> q(n);
//	for (int i = 0; i < n; i++) {
//		cin >> q[i];
//	}
//	Solution s;
//	while (m--) {
//		int x;
//		cin >> x;
//		vector<int> ans = s.searchRange(q, x);
//		for (int i : ans)
//			cout << i << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}