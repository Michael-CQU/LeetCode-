#include <bits/stdc++.h>
using namespace std;
//����ʵ�ֿ����ݣ�ʱ�临�Ӷ�ΪO��logk��
class Solution {
public:
	double myPow(double x, int n) {
		long long k = n;
		if (k < 0) {
			k = -k;
			x = 1 / x;
		}
		double res = 1;
		while (k) {
			if (k & 1)
				res = res*x;
			k >>= 1;
			x = x*x;
		}
		return res;
	}
};
//������
//class Solution {
//public:
//	double myPow(double x, int n) {
//		if (x == 0)return 0;//��ֹ����Ϊ0
//		long long b = n;
//		double res = 1;
//		if (b < 0) {
//			x = 1 / x;
//			b = -b;
//		}
//		while (b > 0) {//���ݼ���ֳɼ���n�Ķ�������x=x^2�Ĳ������ǿ������㷨
//			if ((b & 1) == 1)res *= x;//�����ʱ��Ӧ�Ķ�����λΪ1�Ļ����ͽ�����˲�����resΪ���յ���˽�����������ʱ��Ӧ�Ķ�����λΪ0�����λ������x���κδη�������1.
//			x *= x;//����x^1,x^2,x^4,...,x^2^m-1�η�
//			b /= 2;//Ҳ���Խ�����λ����b>>=1
//		}
//		return res;
//	}
//};
//������
//class Solution {//����Ҫ˼���߽��������Լ�����Ĳ�������
//public:
//	double myPow(double x, int n) {
//		if (n == INT_MIN)return(x == 1 || x == -1) ? 1 : 0;//������������n��ֵΪ��Сֵʱ���޷����м��㣬���Խ�nת����long long��ʽ�����ô˷�������
//		if (n == 0)
//			return 1;
//		if (n < 0)
//			return myPow(1 / x, -n);
//		if (n % 2 == 1)
//			//return myPow(x, n - 1)*x;
//			return myPow(x*x, n / 2)*x;
//		else
//			return myPow(x*x, n / 2);
//	}
//};//ÿ�εݹ鶼��ʹ��ָ������һ�룬��˵ݹ�Ĳ���ΪO��logn��
//int main() {
//	double x = 1.0;
//	int n = INT_MIN;
//	Solution s;
//	double res = s.myPow(x,n);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}