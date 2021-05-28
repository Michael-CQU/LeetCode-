#include <iostream>
using namespace std;
//���ֲ�������
//void binaryinsertsoft(int arr[],int n) {
//	for (int i = 1; i < n; i++) {
//		int left = 0, right = i - 1;
//		int key = arr[i];
//		while (left < right) {
//			int mid = (right + left) / 2;
//			if (arr[i] > arr[mid])
//				left = mid + 1;
//			else
//				right = mid;
//		}
//		for (int j = i - 1; j >=right; j--) {
//			arr[j + 1] = arr[j];
//		}
//		arr[right] = key;
//	}
//}

//������
//void heapify(int arr[], int head, int n) {
//	if (head < n / 2) {
//		int maxinum = head;
//		int left = 2*head + 1;
//		int right = 2*head + 2;
//		if (arr[left] > arr[maxinum] && left < n)
//			maxinum = left;
//		if (arr[right] > arr[maxinum]&&right < n) 
//			maxinum = right;
//			if (maxinum != head)
//			{
//				swap(arr[maxinum], arr[head]);
//				heapify(arr, maxinum, n);
//			}
//		}
//}
//
//void heapsort1(int arr[], int n) {
//	for (int i = (n / 2 - 1); i >= 0; i--) {
//		heapify(arr, i, n);
//	}
//	for (int i = (n - 1); i >=0; i--) {
//		swap(arr[0],arr[i]);
//		heapify(arr,0,i);
//	}
//}
////�鲢���򣨷ǵݹ飩
//void merge_array(int arr[], int arr1[], int ls1, int rs1, int n) {//���ںϲ�
//	//����һ��k��ls1��ʼ
//	//int i = ls1, j = rs1, k = ls1;
//	//������:ע��k�����Ǵ�0��ʼ����Ϊ�뷽��1��ͬ��arr1�������ڱ���ϲ�����������
//	int i = ls1, j = rs1, k = 0;
//	while (i < rs1&&j < n + 1) {
//		if (arr[i] < arr[j]) {
//			arr1[k++] = arr[i++];
//		}
//		else
//			arr1[k++] = arr[j++];
//	}
//	while (i < rs1)
//		arr1[k++] = arr[i++];
//	while (j < n + 1)
//		arr1[k++] = arr[j++];
//	//��������ÿ�ι鲢ʱ�򣬽����������ظ�����arr��ȷ��������ֵ������arr��
//	{
//	k = 0;
//	while(ls1 <= n)
//	arr[ls1++] = arr1[k++];
//	}
//}
//
//void merge_k(int arr[], int arr1[], int k, int n) {//����ѭ�����й̶�kֵ��ĺϲ�
//	int i = 0;
//	int j;
//	while (i < n - 2 * k + 1) {
//		merge_array(arr, arr1, i, i + k, i + 2 * k - 1);
//		i += 2 * k;
//	}
//	if (i < n - k) {
//		merge_array(arr, arr1, i, i + k, n - 1);
//	}
//	else
//		for (j = i; j < n; j++)
//			arr1[j] = arr[j];
//}
//
//bool mergesort_NR(int arr[],int n) {//����ȷ���Զ���kֵ���кϲ�
//	int k = 1;
//	int *arr1 = new int[n];
//	if (arr == NULL)
//		return false;
//	while (k<n) {
//		merge_k(arr,arr1,k,n);
//		k *= 2;
//		//��������ע�����´���
//		//{
//		//	merge_k(arr1, arr, k, n);
//		//	k *= 2;
//		//}
//	}
//	delete[]arr1;
//	return true;
//}
void quicksort1(int arr[],int left,int right) {
	if (left >= right)
		return;
	int i = left, j = right-1;
	int key = arr[left];
	while (i < j) {
		while (arr[j] >= key&&i < j)
			j--;
		while (arr[i] <= key&&i < j)
			i++;
		swap(arr[i], arr[j]);
	}
	//if (arr[left] >= arr[right-1])
	//	std::swap(arr[left], arr[right-1]);
	//else
	//	left++;
	arr[left] = arr[i];
	arr[i] = key;
	quicksort1(arr, left,i);
	quicksort1(arr, i + 1, right);
}

struct Range {
	int start, end;
	Range(int s = 0, int e = 0) {
		start = s, end = e;
	}
};
template <typename T> // �������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O��"С�"(<)��"���"(>)��"��С�"(>=)���\���ӹ���
void quick_sort2(T arr[], const int len) {
	if (len <= 0)
		return; // ����len���ֵؓ�r����ѯB��Ю��C
				// r[]ģ�M�ѯB,p�锵��,r[p++]��push,r[--p]��pop��ȡ��Ԫ��
	Range r[len];
	int p = 0;
	r[p++] = Range(0, len - 1);
	while (p) {
		Range range = r[--p];
		if (range.start >= range.end)
			continue;
		T mid = arr[range.start];
		int left = range.start, right = range.end - 1;
		while (left < right) {
			while (arr[right] >= mid && left < right) right--;
			while (arr[left] <= mid && left < right) left++;
			std::swap(arr[left], arr[right]);
		}
		//if (arr[left] >= arr[range.end])
		//	std::swap(arr[left], arr[range.end]);
		//else
		//	left++;
		r[p++] = Range(range.start, left);
		r[p++] = Range(left + 1, range.end);
	}
}

int main() {
	int arr[] = {9,1,5,4,6,7,3,2,5,8};
	//int arr[] = {1,3,5,7,9,2,4,6,8 };
	//int arr1[9];
	int n = sizeof(arr) / sizeof(int);
	//merge_1(arr,arr1,0,5,8);
	//mergesort_NR(arr, n);
	//quicksort1(arr,0,n);
	quick_sort2(arr,n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}