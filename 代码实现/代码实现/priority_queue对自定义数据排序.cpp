#include<queue>
#include<iostream>

using namespace std;

class node {
public:
	node(int x = 0, int y = 0) :x(x), y(y) {}
	int x, y;
};
//�µ��������Ϊ���Ȱ��� x ֵ������� x ��ȣ��� y ��ֵ����
bool operator < (const node &a,const node &b) {
	if (a.x > b.x) return 1;
	else if (a.x == b.x)
		if (a.y >= b.y) return 1;
	return 0;
}

//int main() {
//	//����һ�� priority_queue ��������������ʹ��Ĭ�ϵ� vector ���������Լ� less �������
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