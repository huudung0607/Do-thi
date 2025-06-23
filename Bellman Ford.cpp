
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
vector<edge> canh;
int d[10005];
int n, m;
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		canh.push_back({ x,y,w });
	}
}
void BellmanFord(int s) {
	fill(d + 1, d + n + 1, 1e9);
	d[s] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (edge e : canh) {
			int u = e.x, v = e.y, w = e.w;
			if (d[u] < 1e9) {
				d[v] = min(d[v], d[u] + w);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << ' ';
	}
}

int main()
{
	nhap();
	BellmanFord();
}

