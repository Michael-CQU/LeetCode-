#include <bits/stdc++.h>
using namespace std;
//�������ڷ���

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int i = 1, j = 2, s = 3;//��ʼ������������i��j����ֵ�����������еĺ�Ϊs
		vector<vector<int>> res;
		while (i < j) {
			if (s == target) {
				vector<int> temp;
				for (int k = i; k <= j; k++) {
					temp.push_back(k);
				}
				res.push_back(temp);
			}
			if (s > target) {
				s -= i;
				i++;
			}
			else {
				j++;
				s += j;
			}
		}
		return res;
	}
};