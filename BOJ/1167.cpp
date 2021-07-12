#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <stack>
#include <math.h>
#include <assert.h>

using namespace std;

typedef long long ll;

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

const int INF = 987654321;

/* --- */

int v;
vector<pair<int, int>> tr[100001];
int visited[100001];

int dfs(int p, int d) {
    visited[p] = d;

    int maxDepth = 0;
    for (int i = 0; i < tr[p].size(); ++i) {
        if (visited[tr[p][i].first])
            continue;

        maxDepth = max(dfs(tr[p][i].first, d + tr[p][i].second), maxDepth);
    }
    return max(d, maxDepth);
}

int main() {
    // input
    cin >> v;
    for (int i = 0; i < v; ++i) {
        int start;
        scanf("%d", &start);
        while (true) {
            int e, cost;
            scanf("%d", &e);
            if (e == -1) break;
            scanf("%d", &cost);
            tr[start].push_back(make_pair(e, cost));
        }
    }

    // find max depth
    dfs(1, 1);
    int maxE = 2;
    for (int i = 3; i <= v; ++i) {
        if (visited[i] > visited[maxE])
            maxE = i;
    }

    // result
    memset(visited, 0, sizeof(visited));
    cout << dfs(maxE, 1) - 1 << endl;

    return 0;
}
