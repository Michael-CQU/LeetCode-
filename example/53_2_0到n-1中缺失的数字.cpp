#include <bits/stdc++.h>
using namespace std;
//�ù�ϣ�����в��ҵ�ʱ�临�Ӷ�Ϊn�����Ƽ�
//class Solution {
//public:
//	int missingNumber(vector<int>& nums) {
//		unordered_set<int> st;
//		for (int i : nums) {
//			st.insert(i);
//		}
//		for (int i = 0; i <= nums.size(); i++) {
//			if (st.find(i) == st.end())
//				return i;
//		}
//		return -1;
//	}
//};
//�ö��ַ�ʵ��ʱ�临�Ӷ�Ϊlog��n���Ĳ���
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int pivot = (right - left) / 2 + left;
			if (nums[pivot] == pivot)
				left = pivot + 1;
			else
				right = pivot;
		}
		if (left == nums[nums.size() - 1])//����һ�£����������һ��ֵ�Ͷ�Ӧ���±����ʱ��˵��ȱ�ٵľ���nums.size()���Ǹ�ֵ
			return left + 1;
		return left;
	}
};

//int main() {
//	vector<int> test = {0,1,2,3,4,5,6,7,8};
//	Solution s;
//	int res = s.missingNumber(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}