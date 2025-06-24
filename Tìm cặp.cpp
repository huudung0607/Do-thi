
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
int n;
vector<int> ke[100005];
int d[100005];
int visited[100005];
void nhap() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void dfs(int u, int parent) {
	for (int v : ke[u]) {
		if (v != parent) {
			d[v] = d[u] + 1;
			dfs(v, u);
		}
	}
}

int main()
{
	nhap();
	d[1] = 0;
	dfs(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += d[i] + 1;
	}
	cout << ans;
}

