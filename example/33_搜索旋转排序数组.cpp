#include<bits/stdc++.h>
using namespace std;

//����һ��������153�⣬���ҵ��ֽ�㣬���������������ó�����ַ�
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

//��������������һ��Ϊ��������һ����һ��������ģ���һ������������Ҳ���ǲ������򡣴�ʱ���򲿷��ö��ַ����ҡ����򲿷���һ��Ϊ��������һ��һ��������һ���������򣬿������򡣾�����ѭ��. 
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