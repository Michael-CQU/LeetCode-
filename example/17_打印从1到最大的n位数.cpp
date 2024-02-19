#include<bits/stdc++.h>
using namespace std;
//大树打印法（如果数值超过int能表示的最大值，则需用string方法来解决）
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

	// 枚举所有情况
	void dfs(int end, int index) {
		if (index == end) {
			save(); return;
		}
		for (int i = 0; i <= 9; ++i) {
			//方法一：对s的固定位置进行修改
			//s[index] = i + '0';
			//dfs(end, index + 1);
			//方法二：对s的长度进行增加和减小
			s += i + '0';
			dfs(end, index + 1);
			s.pop_back();
		}
	}

	// 去除首部0
	void save() {
		int ptr = 0;
		while (ptr < s.size() && s[ptr] == '0') ptr++;
		if (ptr != s.size())
			nums.emplace_back(stoi(s.substr(ptr)));//substr第一个参数代表起始位置（默认为pos = 0），第二个参数代表终止位置（默认为s.size()-pos），如果只写一个参数，就是起始位置的参数
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