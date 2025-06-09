
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

vector<int> ke[1005];
int n, m;

void nhap() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y); //them y vao danh sach ke cua x
		ke[y].push_back(x); //them x vao danh sach ke cua y
		//neu do thi co huong thi bo ke[y].push_back(x);
	}
}

int main()
{
	nhap();
	for (int i = 1; i <= n; i++) {
		cout << i << " : ";
		sort(ke[i].begin(), ke[i].end());
		for (auto x : ke[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}
Input 01
5 4
2 5
4 1
4 2
4 3
Output 01
1 : 4 
2 : 4 5 
3 : 4 
4 : 1 2 3 
5 : 2
