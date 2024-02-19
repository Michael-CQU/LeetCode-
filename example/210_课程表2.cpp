#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
	// �洢����ͼ
	//vector<vector<int>> edges;
	//// �洢ÿ���ڵ�����
	//vector<int> indeg;
	//// �洢��
	//vector<int> result;

public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> edges;
		// �洢ÿ���ڵ�����
		vector<int> indeg;
		// �洢��
		vector<int> result;
		edges.resize(numCourses);
		indeg.resize(numCourses);
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]);
			++indeg[info[0]];
		}

		queue<int> q;
		// ���������Ϊ 0 �Ľڵ���������
		for (int i = 0; i < numCourses; ++i) {
			if (indeg[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			// �Ӷ���ȡ��һ���ڵ�
			int u = q.front();
			q.pop();
			// �������
			result.push_back(u);
			for (int v : edges[u]) {
				--indeg[v];
				// ������ڽڵ� v �����Ϊ 0���Ϳ���ѡ v ��Ӧ�Ŀγ���
				if (indeg[v] == 0) {
					q.push(v);
				}
			}
		}

		if (result.size() != numCourses) {
			return{};
		}
		return result;
	}
};

//int main() {
//	vector<vector<int>> prerequisites = { {1,0},{2,0},{3,1},{3,2} };
//	int m = 4;
//	Solution s;
//	vector<int> res = s.findOrder(m, prerequisites);
//	for (int a : res)
//		cout << a << endl;
//	system("pause");
//	return 0;
//}