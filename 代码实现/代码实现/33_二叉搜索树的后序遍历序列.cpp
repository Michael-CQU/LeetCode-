#include <iostream>
#include <vector>
#include<stack>
using namespace std;
//递归分治（时间复杂度为N^2,最差情况下树退化成为链表）
//class Solution {
//public:
//	bool myverifypostorder(vector<int>& poster, int start, int end) {
//		if (start >= end)
//			return true;
//		int p = start;
//		while (poster[p] < poster[end])
//			p++;
//		int m = p;
//		while (poster[p] > poster[end])
//			p++;
//		return p == end&&myverifypostorder(poster, start, m - 1) && myverifypostorder(poster, m, p - 1);
//	}
//	bool verifyPostorder(vector<int>& postorder) {
//		return myverifypostorder(postorder, 0, postorder.size() - 1);
//	}
//};
//迭代法（单调栈实现）
class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		stack<int> s;
		int root = INT_MAX;
		for (int i = postorder.size() - 1; i >= 0; i--) {
			if (postorder[i] > root)//如果节点值比root值大，说明不符合左子树的规则
				return false;
			while (!s.empty() && s.top() > postorder[i]) {//当反向后序数组下降时，说明到了左子树，需要对左子树进行判断
				root = s.top();//栈顶大于遍历值保证了右子树的正确
				s.pop();
			}
			s.push(postorder[i]);
		}
		return true;
	}
};
//int main() {
//	vector<int> test = {1,3,2,6,5};
//	Solution s;
//	s.verifyPostorder(test);
//	system("pause");
//	return 0;
//}