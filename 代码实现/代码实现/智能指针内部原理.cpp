//#include <iostream>  
//#include <stdlib.h>  
//using namespace std;  
//
//template <typename T>  
//class mysharedPtr {  
//public:  
//    mysharedPtr(T* p = NULL);  
//    ~mysharedPtr();  
//    mysharedPtr(const mysharedPtr<T>& other);  
//    mysharedPtr<T>& operator=(const mysharedPtr<T>& other);  
////private:  
//    T* m_ptr;  
//    unsigned int* m_count;  
//};  
//
//template <typename T>  
//mysharedPtr<T>::mysharedPtr(T* p) {  
//    m_ptr = p;  
//    m_count = new unsigned int(0);  
//    ++(*m_count);  
//    cout << "Constructor is succeed!" << endl;  
//}  
//
//template <typename T>  
//mysharedPtr<T>::~mysharedPtr() {  
//    --(*m_count);  
//    if ((*m_count) == 0) {  
//        delete[] m_ptr;  
//        m_ptr = NULL;  
//        delete[] m_count;  
//        m_count = NULL;  
//        cout << "Destructor is succeed!" << endl;  
//    }  
//}  
//
//template <typename T>  
//mysharedPtr<T>::mysharedPtr(const mysharedPtr<T>& other) {  
//    m_ptr = other.m_ptr;  
//    m_count = other.m_count;  
//    ++(*m_count);  
//    cout << "Copy constructor is succeed!" << endl;  
//}  
//
//template <typename T>  
//mysharedPtr<T>& mysharedPtr<T>::operator=(const mysharedPtr<T>& other) {  
//    // ��C++ primer�����������ֵ�������ڼ������������ʹ�ü���֮ǰʹother��ʹ�ü�����1��  
//    // �Ӷ���ֹ����ֵ�������µ������ͷ��ڴ�  
//    ++(*other.m_count);  //ע�⴫����const�޶�����ָ�룬����ָ������õ�ֵ���Ը�
//    --(*m_count);  //���m_countΪ1�Ļ�����Ҫ�ı�ָ���ָ������Ҫ��ָ��ԭ�е�ָ����ͷŵ�
//    // ��������������ʹ�ü�����1�����ö����ʹ�ü�������0����ɾ���ö���  
//    if ((*m_count) == 0) {  
//        delete[] m_ptr;  
//        m_ptr = NULL;  
//        delete[] m_count;  
//        m_count = NULL;  
//        cout << "Left side object is deleted!" << endl;  
//    }  
//    m_ptr = other.m_ptr;  
//    m_count = other.m_count;  
//    cout << "Assignment operator overloaded is succeed!" << endl;  
//    return *this;  
//}  
//
//int main() {  
//    // Test Constructor and Assignment Operator Overloaded  
//    mysharedPtr<int> p1(new int(0));  
//    p1 = p1;  
//    // Test Copy Constructor  
//    mysharedPtr<int> p2(p1);  
//    // Test Assignment Operator Overloaded  
//    mysharedPtr<int> p3(new int(1)); 
//	cout << *p3.m_ptr << endl;
//    p3 = p1;
//	cout << *p3.m_ptr << endl;
//	cout << *p3.m_count << endl;
//    system("Pause");  
//    return 0;  
//} 