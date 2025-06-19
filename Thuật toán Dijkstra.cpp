
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
int n, m, start;
vector<pair<int, int>> ke[100005];
vector<edge> dscanh;
int used[100005];
int d[100005];
void nhap() {
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({ y,w });
		ke[y].push_back({ x,w });
		dscanh.push_back({ x,y,w });
	}
}
void Dijkstra(int s) {
	priority_queue < pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>> q;
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	q.push({ 0,s });
	d[s] = 0;
	while (!q.empty()) {
		pair<int, int> x = q.top(); q.pop();
		// x.first : chi phi duong di
		// x.second : dinh den
		int dis = x.first;
		int u = x.second;
		if (dis > d[u]) continue;
		//Relaxation
		for (pair<int, int> e : ke[u]) {
			int v = e.first, w = e.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({ d[v],v });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
}
int main()
{
	nhap();
	Dijkstra(start);
}

