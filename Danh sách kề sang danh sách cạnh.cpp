
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
vector<int> canh[1001];
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int x;
		while (ss >> x) {
			canh[i].push_back(x);
		}
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		for (auto x : canh[i]) {
			if (i < x) v.push_back({ i,x });
		}
	}
	sort(v.begin(), v.end());
	for (auto x : v) {
		cout << x.first << " " << x.second << endl;
	}
}

