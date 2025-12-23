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

int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };


int n, a[1005][1005];
int s, t, u, v;
int d[1005][1005];
void nhap() {
	cin >> n;
	cin >> s >> t >> u >> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
}

int bfs() {
	queue<pair<int, int>> q;
	q.push({ s,t });
	a[s][t] = 0;
	d[s][t] = 0;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		int i = it.first, j = it.second;
		if (i == u && j == v) {
			return d[i][j];
		}
		for (int k = 0; k < 8; k++) {
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= n
				&& a[i1][j1] == 1) {
				a[i1][j1] = 0;
				d[i1][j1] = d[i][j] + 1;
				q.push({ i1,j1 });
			}
		}
	}
	return -1;
}

int main() {
	nhap();
	cout << bfs();
}
