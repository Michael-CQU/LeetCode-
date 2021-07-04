#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
		int n = dist.size();
		int count = 1, mymin = INT_MAX, idx = 0, c = 0;
		for (int m = 0; m < n; m++) {
			c++;
			mymin = INT_MAX;
			for (int i = 0; i < n; i++) {
				mymin = min(mymin, dist[i] - speed[i]);
			}
			for (int i = 0; i < n; i++) {
				if (mymin == dist[i] - speed[i]) {
					idx = i;
					break;
				}
			}
			dist[idx] = INT_MAX;
			for (int j = 0; j < n; j++) {
				dist[j] = dist[j] - speed[j];
				if (dist[j] < 0)return count;
			}
			count++;
		}
		return count - 1;
	}
};

//class Solution {
//public:
//	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
//		int n = dist.size();
//		int count = 1, mymin = INT_MAX, idx = 0, c = 0;
//		for (int m = 0; m < n; m++) {
//			c++;
//			for (int j = 0; j < n; j++) {
//				dist[j] = dist[j] - speed[j];
//				if (dist[j] < 0)return count;
//			}
//			mymin = INT_MAX;
//			for (int i = 0; i < n; i++) {
//				mymin = min(mymin, dist[i]);
//			}
//			for (int i = 0; i < n; i++) {
//				if (mymin == dist[i]) {
//					idx = i;
//					break;
//				}
//			}
//			dist[idx] = INT_MAX;
//			count++;
//		}
//		return count;
//	}
//};
using namespace std;
//int main() {
//	vector<int> test1 = { 46,33,44,42,46,36,7,36,31,47,38,42,43,48,48,25,28,44,49,47,29,32,30,6,42,9,39,48,22,26,50,34,40,22,10,45,7,43,24,18,40,44,17,39,36 };
//	vector<int> test2 = { 1,2,1,3,1,1,1,1,1,1,1,1,1,1,7,1,1,3,2,2,2,1,2,1,1,1,1,1,1,1,1,6,1,1,1,8,1,1,1,3,6,1,3,1,1 };
//	Solution s;
//	int res = s.eliminateMaximum(test1, test2);
//	system("pause");
//	return 0;
//}