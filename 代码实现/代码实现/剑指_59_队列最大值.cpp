//#include<iostream>
//#include <queue>
//#include <deque>
//using namespace std;
//class MaxQueue {
//	queue<int> q;
//	deque<int> d;
//public:
//	MaxQueue() {
//
//	}
//
//	int max_value() {
//		if (d.empty())
//			return -1;
//		return d.front();
//		//return d.empty()?-1:d.front();
//	}
//
//	void push_back(int value) {
//		q.push(value);
//		while (!d.empty()&&d.back() <= value) {
//			d.pop_back();
//		}
//		d.push_back(value);
//	}
//
//	int pop_front() {
//		if (q.empty())return -1;
//		int tem = q.front();
//		q.pop();
//		if (tem == d.front())
//			d.pop_front();
//		return tem;
//	}
//};
//
//
//int main() {
//	int capacity = 2;
//	MaxQueue* obj = new MaxQueue();
//
//	obj->push_back(1);
//	obj->push_back(2);
//	int param_1 = obj->max_value();
//	cout << "param_1:" << param_1 << endl;
//	obj->pop_front();
//	int param_2 = obj->max_value();
//	cout << "param_2:" << param_2 << endl;
//	system("pause");
//	return 0;
//}