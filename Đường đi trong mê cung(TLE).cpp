
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
int visited[1005][1005];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int n, a[1005][1005];
int s, t, u, v;
int d[1005][1005];
int step = 0;
void nhap() {
	cin >> n;
	cin >> s >> t >> u >> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			d[i][j] = INT_MAX;
		}
	}
}
void dfs(int i, int j) {
	if (i == u && j == v) {
		d[i][j] = min(d[i][j], step);
		return;
	}
	for (int k = 0; k < 8; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= n
			&& !visited[i1][j1] && a[i1][j1] == 1) {
			visited[i1][j1] = 1;
			step++;
			dfs(i1, j1);
			visited[i1][j1] = 0;
			step--;
		}
	}
}
int main()
{
	nhap();
	if (a[s][t] == 1) {
		visited[s][t] = 1;
		dfs(s, t);
		if (d[u][v] != INT_MAX) {
			cout << d[u][v];
		}
		else cout << -1;
	}
}

