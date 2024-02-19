#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//方法一：两次遍历
//class Solution {
//public:
//	vector<TreeNode*> getpath(TreeNode* root, TreeNode* target) {
//		TreeNode* node = root;
//		vector<TreeNode*> ans;
//		while (node != target) {
//			ans.push_back(node);
//			if (node->val > target->val)
//				node = node->left;
//			else
//				node = node->right;
//		}
//		ans.push_back(node);
//		return ans;
//	}
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		vector<TreeNode*> p_path = getpath(root, p);
//		vector<TreeNode*> q_path = getpath(root, q);
//		TreeNode* node = nullptr;
//		for (int i = 0; i < p_path.size() && i < q_path.size(); i++) {
//			if (p_path[i] == q_path[i]) {
//				node = p_path[i];
//			}
//			else
//				break;
//		}
//		return node;
//	}
//};

//方法二：一次遍历
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* node = root;
		while (1) {
			if (p->val < node->val&&q->val < node->val)
				node = node->left;
			else if (p->val > node->val&&q->val > node->val)
				node = node->right;
			else
				break;
		}
		return node;
	}
};
//TreeNode * creatBTree111(int data[], int index, int n)
//{
//	TreeNode * pNode = NULL;
//
//	//if (index < n && data[index] != -1)//数组中-1 表示该节点为空
//	if (index < n)//数组中-1 表示该节点为空
//	{
//		//pNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
//		pNode = new TreeNode(0);
//		//if (pNode == NULL)
//		//	return NULL;
//		//if (data[index] == -1) {
//		//	return nullptr;
//		//}
//		pNode->val = data[index];
//		pNode->left = creatBTree111(data, 2 * index + 1, n);//将二叉树按照层序遍历, 依次标序号, 从0开始
//		pNode->right = creatBTree111(data, 2 * index + 2, n);
//	}
//
//	return pNode;
//}
//int main() {
//	int arr[] = { 6,2,8,0,4,7,9,-1,-1,3,5 };
//	TreeNode* test = creatBTree111(arr, 0, 11);
//	Solution s;
//	TreeNode* first = test->left->right->left;
//	TreeNode* second = test->left->right->right;
//	TreeNode* res = s.lowestCommonAncestor(test, first, second);
//	system("pause");
//	return 0;
//}