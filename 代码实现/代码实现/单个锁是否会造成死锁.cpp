#include<bits/stdc++.h>
using namespace std;

mutex mut;
void myprint() {
	mut.lock();
	cout << "第一次获取锁" << endl;
	mut.lock();
	cout << "第一次获取锁" << endl;
	mut.unlock();
}

//int main() {
//	thread t1(myprint);
//	t1.join();
//	system("pause");
//}