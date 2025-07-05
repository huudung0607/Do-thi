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
vector<int> ke[100005];
bool visited[100005];
set<int> ve;
int degree[100005];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		degree[x]++;
		degree[y]++;
		ve.insert(x); ve.insert(y);
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int e = q.front(); q.pop();
		for (auto v : ke[e]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

void euler() {
	for (int i = 1; i <= n; i++) {
		if (degree[i] % 2 == 1) {
			cout << "29tech"; return;
		}
	}
	bfs(1);
	for (int i : ve) {
		if (!visited[i]) {
			cout << "29tech"; return;
		}
	}
	cout << "28tech";
}
int main() {
	nhap();
	euler();
}
