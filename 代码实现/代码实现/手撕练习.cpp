#include<iostream>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
		int n = s.size();
        string temp;
        bool flag = true;
        int i = 0;
        long long res = 0;
        while(i<n&&s[i] == ' ')
            i++;
        if(s[i] == '-'){
            flag = false;
            i++;
        }
        else if(s[i] == '+')
            i++;
        while(i<n&&(s[i]-'0')>=0&&(s[i]-'0')<=9){
            temp+=s[i];
            i++;
        }
        if(flag){
            for(int i = 0;i<temp.size();i++){
					res = res*10+(temp[i]-'0');
					if (res < INT_MAX / 10)
						return res;
                    else
                    return INT_MAX;
            }
        }
        else{
            for(int i = 0;i<temp.size();i++){
                    if(res>INT_MIN/10)
                    res = res*10-(temp[i]-'0');
                    else
                    return INT_MIN;
            }
        }
        return (int)res;
    }
};

int main() {
	Solution s;
	string test = "21474836460";
	int res = 0;
	res = s.myAtoi(test);
	cout << res << endl;
	system("pause");
	return 0;
}