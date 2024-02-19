#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void generate(vector<string>& ans, string temp, int left, int right) {
		if (left == 0 && right == 0) {
			ans.emplace_back(temp);
			cout << temp << endl;
			return;
		}
		if (left == right) {
			temp = temp + "(";
			generate(ans, temp, left - 1, right);
			temp.pop_back();
		}
		else {
			if(left > 0) {
			temp = temp + "(";
			generate(ans, temp, left - 1, right);
			temp.pop_back();
		}
				temp = temp + ")";
				generate(ans, temp, left, right - 1);
				temp.pop_back();
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		string temp = "";
		generate(ans, temp, n, n);
		return ans;
	}
};

//int main() {
//	int num = 3;
//	Solution s;
//	vector<string> res = s.generateParenthesis(num);
//	for (auto i : res)
//		cout << i << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}