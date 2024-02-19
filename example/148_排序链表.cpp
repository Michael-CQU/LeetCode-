#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//利用快慢指针对链表进行归并排序，注意对数组进行归并排序时需要额外的n空间存储临时数组，而对于链表进行归并排序时直接用链表的指针修改指向就可以，不需要开辟新的空间
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* fast = head->next;//fast初始值设为head->next时，fast到达末尾时，奇数时slow在中间数位置，偶数时slow在中间两个数的左边那个数；如果fast的初始值设置为fast，fast到达末尾时，偶数时slow在中间两个数的右边那个数，因此下边的mid就不能在while循环外边进行赋值了，需要在fast = fast->next->next;下边用if进行判断，当fast到达nullptr时，slow在执行slow->next之前的位置为中间两个数的左边那个数
		ListNode* slow = head;
		while (fast != nullptr&&fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* mid = slow->next;
		slow->next = nullptr;//核心思想1：此处将链表断成两个链表，从而对链表进行归并排序
		ListNode* left = sortList(head);
		ListNode* right = sortList(mid);
		ListNode* dummy = new ListNode(-1);//核心思想2：进行归并排序时首先创建一个哑结点，从而使得在递归返回时可以方便返回头结点（dummy->next）
		ListNode* node = dummy;
		while (left != nullptr&&right != nullptr) {
			if (left->val < right->val) {
				node->next = left;
				left = left->next;
			}
			else {
				node->next = right;
				right = right->next;
			}
			node = node->next;
		}
		if (left != nullptr)
			node->next = left;
		if (right != nullptr)
			node->next = right;
		return dummy->next;
	}
};

//int main() {
//	ListNode* A = new ListNode(4);
//	ListNode* B = new ListNode(2);
//	ListNode* C = new ListNode(1);
//	ListNode* D = new ListNode(3);
//	ListNode* E = new ListNode(5);
//	ListNode* F = new ListNode(6);
//	A->next = B;
//	B->next = C;
//	C->next = D;
//	D->next = E;
//	E->next = F;
//	Solution s;
//	ListNode* res = s.sortList(A);
//	while (res) {
//		cout << res->val << endl;
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}