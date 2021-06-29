#include<iostream>
#include <vector>
using namespace std;

//ֱ�Ӳ�������
void insertion_sort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		int key = arr[i];
		int j = i - 1;
		while ((j >= 0) && (key < arr[j])) {//�ƶ�Ԫ��
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
//�۰��������
void binaryInsertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int low = 0, high = i - 1;//��Ҫ�����Ԫ�ظ��Ƴ���
		int temp = arr[i];
		//��low>highʱ��֤���۰���ҽ���
		while (low <= high) {
			int mid = (low + high) / 2;
			//ÿ�κ��۰�鵽��Ԫ�رȽϴ�С
			//��������Ԫ�ر��۰�鵽��Ԫ��Сʱ����ô��ȷ����λ���ڵͰ����������ڸ߰���
			if (arr[i] < arr[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		//���۰���ҵ�����ȷ����λ��Ϊhigh+1
		//��high+1�����Ԫ�����κ���
		for (int j = i - 1; j >= high + 1; j--)
			arr[j + 1] = arr[j];
		//����ȷλ�ò��븴�Ƴ����Ĵ�����Ԫ��
		arr[high + 1] = temp;
	}
}

//ϣ������
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
//ð������
template<typename T> //�����򸡵����Կ�ʹ��,��Ҫʹ����(class)��ṹ��(struct)ʱ�������ش���(>)�����
void bubble_sort(T arr[], int len) {
	int i, j;
	for (i = 0; i < len - 1; i++)//i��ʾ���еڼ���bubble
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}
//�������򣨵ݹ鷨��
//�������򣨴�С����
void quickSort(int left, int right, int arr[])
{
	if (left >= right)
		return;
	int i, j, base;
	i = left, j = right;
	base = arr[left];  //ȡ����ߵ���Ϊ��׼��
	while (i < j)
	{
		while (arr[j] >= base && i < j)//������ע�⣺���pivotֵ�������ȡ����һ��Ҫ�ȴ�j--��ʼ����i++��˳��һ�����ܷ���ע����ں�һ��Ҫд�ϣ���Ȼ�߼����д��󣬺�pivot��ȵ�ֵ�ͻ��pivot�޷�����һ��
			j--;
		while (arr[i] <= base && i < j)//���Ҫ�Ӵ�С���У����Ϊarr[i] >= base
			i++;
		swap(arr[i], arr[j]);
	}
	//��׼����λ
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//�ݹ����
	quickSort(i + 1, right, arr);//�ݹ��ұ�
}
//ѡ������
template<typename T> //�������c���Կ�ʹ�ã���Ҫʹ�������class���r����O����춣�>�����\���ӹ���
void selection_sort(std::vector<T>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[j] < arr[min])
				min = j;
		std::swap(arr[i], arr[min]);
	}
}
//�����򣨷���һ��
void adjustHeap(int arr[], int head, int size) {

	// ���ͷ�ڵ��Ƿ�Ҷ�ӽڵ����Ҫ���е���
	if (head < size / 2) {
		// �����±��0��ʼ
		int maxnIndex = head;
		int left = 2 * head + 1;
		int right = 2 * head + 2;
		if (left<size && arr[left]>arr[maxnIndex])
			maxnIndex = left;
		if (right<size && arr[right]>arr[maxnIndex])
			maxnIndex = right;
		if (maxnIndex != head) {
			swap(arr[head], arr[maxnIndex]); // �����ֵ����ͷ�ڵ�
			adjustHeap(arr, maxnIndex, size); // Ϊ�˷�ֹ�����������������ѵ���������Ҫ�ݹ����
		}
	}
}

// ��ʼ����
void buildHeap(int arr[], int size) {
	//�ӵ�һ����Ҷ�ӽڵ㿪ʼ������
	for (int i = size / 2 - 1; i >= 0; i--) {
		adjustHeap(arr, i, size);
	}
}

