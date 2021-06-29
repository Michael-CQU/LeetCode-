#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
//方法一：快速排序
class Solution {
public:
	int partition(vector<int>& nums, int left, int right) {
		int pivot = nums[left];
		int i = left, j = right;
		while (i < j) {
			while (nums[j] >= pivot&&i < j)
				j--;
			while (nums[i] <= pivot&&i < j)
				i++;
			swap(nums[i], nums[j]);
		}
		swap(nums[i], nums[left]);
		return i;
	}
	int findKthLargest(vector<int>& nums, int k) {
		int len = nums.size();
		int left = 0, right = len - 1;
		int target = len - k;
		while (1) {
			int index = partition(nums, left, right);
			if (index == target) {
				return nums[target];
			}
			else if (index < target) {
				left = index + 1;
			}
			else {
				right = index - 1;
			}
		}
	}
};

////方法二：
//class Solution {
//public:
//	void max_heapify(vector<int>& arr, int start, int end) {
//		// 建立父節點指標和子節點指標
//		int dad = start;
//		int son = dad * 2 + 1;//！！！注意：用数组表示树的话，左子节点是dad * 2 + 1，左子节点是dad * 2 + 2。（自己从0开始画一下图就明白了）
//		while (son <= end) { // 若子節點指標在範圍內才做比較
//			if (son + 1 <= end && arr[son] > arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
//				son++;
//			if (arr[dad] < arr[son]) // 如果父節點大於子節點代表調整完畢，直接跳出函數
//				return;
//			else { // 否則交換父子內容再繼續子節點和孫節點比較
//				swap(arr[dad], arr[son]);
//				dad = son;
//				son = dad * 2 + 1;
//			}
//		}
//	}
//	int findKthLargest(vector<int>& nums, int k) {
//		for (int i = k / 2 - 1; i >= 0; i--) {
//			max_heapify(nums, i, k - 1);
//		}
//		for (int i = k; i < nums.size(); i++) {
//			if (nums[i] > nums[0]) {
//				swap(nums[i], nums[0]);
//				max_heapify(nums, 0, k - 1);
//			}
//		}
//		return nums[0];
//	}
//};

//int main() {
//	vector<int> test = { 2,1 };
//	int k = 2;
//	Solution s;
//	int res = s.findKthLargest(test, k);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}