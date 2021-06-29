#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
	class cmp {
	public:
		bool operator()(pair<int, int> m, pair<int, int> n) {
			return m.second < n.second;
		}
	};
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		for (int i : nums) {
			mp[i]++;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
		vector<int> ans;
		for (auto i : mp) {
			q.emplace(i);
		}
		int res = 0;
		while (k) {
			k--;
			res = q.top().first;
			q.pop();
			ans.emplace_back(res);
		}
		return ans;
	}
};

//int main() {
//	vector<int> test = { 1,1,1,2,2,3 };
//	Solution s;
//	s.topKFrequent(test,2);
//	return 0;
//}