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

int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};


/* --- */

int n;
int grid[130][130];
int cnt[2];

bool canDivide(int startRow, int startColumn, int endRow, int endColumn) {
    int color = grid[startRow][startColumn];

    for (int i = startRow; i < endRow; ++i) {
        for (int j = startColumn; j < endColumn; ++j) {
            if (grid[i][j] != color) return true;
        }
    }

    return false;
}

void dfs(int startRow, int startColumn, int endRow, int endColumn) {
    if (startRow + 1 == endRow) {
        ++cnt[grid[startRow][startColumn]];
        return;
    }

    int color = grid[startRow][startColumn];

    if (canDivide(startRow, startColumn, endRow, endColumn)) {
        int midRow = (startRow + endRow) / 2;
        int midColumn = (startColumn + endColumn) / 2;

        dfs(startRow, startColumn, midRow, midColumn);
        dfs(startRow, midColumn, midRow, endColumn);
        dfs(midRow, startColumn, endRow, midColumn);
        dfs(midRow, midColumn, endRow, endColumn);
    }
    else {
        ++cnt[grid[startRow][startColumn]];
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    dfs(0, 0, n, n);
    cout << cnt[0] << endl;
    cout << cnt[1] << endl;

    return 0;
}
