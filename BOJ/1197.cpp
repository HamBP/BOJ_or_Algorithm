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

int n, e;
vector<pair<int, pair<int, int>>> v;
int cnt;
int parent[10005];

int find(int cur) {
    return parent[cur] == 0 ? cur : find(parent[cur]);
}

int go() {
    int total = 0;

    for (int i = 0; i < e; ++i) {
        int a = find(v[i].second.first);
        int b = find(v[i].second.second);

        if (a == b)
            continue;

        if(a > b) swap(a, b);
        parent[b] = a;

        total += v[i].first;
    }

    return total;
}

int main() {
    cin >> n >> e;

    for (int i = 0; i < e; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(v.begin(), v.end());
    cout << go() << endl;

    return 0;
}
