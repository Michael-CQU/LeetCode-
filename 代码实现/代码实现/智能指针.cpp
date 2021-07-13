//#include <iostream>  
//#include <memory>  
//using namespace std;  
///* 
//成员函数： 
//use_count 返回引用计数的个数 
//unique 返回是否是独占所有权( use_count 为 1) 
//swap 交换两个 shared_ptr 对象(即交换所拥有的对象) 
//reset 放弃内部对象的所有权或拥有对象的变更, 会引起原有对象的引用计数的减少 
//get 返回内部对象(指针)
//*/  
//int main(){  
//    string *s1 = new string("s1");  
//
//    shared_ptr<string> ps1(s1);  
//    shared_ptr<string> ps2;  
//    ps2 = ps1;  
//
//    cout << ps1.use_count() << endl;//2  
//    cout << ps2.use_count() << endl;//2  
//    cout << ps1.unique() << endl;//0  
//    cout << ps2.unique() << endl;//0  
//
//    string *s3 = new string("s3");  
//    shared_ptr<string> ps3(s3);  
//
//    cout << ps1.get() << endl;//返回内部对象(指针)  
//    cout << ps3.get() << endl;  
//    swap(ps1, ps3); //交换所拥有的对象  
//    cout << ps1.get()<<endl;  
//    cout << ps3.get() << endl;  
//
//    cout << ps1.use_count() << endl;//1  
//    cout << ps2.use_count() << endl;//2  
//    ps2 = ps1;  
//    cout << ps1.use_count() << endl;//2  
//    cout << ps2.use_count() << endl;//2  
//    ps1.reset();    //放弃ps1的拥有权，引用计数的减少  
//    cout << ps1.use_count() << endl;//0  
//    cout << ps2.use_count() << endl;//1  
//	system("pause");
//	return 0;
//}  