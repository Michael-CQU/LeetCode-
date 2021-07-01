#include <iostream>
#include <vector>
#include<stack>
using namespace std;
//�ݹ���Σ�ʱ�临�Ӷ�ΪN^2,�����������˻���Ϊ����
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
//������������ջʵ�֣�
class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		stack<int> s;
		int root = INT_MAX;
		for (int i = postorder.size() - 1; i >= 0; i--) {
			if (postorder[i] > root)//����ڵ�ֵ��rootֵ��˵���������������Ĺ���
				return false;
			while (!s.empty() && s.top() > postorder[i]) {//��������������½�ʱ��˵����������������Ҫ�������������ж�
				root = s.top();//ջ�����ڱ���ֵ��֤������������ȷ
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