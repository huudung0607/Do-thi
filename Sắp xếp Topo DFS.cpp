
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
stack<int>st;
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		//ke[y].push_back(x);
	}
}

void dfs(int u) {
	visited[u] = 1;
	for (auto x : ke[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
	st.push(u);
}

int main()
{
	nhap();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}

