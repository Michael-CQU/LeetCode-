#include<bits/stdc++.h>
using namespace std;

/*
���㷨�����ڳ���Ϊ n ������ a��
(�ؼ�����һ��˳���)
���ȴӺ���ǰ���ҵ�һ��˳��� (i,i+1)������ a[i] < a[i+1]����������С������Ϊ a[i]����ʱ [i+1,n) ��Ȼ���½����С�

����ҵ���˳��ԣ���ô������ [i+1,n) �дӺ���ǰ���ҵ�һ��Ԫ�� j ����a[i]<a[j]���������ϴ�������Ϊa[j]��

���� a[i]�� a[j]����ʱ����֤������[i+1,n) ��Ϊ�������ǿ���ֱ��ʹ��˫ָ�뷴ת����[i+1,n) ʹ���Ϊ���򣬶�����Ը������������
*/
//class Solution {
//public:
//	void nextPermutation(vector<int>& nums) {
//		int i = nums.size() - 2;
//		while (i >= 0 && nums[i] >= nums[i + 1])//ע��һ��Ҫ������nums[i]>=nums[i+1]�ĵ��ں�
//			i--;
//		if (i >= 0) {//ע�⵱���鱾�������������ʱ��i���Ϊ-1�����ֱ�������±ߵ�swap�Ȳ�����ֱ�ӽ���reverse����
//			int j = nums.size() - 1;
//			while (j >= i&&nums[i] >= nums[j])//ע��һ��Ҫ������nums[i]>=nums[i+1]�ĵ��ں�
//				j--;
//			swap(nums[i], nums[j]);
//		}
//		reverse(nums.begin() + 1 + i, nums.end());//������reverse��sort�����ԣ�reverseЧ�ʸ���
//	}
//};

//int main() {
//	vector<int> test = { 3,2,1 };
//	Solution s;
//	s.mynextPermutation(test);
//	for (int i : test)
//		cout << i << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}