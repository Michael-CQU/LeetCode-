#include<iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
//前序
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) 
			return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();                       // 中
			st.pop();
			result.push_back(node->val);
			if (node->right) 
				st.push(node->right);           // 右（空节点不入栈）
			if (node->left) 
				st.push(node->left);             // 左（空节点不入栈）
		}
		return result;
	}

//中序
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) { // 指针来访问节点，访问到最底层
				st.push(cur); // 将访问的节点放进栈
				cur = cur->left;                // 左
			}
			else {
				cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
				st.pop();
				result.push_back(cur->val);     // 中
				cur = cur->right;               // 右
			}
		}
		return result;
	}

//后序
//先序遍历是中左右，调整代码的左右循序变为中右左，然后再翻转result数组变为左右中
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);
			if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
			if (node->right) st.push(node->right); // 空节点不入栈
		}
		reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
		return result;
	}
};
TreeNode* creattree3(vector<int> test,int index,int n) {
	TreeNode* root = nullptr;
	if (index < n) {
		root = new TreeNode;
		if (test[index] == -1) {
			return nullptr;
		}
		root->val = test[index];
		root->left = creattree3(test,2*index+1,n);
		root->right = creattree3(test, 2 * index + 2, n);
	}
	return root;
}
void preorder111(TreeNode* root) {
	if (root) {
		cout << root->val << endl;
		preorder111(root->left);
		preorder111(root->right);
	}
}
//int main() {
//	vector<int> test = { 3,5,1,6,2,10,8,-1,-1,7,4 };
//	TreeNode* root = creattree3(test,0,test.size());
//	//preorder111(root);
//	Solution s;
//	vector<int>res = s.preorderTraversal(root);
//	for (int i : res)
//		cout << i << endl;
//	system("pause");
//	return 0;
//}
