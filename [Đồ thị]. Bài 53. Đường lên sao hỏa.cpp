
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
int parent[100001];
int sz[100001];
void init() {
	for (int i = 0; i < n; i++) {
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
	if (u == v)return;
	if (sz[u] < sz[v]) {
		parent[u] = v;
		sz[v] += sz[u];
	}
	else {
		parent[v] = u;
		sz[u] += sz[v];
	}

}
int main()
{
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (parent[i] == i) {
			ans += 1ll * sz[i] * (n - sz[i]);
		}
	}
	ans /= 2; 
	cout << ans;
}

