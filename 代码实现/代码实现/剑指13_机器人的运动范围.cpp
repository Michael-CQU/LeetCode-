#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } };
	int bitnum(int m) {
		int sum = 0;
		while (m != 0) {
			sum += m % 10;
			m /= 10;
		}
		return sum;
	}
	int generate(vector<vector<int>>& visited, int m, int n, int k, int i, int j, int& count) {
		if (i >= m || j >= n || visited[i][j] || bitnum(i) + bitnum(j) > k)
			return 0;
		visited[i][j] = 1;
		count++;
		for (int a = 0; a < 4; a++) {
			int new_i = i + dir[a][0];
			int new_j = j + dir[a][1];
			if (new_i >= 0 && new_i < m&&new_j >= 0 && new_j < n)
				generate(visited, m, n, k, new_i, new_j, count);
		}
		return count;
	}
	int movingCount(int m, int n, int k) {
		vector<vector<int>> visited(m, vector<int>(n));
		int count = 0;
		return generate(visited, m, n, k, 0, 0, count);
	}
};

//int main() {
//	Solution s;
//	int res = s.movingCount(1,2,1);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}