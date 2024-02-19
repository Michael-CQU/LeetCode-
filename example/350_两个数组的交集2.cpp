#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> mp;//需要统计个数的话，就要用map
		vector<int> ans;
		for (int i : nums1) {
			mp[i]++;
		}
		for (int i : nums2) {
			if (mp.find(i) != mp.end()) {
				mp[i]--;
				if (mp[i] == 0) {
					mp.erase(i);
				}
				ans.push_back(i);
			}
		}
		return ans;
	}
};