#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<TreeNode*> get_path(TreeNode* root,TreeNode* m) {
		TreeNode* node = root;
		vector<TreeNode*> path_m;
		while (root != m) {
			path_m.push_back(root);
			if (m->val > root->val) {
				root = root->right;
			}
			else
				root->left;
		}
		path_m.push_back(root);
		return path_m;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path_p = get_path(root, p);
		vector<TreeNode*> path_q = get_path(root, q);
		TreeNode * res = 0;
		for (int i = 0; i < path_p.size() && path_q.size(); i++) {
			if (path_p[i] == path_q[i]) {
				res = path_p[i];
			}
			else
				break;
		}
		return res;
	}
};
//int main() {
//	vector<TreeNode*> arr = {6,2,8,0,4,7,9,null,null,3,5};
//	Solution s;
//	TreeNode* res = s.lowestCommonAncestor(6, 2, 8);
//	system("pause");
//	return 0;
//}