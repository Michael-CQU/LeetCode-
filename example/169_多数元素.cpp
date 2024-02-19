////常规思路：用一个哈希表
//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        int n = nums.size();
//        unordered_map<int,int> mp;
//        int res = nums[0],count = 0;
//        for(int i =0;i<n;i++){
//            mp[nums[i]]++;
//            if(mp[nums[i]]>count){
//                res = nums[i];
//                count = mp[nums[i]];
//            }
//        }
//        return res;
//    }
//};
//
////摩尔投票法：时间复杂度O（n），空间复杂度O（1）
////对比两个数，同伙就++，其他敌人就--，最后留下来的一定是多数元素，因为这个元素数量多
//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        int n = nums.size();
//        int res = nums[0];
//        int count = 1;
//        for(int i = 1;i<n;i++){
//            if(res == nums[i])
//                count++;
//            else
//                count--;
//            if(count<0){
//                res = nums[i];
//                count = 1;
//            }
//        }
//        return res;
//    }
//};