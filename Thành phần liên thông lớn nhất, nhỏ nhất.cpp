
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
vector<int>ke[200005];
int visited[200005];
int cnt = 0;
void nhap() {
	cin >> n;
	for (int i = 0; i < n; i++) {
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
	nhap();
	int maxcnt = -1;
	int mincnt = 1000000;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt = 0;
			dfs(i);
			if (cnt == 1) continue;
			mincnt = min(mincnt, cnt);
			maxcnt = max(maxcnt, cnt);
		}
	}
	cout << mincnt << " " << maxcnt << endl;
}

