#include <bits/stdc++.h>
using namespace std;
//����һ��ʱ�临�ӶȲ�̫�ã���Ϊֻ����һ�ζ��ֲ���
//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		int count = 0;
//		if (nums.size() == 0)return count;
//		int left = 0, right = nums.size() - 1;
//		while (left < right) {
//			int pivot = (right - left) / 2 + left;
//			if (nums[pivot] > target)
//				right = pivot;
//			else if (nums[pivot] < target)
//				left = pivot + 1;
//			else {
//				right--;
//			}
//		}
//		while (left<nums.size()&&nums[left] == target) {
//			count++;
//			left++;
//		}
//		return count;
//	}
//};
//�����������ζ��ֲ���
class Solution {
public:
	int mysearchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int pivot = (right - left) / 2 + left;
			if (nums[pivot] < target) {
				left = pivot + 1;
			}
			else if (nums[pivot] > target) {
				right = pivot;
			}
			else {
				right--;
			}
		}
		return left;
	}
	vector<int> searchRange(vector<int>& nums, int target) {

		int leftIndex = mysearchRange(nums, target);
		int rightIndex = mysearchRange(nums, target + 1);
		if (nums.size() == 0) return{ -1,-1 };//��������1��������Ϊ��ʱ������{-1��-1}
		if (nums[nums.size() - 1] < target + 1)//��������2����Ҫ�ҵ��ұ߽���������һ��ֵ��ʱ���������һ��ֵ��target����rightIndex���ص�Ҳ��target���±꣬�����Ҫ��rightIndex++�Ӷ����±굽��target�ĺ�һλ
			rightIndex++;
		if (nums[leftIndex] == target)//��������3�����ַ����ص���Ŀ��ֵӦ���������е�λ�ã���target�������в�����ʱ�����ص��Ǳ�target��ĵ�һ��ֵ���±�ֵ����������ұ߽��򷵻��������һ���±�nums.size����-1��������߽��򷵻������һ���±�0���������Ҫ������±�����жϿ����ǲ���Ҫ�ҵ�ֵ
			return{ leftIndex,rightIndex - 1 };
		return{ -1,-1 };
	}
};
//int main() {
//	vector<int> test = {3,7,7,8,8,10};
//	int target = 6;
//	Solution s;
//	vector<int> res = s.searchRange(test,target);
//	for(int i:res)
//	cout << i<< endl;
//	system("pause");
//	return 0;
//}