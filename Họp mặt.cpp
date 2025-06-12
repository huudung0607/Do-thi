
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
int n, m, k;
vector<int> ke[100005];
int parent[100005];
int visited[100005];
int mark[100005];
vector<int> nguoi;
int cnt;
void nhap() {
	cin >> k >> n >> m;
	for (int i = 0; i < k; i++) {
		int x; cin >> x; nguoi.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		//ke[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(ke[i].begin(), ke[i].end());
	}
}
void dfs(int u) {
	visited[u] = 1;
	mark[u]++;
	for (auto v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main()
{
	nhap();
	int cnt = 0;
	for (auto x : nguoi) {
		memset(visited, 0, sizeof(visited));
		dfs(x);
	}
	for (int i = 1; i <= n; i++) {
		if (mark[i] == k) {
			cnt++;
		}
	}
	cout << cnt;
}

