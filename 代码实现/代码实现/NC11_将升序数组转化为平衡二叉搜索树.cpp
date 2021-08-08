#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};
 

class Solution {
public:
    TreeNode* myBST(vector<int>& num,int idx){
        if(idx<0||idx>=num.size())
            return nullptr;
        TreeNode* root = new TreeNode(-1);
        root->left = myBST(num,idx-1);
        root->val = num[idx];
        root->right = myBST(num, idx+1);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& num) {
        return myBST(num,1);
    }
};

//int main() {
//	vector<int> test = {-1,0,1,2};
//	Solution s;
//	TreeNode* res = s.sortedArrayToBST(test);
//	system("pause");
//	return 0;
//}