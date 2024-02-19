#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 struct TreeNode {
     int val;
     TreeNode *left;
	TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//�ݹ�+�������
//class Solution {
//public:
//	ListNode* getmid(ListNode* left, ListNode* right) {
//		ListNode* fast = left;
//		ListNode* slow = left;
//		while (fast != right&&fast->next != right) {
//			fast = fast->next->next;
//			slow = slow->next;
//		}
//		return slow;
//	}
//	TreeNode* buildtree(ListNode* left, ListNode* right) {
//		if (left == right)//ע����ֹ���������ݹ鵽ͬһ�����ʱ�򣬾ʹ��������ӽڵ��ˣ�������������ҿ�
						//PS:�����ָ����Ϊ����ָ��������Ĳ�����Ҫ�ǡ�����ҿ������䣬û�а취������ұյı�ʾ��������O(n)��ʱ���ҵ����� ��ʵ������ڶ�������һ�����ҵ����ȣ���Ȼ��index�������䣬��ʱ����ҿ� ����ұ� ��û�����⡣
//			return nullptr;
//		ListNode* mid = getmid(left, right);
//		TreeNode* root = new TreeNode(mid->val);
//		root->left = buildtree(left, mid);
//		root->right = buildtree(mid->next, right);
//		return root;
//	}
//	TreeNode* sortedListToBST(ListNode* head) {
//		return buildtree(head, nullptr);
//	}
//};


//�ݹ�+�������
//ע��ǰ���������������ת��Ϊ��������������������������������˳��
class Solution {
public:
	int getlength(ListNode* head) {
		int res = 0;
		while (head != nullptr) {
			res++;
			head = head->next;
		}
		return res;
	}
	TreeNode* buildTree(ListNode*& head, int left, int right) {
		if (left > right) {//ע����ֹ����������������ұ�
			return nullptr;
		}
		int mid = (left + right+1) / 2;//��д+1Ҳ���ԣ����ǽ�������ͬ�����Ƕ��Ƕ���������
		TreeNode* root = new TreeNode();
		root->left = buildTree(head, left, mid - 1);
		root->val = head->val;
		head = head->next;
		root->right = buildTree(head, mid + 1, right);
		return root;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		int length = getlength(head);
		return buildTree(head, 0, length - 1);
	}
};
//int main() {
//	ListNode* A = new ListNode(-10);
//	ListNode* B = new ListNode(-3);
//	ListNode* C = new ListNode(0);
//	ListNode* D = new ListNode(5);
//	ListNode* E = new ListNode(9);
//	A->next = B;
//	B->next = C;
//	C->next = D;
//	D->next = E;
//	Solution s;
//	TreeNode* res = s.sortedListToBST(A);
//	system("pause");
//	return 0;
//}