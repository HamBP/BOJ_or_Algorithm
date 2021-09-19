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

int w, h, m;
int grid[2510][2510];
int gridR[2510][2510];

void put(int r, int c, int k) {
    ++r;
    ++grid[r - k][c];
    ++grid[r - k - 1][c];
    ++grid[r + k][c];
    ++grid[r + k + 1][c];
    --grid[r][c - k];
    --grid[r][c - k - 1];
    --grid[r][c + k];
    --grid[r][c + k + 1];
}

void putR(int r1, int c1, int r2, int c2) {
    ++gridR[r1][c1];
    ++gridR[r2 + 1][c2 + 1];
    --gridR[r2 + 1][c1];
    --gridR[r1][c2 + 1];
}

void right() {
    int row = h + 5;
    int column = w + 5;
    for (int i = 0; i < row; ++i) {
        for (int j = 1; j < column; ++j) {
            gridR[i][j] += gridR[i][j - 1];
        }
    }
}

void down() {
    int row = h + 5;
    int column = w + 5;
    for (int i = 1; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            gridR[i][j] += gridR[i - 1][j];
        }
    }
}

void leftDown() {
    int row = h + 5;
    int column = w + 5;
    for (int i = 1; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            grid[i][j] += grid[i - 1][j + 1];
        }
    }
}

void rightDown() {
    int row = h + 5;
    int column = w + 5;
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < column; ++j) {
            grid[i][j] += grid[i - 1][j - 1];
        }
    }
}

void swip() {
    right();
    down();
    leftDown();
    rightDown();
}

int main() {
    cin >> w >> h >> m;
    for (int i = 0; i < m; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            putR(b, a, d, c);
        }
        else {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            put(b, a, c);
        }
    }

    swip();

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if ((grid[i][j] + gridR[i][j]) % 2 == 0) printf(".");
            else printf("#");
        }
        printf("\n");
    }

    return 0;
}
