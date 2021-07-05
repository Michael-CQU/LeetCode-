#include<bits/stdc++.h>
using namespace std;
//本题的常规思路是两个嵌套循环遍历，时间复杂度是O（n）。注意双指针移动一格直接相当于跳过循环中一轮的结果（看力扣题解中的二维图便于理解）
//类似的题还有力扣167/240
class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		int i = 0;
		int j = height.size() - 1;
		while (i < j) {
			int area = (j - i) * min(height[i], height[j]);//移动高的柱子不会对答案产生影响，因为area受限于低的柱子。
			res = max(res, area);
			if (height[i] < height[j]) {
				i++;
			}
			else {
				j--;
			}
		}
		return res;
	}
};