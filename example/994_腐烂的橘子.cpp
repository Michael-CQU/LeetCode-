#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
		int m = grid.size(), n = grid[0].size();
		int count = 0;//好橘子的个数
		queue<pair<int, int>> q;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					count++;
				}
				if (grid[i][j] == 2) {
					q.push(make_pair(i, j));
				}
			}
		}
		int res = 0;
		while (count>0&&!q.empty()) {
			res++;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				pair<int, int> temp = q.front();
				q.pop();
				for (int j = 0; j < 4; j++) {
					int new_x = temp.first + dir[j][0];
					int new_y = temp.second + dir[j][1];
					if (new_x >= 0 && new_x < m&&new_y >= 0 && new_y < n&&grid[new_x][new_y] == 1) {
						count--;
						grid[new_x][new_y] = 2;
						q.push(make_pair(new_x, new_y));
					}
				}
			}
		}
		if (count == 0)
			return res;
		else
			return -1;
	}
};

//int main() {
//	vector<vector<int>> grid = { {2,1,1}, {1,1,0}, {0,1,1} };
//	//vector<vector<int>> grid = { {2},{1}};
//	Solution s;
//	int res = s.orangesRotting(grid);
//	cout << res << endl;
//	system("pause");
//}