
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

int parent[10000];
int sz[10005];
int n, m;
int visited[10005];
int bac[10005];
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
void Union(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	if (bac[u] < bac[v] || bac[u] == bac[v] && u > v) {
		parent[u] = v;
	}
	else parent[v] = u;
}

int main()
{
	cin >> n >> m;
	init();
	vector<pair<int, int>> v;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v.push_back({ x,y });
		bac[x]++;
		bac[y]++;
	}
	for (auto x : v) {
		Union(x.first, x.second);
	}
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (i == parent[i]) {
			res.push_back(i);
		}
	}
	sort(res.begin(), res.end());
	for (auto x : res) {
		cout << x << " ";
	}
}

