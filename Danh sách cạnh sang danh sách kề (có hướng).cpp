
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
vector<int> ke[1005];
int n, m;
void nhap() {
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
	}
}
int main()
{
	cin >> n >> m;
	nhap();
	for (int i = 1; i <= n; i++) {
		cout << i << " : ";
		sort(ke[i].begin(), ke[i].end());
		for (auto x : ke[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

