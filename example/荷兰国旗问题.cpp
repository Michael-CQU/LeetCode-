#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> netherlandsFlag(vector<int>& num,int L,int R,int target) {
		int less = L - 1;
		int more = R + 1;
		while (L < more) {
			if (num[L] < target) {
				swap(num[L++], num[++less]);
			}
			else if (num[L] == target) {
				L++;
			}
			else {
				swap(num[L], num[--more]);
			}
		}
		return{less+1,more-1};
	}
};
//int main() {
//	Solution s;
//	vector<int> input = {2, 3, 1, 9, 7, 6, 1, 4, 5};
//	vector<int> ans;
//	ans = s.netherlandsFlag(input,0,input.size()-1,4);
//	for (int i : ans)
//		cout << i << endl;
//	system("pause");
//}