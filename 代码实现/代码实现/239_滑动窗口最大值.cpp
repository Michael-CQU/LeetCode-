#include<iostream>
#include <vector>
#include <queue>
using namespace std;
//����һ�����ȶ���
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < k; ++i) {
			q.emplace(nums[i], i);
		}
		vector<int> ans = { q.top().first };
		for (int i = k; i < n; ++i) {
			q.emplace(nums[i], i);
			while (q.top().second <= i - k) {
				q.pop();
			}
			ans.push_back(q.top().first);
		}
		return ans;
	}
};
//����������������
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		deque<int> q;
		for (int i = 0; i < k; ++i) {
			while (!q.empty() && nums[i] >= nums[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
		}

		vector<int> ans = { nums[q.front()] };
		for (int i = k; i < n; ++i) {
			while (!q.empty() && nums[i] >= nums[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
			while (q.front() <= i - k) {//����˵���������±��Ǵ�1��ʼ�ģ���Ӧ�ģ����е�ͷԪ���±�ҲҪ��1��ʼ��ɾ��ͷԪ�ص�����Ϊfront_id<new_id-L+1��������������±��Ǵ�0��ʼ�ģ���Ӧ�ģ����е�ͷԪ���±�ҲҪ��0��ʼ��ɾ��ͷԪ�ص������ͱ�Ϊfront_id < new_id - L��
				q.pop_front();
			}
			ans.push_back(nums[q.front()]);
		}
		return ans;
	}
};

//���������ֿ�+Ԥ����
//class Solution {
//public:
//	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//		int n = nums.size();
//		vector<int> prefixMax(n), suffixMax(n);
//		for (int i = 0; i < n; ++i) {
//			if (i % k == 0) {
//				prefixMax[i] = nums[i];
//			}
//			else {
//				prefixMax[i] = max(prefixMax[i - 1], nums[i]);
//			}
//		}
//		for (int i = n - 1; i >= 0; --i) {
//			if (i == n - 1 || (i + 1) % k == 0) {
//				suffixMax[i] = nums[i];
//			}
//			else {
//				suffixMax[i] = max(suffixMax[i + 1], nums[i]);
//			}
//		}
//
//		vector<int> ans;
//		for (int i = 0; i <= n - k; ++i) {
//			ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
//		}
//		return ans;
//	}
//};
//int main() {
//	vector<int> test = { 1,3,1,2,0,5};
//	int k = 3;
//	Solution s;
//	vector<int> result = s.maxSlidingWindow(test,k);
//	for (int i : result)
//		cout << i << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}