#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n)));
		int buy1 = -prices[0], sell1 = 0;
		int buy2 = -prices[0], sell2 = 0;
		for (int i = 1; i < n; ++i) {
			buy1 = max(buy1, -prices[i]);
			sell1 = max(sell1, buy1 + prices[i]);
			buy2 = max(buy2, sell1 - prices[i]);
			sell2 = max(sell2, buy2 + prices[i]);
		}
		return sell2;
	}
};
//int main() {
//	vector<int> test = { 3,3,5,0,0,3,1,4 };
//	Solution s;
//	int res = s.maxProfit(test);
//	system("pause");
//	return 0;
//}