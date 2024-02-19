#include <bits/stdc++.h>
using namespace std;
/*
���
���a��b����ֵ����ͬ���������Ϊ1�����a��b����ֵ��ͬ�������Ϊ0��
1. �����ɣ�a^a = 0
2. ����ɣ�a^0 = a
3. �����ɣ�a^b = b^a
4. ����ɣ�a^b^c = a^c^b
5. �Է���a^b^a = b
*/
//����һ������ͳ�ƣ���ͳ�Ƹ�����λ��1�ĸ�����Ȼ�󽫸�����λ��mȡ�ಢ�ָ���res�ϣ��ؼ�����
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int counts[32] = { 0 };
		for (int num : nums) {
			for (int i = 0; i < 32; i++) {
				counts[i] += num & 1;//��¼�������ָ�������λ��1���ִ���
				num >>= 1;
			}
		}
		int res = 0, m = 3;//�ؼ���ֻ��Ҫ�޸�������ֵm������ʵ�ֽ�� ����һ���������⣬�������ֶ�����m�ε�ͨ������
		for (int i = 31; i >= 0; i--) {
			res <<= 1;
			res |= counts[i] % m;//���������(res<<=1������仰���±ߵĻ�)�����һ�ֵ� ���һ��������������ƣ���ô����һλ ��Զ�� 0 �ˣ������Ͳ����ˣ���仰���Եõ�ֻ����һ�ε��Ǹ����ֵĸ���������λ��ֵ�����ָ���res�ϣ�
		}
		return res;
	}
};
//������:����״̬�Զ�����û��ͨ���ԣ�Ҫ��������һ��
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int ones = 0, twos = 0;//��Ϊ��������ͬ��������˶�3����Ϊ0,1,2���������λ����������ʾ״̬
//		for (int num : nums) {
//			ones = ones ^ num & ~twos;//�������λ��״̬
//			twos = twos ^ num & ~ones;
//		}
//		return ones;//��Ϊ���ȡ��Ľ��ֻ��Ϊ0����1�����ֻ����onesλ��ֵ����
//	}
//};
//int main() {
//	vector<int> test = { 1,3,3,3,4,4,4 };
//	Solution s;
//	int res = s.singleNumber(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}