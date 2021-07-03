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

using namespace std;

typedef long long ll;

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

const int INF = 987654321;

/* --- */

ll a, b;
ll cache[100];

ll dp(int n) {
    if (n == 0 || n == 1) return n;

    ll& ret = cache[n];
    if (ret != -1) return ret;

    return ret = 2 * dp(n - 1) + (1LL << (n - 1));
}

ll oneInBinary(ll x) {
    ll ans = x & 1;
    for (int i = 54; i > 0; i--) {
        if (x & (1LL << i)) {
            ans += dp(i) + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }
    return ans;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> a >> b;

    cout << oneInBinary(b) - oneInBinary(a - 1) << endl;

    return 0;
}
