//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std; 
//class Solution {
//public:
//	int numDecodings(string s) {
//		int n = s.size();
//		s = " " + s;//�����ڱ����Ӷ������жϱ߽����⣬������Ŀ����ǰ���㣬��ǰ����������Ч�׷�ӿո�ȿ��Ա�������ǰ���㣬Ҳ��ʹ�±�� 1 ��ʼ���� f[i-1] �ȸ����±���жϡ�
//		cout << s << endl;
//		vector<int> f(n + 1);
//		f[0] = 1;
//		for (int i = 1; i <= n; ++i) {
//			if (1 <= (s[i] - '0')&& (s[i] - '0') <= 9) {
//				f[i] = f[i - 1];
//			}
//			if (10 <= ((s[i - 1] - '0') * 10 + (s[i] - '0'))&& ((s[i - 1] - '0') * 10 + (s[i] - '0')) <= 26) {
//				f[i] += f[i - 2];
//			}
//		}
//		return f[n];
//	}
//};
//
//int main() {
//	string str = "226";
//	Solution s;
//	int result = s.numDecodings(str);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}