
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
vector<int>ke[100005];
stack<int> st;
int visited[100005];
int degree[100005];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		degree[y]++;
		//ke[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(ke[i].begin(), ke[i].end());
	}
}
void Kahn() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) q.push(i);
	}
	int dem = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		dem++;
		cout << x << " ";
		for (auto v : ke[x]) {
			degree[v]--;
			if (degree[v] == 0) {
				q.push(v);
			}
		}
	}
	if (dem < n) cout << "Co chu trinh";
	else cout << "Khong co chu trinh";
	//vì thuật toán Kahn không xóa được các đỉnh về 0 nếu có chu trình
	// 1 -> 2 -> 3 -> 1 (chu trình)
	//đỉnh mà Kahn không in ra chính là chu trình
	//vd 8 9
	/*  1 2
		2 3
		3 6
		5 6
		6 8
		4 5
		2 4
		4 7
		8 5
		in ra 1 2 3 4 7, còn 5 6 8 không in do là chu trình
	*/
}

int main() {
	nhap();
	Kahn();
}
