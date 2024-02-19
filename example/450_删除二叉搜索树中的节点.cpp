#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
	int count = 0;
public:
	int getMin(struct TreeNode* node) {
		// BST ����ߵľ�����С��
		while (node->left != NULL)
			node = node->left;

		return node->val;
	}

	TreeNode* deleteNode(TreeNode* root, int key) {


		if (NULL == root)
		{
			return  NULL;
		}
		int num = root->val;

		if (num == key)
		{
			/*����ɾ���߼�*/
			if (NULL == root->left && NULL == root->right)
			{
				return NULL;
			}
			else if (NULL == root->left)
			{
				return root->right;
			}
			else if (NULL == root->right)
			{
				return root->left;
			}
			/*�������ӽڵ�����*/
			/* �����ҵ��������������Ǹ��ڵ㣬��������������С���Ǹ��ڵ��������Լ�--�ѵ� */
			int minVal = getMin(root->right); /*��������С��*/
			root->val = minVal; /*�ҵ�֮���滻*/
			root->right = deleteNode(root->right, minVal); /*�ݹ�-ɾ�����ӽڵ��е�����ڵ�*/
		}
		else if (num > key)
		{
			root->left = deleteNode(root->left, key);
		}
		else if (num < key)
		{
			root->right = deleteNode(root->right, key);
		}

		return root;
	}

	TreeNode*deleteTree(TreeNode* root) {
		if (root == NULL)
			return nullptr;
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
		count++;
		cout << count << endl;
	}
};

TreeNode * creatBTree(int data[], int index, int n)
{
	TreeNode * pNode = NULL;

	//if (index < n && data[index] != -1)//������-1 ��ʾ�ýڵ�Ϊ��(�˷������ս������)
	if (index < n)//������-1 ��ʾ�ýڵ�Ϊ��
	{
		pNode = new TreeNode;
		if (pNode == NULL)
			return NULL;
		pNode->val = data[index];
		pNode->left = creatBTree(data, 2 * index + 1, n);//�����������ղ������, ���α����, ��0��ʼ
		pNode->right = creatBTree(data, 2 * index + 2, n);
	}

	return pNode;
}
void levelordertraver1(TreeNode* result) {
	queue<TreeNode*> que;
	TreeNode* tem;
	if (result) {
		que.push(result);
		while (!que.empty()) {
			tem = que.front();
			que.pop();
			if (tem->val != -1)
				cout << tem->val << " ";
			else
				cout << "null" << " ";
			if (tem->left) {
				que.push(tem->left);
			}
			if (tem->right) {
				que.push(tem->right);
			}
		}
		cout << endl;
	}
}
//int main() {
//	int a[] = { 30,5,40,2,-1,35,80,-1,-1,-1,-1,32,-1,60,85,-1,-1,-1,-1,-1,-1,-1,-1,31,33 };
//	TreeNode *root = NULL;
//	root = creatBTree(a, 0, sizeof(a) / sizeof(a[0]));
//	Solution s;
//	TreeNode* result;
//	result = s.deleteNode(root,40);
//	levelordertraver1(result);
//	TreeNode* deletetree = s.deleteTree(result);
//	system("pause");
//	return 0;
//}