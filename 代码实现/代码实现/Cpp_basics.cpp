#include <iostream>
#include <string>
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

////学生类
//class Student {
//public:
//	void setName(string name) {
//		m_name = name;
//	}
//	void setID(int id) {
//		m_id = id;
//	}
//
//	void showStudent() {
//		cout << "name:" << m_name << " ID:" << m_id << endl;
//	}
//public:
//	string m_name;
//	int m_id;
//};
//
//int main() {
//
//	Student stu;
//	stu.setName("德玛西亚");
//	stu.setID(250);
//	stu.showStudent();
//
//	system("pause");
//
//	return 0;
//}

//class Cube {
//public:
//	void setL(int l) {
//		m_L = l;
//	}
//	int getL() {
//		return m_L;
//	}
//	void setW(int w) {
//		m_W = w;
//	}
//	int getW() {
//		return m_W;
//	}
//	void setH(int h) {
//		m_H = h;
//	}
//	int getH() {
//		return m_H;
//	}
//	int calculateS() {
//		return 2 * m_L*m_W + 2*m_L*m_H + 2 * m_W*m_H;
//	}
//	int calculateV() {
//		return m_L*m_H*m_W;
//	}
//
//	bool isSameByClass(Cube &c) {
//		if(m_L == c.getL() && m_H == c.getH() && m_W == c.getW())
//			return true;
//		return false;
//	}
//private:
//	int m_L;
//	int m_W;
//	int m_H;
//};
//
//bool isSame(Cube &c1, Cube &c2) {
//	if (c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW())
//		return true;
//	return false;
//}
//int main() {
//	Cube c1;
//	c1.setL(10);
//	c1.setW(10);
//	c1.setH(10);
//
//	Cube c2;
//	c2.setL(10);
//	c2.setW(10);
//	c2.setH(10);
//
//	bool result = isSame(c1, c2);
//	cout << result << endl;
//	result = c1.isSameByClass(c2);
//	cout << result << endl;
//	//c1.calculateS();
//	//c1.calculateV();
//	system("pause");
//	return 0;
//}

//class Point {
//public:
//	void setX(int x) {
//		m_X = x;
//	}
//	int getX() {
//		return m_X;
//	}
//	void setY(int y) {
//		m_Y = y;
//	}
//	int getY() {
//		return m_Y;
//	}
//private:
//	int m_X;
//	int m_Y;
//};

//class Circle {
//public:
//	void setR(int r) {
//		m_R = r;
//	}
//	int getR() {
//		return m_R;
//	}
//	void setCenter(Point center) {
//		m_Center = center;
//	}
//	Point getCenter() {
//		return m_Center;
//	}
//private:
//	int m_R;
//	Point m_Center;
//};
#include "circle.h"
#include "point.h"
//void isInCircle(Circle &c, Point &p) {
//	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
//	int rdistance = c.getR() * c.getR();
//	if (distance == rdistance)
//		cout << "点在圆上" << endl;
//	else if(distance > rdistance)
//		cout << "点在圆外" << endl;
//	else
//		cout << "点在圆内" << endl;
//}
//
//int main() {
//	Circle c;
//	c.setR(10);
//	Point center;
//	center.setX(10);
//	center.setY(0);
//	c.setCenter(center);
//	Point p;
//	p.setX(10);
//	p.setY(9);
//	isInCircle(c, p);
//	system("pause");
//	return 0;
//}

//class Person {
//public:
//	//无参（默认）构造函数
//	Person() {
//		cout << "无参构造函数!" << endl;
//	}
//	//有参构造函数
//	Person(int a) {
//		age = a;
//		cout << "有参构造函数!" << endl;
//	}
//	//拷贝构造函数
//	Person(const Person& p) {
//		age = p.age;
//		cout << "拷贝构造函数!" << endl;
//	}
//	//析构函数
//	~Person() {
//		cout << "析构函数!" << endl;
//	}
//public:
//	int age;
//};
//
////2、构造函数的调用
////调用无参构造函数
//void test01() {
//	Person p; //调用无参构造函数
//}
//
////调用有参的构造函数
//void test02() {
//
//	//2.1  括号法，常用
//	Person p1(10);
//	//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
//	//Person p2();
//
//	//2.2 显式法
//	Person p2 = Person(10);
//	Person p3 = Person(p2);
//	//Person(10)单独写就是匿名对象  当前行结束之后，马上析构
//	//Person p3;
//
//	//2.3 隐式转换法
//	Person p4 = 10; // Person p4 = Person(10); 
//	Person p5 = p4; // Person p5 = Person(p4); 
//
//					//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
//					//Person p5(p4);
//}
//
//int main() {
//
//	//test01();
//	test02();
//
//	system("pause");
//
//	return 0;
//}

class Person {
public:
	Person() {
		mA = 0;
	}
	//非静态成员变量占对象空间
	int mA;
	//静态成员变量不占对象空间
	static int mB;
	//函数也不占对象空间，所有函数共享一个函数实例
	void func() {
		cout << "mA:" << this->mA << endl;
	}
	//静态成员函数也不占对象空间
	static void sfunc() {
	}
};

int main() {

	cout << sizeof(Person) << endl;

	system("pause");

	return 0;
}