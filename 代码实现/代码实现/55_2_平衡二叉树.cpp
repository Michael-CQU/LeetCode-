#include<bits/stdc.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {//���������ͨ���Ƚ����������ĸ߶Ȳ����жϡ�ƽ�������������������������ƽ�������������Ҫ�ݹ��жϡ�
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		return isBalanced(root->left) && isBalanced(root->right) && abs(depth(root->left) - depth(root->right)) < 2;
	}
	int depth(TreeNode* root) {
		if (root == nullptr)return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}
};

//����������ͬ���������+��֦��Ч�ʸߣ�
//class Solution {
//public:
//	bool isBalanced(TreeNode* root) {
//		return recur(root) != -1;
//	}
//private:
//	int recur(TreeNode* root) {
//		if (root == nullptr) return 0;
//		int left = recur(root->left);
//		if (left == -1) return -1;
//		int right = recur(root->right);
//		if (right == -1) return -1;
//		return abs(left - right) < 2 ? max(left, right) + 1 : -1;
//	}
//};