//#include <iostream>
//#include <vector>
//using namespace std;
////class Solution {
////public:
////	vector<int> findDisappearedNumbers(vector<int>& nums) {
////		int index = 0, n = nums.size();
////		for (int i = 0; i < n; i++) {
////			index = (nums[i] - 1) % n;
////			//index = (nums[i]-1);
////			cout <<"index= " << index << ": ";
////			nums[index]+= n;
////			cout << nums[index] << " ";
////		}
////		cout << endl;
////		vector<int> result(n);
////		int m = 0;
////		for (int i = 0; i < n; i++) {
////			//cout << nums[i] << endl;
////			if (nums[i] <= n) {
////				cout << i << " ";
////				cout << nums[i] << " ";
////				//result[m++] = nums[i];
////				//cout << result[m] << endl;
////			}
////			cout << endl;
////		}
////		return result;
////	}
////};
//class Solution {
//public:
//	vector<int> findDisappearedNumbers(vector<int>& nums) {
//		int n = nums.size();
//		for (int i = 0; i < n; i++) {
//			if ((nums[abs(nums[i]) - 1]) > 0)
//				nums[abs(nums[i]) -1] *= -1;
//		}
//		vector<int> result;
//		for (int j = 0; j < n; j++) {
//			if (nums[j] > 0)
//			result.emplace_back(j + 1);
//		}
//		return result;
//	}
//};
//int main() {
//	Solution s;
//	vector<int> nums = { 4,3,2,7,8,2,3,1 };
//	vector<int> num = s.findDisappearedNumbers(nums);
//	for(vector<int>::iterator it = num.begin();it!=num.end();it++)
//	cout << *it << endl;
//	system("pause");
//	return 0;
//}