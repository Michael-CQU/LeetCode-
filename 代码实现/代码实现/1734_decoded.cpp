//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> decode(vector<int>& encoded) {
//		int n = encoded.size(), total = 0;
//		vector<int> perm(n + 1);
//		for (int i = 1; i <= n + 1; i++) {
//			total ^= i;
//		}
//		for (int j = n - 1; j > 0; j = j - 2) {
//			total = total ^ encoded[j];
//		}
//		perm[0] = total;
//		for (int m = 0; m < n; m++) {
//			perm[m + 1] = perm[m] ^ encoded[m];
//		}
//		return perm;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> decode = {3,1};
//	vector<int> result = s.decode(decode);
//	for (auto i : result)
//		cout << i << endl;
//	system("pause");
//	return 0;
//}