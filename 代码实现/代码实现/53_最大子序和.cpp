#include<bits/stdc++.h>
using namespace std;
/*动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (auto x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
*/

/*贪心算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
               if(nums.size() == 1){
            return nums[0];
        }
       int maxSubArray = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            //sum要想有资格继续壮大 就必须大于 0 否则还不如恢复0
            sum = max(sum,0);
            sum += nums[i];
            //maxSubArray始终取最大值
            maxSubArray = max(sum,maxSubArray);
        }
        return maxSubArray;
    }
};
*/
//线段树
class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};