//#include <iostream>
//#include <vector>
//using namespace std;
//
////class NumMatrix {
////public:
////	vector<vector<int>> sums;
////
////	NumMatrix(vector<vector<int>>& matrix) {//���캯��
////		int m = matrix.size();
////		if (m > 0) {
////			int n = matrix[0].size();
////			sums.resize(m + 1, vector<int>(n + 1));
////			for (int i = 0; i < m; i++) {
////				for (int j = 0; j < n; j++) {
////					sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
////					//cout << sums[i + 1][j + 1] << " ";
////					
////				}
////				//cout<< endl;
////			}
////		}
////	}
////
////	int sumRegion(int row1, int col1, int row2, int col2) {
////		return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
////	}
////};
//
//class NumMatrix {
//public:
//	vector<vector<int>> sum;
//	NumMatrix(vector<vector<int>>& matrix) {
//		int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();//ע��matrix.size()�����������matrix[0].size()���������
//		cout << m << "   " << n << endl;
//		// �롸һάǰ׺�͡�һ����ǰ׺�������±�� 1 ��ʼ������趨������״Ϊ [n + 1][m + 1]��ģ�岿�֣�
//		sum.resize(m + 1, vector<int>(n + 1));
//		// Ԥ�����ǰ׺�����飨ģ�岿�֣�
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= n; j++) {
//				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];//ע��߽�
//			}
//		}
//	}
//
//	int sumRegion(int row1, int col1, int row2, int col2) {
//		row1++; col1++; row2++; col2++;
//		// ��ĳһ������� [i, j] ��ģ���� sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];��ģ�岿�֣�
//		// ����������Դ�����±�� 0 ��ʼ�����Ҫ��ģ��Ļ����Ͻ��� + 1
//		return sum[row2][col2] - sum[row1 - 1][col2] - sum[row2][col1 - 1] + sum[row1 - 1][col1 - 1];
//	}
//};
//
//int main() {
//	//vector<vector<int>> mat = { {3, 0, 1, 4, 2},
//	//{5, 6, 3, 2, 1 },
//	//{1, 2, 0, 1, 5},
//	//{4, 1, 0, 1, 7},
//	//{1, 0, 3, 0, 5} };
//	//NumMatrix *num = new NumMatrix(mat);
//	//int result = num->sumRegion(1, 1, 5, 5);
//	
//	vector<vector<int>> mat = { {3, 0, 1, 4, 2},
//	{5, 6, 3, 2, 1 },
//	{1, 2, 0, 1, 5},
//	{4, 1, 0, 1, 7} };
//	NumMatrix num(mat);
//	int result = num.sumRegion(0, 0, 3, 3);
//	//cout << result << endl;
//	system("pause");
//	return 0;
//}