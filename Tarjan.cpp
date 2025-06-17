
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
int n, m, timer = 0;
vector<int> ke[10005];
int visited[10005];
int dics[10005], low[10005];

void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(x);
	}

}
void dfs(int u) {
	visited[u] = 1;
	timer++;
	dics[u] = low[u] = timer;
	for (auto x : ke[u]) {
		if (!visited[x]) {
			dfs(x);
			low[u] = min(low[u], low[x]);
		}
		else {
			low[u] = min(low[u], dics[x]);
		}
	}
}
int main()
{
	nhap();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dics[i] << " " << low[i] << endl;
	}
}

