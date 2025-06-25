
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
vector<int> ke[100005];
int fish[100005];
int visited[100005];
int ans = 0;
void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> fish[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(ke[i].begin(), ke[i].end());
	}
}
void dfs(int u,int cnt) {
	visited[u] = 1;
	if (fish[u] == 1) {
		cnt++;
	}
	else cnt = 0;
	if (cnt > m) return;
	if (ke[u].size() == 1) {
		ans++;
	}
	else {
		for (int v : ke[u]) {
			if (!visited[v]) {
				dfs(v, cnt);
			}
		}
	}
}
int main()
{
	nhap();
	dfs(1, 0);
	cout << ans;
}

