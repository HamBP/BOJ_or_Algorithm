#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING

#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <set>
#include <cassert>

using namespace std;

typedef long long ll;

#define INF 1987654321

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

/* *** */

int n, m;
int grid[1005][1005];
int part[1005][1005];
int cnt;

int dfs1(int r, int c) {
    if (part[r][c] || grid[r][c] == -1)
        return 0;

    part[r][c] = cnt;
    int ret = 1;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dy[i];
        int nc = c + dx[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            continue;

        ret += dfs1(nr, nc);
    }

    return ret;
}

void dfs2(int r, int c, int num, int p) {
    if (part[r][c] != p || grid[r][c])
        return;

    grid[r][c] = num;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dy[i];
        int nc = c + dx[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            continue;

        dfs2(nr, nc, num, p);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d", &grid[i][j]);
            grid[i][j] = -grid[i][j];
        }
    }

    // 나누기, 채우기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 0 && part[i][j] == 0) {
                ++cnt;
                int num = dfs1(i, j);
                dfs2(i, j, num, part[i][j]);
            }
        }
    }

    // 계산하기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int output = 0;
            if (grid[i][j] == -1) {
                set<int> s;
                for (int k = 0; k < 4; ++k) {
                    int r = i + dy[k];
                    int c = j + dx[k];
                    if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == -1)
                        continue;
                    int size = s.size();
                    s.insert(part[r][c]);
                    if (size == s.size())
                        continue;
                    output += grid[r][c];
                }
                ++output;
            }

            output %= 10;
            printf("%d", output);
        }
        cout << endl;
    }

    return 0;
}