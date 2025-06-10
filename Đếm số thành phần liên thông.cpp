
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
vector<int> ke[1005];
int n, m;
bool visited[1005];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void dfs(int u) {
	visited[u] = true;
	for (auto x : ke[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}
int main()
{
	nhap();
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dem++;
			dfs(i);	
		}
	}
	cout << dem;
}

