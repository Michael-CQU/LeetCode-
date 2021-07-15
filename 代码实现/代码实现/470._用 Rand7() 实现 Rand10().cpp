#include<bits/stdc++.h>
using namespace std;
////自己实现
//class Solution {
//public:
//    int rand7(){
//        int m = rand()%7;
//        return m;
//    }
//    int rand10() {
//        int x = 41;
//        while(x>39)
//            x = rand7()+rand7()*7;
//        return x%10+1;
//    }
//};
////用官方给的rand7（）
//class Solution {
//public:
//    int Rand7(){
//        int m = rand7();
//        return m;
//    }
//    int rand10() {
//        int x = 41;
//        while(x>40)
//            x = Rand7()+(Rand7()-1)*7;
//        return x%10+1;
//    }
//};
//int main() {
//	Solution s;
//	int m = 1000;
//	int res = 0;
//	while (m--) {
//		res = s.rand10();
//		cout << res << endl;
//	}
//	system("pause");
//	return 0;
//}