
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
vector<int> ke[100005];
int cnt = 0;
int visited[100005];
vector<int> v;
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void dfs(int u) {
	visited[u] = 1;
	cnt++;
	for (auto v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main()
{
	nhap();
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dem++;
			cnt = 0;
			dfs(i);
			v.push_back(cnt);
		}
	}
	cout << "So thanh phan lien thong : " << dem << endl;
	for (int i = 0; i < v.size(); i++) {
		cout <<"Thanh phan lien thong " << i + 1 << " : "
			<< v[i] << " dinh" << endl;
	}
}

