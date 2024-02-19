#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};
//class Solution {
//public:
//	bool isPalindrome(ListNode* head) {
//		ListNode* temp = head;
//		ListNode* front = head;
//		ListNode* back = head;
//		int count = 0;
//		while (temp) {
//			temp = temp->next;
//			count++;
//		}
//		count /= 2;
//		while (count) {
//			back = back->next;
//			count--;
//		}
//
//		ListNode* node = back;
//		ListNode* pre = nullptr;
//		while (node) {
//			ListNode* post = node->next;
//			node->next = pre;
//			pre = node;
//			node = post;
//		}
//
//		back = pre;
//		while (back&&front->val == back->val) {
//			front = front->next;
//			back = back->next;
//		}
//		if (back == nullptr)
//			return true;
//		return false;
//	}
//};

//自己实现
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    ListNode* myreverse(ListNode* root){
        ListNode* pre = nullptr;
        ListNode* node = root;
        while(node!=nullptr){
            ListNode* ne = node->next;
            node->next = pre;
            pre = node;
            node = ne;
        }
        return pre;
    }
    bool isPail(ListNode* head) {
        ListNode* fast,* slow;
        fast = slow = head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prestart = head;
        ListNode* nestart = myreverse(slow->next);
        ListNode* temp = nestart;
        while(nestart!=nullptr){
            if(prestart->val!=nestart->val)
                return false;
            prestart = prestart->next;
            nestart = nestart->next;
        }
        slow->next = myreverse(temp);
        return true;
    }
};

//int main() {
//	ListNode* A = new ListNode(1);
//	ListNode* B = new ListNode(2);
//	ListNode* C = new ListNode(2);
//	ListNode* D = new ListNode(1);
//	ListNode* E = new ListNode(1);
//	A->next = B;
//	B->next = C;
//	C->next = D;
//	D->next = E;
//
//
//	Solution S;
//	//bool res = S.isPalindrome(A);
//	bool res = S.isPail(A);
//	while (A != nullptr) {
//		cout << A->val << " ";
//		A = A->next;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}