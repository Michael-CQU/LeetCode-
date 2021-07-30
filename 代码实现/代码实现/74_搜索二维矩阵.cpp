#include<bits/stdc++.h>
using namespace std;
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size(), n = matrix[0].size();
//        int up = 0,down = m-1;
//        while(up<down){
//            int mid = (down-up+1)/2+up;
//            if(matrix[mid][0]<=target)
//                up = mid;
//            else
//                down = mid-1;
//        }
//        int left = 0,right = n-1;
//        while(left<right){
//            int mid = (right-left+1)/2+left;
//            if(matrix[up][mid]<=target)
//                left = mid;
//            else
//                right = mid-1; 
//        }
//        if(matrix[up][left] == target)
//            return true;
//        else
//            return false;
//    }
//};

//Ð´ÔÚÒ»Æð
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        int left = 0,right = m*n-1;
        while(left<right){
            int mid = (right-left+1)/2+left;
            if(matrix[mid/n][mid%n]<=target)
                left = mid;
            else
                right = mid -1;
        }
        if(matrix[left/n][left%n] == target)
        return true;
        else
        return false;
    }
};
//int main() {
//	//vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
//	vector<vector<int>> matrix = {{1}, {3}};
//	int target = 3;
//	Solution s;
//	bool res = s.searchMatrix(matrix, target);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}