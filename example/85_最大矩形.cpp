#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)return 0;
        int n = matrix[0].size();
        vector<vector<int>> left(m+1,vector<int>(n+1,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '1'){
                    if(j == 0)
                        left[i][j] = 1;
                    else
                        left[i][j] = left[i][j-1]+1;
                } 
            }
        }
        int res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int w = left[i][j];
                int h = 1;
                int temp = w*h;
                for(int k = i-1;k>=0;k--){
                    w = min(w,left[k][j]);
                    h = i-k+1;
                    temp = max(temp,w*h);
                }
                res = max(res,temp);
            }
        }
        return res;
    }
};

//int main() {
//	vector<vector<char>> test = { {"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"} };
//	Solution s;
//	s.maximalRectangle(test);
//	system("pause");
//}