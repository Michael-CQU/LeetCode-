#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> ans;
		queue<Node*> q;
		if (root == nullptr) return ans;
		q.push(root);
		while (!q.empty()) {
			vector<int> temp;
			int num = q.size();
			for (int i = 0; i < num; i++) {
				Node* node = q.front();
				q.pop();
				temp.push_back(node->val);
				for (int j = 0; j < node->children.size(); j++)
					if (node->children[j]) {
						q.push(node->children[j]);
					}
			}
			ans.push_back(temp);
		}
		return ans;
	}
};