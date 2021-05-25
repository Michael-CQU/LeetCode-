#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <ctime>
//#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

////字符串插入和删除
//void test01()
//{
//	string str = "hello";
//	str.insert(1, "111");
//	cout << str << endl;
//
//	str.erase(1, 3);  //从1号位置开始3个字符
//	cout << str << endl;
//
//	str.insert(1,5,'c');
//	cout << str << endl;
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


//#include <vector>
//
//void printVector(vector<int>& v) {
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01()
//{
//	vector<int> v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		//v1[i] = i;
//	}
//	printVector(v1);
//	if (v1.empty())
//	{
//		cout << "v1为空" << endl;
//	}
//	else
//	{
//		cout << "v1不为空" << endl;
//		cout << "v1的容量 = " << v1.capacity() << endl;
//		cout << "v1的大小 = " << v1.size() << endl;
//	}
//
//	//resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
//	v1.resize(15, 10);
//	cout << "v1的容量 = " << v1.capacity() << endl;
//	printVector(v1);
//
//	//resize 重新指定大小 ，若指定的更小，超出部分元素被删除
//	v1.resize(5);
//	cout << "v1的容量 = " << v1.capacity() << endl;
//	printVector(v1);
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

//#include <vector>
//
//void test01()
//{
//	vector<int> v;
//
//	//预留空间
//	//v.reserve(100000);
//
//	int num = 0;
//	int* p = NULL;
//	for (int i = 0; i < 100000; i++) {
//		v.push_back(i);
//		if (p != &v[0]) {
//			p = &v[0];
//			num++;
//			cout << "num:" << num << endl;
//			cout << "v的容量为：" << v.capacity() << endl;
//			cout << "v的大小为：" << v.size() << endl;
//		}
//	}
//
//	/*cout << "num:" << num << endl;*/
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

//#include <deque>
//#include <vector>
//#include <ctime>
//#include <algorithm>
////选手类
//class Person
//{
//public:
//	Person(string name, int score)
//	{
//		this->m_Name = name;
//		this->m_Score = score;
//	}
//
//	string m_Name; //姓名
//	int m_Score;  //平均分
//};
//
//void createPerson(vector<Person>&v)
//{
//	string nameSeed = "ABCDE";
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "选手";
//		name += nameSeed[i];
//
//		int score = 0;
//
//		Person p(name, score);
//
//		//将创建的person对象 放入到容器中
//		v.push_back(p);
//	}
//}
//
////打分
//void setScore(vector<Person>&v)
//{
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		//将评委的分数 放入到deque容器中
//		deque<int>d;
//		for (int i = 0; i < 10; i++)
//		{
//			int score = rand() % 41 + 60;  // 60 ~ 100
//			d.push_back(score);
//		}
//
//		//cout << "选手： " << it->m_Name << " 打分： " << endl;
//		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
//		//{
//		//	cout << *dit << " ";
//		//}
//		//cout << endl;
//
//		//排序
//		sort(d.begin(), d.end());
//
//		//去除最高和最低分
//		d.pop_back();
//		d.pop_front();
//
//		//取平均分
//		int sum = 0;
//		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
//		{
//			sum += *dit; //累加每个评委的分数
//		}
//
//		int avg = sum / d.size();
//
//		//将平均分 赋值给选手身上
//		it->m_Score = avg;
//	}
//
//}
//
//void showScore(vector<Person>&v)
//{
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名： " << it->m_Name << " 平均分： " << it->m_Score << endl;
//	}
//}
//
//int main() {
//
//	//随机数种子
//	srand((unsigned int)time(NULL));
//
//	//1、创建5名选手
//	vector<Person>v;  //存放选手容器
//	createPerson(v);
//
//	//测试
//	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	//{
//	//	cout << "姓名： " << (*it).m_Name << " 分数： " << (*it).m_Score << endl;
//	//}
//
//	//2、给5名选手打分
//	setScore(v);
//
//	//3、显示最后得分
//	showScore(v);
//
//	system("pause");
//
//	return 0;
//}

//#include <vector>
//#include <functional>
//#include <algorithm>
//void test01()
//{
//	vector<bool> v;
//	v.push_back(true);
//	v.push_back(false);
//	v.push_back(true);
//	v.push_back(false);
//
//	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
//	vector<bool> v2;
//	//v2.resize(v.size());
//	//transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
//	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		v2.push_back(*it);
//	}
//	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
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

