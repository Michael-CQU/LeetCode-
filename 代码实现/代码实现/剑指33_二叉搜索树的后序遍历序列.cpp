#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool myverifypostorder(vector<int>& poster, int start, int end) {
		if (start >= end)
			return true;
		int p = start;
		while (poster[p] < poster[end])
			p++;
		int m = p;
		while (poster[p] > poster[end])
			p++;
		return p == end&&myverifypostorder(poster, start, m - 1) && myverifypostorder(poster, m, p - 1);
	}
	bool verifyPostorder(vector<int>& postorder) {
		return myverifypostorder(postorder, 0, postorder.size() - 1);
	}
};

//int main() {
//	vector<int> test = {1,3,2,6,5};
//	Solution s;
//	s.verifyPostorder(test);
//	system("pause");
//	return 0;
//}