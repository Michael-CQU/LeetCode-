#include <iostream>
#include <string>
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

////ѧ����
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
//	stu.setName("��������");
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
//		cout << "����Բ��" << endl;
//	else if(distance > rdistance)
//		cout << "����Բ��" << endl;
//	else
//		cout << "����Բ��" << endl;
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
//	//�޲Σ�Ĭ�ϣ����캯��
//	Person() {
//		cout << "�޲ι��캯��!" << endl;
//	}
//	//�вι��캯��
//	Person(int a) {
//		age = a;
//		cout << "�вι��캯��!" << endl;
//	}
//	//�������캯��
//	Person(const Person& p) {
//		age = p.age;
//		cout << "�������캯��!" << endl;
//	}
//	//��������
//	~Person() {
//		cout << "��������!" << endl;
//	}
//public:
//	int age;
//};
//
////2�����캯���ĵ���
////�����޲ι��캯��
//void test01() {
//	Person p; //�����޲ι��캯��
//}
//
////�����вεĹ��캯��
//void test02() {
//
//	//2.1  ���ŷ�������
//	Person p1(10);
//	//ע��1�������޲ι��캯�����ܼ����ţ�������˱�������Ϊ����һ����������
//	//Person p2();
//
//	//2.2 ��ʽ��
//	Person p2 = Person(10);
//	Person p3 = Person(p2);
//	//Person(10)����д������������  ��ǰ�н���֮����������
//	//Person p3;
//
//	//2.3 ��ʽת����
//	Person p4 = 10; // Person p4 = Person(10); 
//	Person p5 = p4; // Person p5 = Person(p4); 
//
//					//ע��2���������� �������캯�� ��ʼ���������� ��������Ϊ�Ƕ�������
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
//	//�Ǿ�̬��Ա����ռ����ռ�
//	int mA;
//	//��̬��Ա������ռ����ռ�
//	static int mB;
//	//����Ҳ��ռ����ռ䣬���к�������һ������ʵ��
//	void func() {
//		cout << "mA:" << this->mA << endl;
//	}
//	//��̬��Ա����Ҳ��ռ����ռ�
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

////ȡģ����
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
//	m_settingroom = "����";
//	m_bedroom = "����";
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
//	//���صģ��������� Ҳ��Ϊ�º���
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
//	//�����������  
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
////�̳�ǰ��virtual�ؼ��ֺ󣬱�Ϊ��̳�
////��ʱ�����ĸ���Animal��Ϊ�����
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

////��ͨʵ��
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
//		//���Ҫ�ṩ�µ����㣬��Ҫ�޸�Դ��
//	}
//public:
//	int m_Num1;
//	int m_Num2;
//};
//
//void test01()
//{
//	//��ͨʵ�ֲ���
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
////��̬ʵ��
////�����������
////��̬�ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��
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
////�ӷ�������
//class AddCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//
////����������
//class SubCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
////�˷�������
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
//	//�����ӷ�������
//	AbstractCalculator *abc = new AddCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;  //�����˼ǵ�����
//
//				 //��������������
//	abc = new SubCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//
//	//�����˷�������
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
//	//���麯��
//	//����ֻҪ��һ�����麯���ͳ�Ϊ������
//	//�������޷�ʵ��������
//	//���������д�����еĴ��麯��������Ҳ���ڳ�����
//	virtual void func() = 0;
//};
//
//class Son :public Base
//{
//public:
//	void func()
//	{
//		cout << "func����" << endl;
//	}
//};
//
//void test01()
//{
//	Base * base = NULL;
//	//base = new Base; // ���󣬳������޷�ʵ��������
//	base = new Son;
//	base->func();
//	delete base;//�ǵ�����
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
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
//
//	//��һ�ַ�ʽ
//	//char buf[1024] = { 0 };
//	//while (ifs >> buf)
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//�ڶ���
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf,sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//������
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