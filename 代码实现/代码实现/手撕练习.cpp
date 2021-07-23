#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool cmp(ListNode* a,ListNode* b) {
	return a->val > b->val;
}
//int main() {
//	ListNode* A = new ListNode(1);
//	ListNode* B = new ListNode(4);
//	ListNode* C = new ListNode(5);
//	ListNode* D = new ListNode(1);
//	ListNode* E = new ListNode(3);
//	ListNode* F = new ListNode(4);
//	vector<ListNode*> test = { A,B,C,D,E,F };
//	sort(test.begin(), test.end(), cmp);
//	//for (auto i : test)
//	//	cout << i->val << endl;
//	system("pause");
//	return 0;
//}