//#include <algorithm>
//#include <vector>
//
////普通函数
//void print01(int val)
//{
//	cout << val << " ";
//}
////函数对象
//class print02
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//	void aa(int val)
//	{
//		cout << val << "1";
//	}
//};
//
////for_each算法基本用法
//void test01() {
//
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	//遍历算法
//	for_each(v.begin(), v.end(), print01);
//	cout << endl;
//
//	print02 p;
//	for_each(v.begin(), v.end(), p);
//	cout << endl;
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

//#include <algorithm>
//#include <vector>
//
//void test01()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(5);
//	v.push_back(2);
//	v.push_back(4);
//	v.push_back(4);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(2);
//
//	//查找相邻重复元素
//	for (vector<int>::iterator it1 = v.begin(); it1 != v.end(); it1++) {
//		vector<int>::iterator it = adjacent_find(it1, v.end());
//		if (it == v.end()) {
//			cout << "找不到!" << endl;
//		}
//		else {
//			cout << "找到相邻重复元素为:" << *it << endl;
//			it1 = it;
//		}
//	}
//}
//int main(){
//	test01();
//	system("pause");
//	return 0;
//}

//#include <vector>
//
//class myPrint
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//};
//
//void test01()
//{
//	vector<int> v1;
//	vector<int> v2;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//
//	vector<int> vTarget;
//	//取两个里面较大的值给目标容器开辟空间
//	vTarget.resize(10);
//
//	//返回目标容器的最后一个元素的迭代器地址
//	cout << "v1与v2的差集为： " << endl;
//	vector<int>::iterator itEnd =
//		set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for_each(vTarget.begin(), itEnd, myPrint());
//	cout << endl;
//
//
//	cout << "v2与v1的差集为： " << endl;
//	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
//	for_each(vTarget.begin(), itEnd, myPrint());
//	cout << endl;
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

//class Person {
//public:
//	Person() {};
//	Person(int a, int b)
//	{
//		this->m_A = a;
//		this->m_B = b;
//	}
//	//成员函数实现 + 号运算符重载
//	Person operator+(const Person& p) {
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}
//
//
//public:
//	int m_A;
//	int m_B;
//};
//
////全局函数实现 + 号运算符重载
////Person operator+(const Person& p1, const Person& p2) {
////	Person temp(0, 0);
////	temp.m_A = p1.m_A + p2.m_A;
////	temp.m_B = p1.m_B + p2.m_B;
////	return temp;
////}
//
////运算符重载 可以发生函数重载 
//Person operator+(const Person& p2, int val)
//{
//	Person temp;
//	temp.m_A = p2.m_A + val;
//	temp.m_B = p2.m_B + val;
//	return temp;
//}
//
//void test() {
//
//	Person p1(10, 10);
//	Person p2(20, 20);
//
//	//成员函数方式
//	Person p3 = p2 + p1;  //相当于 p2.operaor+(p1)
//	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;
//
//
//	//Person p4 = p3 + 10; //相当于 operator+(p3,10)
//	//cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
//
//}
//
//int main() {
//
//	test();
//
//	system("pause");
//
//	return 0;
//}
//初始化列表
//#include <iostream>
//using namespace std;
//
//class student
//{
//public:
//
//	student(int i, int j);
//
//protected:
//	const int a;
//	int &b;
//
//
//};
//student::student(int i, int j) :a(i), b(j) {}
//
//int main() {
//	student s(1,2);
//	system("pause");
//	return 0;
//}

//静态成员函数与静态成员变量
//#include <iostream>
//using namespace std;
//
//class B {
//private:
//	int x;
//	int y;
//	static int count;
//public:
//	B() :x(0), y(0) {
//		count++;
//	}
//	B(int xx, int yy) :x(xx), y(yy) {
//		count++;
//	}
//	static int getObjCount();
//};
//int B::count = 0;
//int B::getObjCount() {
//	cout << B::x << endl;
//	return count;
//}
//int main()
//{
//	B b;
//	cout << B::getObjCount() << endl;
//	B b1;
//	//cout << b1.getObjCount(b) << endl;
//	B b2(10, 20);
//	
//	//cout << b2.getObjCount(b) << endl;
//	//cout << B::getObjCount(b) << endl;
//
//	B *p = new B;
//	//cout << p->getObjCount(b) << endl;
//	system("pause");
//	return 0;
//}

//括号匹配

//void printMatchedPairs(string expr) {
//	stack<int> s;
//	int length = (int)expr.size();
//
//	for (int i = 0; i < length; i++)
//		if (expr[i] == '(')
//			s.push(i);
//		else if(expr[i] == ')')
//			try {
//			cout << s.top() << ' ' << i << endl;
//			s.pop();
//		}
//		catch(stackem)
//}