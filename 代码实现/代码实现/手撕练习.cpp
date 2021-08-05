#include<bits/stdc++.h>
using namespace std;

class A {
public:
	A() {
		count = new int(10);
		cout << "A构造" << endl;
	}
	virtual ~A() {
		delete count;
		count = nullptr;
		cout << "A析构" << endl;
	}
	int* count;
};
class B :public A {
public:
	B() {
		m = new int(10);
		cout << "B构造" << endl;
	}
	~B() {
		delete m;
		m = nullptr;
		cout << "B析构" << endl;
	}
	int * m;
};

int main() {
	{
		A* a = new B;
		delete a;
	}
	system("pause");
	return 0;
}