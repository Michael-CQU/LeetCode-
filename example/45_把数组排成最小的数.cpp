#include<bits/stdc++.h>
using namespace std;
//方法一：利用内置函数进行比较，修改比较的规则即可
//class Solution {
//public:
//	string minNumber(vector<int>& nums) {
//		string res;
//
//		sort(nums.begin(), nums.end(), cmp);
//        //if(st[0] == "0")//注意看题目要求，如果对于有前导“0”的情况，是直接输出0000还是只输出一个0
			//return "0";
//		for (int &num : nums)
//			res += to_string(num);              //逐个转换成字符串并拼接
//
//		return res;
//	}
//	static bool cmp(int &x, int &y)             //比较函数(一般类成员函数隐藏了this指针，不是pure function。 static 成员函数是没有this指针的，可以用。把比较器放在类外面也是可以的)
//	{
//		return to_string(x) + to_string(y) < to_string(y) + to_string(x);
//	}
//};
//方法二：通过实现修改快速排序规则的方式
/*
设数组 nums 中任意两数字的字符串为 x 和 y ，则规定 排序判断规则 为：(相当于通过组合后的数据大小对比来实现对比组合前数据的大小)
	若拼接字符串 x + y > y + x ，则 x “大于” y ；
	反之，若 x + y < y + x ，则 x “小于” y ；
x “小于” y 代表：排序完成后，数组中 x 应在 y 左边；“大于” 则反之。
*/
class Solution {
public:
	void myquicksort(vector<string>& st, int left, int right) {
		if (left >= right)return;
		int i = left, j = right;
		while (i < j) {//将st[left]当做是pivot基准值即可
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