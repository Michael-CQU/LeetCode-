#include<bits/stdc++.h>
using namespace std;
class Solution {
	vector<char> q;
public:
	string removeKdigits(string num, int k) {
		int n = num.size();
		int count = 0;
		string ans = "0";
		if (k >= n)return ans;//�������Ҫɾ���������ڵ������鳤�ȣ�ֱ�ӷ���0
		for (char i : num) {
			while (count < k && !q.empty() && i < q.back()) {//���ȹ��ɵ�������
				q.pop_back();
				count++;
			}
			q.push_back(i);
		}
		while (count < k) {//�������й�����ɺ󣬶������г��ȳ�����ַ�����ɾ��
			q.pop_back();
			count++;
		}
		for (char i : q) {//��vector�е��ַ�������ans�ַ�����
			ans += i;
		}
		int i = 0;
		while (ans[i] == '0'&&i != ans.size() - 1)//ȥ��ǰ��0
			i++;
		return ans.substr(i);
	}
};