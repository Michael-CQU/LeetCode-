class Solution {
public:
	int target = 0;
	bool res = false;
	void mygenerate(TreeNode* root, int sum) {
		if (root == nullptr)return;
		target += root->val;
		if (target == sum&&root->left == nullptr&&root->right == nullptr) {
			res = true;//��߸�����returnҪ�����������Ҫ���費��Ҫ���л���
		}
		if (root->left) {
			mygenerate(root->left, sum);
		}
		if (root->right) {
			mygenerate(root->right, sum);
		}
		target -= root->val;
	}
	bool hasPathSum(TreeNode* root, int sum) {
		mygenerate(root, sum);
		return res;
	}
};