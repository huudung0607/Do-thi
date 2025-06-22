//Cho cây có n đỉnh và m cạnh với số đỉnh là số chẵn, gốc của cây là đỉnh 1. Bây giờ bạn có nhiệm vụ xóa bỏ 1 số cạnh trên cây sao cho cây của bạn trở thành các cây con có số đỉnh là số chẵn, vậy số lượng cạnh tối đa bạn có thể xóa bỏ là bao nhiêu ?
//
//Trong ví dụ đồ thị dưới đây, nếu bạn xóa cạnh 1 - 6 và 1 - 3 thì cây ban đầu sẽ được tách thành 3 cây con mà mỗi cây con đều có số lượng đỉnh là số chẵn.Và bạn chỉ có thể xóa tối đa 2 cạnh này.
//
//
//
//Đầu vào
//Dòng đầu tiên của mỗi bộ test là là n, m tương ứng với số đỉnh, số cạnh của cây
//
//m dòng tiếp theo mỗi dòng là một cạnh của cây, dữ liệu đảm bảo cạnh chỉ nối giữa 2 đỉnh khác nhau.
//
//Giới hạn
//1 <= n <= 100
//Đầu ra
//In ra số cạnh tối đa có thể xóa
//Ví dụ :
//Input 01
//Copy
//10 9
//2 1
//3 1
//4 3
//5 2
//6 1
//7 2
//8 6
//9 8
//10 8
//Output 01
//Copy
//2

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
vector<int> ke[10005];
int visited[10005];
int cnt = 0;
void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
int dfs(int u) {
	visited[u] = 1;
	int sz = 1;
	for (auto v : ke[u]) {
		if (!visited[v]) {
			int csz = dfs(v);
			if(csz % 2 == 0) {
				cnt++;
			} else {
				sz += csz;
			}
		}	
	}
	return sz;
}
int main() {
	nhap();
	dfs(1);
	cout << cnt;
}
