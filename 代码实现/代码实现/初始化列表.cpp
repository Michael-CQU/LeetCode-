#include<iostream>
using namespace std;
class Sprout1{
public:
    Sprout1(){ // 无参构造函数
        cout << "Construct Sprout1" << endl;
    }
    Sprout1(const Sprout1& t1){ // 拷贝构造函数
        cout << "Copy constructor for Sprout1" << endl;
        this->a = t1.a;
    }
    Sprout1& operator = (const Sprout1& t1){ // 赋值运算符
        cout << "assignment for Sprout1" << endl;
        this->a = t1.a;
        return *this;
    }
private:
    int a;
};
//class Sprout2{ //不使用初始化列表
//public:
//    Sprout1 test1;
//    Sprout2(Sprout1 &t1){
//        test1 = t1;
//    }
//};

class Sprout2{ //使用初始化列表
public:
    Sprout1 test1;
    Sprout2(Sprout1 &t1):test1(t1){}
};

//测试代码
//int main() {
//	Sprout1 t1;
//	Sprout2 t2(t1);
//
//	return 0;
//}