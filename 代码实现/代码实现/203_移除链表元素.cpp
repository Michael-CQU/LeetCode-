//#include<iostream>
//using namespace std;
// struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//	ListNode* removeElements(ListNode* head, int val) {
//		if (!head) return nullptr;
//		ListNode* start = new ListNode(-1,head);
//		ListNode* tem = start;
//		while (tem->next) {
//			if (tem->next->val == val) {
//				tem->next = tem->next->next;
//			}
//			else
//				tem = tem->next;
//		}
//		return start->next;
//	}
//};
//
//int main() {
//	ListNode* A = new ListNode(7);
//	ListNode* B = new ListNode(7);
//	ListNode* C = new ListNode(7);
//	ListNode* D = new ListNode(7);
//	A->next = B;
//	B->next = C;
//	C->next = D;
//	Solution S;
//	ListNode* res = S.removeElements(A,7);
//	cout << res->val << endl;
//	system("pause");
//	return 0;
//}