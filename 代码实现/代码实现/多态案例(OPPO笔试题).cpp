#include<bits/stdc++.h>
using namespace std;
class A {
public:
	virtual void func() {
		cout << "A" << endl;
	}
};
class B :public A {
public:
	void func() {
		cout << "B" << endl;
	}
};
void show(A* ptr1, A* ptr2, A& ref1, A& ref2, A val1, A val2) {
	ptr1->func();//��̬��ָ��ʵ��
	ptr2->func();
	ref1.func();//��̬������ʵ��
	ref2.func();
	val1.func();//ֵ�����޷�ʵ�ֶ�̬
	val2.func();
}
//int main() {
//	A a;
//	B b;
//	show(&a, &b, a, b, a, b);
//	system("pause");
//	return 0;
//}