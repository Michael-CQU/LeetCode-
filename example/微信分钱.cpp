//#include<bits/stdc++.h>
//using namespace std;
//
//vector<double> myrandom(double count,int num) {
//	vector<double> ans(num,0.01);
//	int countsum = count * 100 - num;
//	int i = 0;
//	while (countsum > 0) {
//		//int base = min(countsum, 2000);
//		//int temp = rand() % base + 1;
//		int temp = rand() % countsum + 1;
//		countsum -= temp;
//		ans[(i++)%num] += (double)temp/100;
//	}
//	return ans;
//}
//
//int main() {
//	double m;//½ð¶î
//	int n;
//	cin >> m >> n;
//	double sum = 0;
//	srand((unsigned int)time(NULL));
//	vector<double> res = myrandom(m,n);
//	for (double i : res) {
//		cout << i << " ";
//		sum += i;
//	}	
//		cout << endl;
//		cout << "sum=" << sum << endl;
//		system("pause");
//}