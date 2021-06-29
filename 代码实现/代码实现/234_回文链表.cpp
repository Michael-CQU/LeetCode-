#include<iostream>
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
	bool isPalindrome(ListNode* head) {
		ListNode* temp = head;
		ListNode* front = head;
		ListNode* back = head;
		int count = 0;
		while (temp) {
			temp = temp->next;
			count++;
		}
		count /= 2;
		while (count) {
			back = back->next;
			count--;
		}

		ListNode* node = back;
		ListNode* pre = nullptr;
		while (node) {
			ListNode* post = node->next;
			node->next = pre;
			pre = node;
			node = post;
		}

		back = pre;
		while (back&&front->val == back->val) {
			front = front->next;
			back = back->next;
		}
		if (back == nullptr)
			return true;
		return false;
	}
};

//int main() {
//	ListNode* A = new ListNode(1);
//	ListNode* B = new ListNode(2);
//	ListNode* C = new ListNode(3);
//	ListNode* D = new ListNode(3);
//	ListNode* E = new ListNode(1);
//	A->next = B;
//	B->next = C;
//	C->next = D;
//	D->next = E;
//
//
//	Solution S;
//	bool res = S.isPalindrome(A);
//	system("pause");
//	return 0;
//}