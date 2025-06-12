
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
int n, m, s;
vector<int> ke[200005];
int visited[200005];
int d[200005];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto y : ke[x]) {
			if (!visited[y]) {
				q.push(y);
				visited[y] = 1;
				d[y] = d[x] + 1;
			}
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		for (int i = 1; i <= n; i++) {
			ke[i].clear();
		}
		nhap();
		cin >> s;
		memset(visited, 0, sizeof(visited));
		memset(d, 0, sizeof(d));
		bfs(s);
		for (int i = 1; i <= n; i++) {
			if (i == s) continue;
			if (visited[i]) {
				cout << d[i] * 6 << " ";
			}
			else cout << -1 << " ";
		}
		cout << endl;
	}
}

