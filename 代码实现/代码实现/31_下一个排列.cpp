#include<bits/stdc++.h>
using namespace std;

/*
该算法，对于长度为 n 的排列 a：
(关键是找一个顺序对)
首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i] < a[i+1]。这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。

如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素 j 满足a[i]<a[j]。这样「较大数」即为a[j]。

交换 a[i]与 a[j]，此时可以证明区间[i+1,n) 必为降序。我们可以直接使用双指针反转区间[i+1,n) 使其变为升序，而无需对该区间进行排序。
*/
//class Solution {
//public:
//	void nextPermutation(vector<int>& nums) {
//		int i = nums.size() - 2;
//		while (i >= 0 && nums[i] >= nums[i + 1])//注意一定要补充上nums[i]>=nums[i+1]的等于号
//			i--;
//		if (i >= 0) {//注意当数组本身就是最大的排列时候，i会变为-1，因此直接跳过下边的swap等操作，直接进行reverse即可
//			int j = nums.size() - 1;
//			while (j >= i&&nums[i] >= nums[j])//注意一定要补充上nums[i]>=nums[i+1]的等于号
//				j--;
//			swap(nums[i], nums[j]);
//		}
//		reverse(nums.begin() + 1 + i, nums.end());//这里用reverse和sort都可以，reverse效率更高
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