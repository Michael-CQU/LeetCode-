#include <bits/stdc++.h>
using namespace std;
/*
C++��������ȼ�
9	==  !=	����/������
10	&	��λ��
11	^	��λ���
12	|	��λ��
13  &&  ��
14  ||  ��
*/
//�������ʹ�ã�1.����ֻ����һ�ε������ڲ�ͬ�����У�2.��ͬ�����ֻᱻ�ֵ���ͬ�����С���ô��������ֱ���������������ɵõ��𰸵��������֡�
//������̣��ȶ��������ֽ���һ����򣬵õ���������һ�ε����ֵ����ֵ������������ҵ�����Ϊ 1 ��λ��������һλ�����е����ֽ��з��顣��ÿ�����ڽ������������õ��������֡�
class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int res = 0;//0���κ�����򶼲��䣬ֵ��Ȼ���κ�����ֵ
		for (int i : nums)
			res ^= i;
		int div = 1, a = 0, b = 0;
		while ((res&div) == 0)
			div <<= 1;
		for (int i : nums) {
			if (i&div) {//ע�����ʲôʱ����λ��&��ʲôʱ����λ���^
				a ^= i;
			}
			else {
				b ^= i;
			}
		}
		return{ a,b };
	}
};

//int main() {
//	vector<int> test = { 1,2,10,4,1,4,3,3 };
//	Solution s;
//	vector<int> res = s.singleNumbers(test);
//	for (int i : res)
//		cout << i << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}