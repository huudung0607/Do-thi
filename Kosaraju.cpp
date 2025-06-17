#include <cstring>
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
vector<int> ke[20005];
vector<int> reverse_ke[20005];
int visited[20005];
stack<int> st;

void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		reverse_ke[y].push_back(x);
		//ke[y].push_back(x);
	}
}
void dfs(int u) {
	visited[u] = 1;
	for (auto v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	st.push(u);
}
void dfs2(int u) {
	visited[u] = 1;
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
	int dem = 0;
	memset(visited, 0, sizeof(visited));
	while (!st.empty()) {
		int s = st.top();
		st.pop();
		if (!visited[s]) {
			dfs2(s);
			dem++;
		}
	}
	if (dem == 1) cout << "1";
	else cout << "0";
}

int main()
{
	nhap();
	Kosaraju();
}

