//#include <iostream>  
//#include <unordered_map>  
//#include <map>
//#include <string>  
//using namespace std;
//int main()
//{
//	//ע�⣺C++11�ſ�ʼ֧�����ų�ʼ��
//	unordered_map<int, string> myMap = { { 5, "�Ŵ�" },{ 6, "����" } };//ʹ��{}��ֵ
//	myMap[2] = "����";  //ʹ��[ ]���е������룬���Ѵ��ڼ�ֵ2����ֵ�޸ģ���������롣
//	myMap.insert(pair<int, string>(3, "�¶�"));//ʹ��insert��pair����
//
//	//�������+��������ʹ��
//	auto iter = myMap.begin();//auto�Զ�ʶ��Ϊ����������unordered_map<int,string>::iterator
//	while (iter != myMap.end())
//	{
//		cout << iter->first << "," << iter->second << endl;
//		++iter;
//	}
//
//	//����Ԫ�ز����+��������ʹ��
//	auto iterator = myMap.find(2);//find()����һ��ָ��2�ĵ�����
//	if (iterator != myMap.end())
//		cout << endl << iterator->first << "," << iterator->second << endl;
//	system("pause");
//	return 0;
//}
