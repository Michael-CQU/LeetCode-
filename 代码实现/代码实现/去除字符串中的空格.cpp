//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string test;
//	int m;
//	cin >> m;
//	cin.ignore();
//	getline(cin, test);
//	int n = test.size();
//
//	//方法一：额外空间
//	//string ans;
//	//for (int i = 0; i < n; i++) {
//	//	if (test[i] == ' ') {
//	//		continue;
//	//	}
//	//	else
//	//		ans.push_back(test[i]);
//	//}
//	//cout << ans << endl;
//
//	//方法二：时间复杂度O（n），空间复杂度O（1）
//	int i = 0;
//	for (int j = 0; j < n; j++) {
//		if (test[j] != ' ')
//			test[i++] = test[j];
//	}
//	cout << test.substr(0,i) << endl;
//
//	system("pause");
//	return 0;
//}