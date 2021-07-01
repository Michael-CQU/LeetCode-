#include<bits/stdc++.h>
using namespace std;
//�ݹ��
template<class T>
void merge_sort(vector<T>& arr) {
	int len = arr.size();
	vector<T> temp(len);//����ʼʱ����һ����ԭʼ����һ�������ʱ���飬�Ӷ������ڵݹ������Ƶ���Ĵ�������
	merge_sort_recursive(arr, temp, 0, len - 1);
}
template<class T>
void merge_sort_recursive(vector<T>& arr, vector<T>& temp, int left, int right) {
	if (left >= right)
		return;
	int pivot = (right - left) / 2 + left;
	int start1 = left, end1 = pivot;
	int start2 = pivot + 1, end2 = right;
	merge_sort_recursive(arr, temp, start1, end1);
	merge_sort_recursive(arr, temp, start2, end2);
	int k = left;
	while (start1 <= end1 && start2 <= end2)
		if (arr[start1] < arr[start2]) {
			temp[k++] = arr[start1++];
		}
		else {
			temp[k++] = arr[start2++];
		}
		while (start1 <= end1)
			temp[k++] = arr[start1++];
		while (start2 <= end2)
			temp[k++] = arr[start2++];
		for (k = left; k <= right; k++) {//��temp�д�left��right�ź����ֵ���ǵ�arr������
			arr[k] = temp[k];
		}
}

//int main() {
//	vector<int> test = {8,4,5,7,1,3,6,2};
//	merge_sort<int>(test);
//	for (auto i : test) {
//		cout << i << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}