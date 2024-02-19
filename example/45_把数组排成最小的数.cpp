#include<bits/stdc++.h>
using namespace std;
//����һ���������ú������бȽϣ��޸ıȽϵĹ��򼴿�
//class Solution {
//public:
//	string minNumber(vector<int>& nums) {
//		string res;
//
//		sort(nums.begin(), nums.end(), cmp);
//        //if(st[0] == "0")//ע�⿴��ĿҪ�����������ǰ����0�����������ֱ�����0000����ֻ���һ��0
			//return "0";
//		for (int &num : nums)
//			res += to_string(num);              //���ת�����ַ�����ƴ��
//
//		return res;
//	}
//	static bool cmp(int &x, int &y)             //�ȽϺ���(һ�����Ա����������thisָ�룬����pure function�� static ��Ա������û��thisָ��ģ������á��ѱȽ�������������Ҳ�ǿ��Ե�)
//	{
//		return to_string(x) + to_string(y) < to_string(y) + to_string(x);
//	}
//};
//��������ͨ��ʵ���޸Ŀ����������ķ�ʽ
/*
������ nums �����������ֵ��ַ���Ϊ x �� y ����涨 �����жϹ��� Ϊ��(�൱��ͨ����Ϻ�����ݴ�С�Ա���ʵ�ֶԱ����ǰ���ݵĴ�С)
	��ƴ���ַ��� x + y > y + x ���� x �����ڡ� y ��
	��֮���� x + y < y + x ���� x ��С�ڡ� y ��
x ��С�ڡ� y ����������ɺ������� x Ӧ�� y ��ߣ������ڡ� ��֮��
*/
class Solution {
public:
	void myquicksort(vector<string>& st, int left, int right) {
		if (left >= right)return;
		int i = left, j = right;
		while (i < j) {//��st[left]������pivot��׼ֵ����
			while (st[j] + st[left] >= st[left] + st[j]&&i<j)
				j--;
			while (st[i] + st[left] <= st[left] + st[i]&&i<j)
				i++;
			swap(st[i], st[j]);
		}
		swap(st[i], st[left]);
		myquicksort(st,left,i-1);
		myquicksort(st,i+1,right);
	}
	string minNumber(vector<int>& nums) {
		vector<string> st;
		string res = "";
		for (int i : nums) {
			st.push_back(to_string(i));
		}
		myquicksort(st, 0, st.size() - 1);
		for (auto i : st)
			res += i;
		return res;
	}
};
//int main() {
//	vector<int> test = {3,30,34,9,5};
//	Solution s;
//	string res = s.minNumber(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}