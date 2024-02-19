#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
	int n = nums.size();
	vector<int> res(n); // ��Ž��
	stack<int> s;
	// ��װ�������?�ȷ�����
	for (int i = 2 * n - 1; i >= 0; i--) {//ѭ�����������ʽ
		while (!s.empty() && s.top() <= nums[i % n])
			s.pop();
		res[i % n] = s.empty() ? -1 : s.top();
		s.push(nums[i % n]);
	}
	return res;
}

//int main() {
//	vector<int> nums = {2,1,2,4,3};
//	vector<int> result = {nextGreaterElements(nums)};
//	system("pause");
//	return 0;
//}