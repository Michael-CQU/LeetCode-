#include <bits/stdc++.h>
using namespace std;
/*
10
1 1
1 3
2 2
3 5
4 1
5 3
6 1
6 3
7 2
1 13
*/
//int main(int argc, char *argv[]) {
//		int n;
//		cin >> n;
//		vector<vector<long long>> nums(n, vector<long long>(2, 0));
//		int x, y;
//		for (int i = 0; i < n; ++i) {
//			cin >> x >> y;
//			nums[i][0] = x;
//			nums[i][1] = x+y;
//		}
//
//		vector<pair<long long, int>> res;
//		for (int i = 0; i < n; ++i) {
//			res.push_back({nums[i][0], 1});					/**<上车 */
//			res.push_back({nums[i][1], -1});				/**<下车 */
//		}
//		sort(res.begin(), res.end());						/**<按照时间点排序 */
//
//		int ans = 0;
//		int output = 0;
//		for (const auto& e : res) {
//			ans += e.second;
//			output = max(output, ans);						/**<公交车上最多的乘客 */
//		}
//		cout << output << endl;
//		system("pause");
//}


#if 0
1
2
1 2
2 3
output
2

#endif