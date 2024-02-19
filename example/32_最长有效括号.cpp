#include<bits/stdc++.h>
using namespace std;

class Solution {
stack<int> sk;
public:
    int longestValidParentheses(string s) {
        int len = 0,maxlen = 0;
        sk.push(-1);//始终保持栈底元素为当前已经遍历过的元素中「最后一个没有被匹配的右括号的下标」；如果一开始栈为空，第一个字符为左括号的时候我们会将其放入栈中，这样就不满足提及的「最后一个没有被匹配的右括号的下标」，为了保持统一，我们在一开始的时候往栈中放入一个值为 -1−1 的元素
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(')
                sk.push(i);
            else{
                sk.pop();
                if(sk.empty()){
                    sk.push(i);
                }
                else{
                    maxlen = max(maxlen,i-sk.top());
                }
            }
        }
        return maxlen;
    }
};