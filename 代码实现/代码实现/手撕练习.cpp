#include<bits/stdc++.h>
using namespace std;

uint64_t fun(uint32_t a) {
	static const uint32_t b = 1 << 12;
	return a*b;
}
//int main() {
//	int a = INT_MAX;
//	uint64_t res = fun(a);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}
