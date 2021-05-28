#include <iostream>
using namespace std;
//二分插入排序
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

//堆排序
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
////归并排序（非递归）
//void merge_array(int arr[], int arr1[], int ls1, int rs1, int n) {//用于合并
//	//方法一：k从ls1开始
//	//int i = ls1, j = rs1, k = ls1;
//	//方法二:注意k必须是从0开始，因为与方法1不同，arr1不再用于保存合并排序后的数据
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
//	//方法二：每次归并时候，将排序结果传回给数组arr，确保排序后的值在数组arr中
//	{
//	k = 0;
//	while(ls1 <= n)
//	arr[ls1++] = arr1[k++];
//	}
//}
//
//void merge_k(int arr[], int arr1[], int k, int n) {//用于循环进行固定k值后的合并
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
//bool mergesort_NR(int arr[],int n) {//用于确定以多大的k值进行合并
//	int k = 1;
//	int *arr1 = new int[n];
//	if (arr == NULL)
//		return false;
//	while (k<n) {
//		merge_k(arr,arr1,k,n);
//		k *= 2;
//		//方法二：注释以下代码
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
template <typename T> // 整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)、"大於"(>)、"不小於"(>=)的運算子功能
void quick_sort2(T arr[], const int len) {
	if (len <= 0)
		return; // 避免len等於負值時宣告堆疊陣列當機
				// r[]模擬堆疊,p為數量,r[p++]為push,r[--p]為pop且取得元素
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