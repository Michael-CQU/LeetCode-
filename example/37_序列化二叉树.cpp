#include<iostream>
#include <string>
#include <queue>
#include<sstream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//class Codec {
//public:
//	string serialize(TreeNode* root) {//层序遍历创建序列
//		string ans = "";
//		queue<TreeNode*> q;
//		q.push(root);
//		while (!q.empty()) {
//			TreeNode* node = q.front();
//			q.pop();
//			if (node != nullptr) {
//				ans += to_string(node->val);
//				q.push(node->left);
//				q.push(node->right);
//			}
//			else {
//				ans += "x";
//			}
//			ans += ",";
//		}
//		//ans.erase(ans.end()-1);
//		return ans;
//	}
//
//	void mytransfer(queue<string>& q,string s) {
//		int begin = 0;
//		int n = s.size();
//		int start = 0;
//		for (int i = 0; i < n; i++) {
//			if (s[i] == ',') {
//				q.push(s.substr(start, i - start));
//				start = i + 1;
//			}
//		}
//	}
//	TreeNode* mydeserialize(queue<string>& v, int index, int n) {
//		TreeNode* root = nullptr;
//		queue<TreeNode*> q;
//		string head = v.front();
//		if (head != "x") {
//			root = new TreeNode(stoi(head));
//			q.push(root);
//		}
//		v.pop();
//		while (!q.empty()) {
//			TreeNode* node = q.front();
//			q.pop();
//			string left = v.front();
//			v.pop();
//			string right = v.front();
//			v.pop();
//			if (left != "x") {
//				TreeNode* treeleft = new TreeNode(stoi(left));
//				node->left = treeleft;
//				q.push(treeleft);
//			}
//			if (right != "x") {
//				TreeNode* treeright = new TreeNode(stoi(right));
//				node->right = treeright;
//				q.push(treeright);
//			}
//		}
//		return root;
//	}
//	TreeNode* deserialize(string data) {//根据自己创建出的序列，首先用mytransfer来将string转化为queue保存单个值，在用mydeserialize层序遍历来一层一层恢复出树的结构
//		queue<string> v;
//		//data += ",";
//		mytransfer(v, data);
//		int n = v.size();
//		TreeNode* res = mydeserialize(v, 0, n);
//		return res;
//	}
//};


void levelordertraver111(TreeNode* result) {
	queue<TreeNode*> que;
	TreeNode* tem;
	if (result) {
		que.push(result);
		while (!que.empty()) {
			tem = que.front();
			que.pop();
			if (tem->val != INT_MAX)
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

TreeNode * creatBTree111(int data[], int index, int n)
{
	TreeNode * pNode = NULL;

	//if (index < n && data[index] != -1)//数组中-1 表示该节点为空
	if (index < n)//数组中-1 表示该节点为空
	{
		//pNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
		pNode = new TreeNode(0);
		//if (pNode == NULL)
		//	return NULL;
		if (data[index] == -1) {
			return nullptr;
		}
		pNode->val = data[index];
		pNode->left = creatBTree111(data, 2 * index + 1, n);//将二叉树按照层序遍历, 依次标序号, 从0开始
		pNode->right = creatBTree111(data, 2 * index + 2, n);
	}

	return pNode;
}
//
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)return "";
        ostringstream output;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr)output<<"# ";
            else{
                output<<node->val<<" ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return output.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        vector<TreeNode*> nodes;
        string val;
        istringstream input(data);
        while(input>>val){
            if(val == "#")
                nodes.push_back(nullptr);
            else    
                nodes.push_back(new TreeNode(stoi(val)));
        }
        int pos = 1;
        for(int i = 0;i<nodes.size()/2;i++){
            if(nodes[i] == nullptr)continue;
            nodes[i]->left = nodes[2*i+1];
            nodes[i]->right = nodes[2*i+2];
        }
        return nodes[0];
    }
};
//int main() {
//	//int	data[] = {1,2,3,-1,-1,4,5};
//	//[5,2,3,null,null,2,4,3,1]
//	int data[] = {5,2,3,-1,-1,2,4,3,1};
//	TreeNode* test = creatBTree111(data, 0, 9);
//	Codec codec;
//
//	string ss = codec.serialize(test);
//	for (auto i : ss) {
//		cout << i << " ";
//	}
//	cout << endl;
//	//codec.deserialize(codec.serialize(root));
//	TreeNode* res = codec.deserialize(ss);
//	levelordertraver111(res);
//	system("pause");
//	return 0;
//}