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
int st[400005];

int getLength() {
    int result = 1;
    while (result < n) {
        result *= 2;
    }
    return result;
}

void initSeg(int node, int left, int right) {
    if (left + 1 == right) {
        if (left >= n) st[node] = 1000000000;
        else st[node] = arr[left];
        return;
    }

    int mid = (left + right) / 2;
    initSeg(node * 2, left, mid);
    initSeg(node * 2 + 1, mid, right);
    st[node] = min(st[node * 2], st[node * 2 + 1]);
}

int getValue(int node, int nodeLeft, int nodeRight, int left, int right) {
    if (nodeLeft >= right || nodeRight <= left) return 1000000000;
    if (left <= nodeLeft && nodeRight <= right) return st[node];
    if (nodeLeft < right || nodeRight > left) {
        int mid = (nodeLeft + nodeRight) / 2;
        return min(
            getValue(node * 2, nodeLeft, mid, left, right),
            getValue(node * 2 + 1, mid, nodeRight, left, right)
        );
    }
    assert(false);
    return -1;
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
        printf("%d\n", getValue(1, 0, len, a - 1, b));
    }

    return 0;
}
