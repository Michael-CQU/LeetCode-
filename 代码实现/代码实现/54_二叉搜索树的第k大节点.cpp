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
	void generate(TreeNode* root, int& ans, int& k) {//�����������������ǵ��򣬵�K��Ҳ���ǵ�k��ֵ����˵�--k==0ʱ�ʹ����˵�k��ֵ

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