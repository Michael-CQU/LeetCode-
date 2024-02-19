#include<bits/stdc++.h>
using namespace std;

////方法一：数组存储：一个数组存储从左边开始的最大值，一个数组存储从右边开始的最小值，两个数组重合的值就是最后的结果
//int main() {
//	int m;
//	cin >> m;
//	vector<int> test(m);
//	for (int i = 0; i < m; i++)
//		cin >> test[i];
//	vector<int> left(m), right(m);
//	vector<int> ans;
//	int mymax = test[0], mymin = test[m-1];
//	for (int i = 0; i < m; i++) {
//		if (test[i] > mymax)
//			mymax = test[i];
//		left[i] = mymax;
//	}
//	for (int i = m - 1; i >= 0; i--) {
//		if (test[i] < mymin)
//			mymin = test[i];
//		right[i] = mymin;
//	}
//	for (int i = 0; i < m; i++) {
//		if (left[i] == right[i]) {
//			ans.push_back(left[i]);
//			cout << left[i] << " ";
//		}
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

////方法二：用单调栈来存储
//int main() {
//	int m;
//	cin >> m;
//	vector<int> test(m);
//	for (int i = 0; i < m; i++)
//		cin >> test[i];
//	deque<int> st;
//	int mymax = test[0];
//	st.push_back(test[0]);
//	for (int i = 1; i < m; i++) {
//
//		while (!st.empty() && test[i] <= st.back()) {
//			st.pop_back();
//		}
//		if (test[i] > mymax) {
//			st.push_back(test[i]);
//		}
//		mymax = max(test[i],mymax);
//	}
//	while (!st.empty()) {
//		cout << st.front() << " ";
//		st.pop_front();
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}