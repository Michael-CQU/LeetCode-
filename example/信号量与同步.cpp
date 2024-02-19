#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

class semaphore {
    public:
        semaphore(int value=1): count{value}{}
        
        void wait(){//P����
            unique_lock<std::mutex> lock(mut);//�˴�����ʹ��unique_lock,Ϊ����wait�����ͷ���
            if (--count<0) {
                condition.wait(lock); //��������ʱ�Զ��ͷ���
            }
        }
        void signal(){//V����
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
//�����й������ͳһʹ�� c++11 �� {} ��ʽ����Ȼ () ��Ȼʹ�ã����� count{value} �� count(value)��lock{mutex} �� lock(mutex) ���ǿ��Եģ�




//ʵ�ֶ��߳�ͬ��
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

//ʵ��������������
semaphore mu(1);
semaphore emptybuffer(100);//��emptyΪ0ʱ�����߲�����д
semaphore fullbuffer(0);//��full��Ϊ0ʱ�����߿��Զ�

void productor() {
	while (1) {
		emptybuffer.wait();
		mu.wait();
		//�����ɵ����ݷŵ���������
		cout << "����" << endl;
		mu.signal();
		fullbuffer.signal();
	}
}

void consumer() {
	while (1) {
		fullbuffer.wait();
		mu.wait();
		//�ӻ��������ȡ����
		cout << "����" << endl;
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