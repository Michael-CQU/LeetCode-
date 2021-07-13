#include<bits/stdc++.h>
using namespace std;  
//int main(){  
    //vector<int> v;  //v是存放int类型变量的可变长数组，开始时没有元素  
    //for (int n = 0; n<5; ++n)  
    //    v.push_back(n);  //push_back成员函数在vector容器尾部添加一个元素  
    //vector<int>::iterator i;  //定义正向迭代器  
    //for (i = v.begin(); i != v.end(); ++i) { 
    ////用迭代器遍历容器，begin 成员函数返回指向容器中第一个元素的迭代器。++i 使得 i 指向容器中的下一个元素。end 成员函数返回的不是指向最后一个元素的迭代器，而是指向最后一个元素后面的位置的迭代器，因此循环的终止条件是i != v.end()  
    //    cout << *i << " ";  //*i 就是迭代器i指向的元素  
    //    *i *= 2;  //每个元素变为原来的2倍  
    //}  
    //cout << endl;  
    ////用反向迭代器遍历容器  
    //for (vector<int>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j)  
    //    cout << *j << " ";  

	//1. 对于节点式容器(map, list, set)元素的删除，插入操作会导致指向该元素的迭代器失效，其他元素迭代器不受影响
	//2. 对于顺序式容器(vector，string，deque)元素的删除、插入操作会导致指向该元素以及后面的元素的迭代器失效
	//vector<int> vec = { 1,2,3,3,4,5 };
	//vector<int>::iterator iter2;
	//	for(iter2 = vec.begin(); iter2 != vec.end(); )
	//	{
	//		printf("%d " , *iter2 );
	//		//注意这里
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
//		testMap.erase(iter++); //注意这里，是通过key删除
//	}
//	else
//		iter++;
//}
//	system("pause");
//    return 0;  
//}  