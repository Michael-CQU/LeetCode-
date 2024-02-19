#include<bits/stdc++.h>
using namespace std;
//������ʹ�ÿռ�ķ���
/*
stack�����洢��min�Ĳ�ֵ��min�洢��Сֵ��ÿ�γ�ջ��ʱ��ͨ����ֵ�͵�ǰmin����Ҫ��ջ��ֵ��֮ǰ��min
�����ֵdiff���ڵ���0��˵��Ҫ��ջ��ֵ���ڵ��ڵ�ǰmin����ôҪ��ջ��ֵ����ջ��ʱ��û�и���min������min+diff��
�����ֵdiffС��0��˵����ǰҪ��ջ��ֵ����min(��Ϊ��ջ��ʱ������ѡ��ľ���min����ջԪ�ص���Сֵ)��ͬʱ��ͨ��min-diff�����֮ǰmin
Ҫע�����diff���ܻᳬ��int��Χ�������� Integer.MAX_VALUE - 1 ���֣�����diffҪ��Long��
*/
class MinStack {
	stack<long> data;
	int Min;
public:
	MinStack() {
		//data.push(0);
	}

	void push(int val) {
		if (data.empty()) {
			Min = val;
		}
		long long diff = (long)val - Min;//���val����С�������������Խ�磬������long������
		data.push(diff);
		Min = min(Min, val);
	}

	void pop() {
		long long diff = data.top();
		data.pop();
		if (diff >= 0);
		else {
			Min = (int)(Min - diff);
		}
	}

	int top() {
		long long diff = data.top();
		if (diff >= 0)
			return (int)(Min + diff);
		else
			return Min;
	}

	int getMin() {
		return Min;
	}


};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/