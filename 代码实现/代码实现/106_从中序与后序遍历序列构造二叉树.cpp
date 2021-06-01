//#include <iostream>
//#include <unordered_map>
//#include <queue>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
//};
////÷––Ú+∫Û–Ú
//class Solution {
//	unordered_map<int, int> index;
//public:
//	TreeNode* mybuildTree(vector<int>& inorder, int in_left, int in_right, vector<int>& postorder, int po_left, int po_right) {
//		if (in_left > in_right || po_left > po_right)
//			return nullptr;
//		int po_root = po_right;
//		int in_root = index[postorder[po_root]];
//		TreeNode* root = new TreeNode(postorder[po_root]);
//		int size_left_subtree = in_root - in_left;
//		root->right = mybuildTree(inorder, in_root + 1, in_right, postorder, po_left + size_left_subtree + 1, po_right - 1);
//		root->left = mybuildTree(inorder, in_left, in_root - 1, postorder, po_left, po_left + size_left_subtree);
//		return root;
//	}
//	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//		for (int i = 0; i < inorder.size(); i++) {
//			index[inorder[i]] = i;
//		}
//		return mybuildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
//	}
//};