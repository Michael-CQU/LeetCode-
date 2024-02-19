#include <bits/stdc++.h>
using namespace std;
//����vector�������ַ���s�е�Ԫ�أ�vector��ֻ�з��ظ�Ԫ�أ��Ӷ�ʹ�õڶ��α�������Ч
class Solution {
public:
	char firstUniqChar(string s) {
		unordered_map<char, bool> mp;
		vector<char> keys;
		for (char i : s) {
			if (mp.find(i) == mp.end()) {
				keys.push_back(i);
				mp[i] = true;
			}
			else
			mp[i] = false;
		}
		for (char i : keys) {
			if (mp[i] == true)
				return i;
		}
		return ' ';
	}
};

//int main() {
//	string test = "leetcode";
//	Solution s;
//	char res = s.firstUniqChar(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}