#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
��������O��NlogK��������
1.kָ��ָ��k������ÿ��ʹ��С���ѣ����ȶ��У���logk�����Сֵ
2.��k��������������ϲ�
*/
//��������˳��һ��һ���ϲ�
//class Solution {
//public:
//	ListNode* mymergesort(ListNode* ans,ListNode* list) {
//		if (ans == nullptr)return list;
//		if (list == nullptr)return ans;
//		ListNode* head = new ListNode(-1);
//		ListNode* node = head;
//		while (ans&&list) {
//			if (ans->val <= list->val) {
//				node->next = ans;
//				ans = ans->next;
//			}
//			else {
//				node->next = list;
//				list->next = list;
//			}
//			node = node->next;
//		}
//		if (ans)
//			node->next = ans;
//		if (list)
//			node->next = list;
//		return head->next;
//	}
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//		ListNode* ans = nullptr;
//		for (auto i : lists) {
//			ans = mymergesort(ans,i);
//		}
//		return ans;
//    }
//};
//���ι鲢�������ϲ�����ȵ�һ�ַ������ÿռ任ʱ�䣩
//class Solution {
//public:
//		ListNode* mymergesort(ListNode* ans,ListNode* list) {
//		if (ans == nullptr)return list;
//		if (list == nullptr)return ans;
//		ListNode* head = new ListNode(-1);
//		ListNode* node = head;
//		while (ans&&list) {
//			if (ans->val <= list->val) {
//				node->next = ans;
//				ans = ans->next;
//			}
//			else {
//				node->next = list;
//				list = list->next;
//			}
//			node = node->next;
//		}
//		if (ans)
//			node->next = ans;
//		if (list)
//			node->next = list;
//		return head->next;
//	}
//		ListNode* mergedigui(vector <ListNode*> &lists, int l, int r) {
//			if (l == r)
//				return lists[l];
//			int mid = (r - l) / 2 + l;
//			ListNode* l1 = mergedigui(lists, l, mid);//��
//			ListNode* l2 = mergedigui(lists, mid + 1, r);
//			return mymergesort(l1,l2);//��
//		}
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//		if (lists.size() == 0)
//			return nullptr;
//		ListNode* res = nullptr;
//		res = mergedigui(lists, 0, lists.size() - 1);
//		return res;
//    }
//};
//���ȶ��У���С�ѣ���ʱ�临�Ӷ�ΪO��knlogk�����ռ临�Ӷ�ΪO��k��
class cmp {
public:
	bool operator()(ListNode* a, ListNode* b) {
		return a->val > b->val;
	}
};
class Solution {
public:
	priority_queue<ListNode*, vector<ListNode*>, cmp> q;
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		for (auto i : lists)
			if (i)q.push(i);
		ListNode* head = new ListNode(-1);
		ListNode* tail = head;
		while (!q.empty()) {
			auto f = q.top();
			q.pop();
			tail->next = f;
			tail = tail->next;
			if (f->next)
				q.push(f->next);
		}
		return head->next;
	}
};
//int main() {
//	ListNode* A = new ListNode(1);
//	ListNode* B = new ListNode(4);
//	ListNode* C = new ListNode(5);
//	A->next = B;
//	B->next = C;
//	ListNode* D = new ListNode(1);
//	ListNode* E = new ListNode(3);
//	ListNode* F = new ListNode(4);
//	D->next = E;
//	E->next = F;
//	ListNode* G = new ListNode(2);
//	ListNode* H = new ListNode(6);
//	G->next = H;
//	vector<ListNode*> test = { A,D,G };
//	Solution s;
//	s.mergeKLists(test);
//	system("pause");
//	return 0;
//}