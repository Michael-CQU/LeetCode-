#include<iostream>
#include<vector>
#include <string>
using namespace std;
vector<int> mul(vector<int>&A, int b) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++) {//t和加法中不一样，加法中为0或1，而乘法中t有可能非常大，因此要放在循环中多走几轮
		if (i < A.size())t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}
//int main() {
//	string a;
//	int b;
//	cin >> a >> b;
//	vector<int>A;
//	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
//	auto C = mul(A, b);
//	for (int i = C.size() - 1; i >= 0; i--)
//		cout << C[i];
//	return 0;
//}