#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//		int qlen = queries.size();
//		vector<int> xorresult(qlen);
//		for (int i = 0; i < qlen; i++) {
//			int j = queries[i][0];
//				int result = arr[j];
//			for (j = queries[i][0]; j < queries[i][1]; j++) {
//				result ^= arr[j + 1];
//			}
//			//xorresult.push_back(result);
//			xorresult[i] = result;
//		}
//		return xorresult;
//	}
//};
class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		int alen = arr.size();
		vector<int> xorr (alen + 1);
		for (int i = 0; i < alen; i++) {
			xorr[i+1] = xorr[i] ^ arr[i];
			//cout << xorr[i+1] << endl;
		}
		int qlen = queries.size();
		vector<int> result(qlen);
		for (int j = 0; j < qlen; j++) {
			result[j] = xorr[queries[j][0]] ^ xorr[queries[j][1]+1];
		}
		return result;
	}
};

int main() {
	vector<int> arr = { 4,8,2,10 };
	vector<vector<int>> queries = { {2,3},{1,3},{0,0},{0,3} };
	Solution s;
	vector<int> xorresult = s.xorQueries(arr, queries);
	for (auto i : xorresult)
		cout << i << endl;
	system("pause");
	return 0;
}