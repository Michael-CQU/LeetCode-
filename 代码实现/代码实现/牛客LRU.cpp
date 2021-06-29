#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Solution {
	unordered_map<int, pair<int, int>> mp;
	list<pair<int, int>> cap;
	int size = 0;
public:
	/**
	* lru design
	* @param operators int整型vector<vector<>> the ops
	* @param k int整型 the k
	* @return int整型vector
	*/
	void put(int key, int value) {
		if (mp.find(key) != mp.end()) {
			cap.remove(mp[key]);
			mp.erase(key);
			put(key, value);
			mp.insert(make_pair(key, make_pair(key, value)));
		}
		else {
			mp.insert(make_pair(key, make_pair(key, value)));
			cap.emplace_front(key, value);
		}
		if (cap.size()>size) {
			mp.erase(cap.back().first);
			cap.pop_back();
		}
	}
	int get(int key) {
		if (mp.find(key) != mp.end()) {

			int cal = mp[key].second;
			cap.remove(mp[key]);
			mp.erase(key);
			put(key, cal);
			return cal;
		}
		return -1;
	}
	vector<int> LRU(vector<vector<int> >& operators, int k) {
		// write code here
		size = k;
		vector<int> ans;
		for (auto i : operators) {
			if (i[0] == 1)
				put(i[1], i[2]);
			else {
				ans.push_back(get(i[1]));
			}
		}
		return ans;
	}
};

//int main() {
//	vector<vector<int>> test = { {1,1,1},{1,2,2},{1,3,2},{2,1},{1,4,4},{2,2} };
//	int k = 3;
//	Solution s;
//	vector<int> ans = s.LRU(test, k);
//	system("pause");
//	return 0;
//}