#include <iostream>  
#include <stdlib.h>  
using namespace std;  
//����Ǿɰ棬����˺�����´���


//��һ�����ü�����ָ�����ͱ���m_count��ר���������ü�����ʹ�ÿ������캯���͸�ֵ�������캯��ʱ�����ü�����1�������ü���Ϊ0ʱ���ͷ���Դ��

//���졢�������������졢��ֵ�������������int�ͼ�������T��ָ�룩
template <typename T>  
class mysharedPtr {  
public:  
    mysharedPtr(T* p = nullptr);  
    ~mysharedPtr();  
    mysharedPtr(const mysharedPtr<T>& other);  
    mysharedPtr<T>& operator=(const mysharedPtr<T>& other);  
//private:  
    T* m_ptr;  
    unsigned int* m_count;  
};  

template <typename T>  
mysharedPtr<T>::mysharedPtr(T* p) {  
    m_ptr = p;  
    m_count = new unsigned int(0);//Ϊm_count����ռ䣬����1��˵����һ������ָ�����ָ�����ǵ��ڴ���Դ��
    ++(*m_count);  
    cout << "Constructor is succeed!" << endl;  
}  

template <typename T>  
mysharedPtr<T>::~mysharedPtr() {  
    --(*m_count);  
    if ((*m_count) == 0) {//*m_count��1�����Ϊ0ʱ��˵��û������ָ�����ָ�����ǵ��ڴ���Դ�ˣ��ͷ���Դ  
        delete[] m_ptr;  
        m_ptr = NULL;  
        delete[] m_count;  
        m_count = NULL;  
        cout << "Destructor is succeed!" << endl;  
    }  
}  

template <typename T>  
mysharedPtr<T>::mysharedPtr(const mysharedPtr<T>& other) {  
    m_ptr = other.m_ptr;  
    m_count = other.m_count;  
    ++(*m_count);//����ָ��ͬһ���ڴ���Դ�����Ҽ���*m_count��1����Ϊ�ڶ���������++���Թ����¾�ֵ����仯�� 
    cout << "Copy constructor is succeed!" << endl;  
}  

template <typename T>  
mysharedPtr<T>& mysharedPtr<T>::operator=(const mysharedPtr<T>& other) {  
//�������ֵ�������ڼ������������ʹ�ü���֮ǰʹother��ʹ�ü�����1���Ӷ���ֹ����ֵ�������µ������ͷ��ڴ�  
    ++(*other.m_count);//ע�⴫����const�޶�����ָ�룬����ָ������õ�ֵ���Ըģ�ָ�򲻿��Ը�
    --(*m_count);//���m_countΪ1�Ļ�����Ҫ�ı�ָ���ָ������Ҫ��ָ��ԭ�е�ָ����ͷŵ���ע���ȸ�*other.m_count++���ٶ�*m_count--����ֹ����ֵʱ��*m_countΪ1ʱ����--*m_countΪ0�˵����ͷ�����Դ��

	// ��������������ʹ�ü�����1�����ö����ʹ�ü�������0����ɾ���ö���
    if ((*m_count) == 0) {//���ͷ���Դ  
        delete[] m_ptr;  
        m_ptr = NULL;  
        delete[] m_count;  
        m_count = NULL;  
        cout << "Left side object is deleted!" << endl;  
    }  
    m_ptr = other.m_ptr;//��ָ������Դ  
    m_count = other.m_count;  
    cout << "Assignment operator overloaded is succeed!" << endl;  
    return *this;  
}  

//int main() {  
//    // Test Constructor and Assignment Operator Overloaded  
//    mysharedPtr<int> p1(new int(0));  
//    p1 = p1;  
//	cout << *p1.m_count << endl;
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