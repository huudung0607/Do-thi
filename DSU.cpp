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
int parent[20005];
void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
int find(int u) {
	while (u != parent[u]) {
		u = parent[u];
	}
	return u;
}
bool Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (u < v) {	
		parent[v] = u;
	}
	else parent[u] = v;
	return true;
}
int main() {
	cin >> n >> m;
	init();
	
}
