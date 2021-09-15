#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

class semaphore {
    public:
        semaphore(int value=1): count{value}{}
        
        void wait(){//P操作
            unique_lock<std::mutex> lock(mut);//此处必须使用unique_lock,为了让wait可以释放锁
            if (--count<0) {
                condition.wait(lock); //会在阻塞时自动释放锁
            }
        }
        void signal(){//V操作
            lock_guard<std::mutex> lock(mut);
            if(++count<=0) {
                condition.notify_one();
            }
        }
        
    private:
        int count;
        std::mutex mut;
        condition_variable condition;
};
//程序中构造对象统一使用 c++11 的 {} 方式，虽然 () 依然使用，比如 count{value} 和 count(value)，lock{mutex} 和 lock(mutex) 都是可以的；




//实现多线程同步
//mutex m;
//semaphore ba(0), cb(0), dc(0);
// 
//void a()
//{
//    ba.wait();  // b --> a
//    std::lock_guard<std::mutex> lock{m};
//    std::cout << "thread a" << '\n';
//}
//void b()
//{
//    cb.wait();  // c --> b
//    std::lock_guard<std::mutex> lock{m};
//    std::cout << "thread b" << '\n';
//    ba.signal();  // b --> a
//}
//void c()
//{
//    dc.wait();  // d --> c
//    std::lock_guard<std::mutex> lock{m};
//    std::cout << "thread c" << '\n';
//    cb.signal();  // c --> b
//}
//void d()
//{
//    std::lock_guard<std::mutex> lock{m};
//    std::cout << "thread d" << '\n';
//    dc.signal();  // d --> c
//}
// 
//int main()
//{
//    
//    std::thread th1{a}, th2{b}, th3{c}, th4{d};
//    
//    th1.join();
//    th2.join();
//    th3.join();
//    th4.join();
//    
//    std::cout << "thread main" << std::endl;
//	system("pause");
//    return 0;
//}

//实现生产者消费者
semaphore mu(1);
semaphore emptybuffer(100);//当empty为0时生产者不可以写
semaphore fullbuffer(0);//当full不为0时消费者可以读

void productor() {
	while (1) {
		emptybuffer.wait();
		mu.wait();
		//将生成的数据放到缓冲区中
		cout << "生产" << endl;
		mu.signal();
		fullbuffer.signal();
	}
}

void consumer() {
	while (1) {
		fullbuffer.wait();
		mu.wait();
		//从缓冲区里读取数据
		cout << "消费" << endl;
		mu.signal();
		emptybuffer.signal();
		//Sleep(1);
	}
}

//int main() {
//	thread product(productor);
//	thread consum(consumer);
//	product.join();
//	consum.join();
//	system("pause");
//	return 0;
//}