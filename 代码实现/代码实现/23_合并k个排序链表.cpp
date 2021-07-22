#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//暴力：按顺序一个一个合并
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
//分治归并：两两合并
class Solution {
public:
		ListNode* mymergesort(ListNode* ans,ListNode* list) {
		if (ans == nullptr)return list;
		if (list == nullptr)return ans;
		ListNode* head = new ListNode(-1);
		ListNode* node = head;
		while (ans&&list) {
			if (ans->val <= list->val) {
				node->next = ans;
				ans = ans->next;
			}
			else {
				node->next = list;
				list = list->next;
			}
			node = node->next;
		}
		if (ans)
			node->next = ans;
		if (list)
			node->next = list;
		return head->next;
	}
		ListNode* mergedigui(vector <ListNode*> &lists, int l, int r) {
			if (l == r)return lists[l];
			if (l > r)return nullptr;
			int mid = (r - l) / 2 + l;
			ListNode* temp = nullptr;
			temp = mymergesort(mergedigui(lists, l, mid), mergedigui(lists, mid + 1, r));
			return temp;
		}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* res = nullptr;
		res = mergedigui(lists, 0, lists.size() - 1);
		return res;
    }
};