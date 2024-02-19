#include<bits/stdc++.h>
using namespace std;
//方法一：基于二分搜索进行查询，时间复杂度为m*log(n)
//class Solution {
//public:
//	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//		if (matrix.empty()||matrix[0].size() == 0)return false;
//		int m = matrix.size();
//		int n = matrix[0].size();
//		for (int i = 0; i<m&&target>=matrix[i][0]; i++) {
//			int left = 0, right = n - 1;
//			while (left < right) {
//				int mid = (right - left) / 2 + left;
//				if (matrix[i][mid] < target)
//					left = mid + 1;
//				else
//					right = mid;
//			}
//			if (matrix[i][left] == target) {
//				return true;
//			}
//		}
//		return false;
//	}
//};
//方法二：
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {//通过对行和列的排除来逼近要求的值
		int row = matrix.size() - 1;
		int col = 0;
		while (row >= 0 && col < matrix[0].size()) {
			if (matrix[row][col] > target) {
				row--;
			}
			else if (matrix[row][col] < target) {
				col++;
			}
			else {
				return true;
			}
		}
		return false;
	}
};

//int main() {
//	vector<vector<int>> test = { {1,4,7,11,15 }, {2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
//	//vector<vector<int>> test = { {} };
//	int target = 5;
//	Solution s;
//	bool res = s.findNumberIn2DArray(test,target);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}