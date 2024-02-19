#include<bits/stdc++.h>
using namespace std;

//方法一：类似于153题，先找到分界点，再在两段区间内用常规二分法
class Solution {
public:
    int findpivot(vector<int>& nums){
        int n = nums.size();
        int left = 0,right = n-1;
        while(left<right){
            int mid = (right-left)/2+left;
            if(nums[mid]<=nums[right]){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
    int myfind(vector<int>& nums, int left,int right,int target){
        while(left<right){
            int mid = (right-left)/2+left;
            if(nums[mid]<target)
                left = mid+1;
            else
                right = mid;
        }
        if(nums[left] == target)
            return left;
        else
            return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = findpivot(nums);
        if(target>nums[nums.size()-1])
            return myfind(nums,0,pivot-1,target);
        else
            return myfind(nums,pivot,nums.size()-1,target);
    }
};

//方法二：将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环. 
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int n = nums.size();
//        int left = 0,right = n-1;
//        while(left<right){
//            int mid = (right-left)/2+left;
//            if(nums[mid]<=nums[right]){
//                if(nums[mid]<target&&target<=nums[right]){
//                    left = mid + 1;
//                }
//                else{
//                    right = mid;
//                }
//            }
//            else{
//                if(nums[left]<=target&&target<=nums[mid]){
//                    right = mid;
//                }
//                else{
//                    left = mid + 1;
//                }
//            }
//        }
//        if(nums[left] == target)
//            return nums[left];
//        else
//            return -1;
//    }
//};