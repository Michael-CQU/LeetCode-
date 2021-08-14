//#include<bits/stdc++.h>
//using namespace std;

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<char,int> mp={{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}};
int main(){
    string a;
    while(cin>>a){
        int n = a.size();
        int res = 0;
        for(int i = 2;i<n;i++){
            res = res*16 + mp[a[i]];
        }
        cout << res <<endl;
    }
}