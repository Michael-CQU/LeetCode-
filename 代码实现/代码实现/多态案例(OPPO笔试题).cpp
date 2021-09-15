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
	ptr1->func();//多态用指针实现
	ptr2->func();
	ref1.func();//多态用引用实现
	ref2.func();
	val1.func();//值传递无法实现多态
	val2.func();
}
//int main() {
//	A a;
//	B b;
//	show(&a, &b, a, b, a, b);
//	system("pause");
//	return 0;
//}