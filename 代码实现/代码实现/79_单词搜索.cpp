#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

	bool exist1(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));


		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (dfs(i, j, 0, board, word, visited))
					return true;
			}
		}
		return false;
	}

	bool dfs(int x, int y, int index, vector<vector<char>>& board, string &word, vector<vector<bool>>& visited) {
		if (index == word.size() - 1) {
			return word[index] == board[x][y];
		}

		if (word[index] == board[x][y]) {
			visited[x][y] = true;
			for (int i = 0; i < 4; i++) {
				int new_x = x + dir[i][0];
				int new_y = y + dir[i][1];

				if (new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[0].size() && !visited[new_x][new_y])
					if (dfs(new_x, new_y, index + 1, board, word, visited))
						return true;
			}
			visited[x][y] = false;

		}
		return false;
	}
};

//int main() {
//	vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
//	string ss = "ABCCED";
//	Solution s;
//	bool res = s.exist1(board,ss);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}