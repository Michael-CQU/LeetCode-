#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
	priority_queue<int, vector<int>, greater<int>> A;//greater����С���ѣ�����߶�����Ǵ�����
	priority_queue<int, vector<int>, less<int>> B;//less����󶥶ѣ�����߶�����ǱȽ�С������
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {//��һ��С������һ���󶥶���ά����ͬʱҪȷ���������������ȶ�
		if (A.size() != B.size()) {//��A,B�����������ͬʱ��Ĭ�������A�����������࣬���Ҫ��B�ȶ�һ�����������Ҫ��num����A�н���ɸѡ����A����С����ɸѡ�����ٸ�B
			A.push(num);
			B.push(A.top());
			A.pop();
		}
		else {//��A,B����������ͬʱ����ʱҪ��A�е�����һ�������ǲ���ֱ�ӽ�num��ӵ�A�У���ΪҲ��num��ֵҪ��B�е�ĳЩֵС�����Ҫ�Ƚ�num����B�н���ɸѡ��Ȼ���ٽ�B�����뵽A��
			B.push(num);
			A.push(B.top());
			B.pop();
		}
	}

	double findMedian() {
		return A.size() != B.size() ? A.top() : (A.top() + B.top()) / 2.0;//ע������Ҫд��2.0������д��2����Ϊ���д��2�ͻ�����ȡ�����Ӷ���С�����ֽ��нضϣ����½���Ĳ���ȷ
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