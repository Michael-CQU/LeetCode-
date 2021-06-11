#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n1 = word1.size(), n2 = word2.size();
		if (n1*n2 == 0) return n1 + n2;
		int left, down, leftdown;
		vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
		for (int i = 0; i <= n1; i++) {
			dp[i][0] = i;
		}
		for (int j = 0; j <= n2; j++) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n2; j++) {
				left = dp[i - 1][j];
				down = dp[i][j - 1];
				leftdown = dp[i - 1][j - 1];
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = 1 + min(left, min(down, leftdown - 1));
				else
					dp[i][j] = 1 + min(left, min(down, leftdown));
			}
		}
		return dp[n1][n2];
	}
};

//int main(){
//	string word1 = "horse";
//	string word2 = "ros";
//	Solution s;
//	int ans = s.minDistance(word1, word2);
//	cout << ans << endl;
//	system("pause");
//	return 0;
//}