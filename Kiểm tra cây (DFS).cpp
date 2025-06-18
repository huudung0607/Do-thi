
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
int parent[10005];
int visited[10005];

void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
bool dfs(int u) {
	visited[u] = 1;
	for (auto v : ke[u]) {
		if (!visited[v]) {
			parent[v] = u;
			if (dfs(v)) return true;
		}
		else {
			if (v != parent[u]) return true;
		}
	}
	return false;
}
// nen check xem co lien thong hay khong (la chung 1 parent)
int main()
{
	nhap();
	if (m != n - 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (dfs(i)) {
				cout << 0;
				return 0;
			}
		}
	}
	cout << 1;
}

