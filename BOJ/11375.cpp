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
vector<int> v[1005];
bool visited[1005];
int matched[1005];

bool dfs(int cur) {
    if (visited[cur]) return 0;
    visited[cur] = true;

    for (int i = 0; i < v[cur].size(); ++i) {
        int task = v[cur][i];

        if (matched[task] == 0 || dfs(matched[task])) {
            matched[task] = cur;
            return true;
        }
    }

    return false;
}

int bmatch() {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) ++ret;
    }
    return ret;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; ++j) {
            int input;
            scanf("%d", &input);
            v[i].push_back(input);
        }
    }

    cout << bmatch() << endl;

    return 0;
}
