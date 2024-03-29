#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = " " + s;//�ڱ�
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i<=n;i++){
            int temp = (s[i-1]-'0')*10+(s[i]-'0');
            if(s[i]!='0'){
                dp[i] = dp[i-1];
            }
            if(temp>=10&&temp<=26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};

//int main() {
//	Solution s;
//	string input = "30";
//	s.numDecodings(input);
//	system("pause");
//}