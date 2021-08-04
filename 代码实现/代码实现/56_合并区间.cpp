#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int left = -2e9, right = -2e9;
		int m = intervals.size();
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		for (int i = 0; i < m; i++) {
			if (right < intervals[i][0]) {
				if (left != -2e9)
					ans.push_back({ left,right });
				left = intervals[i][0];
				right = intervals[i][1];
			}
			else {
				right = max(right, intervals[i][1]);
			}
		}
		if (left != -2e-9)ans.push_back({ left,right });
		return ans;
	}
};

//int main() {
//	vector<vector<int>> test = { {1,3} ,{2,6} ,{8,10} ,{15,18}};
//	Solution s;
//	vector<vector<int>> res = s.merge(test);
//	system("pause");
//	return 0;
//}