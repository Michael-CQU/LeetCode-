#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
    unordered_map<char,int> window,need;
    vector<int> ans;
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0,right = 0;
        int valid = 0;
        for(int i :p)
        need[i]++;
        while(right<s.size()){
            char c = s[right];
            right++;
            if(need.find(c)!=need.end()){
                window[c]++;
                if(window[c] == need[c])
                valid++;
            }
            while(right-left>=p.size()){
                if(valid == need.size())
                ans.push_back(left);
                char d = s[left];
                left++;
            if(need.find(d)!=need.end()){
                if(window[d] == need[d])
                valid--;
                window[d]--;
            }
            }
        }
        return ans;
    }
};

//int main(){
//	string test1, test2;
//	cin >> test1 >>test2;
//	Solution s;
//	vector<int> ans = s.findAnagrams(test1, test2);
//	for (int i : ans)
//		cout << i << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}