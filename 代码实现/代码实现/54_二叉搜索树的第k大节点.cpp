#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	void generate(TreeNode* root, int& ans, int& k) {//中序遍历反着输出就是倒序，第K大也就是第k个值，因此当--k==0时就代表到了第k个值

		if (root) {
			generate(root->right, ans, k);
			if (--k == 0) {
				ans = root->val;
				return;
			}
			generate(root->left, ans, k);
		}
	}
	int kthLargest(TreeNode* root, int k) {
		int ans = 0;
		generate(root, ans, k);
		return ans;
	}
};