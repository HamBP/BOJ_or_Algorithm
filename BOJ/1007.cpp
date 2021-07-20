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

using namespace std;

#define INF 987654321

/* *** */

int tc, n;
vector<pair<int, int>> v;
vector<pair<int, int>> picked;
int arr[30];

double dfs(int cur, int total) {
    if (cur == n) {
        if (total != 0)
            return 1000000;

        long long x = 0;
        long long y = 0;

        for (int i = 0; i < n; ++i) {
            x += arr[i] * v[i].first;
            y += arr[i] * v[i].second;
        }
        x *= x;
        y *= y;

        return sqrt(x + y);
    }

    double ret = 1000000;

    arr[cur] = -1;
    ret = min(ret, dfs(cur + 1, total - 1));

    arr[cur] = 1;
    ret = min(ret, dfs(cur + 1, total + 1));

    return ret;
}

int main() {
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            int x, y;
            scanf("%d %d", &x, &y);
            v.push_back(make_pair(x, y));
        }
        printf("%.15lf \n", dfs(0, 0));
        v.clear();
    }

    return 0;
}
