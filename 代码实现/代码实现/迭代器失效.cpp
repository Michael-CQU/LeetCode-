#include<bits/stdc++.h>
using namespace std;  
//int main(){  
    //vector<int> v;  //v�Ǵ��int���ͱ����Ŀɱ䳤���飬��ʼʱû��Ԫ��  
    //for (int n = 0; n<5; ++n)  
    //    v.push_back(n);  //push_back��Ա������vector����β�����һ��Ԫ��  
    //vector<int>::iterator i;  //�������������  
    //for (i = v.begin(); i != v.end(); ++i) { 
    ////�õ���������������begin ��Ա��������ָ�������е�һ��Ԫ�صĵ�������++i ʹ�� i ָ�������е���һ��Ԫ�ء�end ��Ա�������صĲ���ָ�����һ��Ԫ�صĵ�����������ָ�����һ��Ԫ�غ����λ�õĵ����������ѭ������ֹ������i != v.end()  
    //    cout << *i << " ";  //*i ���ǵ�����iָ���Ԫ��  
    //    *i *= 2;  //ÿ��Ԫ�ر�Ϊԭ����2��  
    //}  
    //cout << endl;  
    ////�÷����������������  
    //for (vector<int>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j)  
    //    cout << *j << " ";  

	//1. ���ڽڵ�ʽ����(map, list, set)Ԫ�ص�ɾ������������ᵼ��ָ���Ԫ�صĵ�����ʧЧ������Ԫ�ص���������Ӱ��
	//2. ����˳��ʽ����(vector��string��deque)Ԫ�ص�ɾ������������ᵼ��ָ���Ԫ���Լ������Ԫ�صĵ�����ʧЧ
	//vector<int> vec = { 1,2,3,3,4,5 };
	//vector<int>::iterator iter2;
	//	for(iter2 = vec.begin(); iter2 != vec.end(); )
	//	{
	//		printf("%d " , *iter2 );
	//		//ע������
	//		if( *iter2 == 3 ){
	//			iter2 = vec.erase( iter2 );
	//		}else{
	//			iter2++;
	//		}
	//	}

//	list<int> vec = { 1,2,3,3,4,5 };
//	list<int>::iterator iter2;
//for(iter2 = vec.begin(); iter2 != vec.end();)
//{
//    printf("%d " , *iter2 );
//			if( *iter2 == 3 ){
//				iter2 = vec.erase( iter2 );
//			}else{
//				iter2++;
//			}
//}
//	map<int, int> testMap = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6} };
//	map<int,int>::iterator iter;
//for(iter = testMap.begin(); iter != testMap.end();)
//{
//    printf("%d " , iter->second );
//	if (iter->second == 3)
//	{
//		testMap.erase(iter++); //ע�������ͨ��keyɾ��
//	}
//	else
//		iter++;
//}
//	system("pause");
//    return 0;  
//}  