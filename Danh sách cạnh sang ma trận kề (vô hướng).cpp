
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
int a[5005][5005];
int main()
{
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		a[u][v] = a[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
//Input 01
5 4
4 3
3 1
4 2
5 4
Output 01
0 0 1 0 0 
0 0 0 1 0 
1 0 0 1 0 
0 1 1 0 1 
0 0 0 1 0
