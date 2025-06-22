
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
//Nhân dịp nghỉ lễ ngày 2 / 9, Tèo muốn đi du lịch tại nước Neverland, từ thành phố Hồ Chí Minh muốn tới Neverland 
//có tất cả M chuyến bay 1 chiều giữa các thành phố, các thành phố Tèo có thể đi qua được đánh số từ 1 tới N,
//trong đó thành phố Hồ Chí Minh được đánh số là 1 và Neverland được đánh số là N.
//
//Tèo có một phiếu giảm giá ngày Quốc khánh có thể áp dụng để giảm 50 % giá vé cho 1 chuyến bay duy nhất 
//trong tất cả các chuyến bay trong hành trình tới Neverland.Nếu giá vé chuyến bay là số lẻ thì bạn sẽ được 
//làm tròn xuống.Bạn hãy giúp Tèo sử dụng phiếu giảm giá này một cách hợp lý để có thể tối thiểu chi phí bay của Tèo
//.Dữ liệu đảm bảo Tèo luôn tìm được đường đi từ thành phố HCM tới Neverland.
int n, m;
vector<pair<long long, int>> ke[1000005];
long long d[1000005][2];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ke[u].push_back({ v,w });
	}
}

void Dijkstra(int s) {
	priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>,
		greater<tuple<long long, int, int>>> q;
	for(int i = 1; i <= n; i++) {
		d[i][0] =1e18; 
		d[i][1] = 1e18; 
	}
	d[s][0] = 0; 
	q.push({ 0, s, 0 }); 
	while (!q.empty()) {
		int u = get<1>(q.top());
		long long du = get<0>(q.top());
		int used = get<2>(q.top());
		q.pop();
		if (du > d[u][used]) continue;
		for (auto it : ke[u]) {
			int v = it.first;
			long long w = it.second;
			if (used == 0) {
				if (d[v][0] > du + w) {
					d[v][0] = du + w;
					q.push({ d[v][0], v, 0 });
				}
				if (d[v][1] > du + w / 2) {
					d[v][1] = du + w / 2;
					q.push({ d[v][1], v, 1 });
				}
			} else { 
				if (d[v][1] > du + w) {
					d[v][1] = du + w;
					q.push({ d[v][1], v, 1 });
				}
			}
		}
	}
	cout << min(d[n][0], d[n][1]);
}
int main()
{
	nhap();
	Dijkstra(1);
}

