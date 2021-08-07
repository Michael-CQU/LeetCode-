#include<iostream>
#include <tuple>
using namespace std;
//学习时的方法
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};
class Solution {
public:
	ListNode* myreverse(ListNode* head) {

		ListNode* prenode = nullptr;
		ListNode* node = head;
		while (node) {
			ListNode* nextnode = node->next;
			node->next = prenode;
			prenode = node;
			node = nextnode;
		}
		return prenode;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* end = dummy;
		while (end->next) {
			for (int i = 0; i < k&&end != nullptr; i++) {
				end = end->next;
			}
			if (end == nullptr) {
				break;
			}
			ListNode* start = pre->next;
			ListNode* next = end->next;
			end->next = nullptr;
			pre->next = myreverse(start);
			start->next = next;
			pre = start;
			end = start;
		}
		return dummy->next;
	}
};
//int main() {
//	ListNode* A = new ListNode(5);
//	ListNode* B = new ListNode(4,A);
//	ListNode* C = new ListNode(3,B);
//	ListNode* D = new ListNode(2,C);
//	ListNode* E = new ListNode(1,D);
//	Solution s;
//	ListNode* res = s.reverseKGroup(E,3);
//	while (res) {
//		cout << res->val << endl;
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}

//自我实现！掌握
//struct Listnode {
//	int val;
//	Listnode* next;
//	Listnode() :val(-1), next(nullptr) {}
//	Listnode(int x) :val(x), next(nullptr) {}
//};
//
//class Solution {
//public:
//	Listnode* myreverse(Listnode* head) {
//		Listnode* pre = nullptr;
//		Listnode* node = head;
//		while (node) {
//			Listnode* ne = node->next;
//			node->next = pre;
//			pre = node;
//			node = ne;
//		}
//		return pre;
//	}
//	Listnode* reverseK(Listnode* head, int k) {
//		Listnode* dumy = new Listnode();
//		dumy->next = head;
//		Listnode* start = dumy;
//		Listnode* end = dumy;
//		while (end->next) {
//			for (int i = 0; i < k&&end != nullptr; i++) {
//				end = end->next;
//			}
//			if (end == nullptr)
//				break;
//			Listnode* ne = end->next;
//			end->next = nullptr;
//			Listnode* pre = start->next;
//			start->next = myreverse(pre);
//			pre->next = ne;
//			start = pre;
//			end = pre;
//		}
//		return dumy->next;
//	}
//};
//
//int main() {
//	int m, k;
//	cin >> m >> k;
//	int n = m;
//	Listnode* dumy = new Listnode();
//	Listnode* node = dumy;
//	while (m--) {
//		int temp;
//		cin >> temp;
//		node->next = new Listnode(temp);
//		node = node->next;
//	}
//	Solution s;
//	Listnode* res = s.reverseK(dumy->next, k);
//	for (int i = 0; i < n; i++) {
//		cout << res->val << " ";
//		res = res->next;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
