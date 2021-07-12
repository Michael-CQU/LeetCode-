/*�����ⷨ
class Solution {
public:
string longestPalindrome(string s) {
int len = s.size();
if(len < 2)
return s;
int maxLen = 1;
int begin = 0;
string charArray = s;

//ö�����г����ϸ����1���ִ���charArray[i..j]
for(int i = 0; i< len - 1;i++)
for(int j = i+1; j<len; j++)
{
if((j - i + 1) > maxLen && validPalindromic(charArray,i,j))
{
maxLen = j - i + 1;
begin = i;
}
}
return s.substr(begin,  maxLen);
}
//��֤�ִ��Ƿ�Ϊ���Ĵ�
bool validPalindromic(string charArray,int left,int right)
{
while(left < right)
{
if(charArray[left]!=charArray[right])
return false;
left++;
right--;
}
return true;
}
};
*/

/*������չ��
//������չ��һ��Ҫ��������Ϊһ��ֵ��������Ϊ����ֵ�����
class Solution {
public:
pair<int, int> expandAroundCenter(const string& s, int left, int right) {
while (left >= 0 && right < s.size() && s[left] == s[right]) {
--left;
++right;
}
return {left + 1, right - 1};
}

string longestPalindrome(string s) {
int start = 0, end = 0;
for (int i = 0; i < s.size(); ++i) {
auto [left1, right1] = expandAroundCenter(s, i, i);
auto [left2, right2] = expandAroundCenter(s, i, i + 1);
if (right1 - left1 > end - start) {
start = left1;
end = right1;
}
if (right2 - left2 > end - start) {
start = left2;
end = right2;
}
}
return s.substr(start, end - start + 1);
}
};
*/
//�Լ�ʵ��������չ��
//class Solution {
//public:
//    int mygetlength(string s,int left,int right){
//        while(left>=0&&right<s.size()&&s[left]==s[right]){
//            left--;
//            right++;
//        }
//        return right - left -1;
//    }
//    string longestPalindrome(string s) {
//        int res = 0;
//        int start = 0,len = 0;
//        for(int i = 0;i<s.size();i++){
//            int len1 = mygetlength(s,i,i);
//            int len2 = mygetlength(s,i,i+1);
//            res = max(max(len1,len2),res);
//            if(res>len){
//                start = i-(res-1)/2;
//                len = res;
//            }
//        }
//        return s.substr(start,len);
//    }
//};

//��̬�滮
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2) {
			return s;
		}

		int maxLen = 1;
		int begin = 0;
		// dp[i][j] ��ʾ s[i..j] �Ƿ��ǻ��Ĵ�
		vector<vector<int>> dp(n, vector<int>(n));//ע��dp��һ������
												  // ��ʼ�������г���Ϊ 1 ���Ӵ����ǻ��Ĵ�
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		// ���ƿ�ʼ
		// ��ö���Ӵ�����
		for (int j = 1; j < n; j++) {
			for (int i = 0; i < j; i++)
			{
				if (s[i] != s[j]) {
					dp[i][j] = false;
				}
				else {
					if (j - i < 3) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				}

				// ֻҪ dp[i][L] == true �������ͱ�ʾ�Ӵ� s[i..L] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
				if (dp[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxLen);
	}
};