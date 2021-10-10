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

int n, q;
int arr[200005];
ll st[400020];

ll init(int node, int left, int right) {
    if (left + 1 == right) return st[node] = arr[left];

    int mid = (left + right) / 2;
    return st[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid, right);
}

ll getValue(int node, int left, int right, int nodeLeft, int nodeRight) {
    if (left >= nodeRight || right <= nodeLeft) return 0;
    if (left <= nodeLeft && right >= nodeRight) return st[node];
    else {
        int mid = (nodeLeft + nodeRight) / 2;
        return getValue(node * 2, left, right, nodeLeft, mid) + getValue(node * 2 + 1, left, right, mid, nodeRight);
    }
}

ll setST(int node, int left, int right, int idx, int value) {
    if(idx < left || idx >= right) return st[node];
    if (left + 1 == right) return st[node] = value;

    int mid = (left + right) / 2;
    return st[node] = setST(node * 2, left, mid, idx, value) + setST(node * 2 + 1, mid, right, idx, value);
}

int getLen() {
    int res = 1;
    while (res < n) res *= 2;
    return res;
}

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int len = getLen();
    init(1, 0, len);

    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        printf("%lld\n", getValue(1, a - 1, b, 0, len));
        setST(1, 0, len, c - 1, d);
    }

    return 0;
}
