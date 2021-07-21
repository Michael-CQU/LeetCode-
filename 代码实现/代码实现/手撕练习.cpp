#include <bits/stdc++.h>
using namespace std;

//class Solution {
//	unordered_set<char> st;
//public:
//	int countPalindromicSubsequence(string s) {
//		int ans = 0;
//		int n = s.size();
//		for (int i = 0; i < n - 1; i++) {
//			int j = i + 1;
//			while (s[j] != s[i]&&j < n) {
//				j++;
//			}
//			int m = i + 1;
//			while (m<=n-1&&j!=n) {
//				if (st.find(s[m]) == st.end()&&m!=j) {
//					ans++;
//					st.insert(s[m]);
//				}
//				m++;
//			}
//		}
//			return ans;
//	}
//};

int main() {
	vector<int> numbers(1000);
	generate(numbers.begin(), numbers.end(), rand);
// lambda表达式
	int count3, count13;
count3 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 ==
0;});
cout << "能被3整除的个数为：" << count3 << endl;
count13 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 13
== 0; });
cout << "能被13整除的个数为：" << count13 << endl;
count3 = count13 = 0;
for_each(numbers.begin(), numbers.end(), [=](int x)mutable {count3 += x % 3 == 0;
count13 += x % 13 == 0; });
cout << "能被3整除的个数为：" << count3 << endl;
cout << "能被13整除的个数为：" << count13 << endl;
	system("pause");
	return 0;
}