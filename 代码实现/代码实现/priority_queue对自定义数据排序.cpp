#include<queue>
#include<iostream>

using namespace std;

class node {
public:
	node(int x = 0, int y = 0) :x(x), y(y) {}
	int x, y;
};
//新的排序规则为：先按照 x 值排序，如果 x 相等，则按 y 的值排序
bool operator < (const node &a,const node &b) {
	if (a.x > b.x) return 1;
	else if (a.x == b.x)
		if (a.y >= b.y) return 1;
	return 0;
}

//int main() {
//	//创建一个 priority_queue 容器适配器，其使用默认的 vector 基础容器以及 less 排序规则。
//	priority_queue<node> pq;
//	pq.push(node(1, 2));
//	pq.push(node(2, 2));
//	pq.push(node(3, 4));
//	pq.push(node(3, 3));
//	pq.push(node(2, 3));
//	cout << "x y" << endl;
//	while (!pq.empty()) {
//		cout << pq.top().x << " " << pq.top().y << endl;
//		pq.pop();
//	}
//	system("pause");
//	return 0;
//}