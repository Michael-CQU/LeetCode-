#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
/*思路：哈希表+链表
get：利用迭代器在哈希表中查找关键字key，如果关键字存在，就用splice将这组值在链表中的位置进行移动，移动到链表头，并利用哈希表找到链表中key对应的value进行返回。如果关键字不存在，就返回-1
put：同get一样首先用迭代器在哈希表中找是否存在关键字key，如果存在，就将该值放到链表头，并将put的value赋值给这个list（相当于覆盖）。如果不存在关键字key，就将这个新插入的list放置在链表头，并将list.begin插入到哈希表中，并判断哈希表的容量是否大于了规定的容量，如果大于，则哈希表中删除保存的链表的最后一项，链表中pop最后一项
*/

//方法一：
//class LRUCache {
//private:
//	unordered_map<int, list<pair<int, int>>::iterator> _table;
//	list<pair<int, int>> _lru;
//	int _capacity;
//public:
//	LRUCache(int capacity) :_capacity(capacity) {
//
//	}
//
//	int get(int key) {
//		auto it = _table.find(key);
//		if (it != _table.end()) {
//			_lru.splice(_lru.begin(), _lru, it->second);
//			return it->second->second;
//		}
//		return -1;
//	}
//
//	void put(int key, int value) {
//		auto it = _table.find(key);
//		if (it != _table.end()) {
//			_lru.splice(_lru.begin(), _lru, it->second);
//			it->second->second = value;
//			return;
//		}
//		_lru.emplace_front(key, value);
//		_table[key] = _lru.begin();//此插入方式不建议用
//
//		if (_table.size() > _capacity) {
//			_table.erase(_lru.back().first);
//			_lru.pop_back();
//		}
//	}
//};

//方法二：(手动实现双向链表)
//struct DLinkedNode {
//	int key, value;
//	DLinkedNode* prev;
//	DLinkedNode* next;
//	DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
//	DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
//};
//
//class LRUCache {
//private:
//	unordered_map<int, DLinkedNode*> cache;
//	DLinkedNode* head;
//	DLinkedNode* tail;
//	int size;
//	int capacity;
//
//public:
//	LRUCache(int _capacity) : capacity(_capacity), size(0) {
//		// 使用伪头部和伪尾部节点
//		head = new DLinkedNode();
//		tail = new DLinkedNode();
//		head->next = tail;
//		tail->prev = head;
//	}
//
//	int get(int key) {
//		if (!cache.count(key)) {
//			return -1;
//		}
//		// 如果 key 存在，先通过哈希表定位，再移到头部
//		DLinkedNode* node = cache[key];
//		moveToHead(node);
//		return node->value;
//	}
//
//	void put(int key, int value) {
//		if (!cache.count(key)) {
//			// 如果 key 不存在，创建一个新的节点
//			DLinkedNode* node = new DLinkedNode(key, value);
//			// 添加进哈希表
//			cache[key] = node;
//			// 添加至双向链表的头部
//			addToHead(node);
//			++size;
//			if (size > capacity) {
//				// 如果超出容量，删除双向链表的尾部节点
//				DLinkedNode* removed = removeTail();
//				// 删除哈希表中对应的项
//				cache.erase(removed->key);
//				// 防止内存泄漏
//				delete removed;
//				--size;
//			}
//		}
//		else {
//			// 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
//			DLinkedNode* node = cache[key];
//			node->value = value;
//			moveToHead(node);
//		}
//	}
//
//	void addToHead(DLinkedNode* node) {
//		node->prev = head;
//		node->next = head->next;
//		head->next->prev = node;
//		head->next = node;
//	}
//
//	void removeNode(DLinkedNode* node) {
//		node->prev->next = node->next;
//		node->next->prev = node->prev;
//	}
//
//	void moveToHead(DLinkedNode* node) {
//		removeNode(node);
//		addToHead(node);
//	}
//
//	DLinkedNode* removeTail() {
//		DLinkedNode* node = tail->prev;
//		removeNode(node);
//		return node;
//	}
//};



////方法三：最好理解的方式（首选）
//class LRUCache {
//	unordered_map<int, pair<int, int>> mp;
//	list<pair<int, int>> cap;
//	int size;
//public:
//	LRUCache(int capacity) {
//		size = capacity;
//	}
//
//	int get(int key) {
//		if (mp.find(key) != mp.end()) {
//			int val = mp[key].second;
//			cap.remove(mp[key]);
//			put(key, val);
//			return val;
//		}
//		return -1;
//	}
//
//	void put(int key, int value) {
//		if (mp.find(key) != mp.end()) {
//			cap.remove(mp[key]);
//			mp.erase(key);
//			put(key, value);//注意这里的顺序很重要，一定要先把cap.remove(mp[key])和mp.erase(key)执行完再执行put操作，删除是一个原子操作
//			mp.insert(make_pair(key, make_pair(key, value)));
//		}
//		else {
//			cap.emplace_front(key, value);
//			mp.insert(make_pair(key, make_pair(key, value)));
//		}
//		if (cap.size() > size) {
//			mp.erase(cap.back().first);
//			cap.pop_back();
//		}
//	}
//};


//方法：自己实现链表结构（重要，必须熟练掌握）
struct LinkedNode {
	int key, val;
	LinkedNode* prev;
	LinkedNode* next;
	LinkedNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
	LinkedNode(int key, int value) :key(key), val(value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
	unordered_map<int, LinkedNode*> mp;
	LinkedNode* head;
	LinkedNode* tail;
	int number = 0;
	int size = 0;
public:
	LRUCache(int capacity) {
		size = capacity;
		head = new LinkedNode();
		tail = new LinkedNode();
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		if (mp.find(key) != mp.end()) {
			LinkedNode* node = mp[key];
			remove(node);
			addhead(node);
			return node->val;
		}
		return -1;
	}

	void put(int key, int value) {
		if (mp.find(key) != mp.end()) {
			LinkedNode* node = mp[key];
			node->val = value;
			remove(node);
			addhead(node);
		}
		else {
			LinkedNode* node = new LinkedNode(key, value);
			addhead(node);
			mp.insert(make_pair(key, node));
			number++;
		}
		if (number > size) {
			LinkedNode* node = tail->prev;
			remove(node);
			number--;
			mp.erase(node->key);
			delete node;
		}
	}
	void remove(LinkedNode* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void addhead(LinkedNode* node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/
//int main() {
//	int capacity = 2;
//	LRUCache* obj = new LRUCache(capacity);
//
//	obj->put(2, 1);
//	obj->put(2, 2);
//	int param_1 = obj->get(2);
//	cout << "param_1:" << param_1 << endl;
//	obj->put(1, 1);
//	//int param_2 = obj->get(2);
//	//cout << "param_2:" << param_2 << endl;
//	obj->put(4, 1);
//	int param_3 = obj->get(2);
//	cout << "param_3:" << param_3 << endl;
//	//int param_4 = obj->get(3);
//	//cout << "param_4:" << param_4 << endl;
//	//int param_5 = obj->get(4);
//	//cout << "param_5:" << param_5 << endl;
//	system("pause");
//	return 0;
//}