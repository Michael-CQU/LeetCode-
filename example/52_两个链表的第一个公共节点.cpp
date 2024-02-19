#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		unordered_set<ListNode *> visited;
//		ListNode *temp = headA;
//		while (temp != nullptr) {
//			visited.insert(temp);
//			temp = temp->next;
//		}
//		temp = headB;
//		while (temp != nullptr) {
//			if (visited.count(temp)) {
//				return temp;
//			}
//			temp = temp->next;
//		}
//		return nullptr;
//	}
//};
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {//注意一定要搭配if-else想明白逻辑
		ListNode* ptra = headA;
		ListNode* ptrb = headB;
		while (ptra != ptrb) {
			if (ptra == nullptr)
				ptra = headB;
			else
			ptra = ptra->next;
			if (ptrb == nullptr)
				ptrb = headA;
			else
			ptrb = ptrb->next;
		}
		return ptra;
	}
};
//int main() {
//	ListNode* A = new ListNode(2);
//	ListNode* B = new ListNode(6);
//	ListNode* C = new ListNode(4);
//	ListNode* D = new ListNode(4);
//	ListNode* E = new ListNode(5);
//	A->next = B;
//	B->next = C;
//	//C->next = D;
//	//D->next = E;
//
//	ListNode* AA = new ListNode(1);
//	ListNode* BB = new ListNode(5);
//	ListNode* CC = new ListNode(1);
//	ListNode* DD = new ListNode(8);
//
//	AA->next = BB;
//	//BB->next = CC;
//	//CC->next = DD;
//	//DD->next = C;
//
//	Solution S;
//	ListNode* res = S.getIntersectionNode(A, AA);
//	cout << res->val << endl;
//	system("pause");
//	return 0;
//}