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
//    int mymax = INT_MIN;
//public:
//    int mygetmax(TreeNode* root){
//        if(root == nullptr)return 0;
//        int left = max(mygetmax(root->left),0);//�ݹ���и����ڵ�Ϊ��������·��ֵ
//        int right = max(mygetmax(root->right),0);
//        mymax = max(mymax,left+right+root->val);//�Դ˽ڵ�Ϊ�����·������Ϊ����ֵ�������������ֵ
//        return max(left,right)+root->val;//�����Ե�ǰ�ڵ�Ϊ�����·���ĵ������ֵ
//    }
//    int maxPathSum(TreeNode* root) {
//        if(root == nullptr)return 0;
//        mygetmax(root);
//        return mymax;
//    }
//};