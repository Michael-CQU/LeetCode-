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
		string ch = temp;//ע��ch�Ĵ���λ�ã����������ʹ��������ı�������Ҫ�����ֳ��ָ�
		//���Ǳ���Ҫ����ch������ֱ����temp����Ϊtemp����һ����ȫ�֣��Ѿ��޸���temp�ᵼ����һ���temp���ж��Q�����ֺ�˭��ȫ�ֱ�����˭�Ǿֲ�������
		if (u == n) {
			res.push_back(g);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!col[i] && !de[u + i] && !ude[n + i - u])
			{
				//��������ﴴ��ch������ch��forѭ��ĳһ����֧�ı�������mygenerate��ȫ�ֱ�������˲���Ҫ����
				col[i] = de[u + i] = ude[n + i - u] = true;
				ch[i] = 'Q';
				g[u] = ch;
				mygenerate(u + 1, n);
				ch[i] = '.';//�ֲ�����ch�Ļ��Ͳ���Ҫ������
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