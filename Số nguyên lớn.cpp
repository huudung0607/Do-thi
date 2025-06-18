
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
int F[5005][5005];
int main()
{
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	s = " " + s;
	t = " " + t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i] == t[j]) {
				F[i][j] = F[i - 1][j - 1] + 1;
			}
			else {
				F[i][j] = max(F[i - 1][j], F[i][j - 1]);
			}
		}
	}
	cout << F[n][m];
}

