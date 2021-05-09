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
//	//科学计数法
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
//	//整型输入
//	int a = 0;
//	cout << "请输入整型变量：" << endl;
//	cin >> a;
//	cout << a << endl;
//
//	//浮点型输入
//	double d = 0;
//	cout << "请输入浮点型变量：" << endl;
//	cin >> d;
//	cout << d << endl;
//
//	//字符型输入
//	char ch = 0;
//	cout << "请输入字符型变量：" << endl;
//	cin >> ch;
//	cout << ch << endl;
//
//	//字符串型输入
//	string str;
//	cout << "请输入字符串型变量：" << endl;
//	cin >> str;
//	cout << str << endl;
//
//	//布尔类型输入
//	bool flag = false;
//	cout << "请输入布尔型变量：" << endl;
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
//			cout << "拍桌子" << endl;
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
//	//数组名用途
//	//1、可以获取整个数组占用内存空间大小
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
//	cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
//	cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;
//
//	//2、可以通过数组名获取到数组首地址
//	cout << "数组首地址为： " << (int)arr << endl;
//	cout << "数组中第一个元素地址为： " << (int)&arr[0] << endl;
//	cout << "数组中第二个元素地址为： " << (int)&arr[1] << endl;
//
//	//arr = 100; 错误，数组名是常量，因此不可以赋值
//
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	int arr[6] = {100,200,300,400,500,600};
//	//小猪最大体重
//	//int max = arr[0];
//	//for (int i = 1; i < 5; i++) {
//	//	if (arr[i] > max)
//	//		max = arr[i];
//	//}
//	//cout << max << endl;
//	//元素逆置
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
//	冒泡排序
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
//	//方式1  
//	//数组类型 数组名 [行数][列数]
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
//	//方式2 
//	//数据类型 数组名[行数][列数] = { {数据1，数据2 } ，{数据3，数据4 } };
//	int arr2[2][3] =
//	{
//		{1,2,3},
//		{4,5,6}
//	};
//
//	//方式3
//	//数据类型 数组名[行数][列数] = { 数据1，数据2 ,数据3，数据4  };
//	int arr3[2][3] = { 1,2,3,4,5,6 };
//
//	//方式4 
//	//数据类型 数组名[][列数] = { 数据1，数据2 ,数据3，数据4  };
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

	//二维数组数组名
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	cout << "二维数组大小： " << sizeof(arr) << endl;
	cout << "二维数组一行大小： " << sizeof(arr[0]) << endl;
	cout << "二维数组元素大小： " << sizeof(arr[0][0]) << endl;

	cout << "二维数组行数： " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数： " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
	cout << "二维数组元素个数： " << sizeof(arr) / sizeof(arr[0][0]) << endl;

	//地址
	cout << "二维数组首地址：" << arr << endl;
	cout << "二维数组第一行地址：" << arr[0] << endl;
	cout << "二维数组第二行地址：" << arr[1] << endl;

	cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
	cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;

	system("pause");

	return 0;
}