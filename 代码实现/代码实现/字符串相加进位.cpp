#include<bits/stdc++.h>
using namespace std;

vector<int> myadd(vector<int>& a,vector<int>& b) {
	int t = 0;
	vector<int> c;
	for (int i = 0; i < a.size() || i < b.size(); i++) {
		if (i < a.size())t += a[i];
		if (i < b.size())t += b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if (t)c.push_back(1);
	return c;
}
//int main() {
//	string a, b;
//	vector<int> A, B;
//	cin >> a >> b;
//	for (int i = a.size() - 1; i >= 0;i--) {
//		A.push_back(a[i] - '0');
//	}
//	for (int i = b.size() - 1; i >= 0; i--) {
//		B.push_back(b[i] - '0');
//	}
//	vector<int> ans = myadd(A, B);
//	for (int i = ans.size()-1;i>=0;i--)
//		cout << ans[i];
//	cout << endl;
//	system("pause");
//	return 0;
//}