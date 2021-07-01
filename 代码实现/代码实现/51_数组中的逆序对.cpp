#include<bits/stdc++.h>
using namespace std;

//class Solution {
//public:
//	int reversePairs(vector<int>& nums) {
//		vector<int> tmp(nums.size());
//		return mergeSort(0, nums.size() - 1, nums, tmp);
//	}
//private:
//	int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
//		// 终止条件
//		if (l >= r) return 0;
//		// 递归划分
//		int m = (l + r) / 2;
//		int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
//		// 合并阶段
//		int i = l, j = m + 1;
//		for (int k = l; k <= r; k++)
//			tmp[k] = nums[k];
//		for (int k = l; k <= r; k++) {
//			if (i == m + 1)
//				nums[k] = tmp[j++];
//			else if (j == r + 1 || tmp[i] <= tmp[j])
//				nums[k] = tmp[i++];
//			else {
//				nums[k] = tmp[j++];
//				res += m - i + 1; // 统计逆序对
//			}
//		}
//		return res;
//	}
//};



class Solution {
public:
	int res = 0;
	void mymergesort(vector<int>& nums, vector<int>& temp, int left, int right) {
		if (left >= right)return;
		int pivot = (right - left) / 2 + left;
		int start1 = left, end1 = pivot;
		int start2 = pivot + 1, end2 = right;
		mymergesort(nums, temp, start1, end1);
		mymergesort(nums, temp, start2, end2);
		int k = left;
		while (start1 <= end1&&start2 <= end2) {
			if (nums[start1] <= nums[start2])
				temp[k++] = nums[start1++];
			else {
				temp[k++] = nums[start2++];
				res += pivot - start1 + 1;//如果在进行排序时nums[start1]>nums[start2]时，会形成pivot-start+1个逆序对，因此对这个时候形成的逆序对累加，就形成了最后的结果
			}
		}
		while (start1 <= end1)
			temp[k++] = nums[start1++];
		while (start2 <= end2)
			temp[k++] = nums[start2++];
		//res += pivot - start1 + 1;
		for (int k = left; k <= right; k++) {
			nums[k] = temp[k];
		}
	}
	int reversePairs(vector<int>& nums) {
		vector<int> temp(nums.size());
		mymergesort(nums, temp, 0, nums.size() - 1);
		return res;
	}
};
//int main() {
//	vector<int> test = {7,3,2,6,0,1,5,4};
//	//vector<int> test = { 7,5,6,4 };
//	Solution s;
//	int ans = s.reversePairs(test);
//	cout << ans << endl;
//	system("pause");
//	return 0;
//}