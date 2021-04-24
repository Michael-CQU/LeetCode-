//#include <vector>
//#include <string>
//#include "time_interval.h"
//
//int main() {
//
//
//	std::vector<std::string> v;
//	int count = 10000000;
//	v.reserve(count);       //Ԥ����ʮ���С���ų��������ڴ��ʱ��
//
//	{
//		TIME_INTERVAL_SCOPE("push_back string:");
//		for (int i = 0; i < count; i++)
//		{
//			std::string temp("ceshi");
//			v.push_back(temp);// push_back(const string&)����������ֵ����
//		}
//	}
//
//	v.clear();
//	{
//		TIME_INTERVAL_SCOPE("push_back move(string):");
//		for (int i = 0; i < count; i++)
//		{
//			std::string temp("ceshi");
//			v.push_back(std::move(temp));// push_back(string &&), ��������ֵ����
//		}
//	}
//
//	v.clear();
//	{
//		TIME_INTERVAL_SCOPE("push_back(string):");
//		for (int i = 0; i < count; i++)
//		{
//			v.push_back(std::string("ceshi"));// push_back(string &&), ��������ֵ����
//		}
//	}
//
//	v.clear();
//	{
//		TIME_INTERVAL_SCOPE("push_back(c string):");
//		for (int i = 0; i < count; i++)
//		{
//			v.push_back("ceshi");// push_back(string &&), ��������ֵ����
//		}
//	}
//
//	v.clear();
//	{
//		TIME_INTERVAL_SCOPE("emplace_back(c string):");
//		for (int i = 0; i < count; i++)
//		{
//			v.emplace_back("ceshi");// ֻ��һ�ι��캯���������ÿ������캯�����ٶ����
//		}
//	}
//}