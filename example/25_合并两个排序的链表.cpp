#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//µÝ¹é
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		else if (l2 == nullptr)
			return l1;
		else if (l1->val < l2->val) {
				l1->next = mergeTwoLists(l1->next, l2);
				return l1;
			}
		else {
				l2->next = mergeTwoLists(l1, l2->next);
				return l2;
			}
	}
};
//µü´ú
//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		ListNode* head = new ListNode(-1);
//		ListNode* pre = head;
//		while (l1&&l2) {
//			if (l1->val <= l2->val) {
//				pre->next = l1;
//				l1 = l1->next;
//			}
//			else {
//				pre->next = l2;
//				l2 = l2->next;
//			}
//			pre = pre->next;
//		}
//		if (l1) {
//			pre->next = l1;
//		}
//		if (l2) {
//			pre->next = l2;
//		}
//		return head->next;
//	}
//};
//int main() {
//	ListNode* A = new ListNode(1);
//	ListNode* B = new ListNode(2);
//	ListNode* C = new ListNode(3);
//	ListNode* D = new ListNode(4);
//	ListNode* E = new ListNode(5);
//	ListNode* F = new ListNode(6);
//	A->next = B;
//	B->next = C;
//	C->next = D;
//	D->next = E;
//	E->next = F;
//	Solution s;
//	ListNode* res = s.getKthFromEnd(A,3);
//	while (res) {
//		cout << res->val<<" ";
//		res = res->next;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}