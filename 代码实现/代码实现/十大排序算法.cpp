#include<iostream>
#include <vector>
using namespace std;

//直接插入排序
void insertion_sort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		int key = arr[i];
		int j = i - 1;
		while ((j >= 0) && (key < arr[j])) {//移动元素
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
//折半插入排序
void binaryInsertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int low = 0, high = i - 1;//将要插入的元素复制出来
		int temp = arr[i];
		//当low>high时，证明折半查找结束
		while (low <= high) {
			int mid = (low + high) / 2;
			//每次和折半查到的元素比较大小
			//当待插入元素比折半查到的元素小时，那么正确插入位置在低半区；否则在高半区
			if (arr[i] < arr[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		//由折半查找到的正确插入位置为high+1
		//将high+1后面的元素依次后移
		for (int j = i - 1; j >= high + 1; j--)
			arr[j + 1] = arr[j];
		//在正确位置插入复制出来的待插入元素
		arr[high + 1] = temp;
	}
}

//希尔排序
template<typename T>
void shell_sort(T array[], int length) {
	int h = 1;
	while (h < length / 3) {
		h = 3 * h + 1;
	}
	while (h >= 1) {
		for (int i = h; i < length; i++) {
			for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
				std::swap(array[j], array[j - h]);
			}
		}
		h = h / 3;
	}
}
//冒泡排序
template<typename T> //整数或浮点数皆可使用,若要使用类(class)或结构体(struct)时必须重载大于(>)运算符
void bubble_sort(T arr[], int len) {
	int i, j;
	for (i = 0; i < len - 1; i++)//i表示进行第几轮bubble
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}
//快速排序（递归法）
//快速排序（从小到大）
void quickSort(int left, int right, int arr[])
{
	if (left >= right)
		return;
	int i, j, base;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)//！！！注意：如果pivot值从最左边取，则一定要先从j--开始，再i++。顺序一定不能反。注意等于号一定要写上，不然逻辑会有错误，和pivot相等的值就会和pivot无法挨在一起
			j--;
		while (arr[i] <= base && i < j)//如果要从大到小排列，则改为arr[i] >= base
			i++;
		swap(arr[i], arr[j]);
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}
//选择排序
template<typename T> //整數或浮點數皆可使用，若要使用物件（class）時必須設定大於（>）的運算子功能
void selection_sort(std::vector<T>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[j] < arr[min])
				min = j;
		std::swap(arr[i], arr[min]);
	}
}
//堆排序（方法一）
void adjustHeap(int arr[], int head, int size) {

	// 如果头节点是非叶子节点才需要进行调整
	if (head < size / 2) {
		// 数组下标从0开始
		int maxnIndex = head;
		int left = 2 * head + 1;
		int right = 2 * head + 2;
		if (left<size && arr[left]>arr[maxnIndex])
			maxnIndex = left;
		if (right<size && arr[right]>arr[maxnIndex])
			maxnIndex = right;
		if (maxnIndex != head) {
			swap(arr[head], arr[maxnIndex]); // 将最大值放在头节点
			adjustHeap(arr, maxnIndex, size); // 为了防止调整后的子树不满足堆的条件，需要递归调整
		}
	}
}

// 初始化堆
void buildHeap(int arr[], int size) {
	//从第一个非叶子节点开始调整堆
	for (int i = size / 2 - 1; i >= 0; i--) {
		adjustHeap(arr, i, size);
	}
}

