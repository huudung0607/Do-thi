
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
#include <fstream>
using namespace std;

vector<int> ke[10005];
int parent[10005];
int visited[10005];
int n, x, y;

void nhap() {
	cin >> n >> x >> y;
	cin.ignore();
	for (int i = 1;i <= 8;i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		while (ss >> tmp) {
			int num = stoi(tmp);
			ke[i].push_back(num);
		}
	}
}
void dfs(int u) {
	visited[u] = 1;
	for (int v : ke[u]) {
		if (!visited[v]) {
			parent[v] = u;
			dfs(v);
		}
	}
}

int main() {
	nhap();
	dfs(x);
	vector<int>path;
	int start = x, end = y;
	while (end != x) {
		path.push_back(end);
		end = parent[end];
	}
	path.push_back(x);
	reverse(path.begin(), path.end());
	cout << path.size() << endl;
	for (auto x : path) {
		cout << x << " ";
	}
}
