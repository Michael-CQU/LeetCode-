//#include<iostream>
//using namespace std;
//const int N = 10010;
//
////��new���������ٶ��������Ҫ�ڱ�����������ģ������(��̬����)
//
////head��ʾͷ�ڵ���±�
////e[i]��ʾ�ڵ�i��ֵ
////ne[i]��ʾ�ڵ�i��nextָ���Ƕ���
////idx�洢��ǰ�Ѿ��õ����ĸ���
//int head, e[N], ne[N], idx;
//
////��ʼ��
//void init() {
//	head = -1;
//	idx = 0;
//}
//
////��x���뵽ͷ�ڵ�
//void add_to_head(int x) {
//	e[idx] = x;
//	ne[idx] = head;
//	head = idx;
//	idx++;
//}
//
////��x���뵽�±���k�ĵ�ĺ�ߣ�ע�⻭ͼ��
//void add(int k, int x) {
//	e[idx] = x;
//	ne[idx] = ne[k];
//	ne[k] = idx;
//	idx++;
//}
//
////���±���k�ĵ����ĵ�ɾ��
//void remove(int k) {
//	ne[k] = ne[ne[k]];
//}
//int main() {
//	int m;
//	cin >> m;
//	init();
//	while (m--) {
//		int k, x;
//		char op;
//		cin >> op;
//		if (op == 'H') {
//			cin >> x;
//			add_to_head(x);
//		}
//		else if (op == 'D') {
//			cin >> k;
//			if (!k)head = ne[head];
//			else remove(k-1);
//		}
//		else {
//			cin >> k >> x;
//			add(k-1, x);
//		}
//	}
//	for (int i = head; i!= -1; i = ne[i])
//		cout << e[i] << " ";
//	cout << endl;
//	return 0;
//}