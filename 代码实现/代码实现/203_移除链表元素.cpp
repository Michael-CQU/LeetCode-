//#include<iostream>
//using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dumy = new ListNode(-1);
		dumy->next = head;
		ListNode* node = dumy;
		while (node->next != nullptr) {
			if (node->next->val == val) {
				ListNode* temp = node->next;//用于释放删除的节点
				node->next = node->next->next;
				delete temp;//同上
			}
			else
				node = node->next;
		}
		head = dumy->next;//用于释放dumy头结点
		delete dumy;
		return head;
	}
};
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