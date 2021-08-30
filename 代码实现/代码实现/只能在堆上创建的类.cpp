/*
class   NoStackObject
{
protected://构造函数设置为保护或者私有
	NoStackObject() {   }
	~NoStackObject() {   }
public:
	static   NoStackObject*   creatInstance()//必须是静态成员函数，因为静态成员函数可以不通过类对象访问，而是通过类名用作用域访问
	{
		return   new   NoStackObject();//调用保护的构造函数   
	}
	void   destroy()
	{
		delete   this;//调用保护的析构函数   
	}
};

NoStackObject*   hash_ptr = NoStackObject::creatInstance();
//对hash_ptr指向的对象进行操作   
hash_ptr->destroy();
hash_ptr = NULL;   //防止使用悬挂指针
*/

//产生堆对象的唯一方法是使用new, 禁止使用new就可禁止产生堆对象. 由于new执行时会调用operator new, 而operator new是可重载的, 所以将operator new和operator delete重载为private即可. 创建栈对象不需要调用new, 因为创建栈对象不需要搜索内存, 而是直接调整堆栈指针将对象压栈, 而operator new的主要任务是搜索合适的堆内存, 为堆对象分配空间.