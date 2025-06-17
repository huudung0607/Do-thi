#include <cstring>
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
int parent[20005];
int sz[20005];
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
}
int main() {
	cin >> n >> m;
	init();
	
}
