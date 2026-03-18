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

struct Node {
	int dist, x, y;
	bool operator>(const Node& other) const {
		return dist > other.dist;
	}
};

int n, m, s, t, u, v;
int a[505][505];
int d[505][505];
pair<int, int> parent[505][505];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void nhap() {
	cin >> n >> m;
	cin >> s >> t >> u >> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
}

void dijkstra() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = 1e9;
		}
	}
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	d[s][t] = 0;
	pq.push({ 0, s, t });
	while (!pq.empty()) {
		Node top = pq.top();
		pq.pop();
		int dis = top.dist;
		int curr_x = top.x;
		int curr_y = top.y;
		if (dis > d[curr_x][curr_y]) continue;
		if (curr_x == u && curr_y == v) break;
		for (int k = 0; k < 4; k++) {
			int nx = curr_x + dx[k];
			int ny = curr_y + dy[k];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == 1) {
				if (d[nx][ny] > d[curr_x][curr_y] + 1) {
					d[nx][ny] = d[curr_x][curr_y] + 1;
					parent[nx][ny] = { curr_x, curr_y };
					pq.push({ d[nx][ny], nx, ny });
				}
			}
		}
	}
}

int main() {
	nhap();
	dijkstra();
	if (d[u][v] == 1e9) {
		cout << 0 << endl;
		return 0;
	}
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
	for (auto p : path) {
		cout << p.first << " " << p.second << endl;
	}
}
