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
bool graph[1005][1005];
vector<int> amatch, bmatch;
vector<bool> visited;

bool dfs(int cur) {
    if (visited[cur]) return false;
    visited[cur] = true;

    for (int i = 0; i < m; ++i) {
        // 선호하지 않는 축사인 경우
        if (!graph[cur][i]) continue;

        if (bmatch[i] == -1 || dfs(bmatch[i])) {
            bmatch[i] = cur;
            amatch[cur] = i;
            return true;
        }
    }

    return false;
}

int match() {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        visited = vector<bool>(n, false);
        if(dfs(i)) ++cnt;
    }

    return cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int cnt;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; ++j) {
            int input;
            scanf("%d", &input);
            graph[i][--input] = true;
        }
    }

    amatch = vector<int>(n, -1);
    bmatch = vector<int>(m, -1);
    cout << match() << endl;

    return 0;
}
