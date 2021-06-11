#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
	bool generate(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y) {
		if (grid[x][y] == '1') {
			grid[x][y] = '2';
			visited[x][y] = 1;
			for (int m = 0; m < 4; m++) {
				int new_x = x + dir[m][0];
				int new_y = y + dir[m][1];
				if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() && !visited[new_x][new_y])
					generate(grid, visited, new_x, new_y);
			}
			visited[x][y] = 0;
			return true;
		}
		return false;
	}
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int count = 0;
		vector<vector<int>> visited(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (generate(grid, visited, i, j))
					count++;
			}
		}
		return count;
	}
};

//int main() {
//	//vector<vector<char>> test = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
//	vector<vector<char>> test = { { '1' } };
//	Solution s;
//	int res = s.numIslands(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}