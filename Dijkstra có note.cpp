
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
int n, m, s;
vector<pair<int, int>>ke[100005];
int d[100005];
void nhap() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({ y,w });
		ke[y].push_back({ x,w });
	}
}
void Dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, 
		greater<pair<int, int>>> q;
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;//ban dau chi phi duong di la vo cung
	}
	d[s] = 0; // chi phí duong di từ s -> s = 0 (dĩ nhiên)
	q.push({ 0,s }); //đẩy (0,s) vào hàng đợi ưu tiên
	//trong đó 0 là chi phí đường đi tới đỉnh, s là đỉnh đến
	// (0,s) là chi phí đi đến s = 0
	while (!q.empty()) {
		pair<int, int> x = q.top(); q.pop();
		int dis = x.first; //chi phí đường đi
		int dinh = x.second; //đỉnh đến
		if (dis > d[dinh]) continue; // chi phí đường đi
		//lớn hơn chi phí đã có (chi phí đã có lưu trong mảng d) thì bỏ
		//qua tại nó không phải chi phí nhỏ nhất.
		// vd ({5,7}) chi phí đường đi đến 7 là 5, nhưng đỉnh 7 hiện tại 
		// chi phí đường đi tính trước đó là d[7] = 4 => 5 > 4 nên không update
		for (pair<int, int> e : ke[dinh]) { //duyệt các đỉnh kề với dinh đang xét (dinh)
			int v = e.first, w = e.second;
			// v là đỉnh, w là trọng số (tại ke[x].push_back({x,w});)
			if (d[v] > d[dinh] + w) { //nếu đường đi đỉnh đang xét lớn
				//hơn đường đi đỉnh trước + trọng số thì update
				//ví dụ : 1 -(1)-> 2 -(1)-> 3
				//		  |--------(6)------|
				// thì đỉnh 1-->2-->3 chi phí = 2
				// 1-->3 thì chi phí = 6
				// xét for(pair e : ke[2]) ke[2] = 3.
				// d[3] > d[2] + w là d[3] = 6 > 1 + 1
				// nên update d[3] = d[e] + w = 2
				d[v] = d[dinh] + w;
				q.push({ d[v],v });//đẩy đường đi ngắn hơn đến v và đỉnh v
				//vào hàng đợi
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";// đường đi ngắn nhất từ s đến các đỉnh còn lại
		// vd từ s đến đỉnh 2 là 2, 3 là 5 thì in 2 5,...
	}
}
int main()
{
	nhap();
	Dijkstra(s);//---> tìm đường đi ngắn nhất từ đỉnh s đến các đỉnh khác
}

