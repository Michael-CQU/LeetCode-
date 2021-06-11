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
		//if (pre_left > pre_right||in_left>in_right)
		if (pre_left > pre_right)
			return nullptr;//�ݹ����һ��Ҫд����ֹ������һ��Ҫд������
		int preorder_root = pre_left;
		int inorder_root = index[preorder[preorder_root]];//ͨ��index����preorder[preorder_root]��index�ж�Ӧ��iֵ����preorder[preorder_root]��inorder���е�λ��
		TreeNode* root = new TreeNode(preorder[preorder_root]);
		int size_left_subtree = inorder_root - in_left;
		root->left = myBuildTree(preorder, inorder, pre_left + 1, pre_left + (size_left_subtree-1)+1, in_left, inorder_root - 1);//ע�������������е����䲻Ҫ�����ã�ǰ�����ǰ��ı߽磬�����������ı߽�
		root->right = myBuildTree(preorder, inorder, (pre_left + size_left_subtree) + 1, pre_right, inorder_root + 1, in_right);
		return root;
		
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		for (int i = 0; i < n; i++) {
			//�����ϣӳ�䣬�������ǿ��ٶ�λ���ڵ�
			index[inorder[i]] = i;//��inorder�е�ֵͨ��i��˳��ӳ����index��
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
			//if(tem->val!= INT_MAX)
			cout << tem->val<< " ";
			//else
				//cout << "null" << " ";
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
//ǰ�����
void PreOrderTraverse(TreeNode* T) {
	if (T) {
		//printf("%c ", T->val);
		cout << T->val << " ";
		PreOrderTraverse(T->left);
		PreOrderTraverse(T->right);
	}
}

//�������
void InOrderTraverse(TreeNode* T) {
	if (T) {
		InOrderTraverse(T->left);
		printf("%c ", T->val);
		InOrderTraverse(T->right);
	}
}

//�������
void postorder1(TreeNode* T) {
	if (T) {
		postorder1(T->left);
		postorder1(T->right);
		cout << T->val << " ";
	}
}
//int main() {
//	vector<int> inorder = { 3,5,6,2,7,4,1,10,8 };
//	vector<int> postorder = { 6,5,7,2,4,3,10,1,8 };
//	Solution s;
//	TreeNode* result = s.buildTree(inorder, postorder);
//	//��α���������������
//	//levelordertraver(result);
//	postorder1(result);
//	system("pause");
//	return 0;
//}