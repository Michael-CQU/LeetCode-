#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int main() {
//
//	float f1 = 3.14f;
//	double d1 = 3.14;
//
//	cout << f1 << endl;
//	cout << d1 << endl;
//
//	cout << "float  sizeof = " << sizeof(f1) << endl;
//	cout << "double sizeof = " << sizeof(d1) << endl;
//
//	//��ѧ������
//	float f2 = 3e2; // 3 * 10 ^ 2 
//	cout << "f2 = " << f2 << endl;
//
//	float f3 = 3e-2;  // 3 * 0.1 ^ 2
//	cout << "f3 = " << f3 << endl;
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	char ch = 'a';
//	cout << ch << endl;
//	cout << sizeof(char) << endl;
//	cout << sizeof(ch) << endl;
//
//	char str1[] = "hello world";
//	cout << str1 << endl;
//	cout << sizeof(str1) << endl;
//
//	string str = "hello world";
//	cout << str << endl;
//	cout << sizeof(str) << endl;
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	//��������
//	int a = 0;
//	cout << "���������ͱ�����" << endl;
//	cin >> a;
//	cout << a << endl;
//
//	//����������
//	double d = 0;
//	cout << "�����븡���ͱ�����" << endl;
//	cin >> d;
//	cout << d << endl;
//
//	//�ַ�������
//	char ch = 0;
//	cout << "�������ַ��ͱ�����" << endl;
//	cin >> ch;
//	cout << ch << endl;
//
//	//�ַ���������
//	string str;
//	cout << "�������ַ����ͱ�����" << endl;
//	cin >> str;
//	cout << str << endl;
//
//	//������������
//	bool flag = false;
//	cout << "�����벼���ͱ�����" << endl;
//	cin >> flag;
//	cout << flag << endl;
//	system("pause");
//	return EXIT_SUCCESS;
//}

//int main() {
//	int i = 100;
//	vector<int> result;
//	do {
//		int a = i / 100;
//		int b = (i / 10)%10;
//		int c = i % 10;
//		//cout << a << " "<<b <<" "<< c << endl;
//		if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
//			result.push_back(i);
//		i++;
//			
//	} while (i < 1000);
//	for (vector<int>::iterator it = result.begin(); it < result.end(); it++) {
//		cout << *it << endl;
//	}
//	system("pause");
//
//	return 0;
//}

//int main() {
//	for (int i = 1; i <= 100; i++) {
//		if (i % 10 == 7 || i / 10 == 7 || i % 7 == 0)
//			cout << "������" << endl;
//		else
//			cout << i << endl;
//	}
//	system("pause");
//
//	return 0;
//}

//int main() {
//	for (int i = 1; i <10; i++) {
//		for (int j = 1; j <= i; j++) {
//			cout << j << "*" << i << "=" << i*j<< " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	//��������;
//	//1�����Ի�ȡ��������ռ���ڴ�ռ��С
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	cout << "����������ռ�ڴ�ռ�Ϊ�� " << sizeof(arr) << endl;
//	cout << "ÿ��Ԫ����ռ�ڴ�ռ�Ϊ�� " << sizeof(arr[0]) << endl;
//	cout << "�����Ԫ�ظ���Ϊ�� " << sizeof(arr) / sizeof(arr[0]) << endl;
//
//	//2������ͨ����������ȡ�������׵�ַ
//	cout << "�����׵�ַΪ�� " << (int)arr << endl;
//	cout << "�����е�һ��Ԫ�ص�ַΪ�� " << (int)&arr[0] << endl;
//	cout << "�����еڶ���Ԫ�ص�ַΪ�� " << (int)&arr[1] << endl;
//
//	//arr = 100; �����������ǳ�������˲����Ը�ֵ
//
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	int arr[6] = {100,200,300,400,500,600};
//	//С���������
//	//int max = arr[0];
//	//for (int i = 1; i < 5; i++) {
//	//	if (arr[i] > max)
//	//		max = arr[i];
//	//}
//	//cout << max << endl;
//	//Ԫ������
//	for (int i = 0; i < 6 / 2; i++) {
//		int temp = arr[i];
//		arr[i] = arr[5-i];
//		arr[5 - i] = temp;
//	}
//	for (int j = 0; j < 6; j++)
//		cout << arr[j] << endl;
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	ð������
//		int arr[] = { 4,2,8,0,5,7,1,3,9 };
//	for (int i = 0; i < 9 - 1; i++) {
//		for (int j = 0; j < 9 - 1 - i; j++) {
//			if (arr[j + 1] < arr[j]) {
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < 9; i++)
//		cout << arr[i] << endl;
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	//��ʽ1  
//	//�������� ������ [����][����]
//	int arr[2][3];
//	arr[0][0] = 1;
//	arr[0][1] = 2;
//	arr[0][2] = 3;
//	arr[1][0] = 4;
//	arr[1][1] = 5;
//	arr[1][2] = 6;
//
//	//for (int i = 0; i < 2; i++)
//	//{
//	//	for (int j = 0; j < 3; j++)
//	//	{
//	//		cout << arr[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//	//��ʽ2 
//	//�������� ������[����][����] = { {����1������2 } ��{����3������4 } };
//	int arr2[2][3] =
//	{
//		{1,2,3},
//		{4,5,6}
//	};
//
//	//��ʽ3
//	//�������� ������[����][����] = { ����1������2 ,����3������4  };
//	int arr3[2][3] = { 1,2,3,4,5,6 };
//
//	//��ʽ4 
//	//�������� ������[][����] = { ����1������2 ,����3������4  };
//	int arr4[][3] = {
//		{1,2,3},
//		{4,5,6}
//	};
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << arr4[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//
//	return 0;
//}

int main() {

	//��ά����������
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	cout << "��ά�����С�� " << sizeof(arr) << endl;
	cout << "��ά����һ�д�С�� " << sizeof(arr[0]) << endl;
	cout << "��ά����Ԫ�ش�С�� " << sizeof(arr[0][0]) << endl;

	cout << "��ά���������� " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "��ά���������� " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
	cout << "��ά����Ԫ�ظ����� " << sizeof(arr) / sizeof(arr[0][0]) << endl;

	//��ַ
	cout << "��ά�����׵�ַ��" << arr << endl;
	cout << "��ά�����һ�е�ַ��" << arr[0] << endl;
	cout << "��ά����ڶ��е�ַ��" << arr[1] << endl;

	cout << "��ά�����һ��Ԫ�ص�ַ��" << &arr[0][0] << endl;
	cout << "��ά����ڶ���Ԫ�ص�ַ��" << &arr[0][1] << endl;

	system("pause");

	return 0;
}