#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//�ж���û�л�������true��false
//�����ⶼ�趨slow = head, fast = head��Ȼ��ѭ���Ǹ���fast != nullptr&&fast->next != nullptr��ѭ���ﵱfast==slowʱ����л�
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* slow = head, *fast = head;
		while (fast != nullptr&&fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)//������ע�����if��˳�������fast��slow�ƶ�֮��
				return true;
		}
		return false;
	}
};