#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) { return s; }//注意考虑numRows == 1的情况
		vector<string> store(numRows);

		int j = 0;
		int flag = 1;
		for (int i = 0; i < s.size(); i++) {
			store[j].push_back(s[i]);//注意如果vector是string，则可以在一个位置上一直向后追加push_back,比如在store[1]位置一直追加字符APLSIIG。(只有string类型可以在vector的指定位置上进行追加操作)
			j += flag;
			if (j == numRows - 1 || j == 0) { flag = -flag; }

		}

		string result;
		for (int i = 0; i < numRows; i++) {
			result = result + store[i];
		}

		return result;
	}
};

//int main() {
//	string test = "ABCD";
//	Solution s;
//	string res = s.convert(test, 1);
//	system("pause");
//	return 0;
//}