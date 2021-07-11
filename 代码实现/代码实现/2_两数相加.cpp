#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(-1);
		ListNode* node = head;
		int temp = 0;
		while (l1 || l2) {
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			temp = n1 + n2 + temp;
			node->next = new ListNode((temp) % 10);
			node = node->next;
			temp /= 10;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		if (temp)
			node->next = new ListNode(1);
		return head->next;
	}
};

//int main() {
//	ListNode *A = new ListNode(2);
//	ListNode *B = new ListNode(4);
//	ListNode *C = new ListNode(3);
//	ListNode *D = new ListNode(5);
//	ListNode *E = new ListNode(6);
//	ListNode *F = new ListNode(4);
//	A->next = B;
//	B->next = C;
//	D->next = E;
//	E->next = F;
//	Solution s;
//	ListNode* res = s.addTwoNumbers(A, D);
//	system("pause");
//	return 0;
//	
//}