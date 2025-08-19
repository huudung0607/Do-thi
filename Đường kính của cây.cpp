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
vector<int>ke[1000005];
int a[1000005];
int visited[1000005];
int n;
int sz[1000005];
int maxDis = -1;
int x = -1;
void nhap() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void dfs(int u) {
	visited[u] = 1;
	for (int v : ke[u]) {
		if (!visited[v]) {
			sz[v] = sz[u] + 1;		
			maxDis = max(maxDis, sz[v]);
			dfs(v);		
		}
	}
	if (sz[u] == maxDis) x = u;
}

int main()
{
	nhap();
	dfs(1);
	memset(visited, 0, sizeof(visited));
	memset(sz, 0, sizeof(sz));
	maxDis = 0;
	dfs(x);
	cout << maxDis;
}

