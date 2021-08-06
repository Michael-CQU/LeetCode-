#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
	vector<list<int>> data;
	static const int base = 769;
	inline int hash(int key) {
		return key%base;
	}
public:
	/** Initialize your data structure here. */
	MyHashSet() :data(base) {//用初始化列表初始化data数组的大小

	}

	void add(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key)
				return;
		}
		data[h].push_back(key);
	}

	void remove(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key) {
				data[h].erase(it);
				return;
			}
		}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key)
				return true;
		}
		return false;
	}
};

/**
* Your MyHashSet object will be instantiated and called as such:
* MyHashSet* obj = new MyHashSet();
* obj->add(key);
* obj->remove(key);
* bool param_3 = obj->contains(key);
*/