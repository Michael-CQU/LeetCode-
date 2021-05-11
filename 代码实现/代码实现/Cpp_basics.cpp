#include <iostream>
using namespace std;

////1. 值传递
//void mySwap01(int a, int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////2. 地址传递
//void mySwap02(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
////3. 引用传递
//void mySwap03(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main() {
//
//	int a = 10;
//	int b = 20;
//
//	mySwap01(a, b);
//	cout << "a:" << a << " b:" << b << endl;
//
//	mySwap02(&a, &b);
//	cout << "a:" << a << " b:" << b << endl;
//
//	mySwap03(a, b);
//	cout << "a:" << a << " b:" << b << endl;
//
//	system("pause");
//
//	return 0;
//}

////发现是引用，转换为 int* const ref = &a;
//void func(int& ref) {
//	ref = 100; // ref是引用，转换为*ref = 100
//}
//int main() {
//	int a = 10;
//
//	//自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
//	int& ref = a;
//	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;
//
//	cout << "a:" << a << endl;
//	cout << "ref:" << ref << endl;
//
//	func(a);
//	cout << "a:" << a << endl;
//	system("pause");
//	return 0;
//}

//学生类
class Student {
public:
	void setName(string name) {
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}

	void showStudent() {
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
public:
	string m_name;
	int m_id;
};

int main() {

	Student stu;
	stu.setName("德玛西亚");
	stu.setID(250);
	stu.showStudent();

	system("pause");

	return 0;
}