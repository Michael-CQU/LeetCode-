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
	/**
	*
	* @param num int’˚–Õvector
	* @return TreeNode¿‡
	*/
	TreeNode* mybuild(vector<int>& num, int left, int right) {
		if (left>right)return nullptr;
		int mid = (right - left + 1) / 2 + left;
		TreeNode* root = new TreeNode(num[mid]);
		root->left = mybuild(num, left, mid - 1);
		root->right = mybuild(num, mid + 1, right);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& num) {
		int n = num.size() - 1;
		return mybuild(num, 0, n);
	}
};

//int main() {
//	vector<int> test = {-1,0,1,2};
//	Solution s;
//	TreeNode* res = s.sortedArrayToBST(test);
//	system("pause");
//	return 0;
//}