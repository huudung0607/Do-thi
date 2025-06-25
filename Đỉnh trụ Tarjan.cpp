
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

using namespace std;
using ll = long long;
int n, m, timer = 0;
vector<int> adj[1005];
int disc[1005], low[1005];
bool visited[1005], AP[1005];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	memset(visited, false, sizeof(AP));
}

void DFS(int u, int par) {
	visited[u] = true;
	disc[u] = low[u] = ++timer;
	int child = 0;
	for (int v : adj[u]) {
		if (v == par) continue;
		if (!visited[v]) {
			DFS(v, u);
			++child;
			low[u] = min(low[u], low[v]);
			if (par != -1 && disc[u] <= low[v]) {
				AP[u] = true;
			}
		}
		else {
			low[u] = min(low[u], disc[v]);
		}
	}
	if (par == -1 && child > 1) AP[u] = true;
}

int main() {
	nhap();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i, -1);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (AP[i]) cout << i << ' ';
	}
}
