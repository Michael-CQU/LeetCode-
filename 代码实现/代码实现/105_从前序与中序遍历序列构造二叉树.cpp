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

class Solution {
private:
	unordered_map<int, int> index;
public:
	TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
		if (pre_left > pre_right||in_left>in_right)return nullptr;
		int preorder_root = pre_left;
		int inorder_root = index[preorder[preorder_root]];//通过index索引preorder[preorder_root]在index中对应的i值，即preorder[preorder_root]在inorder表中的位置
		TreeNode* root = new TreeNode(preorder[preorder_root]);
		int size_left_subtree = inorder_root - in_left;
		root->left = myBuildTree(preorder, inorder, pre_left + 1, pre_right + size_left_subtree, in_left, inorder_root - 1);
		root->right = myBuildTree(preorder, inorder, pre_left + size_left_subtree + 1, pre_right, inorder_root + 1, in_right);
		return root;
		
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		for (int i = 0; i < n; i++) {
			//构造哈希映射，帮助我们快速定位根节点
			index[inorder[i]] = i;//将inorder中的值通过i的顺序映射在index中
		}
		return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};
void levelordertraver(TreeNode* result) {
	queue<TreeNode*> que;
	TreeNode *N1;
	TreeNode* tem;
	if (result) {
		que.push(result);
		while (!que.empty()) {
			tem = que.front();
			que.pop();
			if(tem->val!= INT_MAX)
			cout << tem->val<< " ";
			else
				cout << "null" << " ";
			if (tem->left) {
				que.push(tem->left);
			}
			else
				que.push(N1);
			if (tem->right) {
				que.push(tem->right);
			}
			else
				que.push(N1);
		}
		cout << endl;
	}
}

//int main() {
//	vector<int> preorder = { 3,9,20,15,7 };
//	vector<int> inorder = { 9,3,15,20,7 };
//	Solution s;
//	TreeNode* result = s.buildTree(preorder, inorder);
//	//层次遍历输出二叉树结果
//	levelordertraver(result);
//	system("pause");
//	return 0;
//}