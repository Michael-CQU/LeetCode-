#include<iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		stack<int> num;
		stack<string> alp;
		int fig = 0;
		string res = "";
		for (auto i : s) {
			if (i >= '0'&&i <= '9') {
				fig = fig * 10 + (i - '0');
			}
			if ((i >= 'a'&&i <= 'z') || (i >= 'A'&&i <= 'Z')) {
				res = res + i;
			}
			if (i == '[') {
				num.push(fig);
				fig = 0;
				alp.push(res);
				res = "";
			}
			if (i == ']') {
				int k = num.top();
				num.pop();
				while (k) {
					k--;
					alp.top() += res;
				}
				res = alp.top();
				alp.pop();
			}
		}
		return res;
	}
};

//int main() {
//	string test = "3[a]2[bc]";
//	Solution s;
//	string res = s.decodeString(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}