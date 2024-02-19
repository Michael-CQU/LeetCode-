#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};
//中序+后序
class Solution {
	unordered_map<int, int> index;
public:
	TreeNode* mybuildTree(vector<int>& inorder, int in_left, int in_right, vector<int>& postorder, int po_left, int po_right) {
		if (in_left > in_right || po_left > po_right)
			return nullptr;
		int po_root = po_right;
		int in_root = index[postorder[po_root]];
		TreeNode* root = new TreeNode(postorder[po_root]);
		int size_left_subtree = in_root - in_left;
		root->left = mybuildTree(inorder, in_left, in_root - 1, postorder, po_left, po_left + size_left_subtree-1);
		root->right = mybuildTree(inorder, in_root + 1, in_right, postorder, po_left + size_left_subtree, po_right - 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		for (int i = 0; i < inorder.size(); i++) {
			index[inorder[i]] = i;
		}
		return mybuildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
};

//int main() {
//	vector<int> inorder = { 9,3,15,20,7 };
//	vector<int> postorder = { 9,15,7,20,3 };
//	Solution s;
//	TreeNode* result = s.buildTree(inorder, postorder);
//	//层次遍历输出二叉树结果
//	//levelordertraver(result);
//	//postorder1(result);
//	system("pause");
//	return 0;
//}