#include<bits/stdc++.h>
using namespace std;

mutex mut;
void myprint() {
	mut.lock();
	cout << "��һ�λ�ȡ��" << endl;
	mut.lock();
	cout << "��һ�λ�ȡ��" << endl;
	mut.unlock();
}

//int main() {
//	thread t1(myprint);
//	t1.join();
//	system("pause");
//}