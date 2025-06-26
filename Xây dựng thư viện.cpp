
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
int road, clib;
vector<int>ke[200005];
int visited[200005];
int cnt = 0;
void nhap() {
	cin >> n >> m;
	cin >> clib >> road;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void dfs(int u) {
	cnt++;
	visited[u] = 1;
	for (int v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}
int main()
{
	int t; cin >> t;
	while (t--) {
		nhap();
		long long res1 = 1ll * clib * n;
		memset(visited, 0, sizeof(visited));
		long long res2 = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				cnt = 0;
				dfs(i);
				res2 += clib + 1ll * (cnt - 1) * road;
			}
		}
		cout << min(res1, res2) << endl;
		for (int i = 1; i <= n; i++) {
			ke[i].clear();
		}
	}
}

