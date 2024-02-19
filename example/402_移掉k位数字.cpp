#include<bits/stdc++.h>
using namespace std;
class Solution {
	vector<char> q;
public:
	string removeKdigits(string num, int k) {
		int n = num.size();
		int count = 0;
		string ans = "0";
		if (k >= n)return ans;//考虑如果要删除的数大于等于数组长度，直接返回0
		for (char i : num) {
			while (count < k && !q.empty() && i < q.back()) {//首先构成单调序列
				q.pop_back();
				count++;
			}
			q.push_back(i);
		}
		while (count < k) {//单调序列构建完成后，对序列中长度超标的字符进行删除
			q.pop_back();
			count++;
		}
		for (char i : q) {//将vector中的字符拷贝到ans字符串中
			ans += i;
		}
		int i = 0;
		while (ans[i] == '0'&&i != ans.size() - 1)//去除前导0
			i++;
		return ans.substr(i);
	}
};