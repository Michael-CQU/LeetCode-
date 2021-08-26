#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> mul(vector<int> &A, vector<int> &B) {
	vector<int> C(A.size() + B.size(), 0); // ��ʼ��Ϊ 0����999*99��� 5 λ

	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++)
			C[i + j] += A[i] * B[j];

	int t = 0;
	for (int i = 0; i < C.size(); i++) { // i = C.size() - 1ʱ t һ��С�� 10
		t += C[i];
		C[i] = t % 10;
		t /= 10;
	}

	while (C.size() > 1 && C.back() == 0) C.pop_back(); // ����Ҫȥǰ�� 0����Ϊ���λ�ܿ����� 0
	return C;
}

//int main() {
//	string a, b;
//	cin >> a >> b; // a = "1222323", b = "2323423423"
//
//	vector<int> A, B;
//	for (int i = a.size() - 1; i >= 0; i--)
//		A.push_back(a[i] - '0');
//	for (int i = b.size() - 1; i >= 0; i--)
//		B.push_back(b[i] - '0');
//
//	auto C = mul(A, B);
//
//	for (int i = C.size() - 1; i >= 0; i--)
//		cout << C[i];
//
//	return 0;
//}