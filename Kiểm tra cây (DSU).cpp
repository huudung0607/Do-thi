
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
int n, m;
int parent[10005];
int sz[10005];
void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int u) {
	if (u == parent[u]) return u;
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
int main()
{
	cin >> n >> m;
	if (m != n - 1) {
		cout << 0;
		return 0;
	}
	init();
	bool ok = false;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		int u = find(x);
		int v = find(y);
		if (!Union(u, v)) ok = true;
	}
	if (ok)cout << 0;
	else cout << 1;
}

