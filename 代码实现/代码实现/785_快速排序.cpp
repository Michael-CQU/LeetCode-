//#include<iostream>
//#include <vector>
//#include <ctime>
//using namespace std;
//
//class Solution {
//public:
//	void myquicksort(vector<int>& num,int left,int right) {
//		if (left >= right)
//			return;
//		//int temp = rand() % (right - left + 1) + left;
//		int temp = (right - left) / 2 + left;
//		swap(num[temp], num[left]);
//		int pivot = num[left];
//		int l = left, r = right;
//		while (l < r) {
//			while (num[r] >= pivot&&l < r)r--;
//			while (num[l] <= pivot&&l < r)l++;
//			swap(num[r], num[l]);
//		}
//		swap(num[l], num[left]);
//		myquicksort(num,left,l-1);
//		myquicksort(num,l+1,right);
//	}
//};
//
//int main() {
//	srand((unsigned)time(NULL));
//	int n = 0;
//	cin >> n;
//	vector<int> test(n);
//	for (int i = 0; i < n; i++) {
//		cin >> test[i];
//	}
//	Solution s;
//	s.myquicksort(test, 0, n - 1);
//	for (auto i : test)
//		cout << i << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}