#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//自我实现
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr)return head;
		ListNode* odd = head, *even = head->next, *temp = head->next;//注意设置一个temp来存储head->next的值
		while (even != nullptr&&even->next != nullptr) {
			odd->next = odd->next->next;
			even->next = even->next->next;
			odd = odd->next;
			even = even->next;
		}
		odd->next = temp;
		return head;
	}
};
//class Solution {
//public:
//	ListNode* oddEvenList(ListNode* head) {
//		if (head == nullptr)return nullptr;
//		ListNode* odd = head;
//		ListNode* evenstart = head->next;
//		ListNode* even = head->next;
//		ListNode* pre = even;
//		int count = 0;
//		while (even) {
//			count++;
//			ListNode* post = even->next;
//			pre = odd;
//			odd->next = post;
//			//even->next = post->next;
//			odd = even;
//			even = post;
//		}
//		if (count % 2 == 1)
//			pre->next = evenstart;
//		else
//			odd->next = evenstart;
//		return head;
//	}
//};

//int main() {
//	ListNode* A = new ListNode(1);
//	ListNode* B = new ListNode(2);
//	ListNode* C = new ListNode(3);
//	ListNode* D = new ListNode(4);
//	ListNode* E = new ListNode(5);
//	A->next = B;
//	B->next = C;
//	C->next = D;
//	D->next = E;
//
//
//	Solution S;
//	ListNode* res = S.oddEvenList(A);
//	while (res) {
//		cout << res->val << endl;
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}