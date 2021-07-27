#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//判断有没有环，返回true和false
//此类题都设定slow = head, fast = head；然后循环是根据fast != nullptr&&fast->next != nullptr，循环里当fast==slow时候就有环
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* slow = head, *fast = head;
		while (fast != nullptr&&fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)//！！！注意这个if的顺序必须在fast和slow移动之后
				return true;
		}
		return false;
	}
};