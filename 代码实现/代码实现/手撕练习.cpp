#include<bits/stdc++.h>
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;
#define _CRTDBG_MAP_ALLOC
uint64_t fun(uint32_t a) {
	static const uint32_t b = 1 << 12;
	return a*b;
}
//class A {
//	int i;
//};
//class B {
//	A* p;
//public:
//	B() { p = new A; }
//	~B() { delete p; }
//};
//void sayhello(B b) {}
//int main() {
//	int a = INT_MAX;
//	uint64_t res = fun(a);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}

//int main() {
//	int a[2][3] = {1,2,3,4,5,6};
//	int(*p)[3] = a;
//	int *q = *a;
//	cout << *(*(a+1)+2) << endl;
//	cout << p[1][2] << endl;
//	cout << *(q+5) << endl;
//	//cout << q[1][2] << endl;
//	system("pause");
//}

//int main() {
//	int a[9] = {0,1,2,3,4,5,6,7,8};
//	int *p = a;
//	cout << *(p+1) << endl;
//	system("pause");
//}

//void fun111(char *&p1) {
//	p1 = (char*)malloc(sizeof(char) * 10);
//	*p1 = 10000;
//	_CrtDumpMemoryLeaks();
//}
//int main() {
//	for (int i = 0; i < 10000000; i++) {
//		char*p = nullptr;
//		fun111(p);
//		free(p);
//		_CrtDumpMemoryLeaks();
//		system("pause");
//		return 0;
//	}
//}
