
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
	nhap();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 1 && a[j][i] == 1) {
				ke[i].push_back(j);
			}
			if (a[i][j] == 1 && a[j][i] == 1 && i > j) {
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
		for (auto x : ke[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

