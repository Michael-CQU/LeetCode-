#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
	priority_queue<int, vector<int>, greater<int>> A;//greater代表小顶堆（堆里边都存的是大数）
	priority_queue<int, vector<int>, less<int>> B;//less代表大顶堆（堆里边都存的是比较小的数）
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {//用一个小顶堆与一个大顶堆来维护，同时要确保堆内数据量的稳定
		if (A.size() != B.size()) {//当A,B里的数据量不同时，默认情况是A的数据量更多，因此要给B匀兑一个数，因此先要将num插入A中进行筛选，将A中最小的数筛选出来再给B
			A.push(num);
			B.push(A.top());
			A.pop();
		}
		else {//当A,B里数据量相同时，此时要让A中的数多一个，但是不能直接将num添加到A中，因为也许num的值要比B中的某些值小，因此要先将num插入B中进行筛选，然后再将B顶插入到A中
			B.push(num);
			A.push(B.top());
			B.pop();
		}
	}

	double findMedian() {
		return A.size() != B.size() ? A.top() : (A.top() + B.top()) / 2.0;//注意这里要写成2.0而不能写成2，因为如果写成2就会向下取整，从而将小数部分进行截断，导致结果的不正确
	}
};
//int main() {
//	vector<int> test = {7,4,5,8,3,1,2};
//	MedianFinder* obj = new MedianFinder();
//	for(int i:test)
//	obj->addNum(i);
//	double param_2 = obj->findMedian();
//	cout << param_2 << endl;
//	system("pause");
//	return 0;
//}