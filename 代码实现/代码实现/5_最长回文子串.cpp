/*暴力解法
class Solution {
public:
string longestPalindrome(string s) {
int len = s.size();
if(len < 2)
return s;
int maxLen = 1;
int begin = 0;
string charArray = s;

//枚举所有长度严格大于1的字串，charArray[i..j]
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
//验证字串是否为回文串
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

/*中心扩展法
//中心扩展法一定要考虑中心为一个值还有中心为两个值的情况
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
//自己实现中心扩展法
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

//动态规划
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
		// dp[i][j] 表示 s[i..j] 是否是回文串
		vector<vector<int>> dp(n, vector<int>(n));//注意dp是一个矩阵
												  // 初始化：所有长度为 1 的子串都是回文串
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		// 递推开始
		// 先枚举子串长度
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

				// 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
				if (dp[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxLen);
	}
};