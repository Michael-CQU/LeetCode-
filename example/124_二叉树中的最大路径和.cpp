#include<bits/stdc++.h>
using namespace std;

//˼����ö�ٶ���ķ�ʽ��ö��·�������Ե�ǰ�ڵ�Ϊ�����·���У�����Ϊ���������ֵ���϶����ֵ��������·����ֵ�������ݵ��������������⣬����·��Ϊ�������������ļ�������ڵ��ֵ��
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
//		return root->val + max(left, right);//���ص���·��
//	}
//	int maxPathSum(TreeNode* root) {
//		mycompare(root);
//		return mymax;
//	}
//};