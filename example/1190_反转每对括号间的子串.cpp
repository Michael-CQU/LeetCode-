#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
//class Solution {
//public:
//	string reverseParentheses(string s) {
//		stack<char> stk;
//		
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] != ')')
//			{
//				stk.push(s[i]);
//			}
//			else {
//				string str = "";
//				while (stk.top() != '(') {
//					str += stk.top();
//					stk.pop();
//				}
//				stk.pop();
//
//				for (int k = 0; k < str.size(); k++) {
//					stk.push(str[k]);
//				}
//			}
//		}
//			string result;
//			while (!stk.empty())
//			{
//				result = stk.top()+result;
//				stk.pop();
//			}
//			return result;
//	}
//};
//

//自我实现
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string test = "";
        for(char i:s){
            if(i == '('){
                st.push(test);
                test = "";
            }
            else if(i == ')'){
                reverse(test.begin(),test.end());
                test = st.top()+test;
                st.pop();
            }
            else{
                test+=i;
            }
        }
        return test;
    }
};
//int main() {
//	string str = "(ed(et(oc))el)";
//	//string str = "a(bcdefghijkl(mno)p)q";
//	Solution s;
//	string result = s.reverseParentheses(str);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}