#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int matrixsum(vector<vector<int>> nums,int x1,int y1,int x2,int y2) {
		int m = nums.size(), n = nums[0].size();
		vector<vector<int>> presum(m+1,vector<int>(n+1,0));
		int res = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + nums[i-1][j-1];
			}
		}
		res = presum[x2][y2] - presum[x1 - 1][y2] - presum[x2][y1 - 1] + presum[x1 - 1][y1 - 1];
		return res;
	}
};

//int main() {
//	int n = 0, m = 0,q = 0;
//	cin >> n >> m>>q;
//	vector<vector<int>> test(n, vector<int>(m));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> test[i][j];
//		}
//	}
//	Solution s;
//	while (q--) {
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		int res = s.matrixsum(test,x1,y1,x2,y2);
//		cout << res << endl;
//	}
//	system("pause");
//	return 0;
//}