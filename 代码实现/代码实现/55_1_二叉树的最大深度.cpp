#include<bits/stdc.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

//方法二：（同理）
//class Solution {
//public:
//	int ans = 0;
//	int maxDepth(TreeNode* root) {
//		if (root == nullptr) return 0;
//		int left = maxDepth(root->left);
//		int right = maxDepth(root->right);
//		ans = max(left, right) + 1;
//		return ans;
//	}
//};