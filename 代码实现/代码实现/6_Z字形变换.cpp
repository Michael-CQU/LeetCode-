#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) { return s; }//ע�⿼��numRows == 1�����
		vector<string> store(numRows);

		int j = 0;
		int flag = 1;
		for (int i = 0; i < s.size(); i++) {
			store[j].push_back(s[i]);//ע�����vector��string���������һ��λ����һֱ���׷��push_back,������store[1]λ��һֱ׷���ַ�APLSIIG��(ֻ��string���Ϳ�����vector��ָ��λ���Ͻ���׷�Ӳ���)
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