//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<windows.h>
//using namespace std;
//int i = 0;
//mutex mux;
//void myprintf(int m) {
//	while (1) {
//		mux.lock();
//		if (i >= 10000)
//			break;
//		i++;
//		cout << m << "线程输出：" << i << endl;
//		Sleep(1);
//		mux.unlock();
//	}
//	cout << m << "线程执行完毕" << endl;
//}
//int main() {
//	thread t1(myprintf,1);
//	thread t2(myprintf,2);
//	thread t3(myprintf,3);
//	t1.join();
//	t2.join();
//	t3.join();
//	system("pause");
//}