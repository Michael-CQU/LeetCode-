//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> largestDivisibleSubset(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		int n = nums.size();
//		vector<int> f(n, 0);
//		vector<int> g(n, 0);
//
//		for (int i = 0; i < n; i++) {
//			// ���ٰ�������һ�����������ʼ����Ϊ 1��������ת�ƶ���
//			int len = 1, prev = i;
//			for (int j = 0; j < i; j++) {
//				if (nums[i] % nums[j] == 0) {
//					cout << "��ѭ��" << j << "�Σ� ";
//					cout << "nums[i] = " << nums[i] << "  ";
//					cout << "nums[j] = " << nums[j] << "  ";
//					cout << endl;
//					// ����ܽ��ڸ��������к��棬����¡���󳤶ȡ�&���Ӻ�ת�ƶ�����
//					if (f[j] + 1 > len) {
//						len = f[j] + 1;
//						prev = j;
//
//						cout << "j = " << j << "  ";
//						cout << "f[j] = " << f[j] << "  ";
//						cout << "len = " << len << "  ";
//						cout << "prev = " << prev;
//						cout << endl;
//					}
//				}
//			}
//			f[i] = len;
//			g[i] = prev;
//			cout << "��ѭ��" << i << "�Σ� ";
//			cout << "f[i] = " << f[i] << "  ";
//			cout << "g[i] = " << g[i] << "  ";
//			cout << endl;
//		}
//
//		// �������е� f[i]��ȡ�á���󳤶ȡ��͡���Ӧ�±꡹
//		int idx = max_element(f.begin(), f.end()) - f.begin();
//		int max = f[idx];
//
//		// ʹ�� g[] ������ݳ����巽��
//		vector<int> ans;
//		while (ans.size() != max) {
//			ans.push_back(nums[idx]);
//			idx = g[idx];
//		}
//		return ans;
//	}
//};
//
//int main() {
//	vector<int> nums = {9,18,54,90,108,180,360,540,720};
//	Solution s;
//	vector<int> result = s.largestDivisibleSubset(nums);
//	system("pause");
//	return 0;
//}