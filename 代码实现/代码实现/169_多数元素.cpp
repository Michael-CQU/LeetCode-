////����˼·����һ����ϣ��
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
////Ħ��ͶƱ����ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1��
////�Ա���������ͬ���++���������˾�--�������������һ���Ƕ���Ԫ�أ���Ϊ���Ԫ��������
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