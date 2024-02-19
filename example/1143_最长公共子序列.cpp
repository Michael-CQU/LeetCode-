#include<bits/stdc++.h>
using namespace std;
//����������������п����ǲ������ģ������飨���ַ�������Ҫ�������ģ�
//��̬�滮Ҳ������·�ģ�������������ַ���Ҫ�ö�̬�滮ʱ�����԰Ѷ�̬�滮 dp[i] ����Ϊ nums[0:i] ����Ҫ��Ľ������������������ַ���Ҫ�ö�̬�滮ʱ�����԰Ѷ�̬�滮�������ά�� dp[i][j] ���京������ A[0:i] �� B[0:j] ֮��ƥ��õ�����Ҫ�Ľ����
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int M = text1.size(), N = text2.size();
		vector<vector<int>> dp(M+1, vector<int>(N+1, 0));//dp[i][j]�ĺ�����text1[0:i-1] �� text2[0:j-1] ������������С�dp[i][j] �Ķ��岻�� text1[0:i] �� text2[0:j] ����Ϊ�˷��㵱 i = 0 ���� j = 0 ��ʱ��dp[i][j]��ʾ��Ϊ���ַ���������һ���ַ�����ƥ�䣬���� dp[i][j] ���Գ�ʼ��Ϊ 0.
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[M][N];
	}
};

//int main() {
//	string test1 = "ace";
//	string test2 = "bc";
//	Solution s;
//	int res = s.longestCommonSubsequence(test1, test2);
//	cout << res << endl;
//	return 0;
//}