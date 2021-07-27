#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

#define INF 987654321

typedef long long ll;

/* *** */

int n;
char grid[205][205];
int cnt;
vector<pair<int, int>> v;

void rotate(int r, int c) {
    ++cnt;
    v.push_back(make_pair(r+1, c+1));

    if (grid[r][c] == 'L') {
        grid[r][c] = 'U';
        grid[r][c + 1] = 'U';
        grid[r + 1][c] = 'D';
        grid[r + 1][c + 1] = 'D';
    }
    else {
        grid[r][c] = 'L';
        grid[r][c + 1] = 'R';
        grid[r + 1][c] = 'L';
        grid[r + 1][c + 1] = 'R';
    }
}

void dfs(int r, int c) {
    if (grid[r][c] == 'L') {
        if (grid[r + 1][c] == 'R') {
            dfs(r + 1, c - 1);
        }
        if (grid[r + 1][c + 1] == 'L') {
            dfs(r + 1, c + 1);
        }
        if (grid[r + 1][c] == 'U') {
            rotate(r + 1, c);
        }
        rotate(r, c);
    }
}

int main() {
    cin >> n;
    int len = 2 * n;

    for (int i = 0; i < len; ++i) {
        scanf("%s", grid[i]);
    }

    for (int i = 0; i < n; ++i) {
        dfs(i * 2, n - 1);
    }

    cout << cnt << endl;
    for (int i = 0; i < v.size(); ++i) {
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}
