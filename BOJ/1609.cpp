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

using namespace std;

typedef long long ll;

#define INF 1987654321

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

/* *** */

int n, m;
int grid[5005][5005];

void put(int r, int c, int k) {
    ++grid[r][c];
    ++grid[r + k + 1][c + 1];
    ++grid[r + k][c + k + 1];
    --grid[r][c + 1];
    --grid[r + k][c];
    --grid[r + k + 1][c + k + 1];
}

void right() {
    int len = n + 5;
    for (int i = 0; i < len; ++i) {
        for (int j = 1; j < len; ++j) {
            grid[i][j] += grid[i][j - 1];
        }
    }
}

void down() {
    int len = n + 5;
    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            grid[i][j] += grid[i - 1][j];
        }
    }
}

void diagnal() {
    int len = n + 5;
    for (int i = 1; i < len; ++i) {
        for (int j = 1; j < len; ++j) {
            grid[i][j] += grid[i - 1][j - 1];
        }
    }
}

int swip() {
    right();
    down();
    diagnal();

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] > 0) ++cnt;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        put(a - 1, b - 1, c + 1);
    }

    cout << swip() << endl;

    return 0;
}
