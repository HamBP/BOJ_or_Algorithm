#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

#define INF 1987654321

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

/* *** */

int n, m, k;
ll arr[1000005];
vector<ll> st;
vector<ll> lazy;

void update_lazy(int node, ll left, ll right) {
    st[node] += (right - left) * lazy[node];
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    lazy[node] = 0;
}

ll cal(ll left, ll right, int node, ll nodeLeft, ll nodeRight) {
    // 범위 밖
    if (nodeLeft >= right || nodeRight <= left) 
        return 0;

    // 범위 내
    if (nodeLeft >= left && nodeRight <= right) {
        return st[node] + lazy[node] * (nodeRight - nodeLeft);
    }

    // 쪼개질 때
    update_lazy(node, nodeLeft, nodeRight);
    ll mid = (nodeLeft + nodeRight) / 2;
    return cal(left, right, node * 2, nodeLeft, mid) + cal(left, right, node * 2 + 1, mid, nodeRight);
}

void update(ll left, ll right, int node, ll nodeLeft, ll nodeRight, ll value) {
    // 범위 밖
    if (nodeLeft >= right || nodeRight <= left || nodeLeft >= n) {
        return;
    }

    // 안 쪼개지는 경우
    if (nodeLeft >= left && nodeRight <= right) {
        lazy[node] += value;
        return;
    }

    // 쪼개야 하는 경우
    ll mid = (nodeLeft + nodeRight) / 2;
    update_lazy(node, nodeLeft, nodeRight);
    update(left, right, node * 2, nodeLeft, mid, value);
    update(left, right, node * 2 + 1, mid, nodeRight, value);
    st[node] = cal(nodeLeft, mid, node * 2, nodeLeft, mid) + cal(mid, nodeRight, node * 2 + 1, mid, nodeRight);
}

ll dc(ll left, ll right, int node) {
    if (left >= n)
        return st[node] = 0;
    
    if (left + 1 >= right)
        return st[node] = arr[left];
    else {
        ll mid = (left + right) / 2;
        return st[node] = dc(left, mid, 2 * node) + dc(mid, right, node * 2 + 1);
    }
}

void initSeg() {
    int cnt = 1;
    while (cnt < n)
        cnt *= 2;

    st = vector<ll>(cnt * 2);
    lazy = vector<ll>(cnt * 2);

    dc(0, cnt, 1);
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
    }
    initSeg();

    int len = m + k;
    for (int i = 0; i < len; ++i) {
        ll op;
        scanf("%lld", &op);
        if (op == 1) {
            ll a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c);
            update(a - 1, b, 1, 0, st.size() / 2, c);
        }
        else {
            ll a, b;
            scanf("%lld %lld", &a, &b);
            printf("%lld\n", cal(a - 1, b, 1, 0, st.size() / 2));
        }
    }

    return 0;
}
