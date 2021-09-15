#include<iostream>
#include<vector>
#include <string>
using namespace std;
//vector<int> mul(vector<int>&A, int b) {
//	vector<int> C;
//	int t = 0;
//	for (int i = 0; i < A.size() || t; i++) {//t和加法中不一样，加法中为0或1，而乘法中t有可能非常大，因此要放在循环中多走几轮
//		if (i < A.size())t += A[i] * b;
//		C.push_back(t % 10);
//		t /= 10;
//	}
//	while (C.size() > 1 && C.back() == 0)C.pop_back();
//	return C;
//}


vector<int> mul(vector<int> &A, vector<int> &B) {
    vector<int> C(A.size() + B.size(), 0); // 初始化为 0，且999*99最多 5 位

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            C[i + j] += A[i] * B[j];

    int t = 0;
	string ans;
    for (int i = 0; i < C.size(); i++) { // i = C.size() - 1时 t 一定小于 10
        t += C[i];
        C[i] = t % 10;
		ans += (C[i] + '0');
        t /= 10;
    }
	while (ans.size() > 1 && ans.back() == 0) ans.pop_back(); 
    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 必须要去前导 0，因为最高位很可能是 0
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
    return C;
}

//int main() {
///*
//9
//8999999999999999999999999999999999999994
//*/
//	string a;
//	string b;
//	cin >> a >> b;
//	vector<int>A,B;
//	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
//	for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
//	auto C = mul(A, B);
//	//for (int i = C.size() - 1; i >= 0; i--)
//		//cout << C[i];
//	system("pause");
//	return 0;
//}