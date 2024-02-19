#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//���ÿ���ָ���������й鲢����ע���������й鲢����ʱ��Ҫ�����n�ռ�洢��ʱ���飬������������й鲢����ʱֱ���������ָ���޸�ָ��Ϳ��ԣ�����Ҫ�����µĿռ�
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* fast = head->next;//fast��ʼֵ��Ϊhead->nextʱ��fast����ĩβʱ������ʱslow���м���λ�ã�ż��ʱslow���м�������������Ǹ��������fast�ĳ�ʼֵ����Ϊfast��fast����ĩβʱ��ż��ʱslow���м����������ұ��Ǹ���������±ߵ�mid�Ͳ�����whileѭ����߽��и�ֵ�ˣ���Ҫ��fast = fast->next->next;�±���if�����жϣ���fast����nullptrʱ��slow��ִ��slow->next֮ǰ��λ��Ϊ�м�������������Ǹ���
		ListNode* slow = head;
		while (fast != nullptr&&fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* mid = slow->next;
		slow->next = nullptr;//����˼��1���˴�������ϳ����������Ӷ���������й鲢����
		ListNode* left = sortList(head);
		ListNode* right = sortList(mid);
		ListNode* dummy = new ListNode(-1);//����˼��2�����й鲢����ʱ���ȴ���һ���ƽ�㣬�Ӷ�ʹ���ڵݹ鷵��ʱ���Է��㷵��ͷ��㣨dummy->next��
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