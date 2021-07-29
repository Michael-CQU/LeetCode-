#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

//class Solution {
//	class cmp {
//	public:
//		bool operator()(pair<int, int> m, pair<int, int> n) {
//			return m.second < n.second;
//		}
//	};
//public:
//	vector<int> topKFrequent(vector<int>& nums, int k) {
//		unordered_map<int, int> mp;
//		for (int i : nums) {
//			mp[i]++;
//		}
//		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
//		vector<int> ans;
//		for (auto i : mp) {
//			q.emplace(i);
//		}
//		int res = 0;
//		while (k) {
//			k--;
//			res = q.top().first;
//			q.pop();
//			ans.emplace_back(res);
//		}
//		return ans;
//	}
//};
//class Solution {
//public:
//	class cmp {
//	public:
//		bool operator()(pair<int, int> m, pair<int, int> n) {
//			return m.second > n.second;//注意对于堆来说，less是大顶堆，greater是小顶堆
//		}
//	};
//	vector<int> topKFrequent(vector<int>& nums, int k) {
//		unordered_map<int, int> mp;
//		vector<int> ans;
//		for (int i : nums)
//			mp[i]++;
//		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
//		for (auto i:mp) {
//			if (q.size() == k) {
//				if (i.second > q.top().second) {
//					q.pop();
//					q.push(i);
//				}
//			}
//			else {
//				q.push(i);
//			}
//		}
//		while (!q.empty()) {
//			ans.push_back(q.top().first);
//			q.pop();
//		}
//		return ans;
//	}
//};
class Solution {
public:
	class cmp {
	public:
		bool operator()(pair<int, int> m, pair<int, int> n) {
			return m.second > n.second;//注意对于堆来说，less是大顶堆，greater是小顶堆
		}
	};
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		vector<int> ans;
		for (int i : nums)
			mp[i]++;
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
		for (auto i:mp) {
			q.push(i);
			if (q.size() > k) {
					q.pop();
			}	
		}
		while (!q.empty()) {
			ans.push_back(q.top().first);
			q.pop();
		}
		return ans;
	}
};
int main() {
	vector<int> test = { 1,1,1,2,2,3 };
	Solution s;
	vector<int> ans = s.topKFrequent(test, 2);
	for (int i : ans)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}