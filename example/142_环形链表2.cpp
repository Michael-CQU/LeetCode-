#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//和141题类似，只是在if (fast == slow)里进行进一步操作，因为fast是slow的两倍速，所以第一次相遇时候fast比slow走的距离多一倍，也就代表这一倍的路程长度与起点head到相遇位置的长度相等，为n个完整圈；而相遇后让fast回到起点，两人速度一样开始走，slow把残圈走完后，剩下的路程就是完整的圈了，因此一定会在入口处相遇。（可以看carl的题解画图分析）
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* fast = head, *slow = head;
		while (fast != nullptr&&fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				fast = head;
				while (fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}
				return slow;
			}
		}
		return nullptr;
	}
};