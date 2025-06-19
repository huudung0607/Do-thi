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
struct edge {
	int x, y, w;
};
int n, m;
vector<pair<int, int>> ke[100005];
vector<edge> dscanh;
int parent[100005];
int sz[100005];
void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	return parent[u] = find(parent[u]);
}
bool Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (sz[u] < sz[v]) {
		parent[u] = v;
		sz[v] += sz[u];
	}
	else {
		parent[v] = u;
		sz[u] += sz[v];
	}
	return true;
}

void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({ y,w });
		ke[y].push_back({ x,w });
		dscanh.push_back({ x,y,w });
	}
}

void Kruskal() {
	sort(dscanh.begin(), dscanh.end(), [](edge a, edge b)->bool {
		return a.w < b.w;
		});
	long long d = 0;
	vector<edge> MST;
	for (int i = 0; i < m; i++) {
		if (MST.size() == n - 1) {
			break;
		}
		if (Union(dscanh[i].x, dscanh[i].y)) {
			d += dscanh[i].w;
			MST.push_back({ dscanh[i] });
		}
	}
	if (MST.size() < n - 1) {
		cout << "IMPOSSIBLE" << endl;
	}
	else cout << d;
}
int main()
{
	nhap();
	init();
	Kruskal();
}
