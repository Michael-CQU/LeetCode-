//#include <bits/stdc++.h>
//using namespace std;
//
//typedef pair<int, int> PII;
//
//const int N = 1e2 + 7;
//int g[N][N], d[N][N];//g�ǳ�ʼ����d��������㵽ԭ��ľ���
//int n, m;
//PII Prev[N][N];//��¼·��
//
//int bfs() {
//    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//    queue <PII> q;
//
//    for (auto &v : d) 
//        for (auto &x : v) {
//            x = - 1;
//        }//��ʼ���������
//
//    d[0][0] = 0;//��0���㵽ԭ��ľ���Ϊ0
//    q.push({0, 0});//��һ�����Ƚ���һ����������q��
//
//    while (!q.empty()) {
//        auto t = q.front();//�ڶ�����ȡ����ͷԪ�أ���pop��
//        q.pop();
//
//        for (int i = 0; i < 4; i++) {//��������������Ҫ��ĵ���뵽����q��
//            int x = t.first + dx[i], y = t.second + dy[i];
//
//            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
//                d[x][y] = d[t.first][t.second]  + 1;
//                Prev[x][y] = t;
//                q.push({x, y});
//            }
//        }
//
//    }
//    //���·��
//    
//    int x = n-1,y = m-1;
//    while(x||y){
//        cout << x << " " << y <<endl;
//        auto t = Prev[x][y];
//        x = t.first,y = t.second;
//    }
//    
//
//    return d[n - 1][m - 1];
//}
//
//
//int main() {
//    cin >> n >> m;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> g[i][j];
//        }
//    }
//
//    cout << bfs() << endl;
//	system("pause");
//    return 0;
//}