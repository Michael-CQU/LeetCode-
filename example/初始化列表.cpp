#include<iostream>
using namespace std;
class Sprout1{
public:
    Sprout1(){ // �޲ι��캯��
        cout << "Construct Sprout1" << endl;
    }
    Sprout1(const Sprout1& t1){ // �������캯��
        cout << "Copy constructor for Sprout1" << endl;
        this->a = t1.a;
    }
    Sprout1& operator = (const Sprout1& t1){ // ��ֵ�����
        cout << "assignment for Sprout1" << endl;
        this->a = t1.a;
        return *this;
    }
private:
    int a;
};
//class Sprout2{ //��ʹ�ó�ʼ���б�
//public:
//    Sprout1 test1;
//    Sprout2(Sprout1 &t1){
//        test1 = t1;
//    }
//};

class Sprout2{ //ʹ�ó�ʼ���б�
public:
    Sprout1 test1;
    Sprout2(Sprout1 &t1):test1(t1){}
};

//���Դ���
//int main() {
//	Sprout1 t1;
//	Sprout2 t2(t1);
//
//	return 0;
//}