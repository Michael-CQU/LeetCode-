#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* node = head;
		while (node) {
			if (node->val == val) {
				pre->next = node->next;
				node = node->next;
			}
			else {
				pre = node;
				node = node->next;
			}
		}
		return dummy->next;
	}
};

//int main() {
//	ListNode* A = new ListNode(1);
//	ListNode* B = new ListNode(2);
//	ListNode* C = new ListNode(3);
//	ListNode* D = new ListNode(4);
//	ListNode* E = new ListNode(5);
//	ListNode* F = new ListNode(4);
//	A->next = B;
//	B->next = C;
//	C->next = D;
//	D->next = E;
//	E->next = F;
//	Solution s;
//	ListNode* res = s.deleteNode(A, 1);
//	while(res) {
//		cout << res->val << endl;
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}