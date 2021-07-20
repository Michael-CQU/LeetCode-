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
//    int mymax = INT_MIN;
//public:
//    int mygetmax(TreeNode* root){
//        if(root == nullptr)return 0;
//        int left = max(mygetmax(root->left),0);//递归进行各个节点为顶点的最大路径值
//        int right = max(mygetmax(root->right),0);
//        mymax = max(mymax,left+right+root->val);//以此节点为顶点的路径最大和为顶点值加上左右两侧的值
//        return max(left,right)+root->val;//返回以当前节点为定点的路径的单侧最大值
//    }
//    int maxPathSum(TreeNode* root) {
//        if(root == nullptr)return 0;
//        mygetmax(root);
//        return mymax;
//    }
//};