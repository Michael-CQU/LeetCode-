#include<bits/stdc++.h>
using namespace std;
//����ĳ���˼·������Ƕ��ѭ��������ʱ�临�Ӷ���O��n����ע��˫ָ���ƶ�һ��ֱ���൱������ѭ����һ�ֵĽ��������������еĶ�άͼ������⣩
//���Ƶ��⻹������167/240
class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		int i = 0;
		int j = height.size() - 1;
		while (i < j) {
			int area = (j - i) * min(height[i], height[j]);//�ƶ��ߵ����Ӳ���Դ𰸲���Ӱ�죬��Ϊarea�����ڵ͵����ӡ�
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