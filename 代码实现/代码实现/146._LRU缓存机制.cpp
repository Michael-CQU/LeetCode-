#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
	unordered_map<int, list<pair<int, int>>::iterator> _table;
	list<pair<int, int>> _lru;
	int _capacity;
public:
	LRUCache(int capacity) :_capacity(capacity) {

	}

	int get(int key) {
		auto it = _table.find(key);
		if (it != _table.end()) {
			_lru.splice(_lru.begin(), _lru, it->second);
			return it->second->second;
		}
		return -1;
	}

	void put(int key, int value) {
		auto it = _table.find(key);
		if (it != _table.end()) {
			_lru.splice(_lru.begin(), _lru, it->second);
			it->second->second = value;
			return;
		}
		_lru.emplace_front(key, value);
		_table[key] = _lru.begin();//此插入方式不建议用

		if (_table.size() > _capacity) {
			_table.erase(_lru.back().first);
			_lru.pop_back();
		}
	}
};

int main() {
	int capacity = 2;
	LRUCache* obj = new LRUCache(capacity);

	obj->put(1, 1);
	obj->put(2, 2);
	int param_1 = obj->get(1);
	cout << "param_1:" << param_1 << endl;
	obj->put(3, 3);
	int param_2 = obj->get(2);
	cout << "param_2:" << param_2 << endl;
	obj->put(4, 4);
	int param_3 = obj->get(1);
	cout << "param_3:" << param_3 << endl;
	int param_4 = obj->get(3);
	cout << "param_4:" << param_4 << endl;
	int param_5 = obj->get(4);
	cout << "param_5:" << param_5 << endl;
	system("pause");
	return 0;
}