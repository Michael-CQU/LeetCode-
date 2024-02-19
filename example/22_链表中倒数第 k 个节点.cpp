#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//统计长度
//class Solution {
//public:
//	ListNode* getKthFromEnd(ListNode* head, int k) {
//		ListNode* fast = head;
//		ListNode* slow = head;
//		int count = 0;
//		while (fast) {
//			count++;
//			fast = fast->next;
//		}
//		int step = count - k;
//		while (step) {
//			step--;
//			slow = slow->next;
//		}
//		return slow;
//	}
//};
//双指针一起走
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (k) {
			k--;
			if (fast = nullptr)return nullptr;//如果k的长度大于链表长度，直接返回nullptr
			fast = fast->next;
		}
		while (fast) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};
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