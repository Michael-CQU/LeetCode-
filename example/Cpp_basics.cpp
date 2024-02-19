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

//class Person {
//public:
//	Person() {
//		mA = 0;
//	}
//	//非静态成员变量占对象空间
//	int mA;
//	//静态成员变量不占对象空间
//	static int mB;
//	//函数也不占对象空间，所有函数共享一个函数实例
//	void func() {
//		cout << "mA:" << this->mA << endl;
//	}
//	//静态成员函数也不占对象空间
//	static void sfunc() {
//	}
//};
//
//int main() {
//
//	cout << sizeof(Person) << endl;
//
//	system("pause");
//
//	return 0;
//}

////取模运算
//int main() {
//	int num = 3987;
//	int thousands = num / 1000;
//	int hundreds = (num / 100) % 10;
//	int tens = (num / 10) % 10;
//	int ones = num % 10;
//	cout << thousands << " " << hundreds << " " << tens << " " << ones << endl;
//	system("pause");
//	return 0;
//}

//class Building;
//class Goodgay {
//public:
//	Goodgay();
//	void visit();
//	void visit2();
//private:
//	Building * building;
//
//};
//
//class Building {
//	friend void Goodgay::visit();
//public:
//	Building();
//	string m_settingroom;
//private:
//	string m_bedroom;
//};
//
//Goodgay::Goodgay() {
//	building = new Building;
//}
//Building::Building() {
//	m_settingroom = "客厅";
//	m_bedroom = "卧室";
//}
//void Goodgay::visit() {
//	cout << building->m_settingroom << endl;
//	cout << building->m_bedroom << endl;
//}
//void Goodgay::visit2() {
//	cout << building->m_settingroom << endl;
//	//cout << building->m_bedroom << endl;
//}
//
//int main() {
//	Goodgay gg;
//	gg.visit();
//
//	system("pause");
//	return 0;
//}

//class MyPrint
//{
//public:
//	void operator()(string text)
//	{
//		cout << text << endl;
//	}
//
//};
//void test01()
//{
//	//重载的（）操作符 也称为仿函数
//	MyPrint myFunc;
//	myFunc("hello world");
//}
//
//
//class MyAdd
//{
//public:
//	int operator()(int v1, int v2)
//	{
//		return v1 + v2;
//	}
//};
//
//void test02()
//{
//	MyAdd add;
//	int ret = add(10, 10);
//	cout << "ret = " << ret << endl;
//
//	//匿名对象调用  
//	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
//}
//
//int main() {
//
//	test01();
//	test02();
//
//	system("pause");
//
//	return 0;
//}

//class Animal
//{
//public:
//	int m_Age;
//};
//
////继承前加virtual关键字后，变为虚继承
////此时公共的父类Animal称为虚基类
//class Sheep : virtual public Animal {};
//class Tuo : virtual public Animal {};
//class SheepTuo : public Sheep, public Tuo {};
//
//void test01()
//{
//	SheepTuo st;
//	st.Sheep::m_Age = 100;
//	st.Tuo::m_Age = 200;
//	cout << "size of SheepTuo:" << sizeof(st) << endl;
//	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
//	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
//	cout << "st.m_Age = " << st.m_Age << endl;
//}
//
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}

////普通实现
//class Calculator {
//public:
//	int getResult(string oper)
//	{
//		if (oper == "+") {
//			return m_Num1 + m_Num2;
//		}
//		else if (oper == "-") {
//			return m_Num1 - m_Num2;
//		}
//		else if (oper == "*") {
//			return m_Num1 * m_Num2;
//		}
//		//如果要提供新的运算，需要修改源码
//	}
//public:
//	int m_Num1;
//	int m_Num2;
//};
//
//void test01()
//{
//	//普通实现测试
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 10;
//	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
//
//	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
//
//	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
//}
//
//
//
////多态实现
////抽象计算器类
////多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
//class AbstractCalculator
//{
//public:
//
//	virtual int getResult()
//	{
//		return 0;
//	}
//
//	int m_Num1;
//	int m_Num2;
//};
//
////加法计算器
//class AddCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//
////减法计算器
//class SubCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
////乘法计算器
//class MulCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//
//
//void test02()
//{
//	//创建加法计算器
//	AbstractCalculator *abc = new AddCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;  //用完了记得销毁
//
//				 //创建减法计算器
//	abc = new SubCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//
//	//创建乘法计算器
//	abc = new MulCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//}
//
//int main() {
//
//	//test01();
//
//	test02();
//
//	system("pause");
//
//	return 0;
//}

//class Base
//{
//public:
//	//纯虚函数
//	//类中只要有一个纯虚函数就称为抽象类
//	//抽象类无法实例化对象
//	//子类必须重写父类中的纯虚函数，否则也属于抽象类
//	virtual void func() = 0;
//};
//
//class Son :public Base
//{
//public:
//	void func()
//	{
//		cout << "func调用" << endl;
//	}
//};
//
//void test01()
//{
//	Base * base = NULL;
//	//base = new Base; // 错误，抽象类无法实例化对象
//	base = new Son;
//	base->func();
//	delete base;//记得销毁
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}

//#include <fstream>
//#include <string>
//void test01()
//{
//	ifstream ifs;
//	ifs.open("test.txt", ios::in);
//
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
//
//	//第一种方式
//	//char buf[1024] = { 0 };
//	//while (ifs >> buf)
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//第二种
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf,sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//第三种
//	string buf;
//	while (getline(ifs,buf))
//	{
//		cout << buf << endl;
//	}
//
//	//char c;
//	//while ((c = ifs.get()) != EOF)
//	//{
//	//	cout << c;
//	//}
//
//	//ifs.close();
//
//
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}