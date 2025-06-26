
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
int n, m, s, t, u, v;
char a[505][505];
int visited[505][505][4];

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

struct State {
	int x, y;
	int direct;
	int dircnt;
};
bool bfs(int i, int j) {
	queue<State> q;
	// int1,int 2 : tọa độ i,j
	// int3 : hướng di chuyển
	// int 4 : số lần di chuyển theo hướng đó
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 0 && j1 >= 0 && i1 < n && j1 <m
			&& (a[i1][j1] == '.' || a[i1][j1] == 'T')) {
			q.push({ i1,j1,k,0 });
			/*Dòng này là bước khởi đầu, bạn đang đứng ở vị trí S.
			Từ đó bắt đầu đi theo 4 hướng:
			Lúc này, chưa đi qua hướng nào trước đó ⇒ chưa rẽ lần nào cả.
			➡️ Vì vậy, int4 = 0
			Đây là hướng đầu tiên được chọn, không phải là một "đổi hướng"
			từ một hướng nào trước đó.*/
			visited[i1][j1][k] = 1;
			//đánh dấu i1,j1 theo hướng của k đã đi, nghĩa là
			//đã đi theo hướng k 1 lần (k : trái,phải,trên,dưới)
		}
	}
	while (!q.empty()) {
		State idk = q.front();
		q.pop();
		if (idk.x == u && idk.y == v && idk.dircnt <= 2) {
			return true;
		}
		for (int k = 0; k < 4; k++) {
			int i1 = idk.x + dx[k];
			int j1 = idk.y + dy[k];
			int newcnt = idk.dircnt + (k != idk.direct);
			//đi theo 4 hướng theo index của dx,dy
			//0,1,2,3 : lên, xuống, trái, phải
			// nếu k là hướng sẽ đi khác với hướng đi đã đi là
			// idx.direct thì sẽ tăng hướng đi mới newcnt lên
			// và idx.dircnt : số lần đã đổi hướng hiện tại
			// vd  k = 1 : đi xuống có idk.dircnt = 2 thì đã đi xuống 2 lần
			if (i1 >= 0 && j1 >= 0 && i1 < n && j1 < m
				&& (a[i1][j1] == '.' || a[i1][j1] == 'T') && newcnt <= 2
				&& !visited[i1][j1][k]) {
				q.push({ i1,j1,k,newcnt });
				visited[i1][j1][k] = 1;
			}
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'T') {
				u = i;
				v = j;
			}
			if (a[i][j] == 'S') {
				s = i;
				t = j;
			}
		}
	}
	if (bfs(s, t)) cout << "YES";
	else cout << "NO";
}

