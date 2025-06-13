
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
	for (int i = 1; i <= n; i++) {
		sort(ke[i].begin(), ke[i].end());
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
				parent[y] = x;
			}
		}
	}
}
void dfs(int u) {
	visited[u] = 1;
	for (auto v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	nhap();
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dem++;
			dfs(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		visited[i] = 1;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				cnt++;
				dfs(j);
			}
		}
		if (cnt > dem) {
			ans++;
		}
	}
	cout << ans;
}

