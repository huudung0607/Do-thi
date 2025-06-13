
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
int n, m, s;
vector<int>ke[10005];
int visited[100005];
void nhap() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		//ke[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(ke[i].begin(), ke[i].end());
	}
}
void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (auto y : ke[x]) {
			if (!visited[y]) {
				q.push(y);
				visited[y] = 1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	nhap();
	bfs(s);
}

