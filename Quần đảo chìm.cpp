
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
vector<int>ke[100005];
int visited[100005];
int dinh = 0;
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
	for (int v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main() {
	nhap();
	//dem so tplt
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dem++;
			dfs(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		int demnew = 0;
		visited[i] = 1;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				demnew++;
				dfs(j);
			}
		}
		if (demnew > dem) {
			ans++;
		}
	}
	cout << ans;
}
