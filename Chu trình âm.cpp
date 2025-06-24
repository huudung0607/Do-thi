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
long long d[10005];
int n, m;
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		canh.push_back({ x,y,w });
	}
}
bool BellmanFord() {
	fill(d + 1, d + n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (edge e : canh) {
			int u = e.x, v = e.y, w = e.w;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if (i == n) return true;
			}
		}
	}
	return false;
}

int main()
{
	nhap();
	if (BellmanFord()) {
		cout << "28tech";
	}
	else cout << "29tech";
}
