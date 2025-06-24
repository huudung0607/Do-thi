
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
vector<int> ke[10005];
int visited[10005];
int cnt = 0;
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void dfs(int u) {
	visited[u] = 1;
	cnt++;
	for (int v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main()
{
	nhap();
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt = 0;
			dfs(i);
			sum += 1ll * cnt * (cnt - 1) / 2;
		}
	}
	if (sum == m) cout << "YES";
	else cout << "NO";
}

