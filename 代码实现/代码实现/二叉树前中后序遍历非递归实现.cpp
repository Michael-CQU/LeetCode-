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
//ǰ��
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) 
			return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();                       // ��
			st.pop();
			result.push_back(node->val);
			if (node->right) 
				st.push(node->right);           // �ң��սڵ㲻��ջ��
			if (node->left) 
				st.push(node->left);             // �󣨿սڵ㲻��ջ��
		}
		return result;
	}

//����
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) { // ָ�������ʽڵ㣬���ʵ���ײ�
				st.push(cur); // �����ʵĽڵ�Ž�ջ
				cur = cur->left;                // ��
			}
			else {
				cur = st.top(); // ��ջ�ﵯ�������ݣ�����Ҫ��������ݣ��Ž�result����������ݣ�
				st.pop();
				result.push_back(cur->val);     // ��
				cur = cur->right;               // ��
			}
		}
		return result;
	}

//����
//��������������ң��������������ѭ���Ϊ������Ȼ���ٷ�תresult�����Ϊ������
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
			if (node->left) st.push(node->left); // �����ǰ������������һ����ջ˳�� ���սڵ㲻��ջ��
			if (node->right) st.push(node->right); // �սڵ㲻��ջ
		}
		reverse(result.begin(), result.end()); // �������ת֮����������е�˳����
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
