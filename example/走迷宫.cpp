//#include <bits/stdc++.h>
//using namespace std;
//
//typedef pair<int, int> PII;
//
//const int N = 1e2 + 7;
//int g[N][N], d[N][N];//g是初始矩阵，d代表这个点到原点的距离
//int n, m;
//PII Prev[N][N];//记录路径
//
//int bfs() {
//    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//    queue <PII> q;
//
//    for (auto &v : d) 
//        for (auto &x : v) {
//            x = - 1;
//        }//初始化距离矩阵
//
//    d[0][0] = 0;//第0个点到原点的距离为0
//    q.push({0, 0});//第一步：先将第一个点插入队列q中
//
//    while (!q.empty()) {
//        auto t = q.front();//第二步：取出队头元素，并pop掉
//        q.pop();
//
//        for (int i = 0; i < 4; i++) {//第三步：将符合要求的点插入到队列q中
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
//    //输出路径
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