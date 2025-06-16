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
vector<int> ke[200005];
int visited[200005];
int degree[200005];
vector<int> reverse_ke[200005];
stack<int> st;
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		//ke[y].push_back(x);
		reverse_ke[y].push_back(x);
		degree[y]++;
	}
	for (int i = 1; i <= n; i++) {
		sort(ke[i].begin(), ke[i].end());
	}
}
void dfs(int u) {
	visited[u] = 1;
	for (auto x : ke[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
	st.push(u);
}
void dfs2(int u) {
	visited[u] = 1;
	cout << u << " ";
	for (auto x : reverse_ke[u]) {
		if (!visited[x]) {
			dfs2(x);
		}
	}
}
void Kosaraju() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs(i);
	}
	memset(visited, 0, sizeof(visited));
	int dem = 0;
	while (!st.empty()) {
		int s = st.top(); st.pop();
		if (!visited[s]) {
			dem++;
			dfs2(s);
			cout << endl;
		}
	}
	if (dem == 1) cout << "Do thi lien thong manh" << endl;
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
void Kahn() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) q.push(i);
	}
	int dem = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << " ";
		dem++;
		for (auto v : ke[u]) {
			degree[v]--;
			if (degree[v] == 0) {
				q.push(v);
			}
		}
	}
	if (dem < n) {
		cout << "Co chu trinh";
	}
}
int main()
{
	nhap();
	Kahn();
}
