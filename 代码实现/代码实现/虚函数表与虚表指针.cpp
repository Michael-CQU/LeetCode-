//#include<bits/stdc++.h>
//using namespace std;
//
//class Base {  
//public:  
//    virtual void Bf() { cout << "Base::Bf()" << endl; }  
//    virtual void Bg() { cout << "Base::Bg()" << endl; }  
//    virtual void Bh() { cout << "Base::Bh()" << endl; }  
//};  
//
//
//class Derived :public Base {  
//public:  
//    void Bf() { cout << "Derived::Df()" << endl; }  
//    void Dg() { cout << "Derived::Dg()" << endl; }  
//    void Dh() { cout << "Derived::Dh()" << endl; }  
//};  
//
//int main() {
//	Base b;
//	Derived d;
//	Base *m;
//	m = &b;
//	m->Bf();
//	m = &d;
//	m->Bf();
//	m = &b;
//	m->Bf();
//	system("pause");
//	return 0;
//}