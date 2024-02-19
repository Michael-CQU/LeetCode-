#include<bits/stdc++.h>
using namespace std;

//思想是枚举定点的方式来枚举路径。在以当前节点为顶点的路径中，最大和为顶点两侧的值加上顶点的值，而两侧路径的值就是数据的最大子数组和问题，单侧路径为左右子树中最大的加上这个节点的值。
//struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//class Solution {
//public:
//	int mymax = INT_MIN;
//	int mycompare(TreeNode* root) {
//		if (root == nullptr)return 0;
//		int left = max(mycompare(root->left), 0);
//		int right = max(mycompare(root->right), 0);
//		int lmr = left + right + root->val;
//		mymax = max(mymax, lmr);
//		return root->val + max(left, right);//返回单侧路径
//	}
//	int maxPathSum(TreeNode* root) {
//		mycompare(root);
//		return mymax;
//	}
//};