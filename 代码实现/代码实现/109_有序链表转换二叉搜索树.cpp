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

//递归+先序遍历
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
//		if (left == right)//注意终止条件（当递归到同一个点的时候，就代表是无子节点了），区间是左闭右开
						//PS:如果用指针作为区间指引，这里的参数需要是“左闭右开”区间，没有办法用左闭右闭的表示，除非用O(n)的时间找到它。 其实可以像第二个方案一样，找到长度，仍然用index描述区间，这时左闭右开 左闭右闭 都没有问题。
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


//递归+中序遍历
//注意前提是有序链表，因此转化为二叉搜索树的中序遍历就是有序链表的顺序
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
		if (left > right) {//注意终止条件，区间是左闭右闭
			return nullptr;
		}
		int mid = (left + right+1) / 2;//不写+1也可以，就是建的树不同，但是都是二叉搜索树
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