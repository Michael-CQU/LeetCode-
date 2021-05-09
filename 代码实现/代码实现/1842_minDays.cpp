#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		int n = bloomDay.size();
		if (n < m * k)
			return -1;
		int left = 1, right = *max_element(bloomDay.begin(),bloomDay.end());

		while(left < right) {
			int mid = left + (right - left) / 2;
			if (canMake(bloomDay,mid,m,k)) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
	bool canMake(vector<int> bloomDay, int days, int m, int k) {
		int bunch = 0;
		int flowers = 0;
		for (int j = 0; j < bloomDay.size(); j++) {
			if (bloomDay[j] <= days) {
				flowers++;
				if (flowers == k) {
					bunch++;
					flowers = 0;
				}
			}
			else {
				flowers = 0;
			}
		}
		return bunch >= m;
	}
};

int main() {
	Solution s;
	vector<int> bloomday = { 7,7,7,7,12,7,7 };
	int result = s.minDays(bloomday,2,3);
	cout << result << endl;
	system("pause");
	return 0;
}