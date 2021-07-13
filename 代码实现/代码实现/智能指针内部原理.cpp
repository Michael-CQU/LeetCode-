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
//    // 《C++ primer》：“这个赋值操作符在减少左操作数的使用计数之前使other的使用计数加1，  
//    // 从而防止自身赋值”而导致的提早释放内存  
//    ++(*other.m_count);  //注意传参是const限定的是指针，所以指针解引用的值可以改
//    --(*m_count);  //如果m_count为1的话，若要改变指针的指向，则需要把指针原有的指向给释放掉
//    // 将左操作数对象的使用计数减1，若该对象的使用计数减至0，则删除该对象  
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