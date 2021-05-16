//#include <iostream>
//#include <vector>
//#include <unordered_set>
//#include <algorithm>
//
//using namespace std;
//
////class Solution {
////private:
////	// ���λ�Ķ�����λ���Ϊ 30
////	static constexpr int HIGH_BIT = 30;
////
////public:
////	int findMaximumXOR(vector<int>& nums) {
////		int x = 0;
////		for (int k = HIGH_BIT; k >= 0; --k) {
////			unordered_set<int> seen;
////			// �����е� pre^k(a_j) �����ϣ����
////			for (int num : nums) {
////				// ���ֻ�뱣�������λ��ʼ���� k ��������λΪֹ�Ĳ���
////				// ֻ�轫������ k λ
////				seen.insert(num >> k);
////			}
////
////			// Ŀǰ x ���������λ��ʼ���� k+1 ��������λΪֹ�Ĳ���
////			// ���ǽ� x �ĵ� k ��������λ��Ϊ 1����Ϊ x = x*2+1
////			int x_next = x * 2 + 1;
////			bool found = false;
////
////			// ö�� i
////			for (int num : nums) {
////				if (seen.count(x_next ^ (num >> k))) {
////					found = true;
////					break;
////				}
////			}
////
////			if (found) {
////				x = x_next;
////			}
////			else {
////				// ���û���ҵ������ʽ�� a_i �� a_j����ô x �ĵ� k ��������λֻ��Ϊ 0
////				// ��Ϊ x = x*2
////				x = x_next - 1;
////			}
////		}
////		return x;
////	}
////};
//
//struct Trie {
//	// ������ָ���ʾ 0 ���ӽڵ�
//	Trie* left = nullptr;
//	// ������ָ���ʾ 1 ���ӽڵ�
//	Trie* right = nullptr;
//
//	Trie() {}
//};
//
//class Solution {
//private:
//	// �ֵ����ĸ��ڵ�
//	Trie* root = new Trie();
//	// ���λ�Ķ�����λ���Ϊ 30
//	static constexpr int HIGH_BIT = 30;
//
//public:
//	void add(int num) {
//		Trie* cur = root;
//		for (int k = HIGH_BIT; k >= 0; --k) {
//			int bit = (num >> k) & 1;
//			if (bit == 0) {
//				if (!cur->left) {
//					cur->left = new Trie();
//				}
//				cur = cur->left;
//			}
//			else {
//				if (!cur->right) {
//					cur->right = new Trie();
//				}
//				cur = cur->right;
//			}
//		}
//	}
//
//	int check(int num) {
//		Trie* cur = root;
//		int x = 0;
//		for (int k = HIGH_BIT; k >= 0; --k) {
//			int bit = (num >> k) & 1;
//			if (bit == 0) {
//				// a_i �ĵ� k ��������λΪ 0��Ӧ������ʾ 1 ���ӽڵ� right ��
//				if (cur->right) {
//					cur = cur->right;
//					x = x * 2 + 1;
//				}
//				else {
//					cur = cur->left;
//					x = x * 2;
//				}
//			}
//			else {
//				// a_i �ĵ� k ��������λΪ 1��Ӧ������ʾ 0 ���ӽڵ� left ��
//				if (cur->left) {
//					cur = cur->left;
//					x = x * 2 + 1;
//				}
//				else {
//					cur = cur->right;
//					x = x * 2;
//				}
//			}
//		}
//		return x;
//	}
//
//	int findMaximumXOR(vector<int>& nums) {
//		int n = nums.size();
//		int x = 0;
//		for (int i = 1; i < n; ++i) {
//			// �� nums[i-1] �����ֵ�������ʱ nums[0 .. i-1] �����ֵ�����
//			add(nums[i - 1]);
//			// �� nums[i] ���� ai���ҳ����� x ���´�
//			x = max(x, check(nums[i]));
//		}
//		return x;
//	}
//};
//
//int main() {
//	vector<int> nums= { 3,10,5,25,2,8 };
//	Solution s;
//	int result = s.findMaximumXOR(nums);
//	//cout << result << endl;
//	system("pause");
//	return 0;
//}