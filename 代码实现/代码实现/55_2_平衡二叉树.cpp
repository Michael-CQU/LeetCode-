#include<bits/stdc.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {//后序遍历，通过比较左右子树的高度差来判断。平衡二叉树必须所有子树都满足平衡条件，因此需要递归判断。
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

//方法二：（同理）后序遍历+剪枝（效率高）
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