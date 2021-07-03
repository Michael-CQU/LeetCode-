#include <bits/stdc++.h>
using namespace std;
//从后向前遍历效率高，不用让ans频繁移动后边的元素。三种方法的时间复杂度都是O（n），只有第二种方法的空间复杂度是O（1）
//方法一：双指针从后遍历，先找到整个单词，再将单词填入到ans中，利用ans存储最终的答案，需要额外的字符串空间O（n）
//class Solution {
//public:
//	string reverseWords(string s) {
//		int i = s.size() - 1;
//		string ans = "";
//		while (i >= 0) {
//			int c = 0;
//			while (i >= 0 && s[i] == ' ')
//				i--;
//			while (i >= 0 && s[i] != ' ') {
//				i--;
//				c++;
//			}
//			if(c)//防止前导空格导致ans重复执行，加入多余的空格
//			ans+=s.substr(i+1,c)+" ";
//		}
//		return ans.substr(0, ans.size() - 1);//删除最后一个多余的空格
//	}
//};
//方法二：双指针（空间复杂度为O（n））
class Solution {
public:
	string reverseWords(string s) {
		// 反转整个字符串
		reverse(s.begin(), s.end());

		int n = s.size();
		int idx = 0;//用于确定s字符串中单词的索引，即最后要确定的位置（重要，着重理解这个变量的含义）
		for (int start = 0; start < n; ++start) {
			if (s[start] != ' ') {
				// 填一个空白字符然后将idx移动到下一个单词的开头位置
				if (idx != 0) s[idx++] = ' ';//一个单词找完以后在这个单词后边添加一个空格，并将索引idx向后移动一位

				// 循环遍历至单词的末尾
				int end = start;//end和start两个指针是用来敲定单词范围的
				while (end < n && s[end] != ' ') s[idx++] = s[end++];

				// 反转整个单词
				reverse(s.begin() + idx - (end - start), s.begin() + idx);

				// 更新start，去找下一个单词
				start = end;
			}
		}
		s.erase(s.begin() + idx, s.end());//最后删除s中多余的部分（由于有前后导或者中间多余的0导致的多余位）
		return s;
	}
};
//方法三：双端队列（C++中尽量用deque来实现栈的功能，因为stack已经被舍弃了）：先将字符串中的数字一个一个找出来，然后将单词压入队列的头部，因为双端队列相当于栈，因此后找到的单词就压入了队列的头部，相当于把单词移到了前边。最后再用一个新的字符串来接收从队列头部出来的一个一个单词即可
//class Solution {
//public:
//	string reverseWords(string s) {
//		int left = 0, right = s.size() - 1;
//		// 去掉字符串开头的空白字符
//		while (left <= right && s[left] == ' ') ++left;
//
//		// 去掉字符串末尾的空白字符
//		while (left <= right && s[right] == ' ') --right;
//
//		deque<string> d;
//		string word;
//
//		while (left <= right) {
//			char c = s[left];
//			if (word.size() && c == ' ') {
//				// 将单词 push 到队列的头部
//				d.push_front(move(word));
//				word = "";
//			}
//			else if (c != ' ') {
//				word += c;
//			}
//			++left;
//		}
//		d.push_front(move(word));
//
//		string ans;
//		while (!d.empty()) {
//			ans += d.front();
//			d.pop_front();
//			if (!d.empty()) ans += ' ';
//		}
//		return ans;
//	}
//};
//int main() {
//	string test = "the sky is blue";
//	Solution s;
//	string res = s.reverseWords(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}