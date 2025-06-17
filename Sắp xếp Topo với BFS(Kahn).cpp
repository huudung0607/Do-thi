
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
vector<int> ke[20005];
int visited[20005];
int degree[20005];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		degree[y]++;
		//ke[y].push_back(x);
	}
}

void Kahn() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) q.push(i);
	}
	int dem = 0;
	while (!q.empty()) {
		dem++;
		int u = q.front();
		q.pop(); cout << u << " ";
		for (int v : ke[u]) {
			degree[v]--;
			if (degree[v] == 0) {
				q.push(v);
			}
		}
	}
	if (dem < n) {
		cout << "Do thi co chu trinh";
	}
	else cout << "Khong co chu trinh";
}

int main()
{
	nhap();
	Kahn();
}

