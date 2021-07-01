#include<bits/stdc++.h>
using namespace std;
void myfastsort(vector<int>& nums,int left,int right) {
	if (left>=right)
		return;
	int pivot = nums[left];
	int i = left, j = right;
	while (i < j) {
		while (nums[j] >= pivot&&i<j)
			j--;
		while (nums[i] <= pivot&&i<j)
			i++;
		swap(nums[i], nums[j]);
	}
	swap(nums[left], nums[i]);
	myfastsort(nums,left,i-1);
	myfastsort(nums,i+1,right);
}


class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		quickSort(arr, 0, arr.size() - 1);
		vector<int> res;
		res.assign(arr.begin(), arr.begin() + k);
		return res;
	}
private:
	void quickSort(vector<int>& arr, int l, int r) {
		// �����鳤��Ϊ 1 ʱ��ֹ�ݹ�
		if (l >= r) return;
		// �ڱ����ֲ������� arr[l] ��Ϊ��׼����
		int i = l, j = r;
		while (i < j) {
			while (i < j && arr[j] >= arr[l]) j--;
			while (i < j && arr[i] <= arr[l]) i++;
			swap(arr[i], arr[j]);
		}
		swap(arr[i], arr[l]);
		// �ݹ����ң�������ִ���ڱ�����
		quickSort(arr, l, i - 1);
		quickSort(arr, i + 1, r);
	}
};

//int main() {
//	vector<int> test = { 0,0,2,3,2,1,1,2,0,4 };
//	Solution s;
//	//s.getLeastNumbers(test,10);
//	myfastsort(test, 0, test.size() - 1);
//	for (int i : test) {
//		cout << i << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}