void headSort(int arr[], int size) {
	// 建堆
	buildHeap(arr, size);

	// 堆排序
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		adjustHeap(arr, 0, i);
	}
}
//堆排序（方法二）
void max_heapify(int arr[], int start, int end) {
	// 建立父節點指標和子節點指標
	int dad = start;
	int son = dad * 2 + 1;//！！！注意：用数组表示树的话，左子节点是dad * 2 + 1，左子节点是dad * 2 + 2。（自己从0开始画一下图就明白了）
	while (son <= end) { // 若子節點指標在範圍內才做比較
		if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
			son++;
		if (arr[dad] > arr[son]) // 如果父節點大於子節點代表調整完畢，直接跳出函數
			return;
		else { // 否則交換父子內容再繼續子節點和孫節點比較
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void heap_sort(int arr[], int len) {
	// 初始化，i從最後一個父節點開始調整
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	// 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
	for (int i = len - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}
//有序数组合并
//将有序数组a[]和b[]合并到c[]中
void MemeryArray(int a[], int n, int b[], int m, int c[])
{
	int i, j, k;

	i = j = k = 0;
	while (i < n && j < m)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}

	while (i < n)
		c[k++] = a[i++];

	while (j < m)
		c[k++] = b[j++];
}
//归并排序（递归）
//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}

bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}
//归并排序（非递归）
void merge_array(int arr[], int arr1[], int ls1, int rs1, int n) {//用于合并
																  //方法一：k从ls1开始
																  //int i = ls1, j = rs1, k = ls1;
																  //方法二:注意k必须是从0开始，因为与方法1不同，arr1不再用于保存合并排序后的数据
	int i = ls1, j = rs1, k = 0;
	while (i < rs1&&j < n + 1) {
		if (arr[i] < arr[j]) {
			arr1[k++] = arr[i++];
		}
		else
			arr1[k++] = arr[j++];
	}
	while (i < rs1)
		arr1[k++] = arr[i++];
	while (j < n + 1)
		arr1[k++] = arr[j++];
	//方法二：每次归并时候，将排序结果传回给数组arr，确保排序后的值在数组arr中
	{
		k = 0;
		while (ls1 <= n)
			arr[ls1++] = arr1[k++];
	}
}

void merge_k(int arr[], int arr1[], int k, int n) {//用于循环进行固定k值后的合并
	int i = 0;
	int j;
	while (i < n - 2 * k + 1) {
		merge_array(arr, arr1, i, i + k, i + 2 * k - 1);
		i += 2 * k;
	}
	if (i < n - k) {
		merge_array(arr, arr1, i, i + k, n - 1);
	}
	else
		for (j = i; j < n; j++)
			arr1[j] = arr[j];
}

bool mergesort_NR(int arr[], int n) {//用于确定以多大的k值进行合并
	int k = 1;
	int *arr1 = new int[n];
	if (arr == NULL)
		return false;
	while (k < n) {
		merge_k(arr, arr1, k, n);
		k *= 2;
		//方法二：注释以下代码
		//{
		//	merge_k(arr1, arr, k, n);
		//	k *= 2;
		//}
	}
	delete[]arr1;
	return true;
}
//基数排序：
int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
	int maxData = data[0];              ///< 最大数
										/// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
	for (int i = 1; i < n; ++i)
	{
		if (maxData < data[i])
			maxData = data[i];
	}
	int d = 1;
	int p = 10;
	while (maxData >= p)
	{
		//p *= 10; // Maybe overflow
		maxData /= 10;
		++d;
	}
	return d;
	/*    int d = 1; //保存最大的位数
	int p = 10;
	for(int i = 0; i < n; ++i)
	{
	while(data[i] >= p)
	{
	p *= 10;
	++d;
	}
	}
	return d;*/
}
void radixsort(int data[], int n) //基数排序
{
	int d = maxbit(data, n);
	int *tmp = new int[n];
	int *count = new int[10]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //进行d次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到data中
			data[j] = tmp[j];
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
}

//int main() {
//	int ARR[] = {9,1,5,4,6,7,3,2,5,8};
//	int n = sizeof(ARR) / sizeof(int);
//	cout << "排序前：" << endl;
//	for (int i = 0; i < n; i++) {
//		cout << ARR[i] << ' ';
//	}
//	cout << endl;
//	//insertion_sort(ARR, n);
//	//binaryInsertionSort(ARR, n);
//	//shell_sort(ARR, n);
//	//bubble_sort(ARR, n);
//	//quickSort(0,n-1,ARR);
//	//heap_sort(ARR, n);//方法二
//	//headSort(ARR, n);//方法一
//	MergeSort(ARR, n);
//
//	cout << "排序后：" << endl;
//	for (int i = 0; i < n; i++) {
//		cout << ARR[i] << ' ';
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}