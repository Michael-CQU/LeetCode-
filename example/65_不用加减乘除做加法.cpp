#include<bits/stdc++.h>
using namespace std;
//��a+bת���ɷǽ�λ��+��λ�����ڲ����üӷ������Ҫһֱת��ֱ���ڶ����������0�� �õݹ��д����ѭ��������һ���ӿ���
//�޽�λ�� �� ������� ������ͬ����λ �� ������ ������ͬ����������һλ��
//class Solution {
//public:
//	int add(int a, int b) {
//		while (b != 0)
//		{
//			int c = (unsigned int)(a & b) << 1;//��λ��������+����һλ
//			a ^= b;//�ǽ�λ�ͣ��������
//			b = c;
//		}
//		return a;
//	}
//};
//�ݹ鷽����
class Solution {
public:
	int add(int a, int b) {
		if (b == 0) {
			return a;
		}
		return add(a^b, (unsigned int)(a&b) << 1);//�����֧�ָ�ֵ���ƾ�ת���޷�������
	}
};
//int main() {
//	int a = -1;
//	int b = 2;
//	Solution s;
//	int res = s.add(a, b);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}