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
int arr[100005];
pair<int, int> st[400005];

int getLength() {
    int result = 1;
    while (result < n) {
        result *= 2;
    }
    return result;
}

void initSeg(int node, int left, int right) {
    if (left + 1 == right) {
        if (left >= n) st[node] = make_pair(1000000000, 1);
        else st[node] = make_pair(arr[left], arr[left]);
        return;
    }

    int mid = (left + right) / 2;
    initSeg(node * 2, left, mid);
    initSeg(node * 2 + 1, mid, right);
    st[node] = make_pair(min(st[node * 2].first, st[node * 2 + 1].first), max(st[node * 2].second, st[node * 2 + 1].second));
}

pair<int, int> getValue(int node, int nodeLeft, int nodeRight, int left, int right) {
    if (nodeLeft >= right || nodeRight <= left) return make_pair(1000000000, 1);
    if (left <= nodeLeft && nodeRight <= right) return st[node];
    if (nodeLeft < right || nodeRight > left) {
        int mid = (nodeLeft + nodeRight) / 2;
        pair<int, int> obj1 = getValue(node * 2, nodeLeft, mid, left, right);
        pair<int, int> obj2 = getValue(node * 2 + 1, mid, nodeRight, left, right);
        return make_pair(
            min(obj1.first, obj2.first),
            max(obj1.second, obj2.second)
        );
    }
    assert(false);
    return make_pair(1000000000, 1);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int len = getLength();
    initSeg(1, 0, len);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        pair<int, int> result = getValue(1, 0, len, a - 1, b);
        printf("%d %d\n", result.first, result.second);
    }

    return 0;
}
