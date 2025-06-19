
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
struct edge {
	int x, y, w;
};
int n, m;
vector<pair<int, int>> ke[100005];
vector<edge> dscanh;
int used[100005];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({ y,w });
		ke[y].push_back({ x,w });
		dscanh.push_back({ x,y,w });
	}
}

void Prim(int s) {
	priority_queue <pair<int, int>, vector 
		<pair<int, int>>, greater<pair<int, int>>> q;
	for (pair<int, int> x : ke[s]) {
		int i = x.first, j = x.second;
		q.push({ j,i });
	}
	used[s] = 1; //cho s vao cay khung
	long long d = 0;
	int cnt = 1;
	while (!q.empty()) {
		pair<int, int> e = q.top(); q.pop();
		if (used[e.second] == 1) continue;
		cnt++;
		d += e.first;
		int u = e.second;
		used[u] = 1;
		for (auto x : ke[u]) {
			int v = x.first, w = x.second;
			if (!used[v]) {
				q.push({ w,v });
			}
		}
	}
	if (cnt < n)cout << "IMPOSSIBLE";
	else cout << d;
}


int main()
{
	nhap();
	Prim(1);
}

