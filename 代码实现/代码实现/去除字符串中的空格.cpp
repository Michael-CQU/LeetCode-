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
//	//����һ������ռ�
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
//	//��������ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1��
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