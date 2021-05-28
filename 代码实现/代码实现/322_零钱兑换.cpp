#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//class Solution {
//	int res = INT_MAX;
//public:
//	int coinChange(vector<int> coins, int amount) {
//		if (coins.size() == 0) {
//			return -1;
//		}
//
//		findWay(coins, amount, 0);
//
//		// 如果没有任何一种硬币组合能组成总金额，返回 -1。
//		if (res == INT_MAX) {
//			return -1;
//		}
//		return res;
//	}
//
//public:
//	void findWay(vector<int> coins, int amount, int count) {
//		if (amount < 0) {
//			return;
//		}
//		if (amount == 0) {
//			res = min(res, count);
//		}
//
//		for (int i = 0; i < coins.size(); i++) {
//			findWay(coins, amount - coins[i], count + 1);
//		}
//		cout << amount << "  " <<count << endl;
//	}
//};

class Solution {
	vector<int> memo;
public:
	int coinChange(vector<int> coins, int amount) {
		if (coins.size() == 0) {
			return -1;
		}
		memo.resize(amount);

		return findWay(coins, amount);
	}
	// memo[n] 表示钱币n可以被换取的最少的硬币数，不能换取就为-1
	// findWay函数的目的是为了找到 amount数量的零钱可以兑换的最少硬币数量，返回其值int
public:
	int findWay(vector<int> coins, int amount) {
		if (amount < 0) {
			return -1;
		}
		if (amount == 0) {
			return 0;
		}
		// 记忆化的处理，memo[n]用赋予了值，就不用继续下面的循环
		// 直接的返回memo[n] 的最优值
		if (memo[amount - 1] != 0) {
			return memo[amount - 1];
		}
		int min = INT_MAX;
		for (int i = 0; i < coins.size(); i++) {
			int res = findWay(coins, amount - coins[i]);
			if (res >= 0 && res < min) {
				min = res + 1; // 加1，是为了加上得到res结果的那个步骤中，兑换的一个硬币
			}
		}
		memo[amount - 1] = (min == INT_MAX ? -1 : min);
		return memo[amount - 1];
	}
};
//int main() {
//	vector<int> coins = { 1,2,5 };
//	int amount = 11;
//	Solution s;
//	int result = s.coinChange(coins, amount);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}