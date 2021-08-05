#include<bits/stdc++.h>
using namespace std;

//智能指针实质是一个对象，行为表现却是一个指针
//主要体现只能指针可以构造时初始化，析构时释放资源
//智能指针是一个类，当超出类的作用域时，类会自动调用析构函数，自动释放资源

//构造、析构、拷贝、赋值、*、->
template<class T>
class smartptr {
public:
	smartptr(T* ptr = nullptr) {//传入指针
		_ptr = ptr;
		_count = new int[1];
		cout << "调用" << endl;
	}
	~smartptr() {
		if (_count != nullptr){//用于判断移动构造
			--(*_count);
			if ((*_count) == 0) {
				delete _ptr;
				_ptr = nullptr;
				delete _count;
				_count = nullptr;
			}
			cout << "析构" << endl;
		}
	}
	smartptr(const smartptr& s) {//传入对象
		_ptr = s._ptr;
		_count = s._count;
		++(*_count);
		cout << "拷贝" << endl;

	}
	smartptr<T>& operator=(const smartptr& s) {//传入对象,引用方式返回本体
		if (this != &s) {
			if (--(*_count) == 0) {
				delete _ptr;
				delete _count;
			}
			_ptr = s._ptr;
			_count = s._count;
			++(*_count);
		}
		cout << "赋值" << endl;
		return *this;
	}
	smartptr(smartptr&& s) {//移动构造
		_ptr = s._ptr;
		_count = s._count;
		s._ptr = nullptr;
		s._count = nullptr;
		cout << "移动" << endl;
	}
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {//为了使一个类对象表现的像一个类型的指针一样
		return _ptr;
	}
public:
	T* _ptr;
	int* _count;
};

//int main() {
//	{
//		smartptr<int> p1(new int[10]);
//		smartptr<int> p2(p1);
//		smartptr<int> p3;
//		p3 = p1;
//		smartptr<int> p4(move(p3));
//	}
//	system("pause");
//	return 0;
//}