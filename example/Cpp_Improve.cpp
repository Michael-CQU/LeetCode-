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

////�ַ��������ɾ��
//void test01()
//{
//	string str = "hello";
//	str.insert(1, "111");
//	cout << str << endl;
//
//	str.erase(1, 3);  //��1��λ�ÿ�ʼ3���ַ�
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
//		cout << "v1Ϊ��" << endl;
//	}
//	else
//	{
//		cout << "v1��Ϊ��" << endl;
//		cout << "v1������ = " << v1.capacity() << endl;
//		cout << "v1�Ĵ�С = " << v1.size() << endl;
//	}
//
//	//resize ����ָ����С ����ָ���ĸ���Ĭ����0�����λ�ã������������ذ汾�滻Ĭ�����
//	v1.resize(15, 10);
//	cout << "v1������ = " << v1.capacity() << endl;
//	printVector(v1);
//
//	//resize ����ָ����С ����ָ���ĸ�С����������Ԫ�ر�ɾ��
//	v1.resize(5);
//	cout << "v1������ = " << v1.capacity() << endl;
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
//	//Ԥ���ռ�
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
//			cout << "v������Ϊ��" << v.capacity() << endl;
//			cout << "v�Ĵ�СΪ��" << v.size() << endl;
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
////ѡ����
//class Person
//{
//public:
//	Person(string name, int score)
//	{
//		this->m_Name = name;
//		this->m_Score = score;
//	}
//
//	string m_Name; //����
//	int m_Score;  //ƽ����
//};
//
//void createPerson(vector<Person>&v)
//{
//	string nameSeed = "ABCDE";
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "ѡ��";
//		name += nameSeed[i];
//
//		int score = 0;
//
//		Person p(name, score);
//
//		//��������person���� ���뵽������
//		v.push_back(p);
//	}
//}
//
////���
//void setScore(vector<Person>&v)
//{
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		//����ί�ķ��� ���뵽deque������
//		deque<int>d;
//		for (int i = 0; i < 10; i++)
//		{
//			int score = rand() % 41 + 60;  // 60 ~ 100
//			d.push_back(score);
//		}
//
//		//cout << "ѡ�֣� " << it->m_Name << " ��֣� " << endl;
//		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
//		//{
//		//	cout << *dit << " ";
//		//}
//		//cout << endl;
//
//		//����
//		sort(d.begin(), d.end());
//
//		//ȥ����ߺ���ͷ�
//		d.pop_back();
//		d.pop_front();
//
//		//ȡƽ����
//		int sum = 0;
//		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
//		{
//			sum += *dit; //�ۼ�ÿ����ί�ķ���
//		}
//
//		int avg = sum / d.size();
//
//		//��ƽ���� ��ֵ��ѡ������
//		it->m_Score = avg;
//	}
//
//}
//
//void showScore(vector<Person>&v)
//{
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "������ " << it->m_Name << " ƽ���֣� " << it->m_Score << endl;
//	}
//}
//
//int main() {
//
//	//���������
//	srand((unsigned int)time(NULL));
//
//	//1������5��ѡ��
//	vector<Person>v;  //���ѡ������
//	createPerson(v);
//
//	//����
//	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	//{
//	//	cout << "������ " << (*it).m_Name << " ������ " << (*it).m_Score << endl;
//	//}
//
//	//2����5��ѡ�ִ��
//	setScore(v);
//
//	//3����ʾ���÷�
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
//	//�߼���  ��v�������˵�v2�У���ִ���߼�������
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
////��ͨ����
//void print01(int val)
//{
//	cout << val << " ";
//}
////��������
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
////for_each�㷨�����÷�
//void test01() {
//
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	//�����㷨
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
//	//���������ظ�Ԫ��
//	for (vector<int>::iterator it1 = v.begin(); it1 != v.end(); it1++) {
//		vector<int>::iterator it = adjacent_find(it1, v.end());
//		if (it == v.end()) {
//			cout << "�Ҳ���!" << endl;
//		}
//		else {
//			cout << "�ҵ������ظ�Ԫ��Ϊ:" << *it << endl;
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
//	//ȡ��������ϴ��ֵ��Ŀ���������ٿռ�
//	vTarget.resize(10);
//
//	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
//	cout << "v1��v2�ĲΪ�� " << endl;
//	vector<int>::iterator itEnd =
//		set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for_each(vTarget.begin(), itEnd, myPrint());
//	cout << endl;
//
//
//	cout << "v2��v1�ĲΪ�� " << endl;
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
//	//��Ա����ʵ�� + �����������
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
////ȫ�ֺ���ʵ�� + �����������
////Person operator+(const Person& p1, const Person& p2) {
////	Person temp(0, 0);
////	temp.m_A = p1.m_A + p2.m_A;
////	temp.m_B = p1.m_B + p2.m_B;
////	return temp;
////}
//
////��������� ���Է����������� 
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
//	//��Ա������ʽ
//	Person p3 = p2 + p1;  //�൱�� p2.operaor+(p1)
//	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;
//
//
//	//Person p4 = p3 + 10; //�൱�� operator+(p3,10)
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
//��ʼ���б�
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

//��̬��Ա�����뾲̬��Ա����
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

//����ƥ��

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