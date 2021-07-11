#include<bits/stdc++.h>
using namespace std;
//ע��������һ��ֻ����if�жϣ�������if-else����ΪҲ����Щֵ����2�ı�������3����5�ı���
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n);
		dp[0] = 1;
		int a = 0, b = 0, c = 0;
		for (int i = 1; i < n; i++) {
			int n1 = dp[a] * 2, n2 = dp[b] * 3, n3 = dp[c] * 5;
			dp[i] = min(n1, min(n2, n3));
			if (dp[i] == n1)
				a++;
			if (dp[i] == n2)
				b++;
			if (dp[i] == n3)
				c++;
		}
		return dp[n - 1];
	}
};