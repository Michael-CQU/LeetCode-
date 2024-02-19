#include<bits/stdc++.h>
using namespace std;
//������ӡ���������ֵ����int�ܱ�ʾ�����ֵ��������string�����������
class Solution {
private:
	vector<int> nums;
	string s;
public:
	vector<int> printNumbers(int n) {
		s.resize(n, '0');
		dfs(n, 0);
		return nums;
	}

	// ö���������
	void dfs(int end, int index) {
		if (index == end) {
			save(); return;
		}
		for (int i = 0; i <= 9; ++i) {
			//����һ����s�Ĺ̶�λ�ý����޸�
			//s[index] = i + '0';
			//dfs(end, index + 1);
			//����������s�ĳ��Ƚ������Ӻͼ�С
			s += i + '0';
			dfs(end, index + 1);
			s.pop_back();
		}
	}

	// ȥ���ײ�0
	void save() {
		int ptr = 0;
		while (ptr < s.size() && s[ptr] == '0') ptr++;
		if (ptr != s.size())
			nums.emplace_back(stoi(s.substr(ptr)));//substr��һ������������ʼλ�ã�Ĭ��Ϊpos = 0�����ڶ�������������ֹλ�ã�Ĭ��Ϊs.size()-pos�������ֻдһ��������������ʼλ�õĲ���
	}
};

//int main() {
//	Solution s;
//	vector<int> ans = s.printNumbers(3);
//	for (int i : ans) {
//		cout << i << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}