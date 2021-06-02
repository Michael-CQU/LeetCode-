/*
//���������㷨���
void slidingWindow(string s, string t) {
	unordered_map<char, int> need, window;
	for (char c : t) need[c]++;

	int left = 0, right = 0;
	int valid = 0;
	while (right < s.size()) {
		// c �ǽ����봰�ڵ��ַ�
		char c = s[right];
		// ���ƴ���
		right++;
		// ���д��������ݵ�һϵ�и���
		...

			//debug �����λ��
			printf("window: [%d, %d)\n", left, right);

		// �ж���ര���Ƿ�Ҫ����
		while (window needs shrink) {
			// d �ǽ��Ƴ����ڵ��ַ�
			char d = s[left];
			// ���ƴ���
			left++;
			// ���д��������ݵ�һϵ�и���
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
		int res = 0; // ��¼���
		while (right < s.size()) {
			char c = s[right];
			right++;
			// ���д��������ݵ�һϵ�и���
			window[c]++;

			//debugλ��
			cout <<"c:"<< c <<"window[c]:"<< window[c] << endl;

			// �ж���ര���Ƿ�Ҫ����
			while (window[c] > 1) {
				char d = s[left];
				left++;
				// ���д��������ݵ�һϵ�и���
				window[d]--;
			}
			// ��������´�
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