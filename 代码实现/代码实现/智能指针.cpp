//#include <iostream>  
//#include <memory>  
//using namespace std;  
///* 
//��Ա������ 
//use_count �������ü����ĸ��� 
//unique �����Ƿ��Ƕ�ռ����Ȩ( use_count Ϊ 1) 
//swap �������� shared_ptr ����(��������ӵ�еĶ���) 
//reset �����ڲ����������Ȩ��ӵ�ж���ı��, ������ԭ�ж�������ü����ļ��� 
//get �����ڲ�����(ָ��)
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
//    cout << ps1.get() << endl;//�����ڲ�����(ָ��)  
//    cout << ps3.get() << endl;  
//    swap(ps1, ps3); //������ӵ�еĶ���  
//    cout << ps1.get()<<endl;  
//    cout << ps3.get() << endl;  
//
//    cout << ps1.use_count() << endl;//1  
//    cout << ps2.use_count() << endl;//2  
//    ps2 = ps1;  
//    cout << ps1.use_count() << endl;//2  
//    cout << ps2.use_count() << endl;//2  
//    ps1.reset();    //����ps1��ӵ��Ȩ�����ü����ļ���  
//    cout << ps1.use_count() << endl;//0  
//    cout << ps2.use_count() << endl;//1  
//	system("pause");
//	return 0;
//}  