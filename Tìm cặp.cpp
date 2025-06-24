
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
vector<int> ke[100005];
int d[100005];
int visited[100005];
void nhap() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void dfs(int u, int parent) { //int u,int parent : Parent la cha cua u
	for (int v : ke[u]) { //duyet ds ke
		if (v != parent) { //tranh di nguoc lai cha
			d[v] = d[u] + 1;
			//  1 (0)
			//	|
			//	|
			//	|--> 2 (1) //v != parent de tranh di nguoc lai
			//		 |            vd : 1 la cha cua 2 nen phai v != parent de 2 tranh di nguoc len 1
			//		 |
			//		  --> 3 (2)
			dfs(v, u); //goi dfs voi u la cha cua v
		}
	}
}

int main()
{
	nhap();
	d[1] = 0;
	dfs(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += d[i] + 1;
		//  1 (0)
		//	|
		//	|
		//	|--> 2 (1) 
		//		 |           
		//		 |
		//		  --> 3 (2)
		// ans += 0 + 1 + 2,...
	}
	cout << ans;
}

