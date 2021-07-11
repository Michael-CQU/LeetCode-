#include<bits/stdc++.h>
using namespace std;
//动态规划+二分法
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> res;
		res.push_back(nums[0]);
		for (int i : nums) {
			if (i > res.back())
				res.push_back(i);
			else{
				int left = 0, right = res.size() - 1;
			while (left < right) {
				int mid = (right - left) / 2 + left;
				if (res[mid] < i)
					left = mid + 1;
				else
					right = mid;
			}
			res[left] = i;
		}
		}
		return res.size();
	}
};