#include <iostream>
#include <vector>
using namespace std;

class Solution {
	int count = 0;
public:
	int recount(vector<int>& nums,vector<int>& temp,int left,int right) {
		if (left >= right)return 0;
		int mid = (right - left) / 2 + left;
		recount(nums, temp, left, mid);
		recount(nums, temp, mid + 1, right);
		int k = left;
		int start1 = left, end1 = mid, start2 = mid + 1, end2 = right;
		while (start1 <= end1&&start2 <= end2) {
			if (nums[start1] <= nums[start2])
				temp[k++] = nums[start1++];
			else {
				temp[k++] = nums[start2++];
				count += mid - start1 + 1;
			}
		}
		while (start1 <= end1)
			temp[k++] = nums[start1++];
		while (start2 <= end2)
			temp[k++] = nums[start2++];
		for (k = left; k <= right; k++)
			nums[k] = temp[k];
		return count;
	}
};

//int main() {
//	int n = 0;
//	cin >> n;
//	vector<int> test(n), temp(n);
//	for (int i = 0; i < n; i++) {
//		cin >> test[i];
//	}
//	Solution s;
//	int res = s.recount(test, temp,0, n - 1);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}