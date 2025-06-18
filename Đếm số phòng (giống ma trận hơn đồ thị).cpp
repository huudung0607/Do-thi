// đếm thành phần liên thông
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
int visited[5005][5005];
char a[5005][5005];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void nhap() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
}
void dfs(int i, int j) {
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m 
			&& !visited[i1][j1] && a[i1][j1] == '.') {
			dfs(i1, j1);
		}
	}
}
int main()
{
	nhap(); 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && a[i][j] == '.') {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt;
}

