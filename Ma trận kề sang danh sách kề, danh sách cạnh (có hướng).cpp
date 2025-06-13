
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
int n;
vector<int> ke[10005];
int a[5005][5005];
vector<pair<int, int>> canh;
void nhap() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	nhap();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 1) {
				ke[i].push_back(j);
				canh.push_back({ i,j });
			}
		}
	}
	for (auto x : canh) {
		cout << x.first << " " << x.second << endl;
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << i << " : ";
		sort(ke[i].begin(), ke[i].end());
		for (auto x : ke[i]) cout << x << " ";
		cout << endl;
	}
	
}

