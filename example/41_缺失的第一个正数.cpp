//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums) {
//		int n = nums.size();
//		for (int i = 0; i < n; i++) {
//			//ע��whileѭ�����ĳ��ֵ�ڲ�����̶�λ�ñ�����nums[i] != nums[nums[i] - 1]����������nums[i]!=i+1,��Ϊ�������{1,1}������ͻᵼ����ѭ����
//			while (nums[i] > 0 && nums[i] <= n&&nums[i] != nums[nums[i] - 1]) {
//				swap(nums[i], nums[nums[i] - 1]);
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			if (nums[i] != i + 1)
//				return i + 1;
//		}
//		return n + 1;
//	}
//};