//#include<bits/stdc++.h>
//using namespace std;
//
//class Solution {
//public:
//	int largestRectangleArea(vector<int>& heights) {
//		int res = 0;
//		stack<int> st;
//		st.push(0);
//		heights.insert(heights.begin(), 0); // 数组头部加入元素0
//		heights.push_back(0); // 数组尾部加入元素0
//		int n = heights.size();
//		for (int i = 1; i < n; i++) {
//			while (heights[i] < heights[st.top()]) {
//				int mid = st.top();
//				st.pop();
//				int h = heights[mid];
//				int w = i - st.top() - 1;
//				res = max(res, h*w);
//			}
//			st.push(i);
//		}
//		return res;
//	}
//};
//
//int main() {
//	vector<int> test = {2,4};
//	Solution s;
//	s.largestRectangleArea(test);
//	system("pause");
//}