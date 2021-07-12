#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;
const int N = 1e5;

class Solution {
public:
	int longestsubstr(vector<int> nums) {
		int n = nums.size();
		vector<int> temp(N);
		int res = 0;
		for (int i = 0,j = 0; i < n; i++) {
			temp[nums[i]]++;
			while (temp[nums[i]] > 1) {
				temp[nums[j]]--;
				j++;
			}
			res = max(res, i - j + 1);
		}
		return res;
	}
};

//int main() {
//	int n = 0;
//	cin >> n;
//	vector<int> test(n);
//	for (int i = 0; i < n; i++) {
//		cin >> test[i];
//	}
//	Solution s;
//	int res = s.longestsubstr(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}