#include<bits/stdc++.h>
using namespace std;
//不额外使用空间的方法
/*
stack用来存储和min的差值，min存储最小值，每次出栈的时候通过差值和当前min计算要出栈的值和之前的min
如果差值diff大于等于0，说明要出栈的值大于等于当前min，那么要出栈的值在入栈的时候没有更新min，返回min+diff；
如果插值diff小于0，说明当前要出栈的值就是min(因为入栈的时候我们选择的就是min和入栈元素的最小值)，同时，通过min-diff计算出之前min
要注意的是diff可能会超出int范围，类似于 Integer.MAX_VALUE - 1 这种，所以diff要用Long存
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
		long long diff = (long)val - Min;//如果val是最小的数，这里可能越界，所以用long来保存
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