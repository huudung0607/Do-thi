
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int>>iii;
struct edge {
	int x, y, w;
};
int n, m, start;
vector<pair<int, int>> ke[100005];
vector<edge> dscanh;
int used[505][505];
int d[505][505];
int a[505][505];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };


void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			d[i][j] = 1e9;
		}
	}
}
void Dijkstra(int i,int j) {
    priority_queue<iii, vector<iii>, greater<iii>> Q;
    d[i][j] = a[i][j];
	Q.push({ a[i][j],{i,j}});
    while (!Q.empty()) {
		pair<int, pair<int, int>> e = Q.top();
		Q.pop();
		int dis = e.first;
		int u = e.second.first;
		int v = e.second.second;
		if (dis > d[u][v]) continue;
		for (int k = 0; k < 4; k++) {
			int u1 = u + dx[k]; int v1 = v + dy[k];
			if (d[u1][v1] > d[u][v] + a[u1][v1]) {
				d[u1][v1] = d[u][v] + a[u1][v1];
				Q.push({ d[u1][v1],{u1,v1} });
			}
		}
    }
}
int main()
{
	nhap();
	Dijkstra(1, 1);
	cout << d[n][m];
}

