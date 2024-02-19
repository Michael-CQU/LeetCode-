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
//		// ��ֹ����
//		if (l >= r) return 0;
//		// �ݹ黮��
//		int m = (l + r) / 2;
//		int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
//		// �ϲ��׶�
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
//				res += m - i + 1; // ͳ�������
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
				res += pivot - start1 + 1;//����ڽ�������ʱnums[start1]>nums[start2]ʱ�����γ�pivot-start+1������ԣ���˶����ʱ���γɵ�������ۼӣ����γ������Ľ��
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