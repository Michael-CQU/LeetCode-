#include<bits/stdc++.h>
using namespace std;
//����򵥷���Ϊͨ����ϣ�������أ�������Ҫ����Ĺ�ϣ��ռ�
//��һ�ַ����������ԭ�ز������൱���ֵ䷽������ź���ֵ��Ӧ����������£�
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int i = 0;
		while(i<nums.size()) {
			if (nums[i] == i) {
				i++;//ע��i������Ҫ��nums[i] == i������
				continue;
			}
			if (nums[i] == nums[nums[i]]) {
				return nums[i];
			}
			swap(nums[i], nums[nums[i]]);
		}
		return -1;
	}
};
//int main() {
//	vector<int> test = {0,3,1,2,5,2,7};
//	Solution s;
//	int res = s.findRepeatNumber(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}