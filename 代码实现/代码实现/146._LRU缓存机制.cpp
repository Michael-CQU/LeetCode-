#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
/*˼·����ϣ��+����
get�����õ������ڹ�ϣ���в��ҹؼ���key������ؼ��ִ��ڣ�����splice������ֵ�������е�λ�ý����ƶ����ƶ�������ͷ�������ù�ϣ���ҵ�������key��Ӧ��value���з��ء�����ؼ��ֲ����ڣ��ͷ���-1
put��ͬgetһ�������õ������ڹ�ϣ�������Ƿ���ڹؼ���key��������ڣ��ͽ���ֵ�ŵ�����ͷ������put��value��ֵ�����list���൱�ڸ��ǣ�����������ڹؼ���key���ͽ�����²����list����������ͷ������list.begin���뵽��ϣ���У����жϹ�ϣ��������Ƿ�����˹涨��������������ڣ����ϣ����ɾ���������������һ�������pop���һ��
*/

//����һ��
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
//		_table[key] = _lru.begin();//�˲��뷽ʽ��������
//
//		if (_table.size() > _capacity) {
//			_table.erase(_lru.back().first);
//			_lru.pop_back();
//		}
//	}
//};

//��������(�ֶ�ʵ��˫������)
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
//		// ʹ��αͷ����αβ���ڵ�
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
//		// ��� key ���ڣ���ͨ����ϣ��λ�����Ƶ�ͷ��
//		DLinkedNode* node = cache[key];
//		moveToHead(node);
//		return node->value;
//	}
//
//	void put(int key, int value) {
//		if (!cache.count(key)) {
//			// ��� key �����ڣ�����һ���µĽڵ�
//			DLinkedNode* node = new DLinkedNode(key, value);
//			// ��ӽ���ϣ��
//			cache[key] = node;
//			// �����˫�������ͷ��
//			addToHead(node);
//			++size;
//			if (size > capacity) {
//				// �������������ɾ��˫�������β���ڵ�
//				DLinkedNode* removed = removeTail();
//				// ɾ����ϣ���ж�Ӧ����
//				cache.erase(removed->key);
//				// ��ֹ�ڴ�й©
//				delete removed;
//				--size;
//			}
//		}
//		else {
//			// ��� key ���ڣ���ͨ����ϣ��λ�����޸� value�����Ƶ�ͷ��
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



////��������������ķ�ʽ����ѡ��
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
//			put(key, value);//ע�������˳�����Ҫ��һ��Ҫ�Ȱ�cap.remove(mp[key])��mp.erase(key)ִ������ִ��put������ɾ����һ��ԭ�Ӳ���
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


//�������Լ�ʵ������ṹ����Ҫ�������������գ�
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