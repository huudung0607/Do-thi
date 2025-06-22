
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
vector<int> ke[100005];
vector<int> rke[100005];
int visited[100005];
stack<int> st;
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		rke[y].push_back(x);//đồ thị lật ngược
		// 1--->2 => 1<---2
	}
}
void dfs(int u) {
	visited[u] = 1;
	for (auto v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	st.push(u);
}
void dfs2(int u) {
	visited[u] = 1;
	for (auto v : rke[u]) {
		if (!visited[v]) {
			dfs2(v);
		}
	}
}

void Kosaraju() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);//tìm thứ tự topo trên đồ thị gốc (stack,st.push(u))
		}
	}
	memset(visited, 0, sizeof(visited));
	int dem = 0;
	while (!st.empty()) {
		int x = st.top(); //lấy đỉnh từ đồ thị gốc, xong dfs đỉnh từ đồ thị gốc đó trên đồ thị ngược.
		st.pop();
		if (!visited[x]) {
			dfs2(x);//dfs trên đồ thị ngược, nếu dfs trên đồ  thị gốc thì x đi được hết tất cả mọi đỉnh
			dem++;
		}
	}
	if (dem == 1) cout << "Lien thong manh"; //gọi từ đỉnh s(1 đỉnh->cnt = 1)
	//đi được hết tất cả các đỉnh khác nên dem = 1 -> liên thông mạnh
	if (dem != 1) cout << "Co nhieu thanh phan ltm";
	//nghĩa là dem > 1 thì gọi được nhiều đỉnh, vd dem = 2 thì có
	// 2 thành phần LTM
}
int main()
{
	nhap();
	Kosaraju();
}

