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
int color[100005];
int visited[100005];
vector<int> ke[100005];
bool flag = true;
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void dfs(int u,int c) {
	color[u] = c; // đánh màu theo 3 - c
	for (int v : ke[u]) {
		if (color[v] != 0) { // nếu color != 0 là đã gán màu
			if (color[v] == color[u]) { //cùng màu thì không phải đồ thị 2 phía
				flag = false;
				return;
			}
		}
		else {
			dfs(v, 3 - c); //neu c = 1 thi 3 - c = 2, c = 2 thi 3 - c = 1
		}
	}
}
int main()
{
	nhap();
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			dfs(i, 1); //gọi DFS và gán màu c = 1
		}
	}
	if (flag) cout << "YES";
	else cout << "NO";
}
