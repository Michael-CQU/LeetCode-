#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	*
	*
	* @param n string字符串
	* @return int整型
	*/
	int NS_LIS(string n) {
		// write code here
		int temp = n[0]-'0';
		int num = n.size();
		int last = n[num-1]-'0';
		if (num ==1)return stoi(n);
		int res = (num - 1) * 9 + temp - 1;
		if (last == 9)
			res++;
		return res;
	}
};
//int main() {
//	//string s = "110328324";
//	string s = "19";
//	Solution ss;
//	int res = ss.NS_LIS(s);
//	return 0;
//}

//int main() {
//	int n = 0;
//	char y[10] = "ntse";
//	char *x = y;
//	n = strlen(x);
//	*x = x[n];
//	x++;
//
//	cout << x << endl;
//	cout << y << endl;
//	return 0;
//}