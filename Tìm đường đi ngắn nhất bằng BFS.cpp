
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
#include <fstream>
using namespace std;

int n, m, s, t, u, v;
int a[505][505];
int visited[505][505];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
pair<int,int> parent[505][505];

void nhap() {
	cin >> n >> m;
	cin >> s >> t >> u >> v;
	for (int i = 1; i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> a[i][j];
		}
	}
}
void bfs() {
	visited[s][t] = 1;
	queue<pair<int, int>> q;
	q.push({ s,t });
	parent[s][t] = { -1,-1 };
	while (!q.empty()) {
		pair<int, int> it = q.front();
		int i = it.first, j = it.second;
		q.pop();
		if (it.first == u && it.second == v) {
			return;
		}
		for (int k = 0;k < 4;k++) {
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1 && !visited[i1][j1]) {
				q.push({ i1,j1 });
				parent[i1][j1] = { i, j };
				visited[i1][j1] = 1;
			}
		}
	}
}
int main() {
	nhap();
	bfs();
	vector<pair<int, int>> path;
	int x = u, y = v;
	while (x != s || y != t) {
		path.push_back({ x,y });
		pair<int, int> tmp = parent[x][y];
		x = tmp.first;
		y = tmp.second;
	}
	path.push_back({ s,t });
	reverse(path.begin(), path.end());
	cout << path.size() << endl;
	for (auto x : path) {
		cout << x.first << " " << x.second << endl;
	}
}
