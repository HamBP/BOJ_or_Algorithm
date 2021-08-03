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

using namespace std;

#define INF 987654321

typedef long long ll;

/* *** */

int k;
int grid[200][200];
int cnt = 1;
int x, y;

bool isEmpty(int r, int c, int len) {
    for (int i = r; i < r + len; ++i) {
        for (int j = c; j < c + len; ++j) {
            if (grid[i][j] < 20000)
                return false;
        }
    }
    return true;
}

void go(int r, int c, int len) {
    if (len == 2) {
        grid[r][c] = min(cnt, grid[r][c]);
        grid[r][c+1] = min(cnt, grid[r][c+1]);
        grid[r+1][c] = min(cnt, grid[r+1][c]);
        grid[r+1][c+1] = min(cnt, grid[r+1][c+1]);
        ++cnt;
        return;
    }

    int nextLen = len / 2;
    if (isEmpty(r, c, nextLen))
        grid[r + nextLen - 1][c + nextLen - 1] = cnt;
    if (isEmpty(r, c + nextLen, nextLen))
        grid[r + nextLen - 1][c + nextLen] = cnt;
    if (isEmpty(r + nextLen, c, nextLen))
        grid[r + nextLen][c + nextLen - 1] = cnt;
    if (isEmpty(r + nextLen, c + nextLen, nextLen))
        grid[r + nextLen][c + nextLen] = cnt;
    ++cnt;
    go(r, c, nextLen);
    go(r, c + nextLen, nextLen);
    go(r + nextLen, c, nextLen);
    go(r + nextLen, c + nextLen, nextLen);
}

int main() {
    cin >> k;
    cin >> x >> y;
    --x; --y;
    memset(grid, 1, sizeof(grid));
    grid[y][x] = -1;

    int len = pow(2, k);
    go(0, 0, len);

    for (int i = len-1; i >= 0; --i) {
        for (int j = 0; j < len; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
