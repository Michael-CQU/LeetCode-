//#include<bits/stdc++.h>
//using namespace std;
//
//ǰ i ���ַ����Ӵ����ܷ�ֽ�ɵ���
//ʣ���Ӵ����Ƿ�Ϊ�������ʡ�
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        unordered_set<string> st;
//        for(string word:wordDict){
//            st.insert(word);
//        }
//        int n = wordDict.size();
//        vector<bool> dp(n+1,0);
//        dp[0] = true;
//        for(int i = 1;i<=s.size();i++){
//            for(int j = 0;j<i;j++){
//                //if(dp[j] == false)continue;
//                if(dp[j]&&st.find(s.substr(j,i-j))!=st.end()){
//                    dp[i] = true;
//                    break;
//                }
//            }
//        }
//        return dp[s.size()];
//    }
//};
//
//int main() {
//	Solution s;
//	string s1 = "leetcode";
//	vector<string> word = { "leet","code" };
//	s.wordBreak(s1,word);
//	system("pause");
//}