void headSort(int arr[], int size) {
	// ����
	buildHeap(arr, size);

	// ������
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		adjustHeap(arr, 0, i);
	}
}
//�����򣨷�������
void max_heapify(int arr[], int start, int end) {
	// ���������cָ�˺��ӹ��cָ��
	int dad = start;
	int son = dad * 2 + 1;//������ע�⣺�������ʾ���Ļ������ӽڵ���dad * 2 + 1�����ӽڵ���dad * 2 + 2�����Լ���0��ʼ��һ��ͼ�������ˣ�
	while (son <= end) { // ���ӹ��cָ���ڹ����Ȳ������^
		if (son + 1 <= end && arr[son] < arr[son + 1]) // �ȱ��^�ɂ��ӹ��c��С���x������
			son++;
		if (arr[dad] > arr[son]) // ��������c����ӹ��c�����{���ꮅ��ֱ����������
			return;
		else { // ��t���Q���Ӄ������^�m�ӹ��c�͌O���c���^
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void heap_sort(int arr[], int len) {
	// ��ʼ����i������һ�������c�_ʼ�{��
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	// �Ȍ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ�����Q���ُ����{��(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ�������ꮅ
	for (int i = len - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}
//��������ϲ�
//����������a[]��b[]�ϲ���c[]��
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
//�鲢���򣨵ݹ飩
//���ж�����������a[first...mid]��a[mid...last]�ϲ���
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
		mergesort(a, first, mid, temp);    //�������
		mergesort(a, mid + 1, last, temp); //�ұ�����
		mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�
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
//�鲢���򣨷ǵݹ飩
void merge_array(int arr[], int arr1[], int ls1, int rs1, int n) {//���ںϲ�
																  //����һ��k��ls1��ʼ
																  //int i = ls1, j = rs1, k = ls1;
																  //������:ע��k�����Ǵ�0��ʼ����Ϊ�뷽��1��ͬ��arr1�������ڱ���ϲ�����������
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
	//��������ÿ�ι鲢ʱ�򣬽����������ظ�����arr��ȷ��������ֵ������arr��
	{
		k = 0;
		while (ls1 <= n)
			arr[ls1++] = arr1[k++];
	}
}

void merge_k(int arr[], int arr1[], int k, int n) {//����ѭ�����й̶�kֵ��ĺϲ�
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

bool mergesort_NR(int arr[], int n) {//����ȷ���Զ���kֵ���кϲ�
	int k = 1;
	int *arr1 = new int[n];
	if (arr == NULL)
		return false;
	while (k < n) {
		merge_k(arr, arr1, k, n);
		k *= 2;
		//��������ע�����´���
		//{
		//	merge_k(arr1, arr, k, n);
		//	k *= 2;
		//}
	}
	delete[]arr1;
	return true;
}
//��������
int maxbit(int data[], int n) //���������������ݵ����λ��
{
	int maxData = data[0];              ///< �����
										/// ������������������λ����������ԭ������ÿ�����ж���λ������΢�Ż��㡣
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
	/*    int d = 1; //��������λ��
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
void radixsort(int data[], int n) //��������
{
	int d = maxbit(data, n);
	int *tmp = new int[n];
	int *count = new int[10]; //������
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //����d������
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //ÿ�η���ǰ��ռ�����
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
		for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
			data[j] = tmp[j];
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
}

//int main() {
//	int ARR[] = {9,1,5,4,6,7,3,2,5,8};
//	int n = sizeof(ARR) / sizeof(int);
//	cout << "����ǰ��" << endl;
//	for (int i = 0; i < n; i++) {
//		cout << ARR[i] << ' ';
//	}
//	cout << endl;
//	//insertion_sort(ARR, n);
//	//binaryInsertionSort(ARR, n);
//	//shell_sort(ARR, n);
//	//bubble_sort(ARR, n);
//	//quickSort(0,n-1,ARR);
//	//heap_sort(ARR, n);//������
//	//headSort(ARR, n);//����һ
//	MergeSort(ARR, n);
//
//	cout << "�����" << endl;
//	for (int i = 0; i < n; i++) {
//		cout << ARR[i] << ' ';
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}