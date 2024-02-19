#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<int> col, de, ude;
	vector<string> g;
	vector<vector<string>> res;
	string temp = "";
public:
	vector<vector<string>> solveNQueens(int n) {
		col.resize(n);
		de.resize(2 * n), ude.resize(2 * n);
		for (int j = 0; j < n; j++) {
			temp += '.';
		}
		for (int i = 0; i < n; i++) {
			g.push_back(temp);
		}
		mygenerate(0, n);
		return res;
	}
	void mygenerate(int u, int n) {
		string ch = temp;//注意ch的创建位置，如果在这里就代表是这层的变量，需要进行现场恢复
		//但是必须要创建ch，不能直接用temp，因为temp又是一个大全局，已经修改了temp会导致下一层的temp会有多个Q（区分好谁是全局变量，谁是局部变量）
		if (u == n) {
			res.push_back(g);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!col[i] && !de[u + i] && !ude[n + i - u])
			{
				//如果在这里创建ch，代表ch是for循环某一个分支的变量，非mygenerate的全局变量，因此不需要回退
				col[i] = de[u + i] = ude[n + i - u] = true;
				ch[i] = 'Q';
				g[u] = ch;
				mygenerate(u + 1, n);
				ch[i] = '.';//局部创建ch的话就不需要回退了
				g[u] = ch;
				col[i] = de[u + i] = ude[n + i - u] = false;
			}
		}
	}
};

//int main() {
//	Solution s;
//	int n;
//	cin >> n;
//	vector<vector<string>> ans = s.solveNQueens(n);
//	for (auto i : ans) {
//		for (auto j : i)
//			cout << j << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}