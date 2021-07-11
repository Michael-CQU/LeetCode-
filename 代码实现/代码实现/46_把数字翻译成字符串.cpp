#include<iostream>
#include <string>
#include <vector>
using namespace std;
//ѭ���Ĵ�����num��λ�������ʱ�佥�����Ӷ�ΪO��logn��
class Solution {
public:
	int translateNum(int num) {
		string s;
		s = to_string(num);
		int n = s.size();
		vector<int> dp(n + 1);
		dp[0] = 1;//ע��������ֵ��������dp[2]�������ɵ�ֵ��10-25֮�䣬��Ҫ��dp[0]+dp[1] = 2�Ƶ�����
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];
			if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0')) < 26)
				dp[i] += dp[i - 2];
		}
		return dp[n];
	}
};
//ע����Ϊdp[i]ֻ��dp[i-1]��dp[i-2]�йأ���˿��������������򻯶�̬�滮���飬Ҳ����������������ɹ������顣

//int main() {
//	int num = 25;
//	Solution s;
//	int res = s.translateNum(num);
//}