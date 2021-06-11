#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
			return nullptr;
		if (root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left == nullptr)
			return right;
		if (right == nullptr)
			return left;
		return root;//只会调用一次
	}
};
TreeNode* creattree(int test[],int index,int n) {
	TreeNode *node = nullptr;
	if (index < n) {
		if (test[index] == -1) {
			return nullptr;
		}
		node = new TreeNode(0);
		node->val = test[index];
		node->left = creattree(test, 2 * index + 1, n);
		node->right = creattree(test, 2 * index + 2, n);
	}
	return node;
}

void levelordertraver2(TreeNode* result) {
	queue<TreeNode*> que;
	TreeNode* tem;
	if (result) {
		que.push(result);
		while (!que.empty()) {
			tem = que.front();
			que.pop();
			if (tem->val != -1)
				cout << tem->val << " ";
			else
				cout << "null" << " ";
			if (tem->left) {
				que.push(tem->left);
			}
			if (tem->right) {
				que.push(tem->right);
			}
		}
		cout << endl;
	}
}
//int main() {
//	int test[] = { 3,5,1,6,2,10,8,-1,-1,7,4 };
//	int n = sizeof(test) / sizeof(int);
//	TreeNode* node = creattree(test,0,n);
//	TreeNode* p = node->left->right->left;
//	TreeNode* q = node->left->right->right;
//	levelordertraver2(node);
//	Solution s;
//	s.lowestCommonAncestor(node,p,q);
//	system("pause");
//	return 0;
//}