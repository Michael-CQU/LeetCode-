#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
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

#include <vector>
#include <functional>
#include <algorithm>
void test01()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}