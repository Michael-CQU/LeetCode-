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
//		// ���û���κ�һ��Ӳ�����������ܽ����� -1��
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
	// memo[n] ��ʾǮ��n���Ա���ȡ�����ٵ�Ӳ���������ܻ�ȡ��Ϊ-1
	// findWay������Ŀ����Ϊ���ҵ� amount��������Ǯ���Զһ�������Ӳ��������������ֵint
public:
	int findWay(vector<int> coins, int amount) {
		if (amount < 0) {
			return -1;
		}
		if (amount == 0) {
			return 0;
		}
		// ���仯�Ĵ���memo[n]�ø�����ֵ���Ͳ��ü��������ѭ��
		// ֱ�ӵķ���memo[n] ������ֵ
		if (memo[amount - 1] != 0) {
			return memo[amount - 1];
		}
		int min = INT_MAX;
		for (int i = 0; i < coins.size(); i++) {
			int res = findWay(coins, amount - coins[i]);
			if (res >= 0 && res < min) {
				min = res + 1; // ��1����Ϊ�˼��ϵõ�res������Ǹ������У��һ���һ��Ӳ��
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