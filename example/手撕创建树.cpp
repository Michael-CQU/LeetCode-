#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Treenode {
	int val;
	Treenode* left;
	Treenode* right;
	Treenode() :val(-1), left(nullptr), right(nullptr) {}
	Treenode(int x) :val(x), left(nullptr), right(nullptr) {}
};

Treenode* Buildmytree(vector<int>& test, int idx, int n) {
	Treenode* node = nullptr;
	if (idx < n) {
		node = new Treenode();
		node->val = test[idx];
		node->left = Buildmytree(test, 2 * idx + 1, n);
		node->right = Buildmytree(test, 2 * idx + 2, n);
	}
	return node;
}
void mylevelorder(Treenode* head) {
	queue<Treenode*> q;
	q.push(head);
	while (!q.empty()) {
		Treenode* temp = q.front();
		q.pop();
		cout << temp->val;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	cout << endl;
}
//int main() {
//	int n;
//	cin >> n;
//	vector<int> test(n);
//	for (int i = 0; i < n; i++) {
//		cin >> test[i];
//	}
//	Treenode* res = Buildmytree(test, 0, n);
//	mylevelorder(res);
//	system("pause");
//	return 0;
//}