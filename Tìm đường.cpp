
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
#include <cstring>
using namespace std;

int dx[4] = { -1, 1, 0, 0 }; 
int dy[4] = { 0, 0, -1, 1 };

int n, m;
char S[505][505];
bool visited[505][505][4][3]; 

struct State {
    int x, y, dir, turns;
};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && S[x][y] != '*';
}

bool bfs(int start_x, int start_y, int target_x, int target_y) {
    queue<State> q;
    memset(visited, false, sizeof(visited));
    for (int dir = 0; dir < 4; dir++) {
        q.push({ start_x, start_y, dir, 0 });
        visited[start_x][start_y][dir][0] = true;
    }
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y, dir = cur.dir, turns = cur.turns;
        if (S[x][y] == 'T' && turns <= 2) {
            return true;
        }
        for (int new_dir = 0; new_dir < 4; new_dir++) {
            int new_x = x + dx[new_dir];
            int new_y = y + dy[new_dir];
            int new_turns = turns + (dir != new_dir);
            if (new_turns <= 2 && isValid(new_x, new_y) && !visited[new_x][new_y][new_dir][new_turns]) {
                visited[new_x][new_y][new_dir][new_turns] = true;
                q.push({ new_x, new_y, new_dir, new_turns });
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    int start_x, start_y, target_x, target_y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> S[i][j];
            if (S[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
            if (S[i][j] == 'T') {
                target_x = i;
                target_y = j;
            }
        }
    }
    if (bfs(start_x, start_y, target_x, target_y)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
