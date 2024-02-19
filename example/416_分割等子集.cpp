#include<bits/stdc++.h>
using namespace std;

//¶þÎ¬
//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        int n = nums.size();
//        int sum = 0;
//        for(int i = 0;i<n;i++){
//            sum+=nums[i];
//        }
//        if(sum%2 == 1)return false;
//        int target = sum/2;
//        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
//        for(int j = nums[0];j<target+1;j++){
//            dp[0][j] = nums[0];
//        }
//        for(int i = 1;i<n;i++){
//            for(int j = 0;j<=target;j++){
//                if(j-nums[i]<0)
//                    dp[i][j] = dp[i-1][j];
//                else 
//                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i]);
//            }
//        }
//        if(dp[n-1][target] == target)
//            return true;
//        else
//            return false;
//    }
//};

//Ò»Î¬
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 == 1)return false;
        int target = sum/2;
        vector<int> dp(target+1,0);

        for(int i = 0;i<n;i++){
            for(int j = target;j>=nums[i];j--){
                    dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[target] == target)
            return true;
        else
            return false;
    }
};
//int main() {
//	Solution s;
//	vector<int> input = {1,5,11,5};
//	s.canPartition(input);
//	system("pause");
//}