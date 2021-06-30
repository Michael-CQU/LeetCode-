#include <bits/stdc.h>

using namespace std;
class Solution {
public:
	void generate(vector<string>& ans,vector<int>& used,string s,string& temp,int i,int n) {
		if (i == n) {
			ans.push_back(temp);
			return;
		}
		for (int j = 0; j < n; j++) {
			if (used[j] || (j > 0 && s[j - 1] == s[j] && used[j - 1] == false)) {
				continue;
			}
			used[j] = 1;
			temp += s[j];
			generate(ans, used, s, temp, i+1, n);
			temp.pop_back();
			used[j] = 0;
		}
	}
	vector<string> permutation(string s) {
		int n = s.size();
		vector<string> ans;
		string temp;
		vector<int> used(n,0);
		sort(s.begin(),s.end());
		generate(ans,used,s,temp,0,n);
		return ans;
	}
};

//int main() {
//	string test = "aab";
//	Solution s;
//	vector<string> res = s.permutation(test);
//	for (auto i : res) {
//		cout << i << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}