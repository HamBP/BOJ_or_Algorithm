#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };


/* --- */

int row, column;
int grid[1005][1005];
bool visited[1005][1005][2];

int main() {
    cin >> row >> column;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            scanf("%1d", &grid[i][j]);
        }
    }

    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), true));
    int cnt = 0;
    bool breakFlag = false;
    while (true) {
        ++cnt;
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            pair<int, int> p = q.front().first;
            int des = q.front().second;
            q.pop();

            if (visited[p.first][p.second][des]) continue;
            visited[p.first][p.second][des] = true;

            if (p.first == row - 1 && p.second == column - 1) {
                breakFlag = true;
                break;
            }

            for (int j = 0; j < 4; ++j) {
                int r = p.first + dy[j];
                int c = p.second + dx[j];
                if (r < 0 || r >= row || c < 0 || c >= column) continue;
                if (grid[r][c] == 1) {
                    if(des == 0) continue;
                    else q.push(make_pair(make_pair(r, c), 0));
                }
                else q.push(make_pair(make_pair(r, c), des));
            }
        }
        if (breakFlag) break;
        if (cnt > row * column) {
            cnt = -1;
            break;
        }
    }

    cout << cnt;

    return 0;
}
