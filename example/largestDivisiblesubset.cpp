//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> largestDivisibleSubset(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		int n = nums.size();
//		vector<int> f(n, 0);
//		vector<int> g(n, 0);
//
//		for (int i = 0; i < n; i++) {
//			// 至少包含自身一个数，因此起始长度为 1，由自身转移而来
//			int len = 1, prev = i;
//			for (int j = 0; j < i; j++) {
//				if (nums[i] % nums[j] == 0) {
//					cout << "内循环" << j << "次： ";
//					cout << "nums[i] = " << nums[i] << "  ";
//					cout << "nums[j] = " << nums[j] << "  ";
//					cout << endl;
//					// 如果能接在更长的序列后面，则更新「最大长度」&「从何转移而来」
//					if (f[j] + 1 > len) {
//						len = f[j] + 1;
//						prev = j;
//
//						cout << "j = " << j << "  ";
//						cout << "f[j] = " << f[j] << "  ";
//						cout << "len = " << len << "  ";
//						cout << "prev = " << prev;
//						cout << endl;
//					}
//				}
//			}
//			f[i] = len;
//			g[i] = prev;
//			cout << "外循环" << i << "次： ";
//			cout << "f[i] = " << f[i] << "  ";
//			cout << "g[i] = " << g[i] << "  ";
//			cout << endl;
//		}
//
//		// 遍历所有的 f[i]，取得「最大长度」和「对应下标」
//		int idx = max_element(f.begin(), f.end()) - f.begin();
//		int max = f[idx];
//
//		// 使用 g[] 数组回溯出具体方案
//		vector<int> ans;
//		while (ans.size() != max) {
//			ans.push_back(nums[idx]);
//			idx = g[idx];
//		}
//		return ans;
//	}
//};
//
//int main() {
//	vector<int> nums = {9,18,54,90,108,180,360,540,720};
//	Solution s;
//	vector<int> result = s.largestDivisibleSubset(nums);
//	system("pause");
//	return 0;
//}