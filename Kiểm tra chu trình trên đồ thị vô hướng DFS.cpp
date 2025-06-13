
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
#include <cstring>
using namespace std;
int n, m, s, t;
vector<int>ke[10005];
int visited[100005];
int parent[100005];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto y : ke[x]) {
			if (!visited[y]) {
				q.push(y);
				visited[y] = 1;
			}
		}
	}
}
bool dfs(int u) {
	visited[u] = 1;
	for (auto v : ke[u]) {
		if (visited[v]) {
			if (v != parent[u]) {
				return true;
			}
		}
		else {
			parent[v] = u;
			if (dfs(v)) return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	nhap();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (dfs(i)) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
}

