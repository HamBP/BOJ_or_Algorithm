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

int n, m, k;
ll arr[1100005];
vector<ll> segTree;

ll initSeg(int left, int right, int node) {
    if (left == right) {
        segTree[node] = arr[left];
        return segTree[node];
    }

    int mid = (left + right) / 2;
    segTree[node] = initSeg(left, mid, 2 * node) + initSeg(mid + 1, right, 2 * node + 1);
    return segTree[node];
}

ll updateSeg(int left, int right, int node, ll idx, ll newValue) {
    if (idx < left || idx > right) return segTree[node];
    
    if (left == right) {
        segTree[node] = newValue;
        return segTree[node];
    }

    int mid = (left + right) / 2;
    segTree[node] = updateSeg(left, mid, 2 * node, idx, newValue) + updateSeg(mid + 1, right, 2 * node + 1, idx, newValue);
    return segTree[node];
}

ll go(ll left, ll right, int node, ll nodeLeft, ll nodeRight) {
    // case 1
    if (nodeRight < left || nodeLeft > right) {
        return 0;
    }

    ll ret = 0;
    // case 3
    if (nodeLeft >= left && nodeRight <= right) {
        return segTree[node];
    }
    else {
        ll mid = (nodeLeft + nodeRight) / 2;
        return go(left, right, 2 * node, nodeLeft, mid) + go(left, right, 2 * node + 1, mid + 1, nodeRight);
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
    }

    int temp = 1;
    while (temp < n) {
        temp *= 2;
    }
    n = temp;
    segTree.resize(2 * n);
    initSeg(0, n-1, 1);

    int len = m + k;
    for (int i = 0; i < len; ++i) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            updateSeg(0, n - 1, 1, b - 1, c);
        }
        else {
            printf("%lld\n", go(b - 1, c - 1, 1, 0, n-1));
        }
    }

    return 0;
}
