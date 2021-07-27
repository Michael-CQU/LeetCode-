#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//��141�����ƣ�ֻ����if (fast == slow)����н�һ����������Ϊfast��slow�������٣����Ե�һ������ʱ��fast��slow�ߵľ����һ����Ҳ�ʹ�����һ����·�̳��������head������λ�õĳ�����ȣ�Ϊn������Ȧ������������fast�ص���㣬�����ٶ�һ����ʼ�ߣ�slow�Ѳ�Ȧ�����ʣ�µ�·�̾���������Ȧ�ˣ����һ��������ڴ������������Կ�carl����⻭ͼ������
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