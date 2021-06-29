#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
//����һ����������
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

////��������
//class Solution {
//public:
//	void max_heapify(vector<int>& arr, int start, int end) {
//		// ���������cָ�˺��ӹ��cָ��
//		int dad = start;
//		int son = dad * 2 + 1;//������ע�⣺�������ʾ���Ļ������ӽڵ���dad * 2 + 1�����ӽڵ���dad * 2 + 2�����Լ���0��ʼ��һ��ͼ�������ˣ�
//		while (son <= end) { // ���ӹ��cָ���ڹ����Ȳ������^
//			if (son + 1 <= end && arr[son] > arr[son + 1]) // �ȱ��^�ɂ��ӹ��c��С���x������
//				son++;
//			if (arr[dad] < arr[son]) // ��������c����ӹ��c�����{���ꮅ��ֱ����������
//				return;
//			else { // ��t���Q���Ӄ������^�m�ӹ��c�͌O���c���^
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