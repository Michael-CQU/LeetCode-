/*
//滑动窗口算法框架
void slidingWindow(string s, string t) {
	unordered_map<char, int> need, window;
	for (char c : t) need[c]++;

	int left = 0, right = 0;
	int valid = 0;
	while (right < s.size()) {
		// c 是将移入窗口的字符
		char c = s[right];
		// 右移窗口
		right++;
		// 进行窗口内数据的一系列更新
		...

			//debug 输出的位置
			printf("window: [%d, %d)\n", left, right);

		// 判断左侧窗口是否要收缩
		while (window needs shrink) {
			// d 是将移出窗口的字符
			char d = s[left];
			// 左移窗口
			left++;
			// 进行窗口内数据的一系列更新
			...
		}
	}
}
*/

#include<iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> window;

		int left = 0, right = 0;
		int res = 0; // 记录结果
		while (right < s.size()) {
			char c = s[right];
			right++;
			// 进行窗口内数据的一系列更新
			window[c]++;

			//debug位置
			cout <<"c:"<< c <<"window[c]:"<< window[c] << endl;

			// 判断左侧窗口是否要收缩
			while (window[c] > 1) {
				char d = s[left];
				left++;
				// 进行窗口内数据的一系列更新
				window[d]--;
			}
			// 在这里更新答案
			res = max(res, right - left);
		}
		return res;
	}
};

//int main(){
//	string test = "abcabcbb";
//	Solution s;
//	int result = s.lengthOfLongestSubstring(test);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}