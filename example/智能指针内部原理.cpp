#include <iostream>  
#include <stdlib.h>  
using namespace std;  
//这个是旧版，看手撕的最新代码


//有一个引用计数的指针类型变量m_count，专门用于引用计数，使用拷贝构造函数和赋值拷贝构造函数时，引用计数加1，当引用计数为0时，释放资源。

//构造、析构、拷贝构造、赋值运算符（变量：int型计数器、T型指针）
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
    m_count = new unsigned int(0);//为m_count申请空间，并加1，说明有一个智能指针对象指向我们的内存资源。
    ++(*m_count);  
    cout << "Constructor is succeed!" << endl;  
}  

template <typename T>  
mysharedPtr<T>::~mysharedPtr() {  
    --(*m_count);  
    if ((*m_count) == 0) {//*m_count减1，结果为0时，说明没有智能指针对象指向我们的内存资源了，释放资源  
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
    ++(*m_count);//对象指向同一块内存资源，并且计数*m_count加1（因为在堆区，所以++可以共享，新旧值都会变化） 
    cout << "Copy constructor is succeed!" << endl;  
}  

template <typename T>  
mysharedPtr<T>& mysharedPtr<T>::operator=(const mysharedPtr<T>& other) {  
//“这个赋值操作符在减少左操作数的使用计数之前使other的使用计数加1，从而防止自身赋值”而导致的提早释放内存  
    ++(*other.m_count);//注意传参是const限定的是指针，所以指针解引用的值可以改，指向不可以改
    --(*m_count);//如果m_count为1的话，若要改变指针的指向，则需要把指针原有的指向给释放掉（注意先给*other.m_count++，再对*m_count--，防止自身赋值时候当*m_count为1时，先--*m_count为0了导致释放了资源）

	// 将左操作数对象的使用计数减1，若该对象的使用计数减至0，则删除该对象
    if ((*m_count) == 0) {//先释放资源  
        delete[] m_ptr;  
        m_ptr = NULL;  
        delete[] m_count;  
        m_count = NULL;  
        cout << "Left side object is deleted!" << endl;  
    }  
    m_ptr = other.m_ptr;//再指向新资源  
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