
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
int n;
int a[1000005];
vector<int> ke[1000005];
int sz[1000005];
int visited[1000005];
void nhap() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		ke[x].push_back(i);
	}
}

void dfs(int u) {
	sz[u] = 0;
	visited[u] = 1;
	for (int v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
			sz[u] += sz[v] + 1;
		}
	}
}

int main() {
	nhap();
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << sz[i] << " ";
	}
}
