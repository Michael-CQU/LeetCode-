#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//DFS
//class Solution {
//public:
//    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
//    void mygenerate(vector<vector<char>>& grid,int i,int j,int m,int n){
//        grid[i][j] = '2';
//        for(int q = 0;q<4;q++){
//            int new_x = i+dir[q][0];
//            int new_y = j+dir[q][1];
//            if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n&&grid[new_x][new_y] == '1')
//                mygenerate(grid,new_x,new_y,m,n);
//        }
//    }
//    int numIslands(vector<vector<char>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        int count = 0;
//        for(int i = 0;i<m;i++){
//            for(int j = 0;j<n;j++){
//                if(grid[i][j] == '1'){
//                    count++;
//                    mygenerate(grid,i,j,m,n);
//                }
//            }
//        }
//        return count;
//    }
//};


//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    count++;
                    grid[i][j] = '2';
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair<int,int> temp = q.front();
                        q.pop();
                        for(int d = 0;d<4;d++){
                            int new_x = i+dir[d][0];
                            int new_y = j+dir[d][1];
							if (new_x >= 0 && new_x < m&&new_y >= 0 && new_y < n&&grid[new_x][new_y] == '1')
								q.push(make_pair(new_x,new_y));
                        }
                    }
                }
            }
        } 
        return count;
    }
};

//int main() {
//	vector<vector<char>> test = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
//	//vector<vector<char>> test = { { '1' } };
//	Solution s;
//	int res = s.numIslands(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}