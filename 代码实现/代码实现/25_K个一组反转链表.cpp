#include<iostream>
#include <tuple>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

//class Solution {
//public:
//	pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail,int k) {
//		ListNode* prev = nullptr;
//		ListNode* node = head;
//		while (k) {
//			ListNode* last = node->next;
//			node->next = prev;
//			prev = node;
//			node = last;
//			k--;
//		}
//		return{ tail,head };
//	}
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		ListNode* dumy = new ListNode(-1);
//		dumy->next = head;
//		ListNode* pre = dumy;
//		while (1) {
//			ListNode* tail = pre;
//			for (int i = 0; i < k; i++) {
//				tail = tail->next;
//				if (tail == nullptr) {
//					return dumy->next;
//				}
//			}
//			ListNode* next = tail->next;
//			tie(head, tail) = myReverse(head, tail,k);
//			pre->next = head;
//			tail->next = next;
//			pre = tail;
//			head = tail->next;
//		}
//		return dumy->next;
//	}
//};
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