
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
int n, m;
vector<int> ke[100005];
int parent[100005];
int visited[100005];
int mark[100005];
int cnt;
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(ke[i].begin(), ke[i].end());
	}
}
void dfs(int u) {
	visited[u] = 1;
	mark[u] = cnt;
	for (auto v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main()
{
	nhap();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int s, t;
		cin >> s >> t;
		if (mark[s] == mark[t]) cout << 1;
		else cout << -1;
		cout << endl;
	}
}

