
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
struct edge {
	int x, y, w;
};
int n, m;
vector<pair<int, int>> ke[100005];
vector<edge> canh;
int used[100005];
void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({ y,w });
		ke[y].push_back({ x,w });
		canh.push_back({ x,y,w });
	}
}
//vd : cin >> x >> y >> w --> 1 2 1
//                        --> 1 3 2
// --> ke[s] (ke[1]) = 2 3 --> x.first = 2/x.first = 3
// --> x.second = 1/x.second = 2

void Prim(int s) {
	priority_queue <pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>> q;
	for (pair<int,int> x : ke[s]) {
		int t = x.first, w = x.second;
		// x.first : dinh den, x.second : trong so
		q.push({ w,t });
	}
	used[s] = 1; // cho dinh s vao cay khung
	long long d = 0; //chi phi duong di cay khung min
	int cnt = 1; //da co 1 dinh trong cay khung
	while (!q.empty()) {
		pair<int, int> e = q.top();
		q.pop();
		int u = e.second;
		int v = e.first;
		if (used[u] == 1) continue; //u: dinh den
		// neu dinh den da nam trong cay khung thi bo qua
		cnt++;
		d += v; //duong di += trong so la e.first
		used[u] = 1; //dua dinh vao cay khung
		for (pair<int, int> x : ke[u]) //duyet cac dinh ke voi u, la dinh vua dua vo cay khung {
			int dinh = x.first, trongso = x.second;
			// x.first,x.second là do ke[x].push_back({y,w}), trong do dinh = y, trongso = w
			// for(pair x : ke[u]) la duyet cac dinh ke voi u la e.second day
			// tai push({w,t}) trong do w la trong so, t la dinh
			if (!(used[dinh])) q.push({ trongso,dinh });
		}
	}
	if (cnt < n) cout << "IMPOSSIBLE"; //nho hon nghia la khong the
	//dua het tat ca n dinh vao trong cay khung -> knong lien thong
	else cout << d;
}
int main()
{
	nhap();
	Prim(1);
}

