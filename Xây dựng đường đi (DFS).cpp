
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
vector<int> ke[10005];
int n, m;
int visited[10005];
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
	for (auto v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}
int main()
{
	nhap();
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			res.push_back(i);
		}
	}
	cout << res.size() - 1 << endl;
	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << " " << res[i + 1] << endl;
	}
}

