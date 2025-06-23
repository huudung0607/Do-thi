
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
vector<pair<int,int>> ke[100005];
int dics[1005][1005];
void nhap() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i == j) dics[i][j] = 0;
			else dics[i][j] = 1e9;
		}
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({ y,w });
		ke[y].push_back({ x,w });
		dics[x][y] = dics[y][x] = w;
	}
}
void Floyd_Warshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dics[i][j] = min(dics[i][j],dics[i][k]
					+ dics[k][j]);
			}
		}
	}
}
int main()
{
	nhap();
	Floyd_Warshall();
	int t;
	cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;
		cout << dics[x][y] << endl;
	}
}

