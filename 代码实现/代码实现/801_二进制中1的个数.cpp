//#include<iostream>
//#include<vector>
//using namespace std;
////也可以用lowbit
//int main() {
//	int n;
//	cin >> n;
//	vector<int> test(n);
//	for (int i = 0; i < n; i++) {
//		cin >> test[i];
//	}
//	vector<int> ans;
//	for (int i : test) {
//		int count = 0;
//		while (i) {
//			if (i & 1 == 1) {
//				count++;
//			}
//			i >>= 1;
//		}
//		ans.push_back(count);
//	}
//	for (int i : ans) {
//		cout << i << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}