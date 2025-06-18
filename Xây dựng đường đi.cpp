
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
void Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (u < v) {
		parent[v] = u;
	}
	else parent[u] = v;
}
int main() {
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		Union(x, y);
	}
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (i == find(i)) res.push_back(i);
	}
	cout << res.size() - 1 << endl;
	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << " " << res[i + 1] << endl;
	}
}


