#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void theKnumber(vector<int>& num,vector<int>& temp,int left,int right) {
		if (left >= right)
			return;
		int mid = (right - left) / 2 + left;
		theKnumber(num, temp, left, mid);
		theKnumber(num, temp, mid + 1, right);
		int k = left;
		int l1 = left, l2 = mid + 1, r1 = mid, r2 = right;
		while (l1<=r1&&l2<=r2) {
			if (num[l1] <= num[l2])
				temp[k++] = num[l1++];
			else
				temp[k++] = num[l2++];
		}
		while (l1 <= r1) {
			temp[k++] = num[l1++];
		}
		while (l2 <= r2) {
			temp[k++] = num[l2++];
		}
		for (k = left; k <= right; k++) {
			num[k] = temp[k];
		}
	}
};

//int main() {
//	int n = 0, k = 0;
//	cin >> n >> k;
//	vector<int> test(n), temp(n);
//	for (int i = 0; i < n; i++) {
//		cin >> test[i];
//	}
//	Solution s;
//	s.theKnumber(test, temp, 0, n - 1);
//	int res = temp[k-1];
//	cout << res << endl;
//	system("pause");
//	return 0;
//}