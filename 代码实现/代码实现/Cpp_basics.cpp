#include <iostream>
using namespace std;

////1. ֵ����
//void mySwap01(int a, int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////2. ��ַ����
//void mySwap02(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
////3. ���ô���
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

////���������ã�ת��Ϊ int* const ref = &a;
//void func(int& ref) {
//	ref = 100; // ref�����ã�ת��Ϊ*ref = 100
//}
//int main() {
//	int a = 10;
//
//	//�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
//	int& ref = a;
//	ref = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;
//
//	cout << "a:" << a << endl;
//	cout << "ref:" << ref << endl;
//
//	func(a);
//	cout << "a:" << a << endl;
//	system("pause");
//	return 0;
//}

//ѧ����
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
	stu.setName("��������");
	stu.setID(250);
	stu.showStudent();

	system("pause");

	return 0;
}