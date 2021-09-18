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

int n;
int arr[4][4005];
vector<ll> a;
vector<ll> b;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &arr[j][i]);
        }
    }
    // a
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a.push_back(arr[0][i] + arr[1][j]);
        }
    }
    // b
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b.push_back(arr[2][i] + arr[3][j]);
        }
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int left = 0;
    int right = 0;
    ll cnt = 0;
    while (left < a.size() && right < b.size()) {
        if (a[left] + b[right] < 0) ++left;
        else if (a[left] + b[right] > 0) ++right;
        else {
            ll l, r;
            for (l = 0; left + l < a.size(); ++l) {
                if (a[left + l] != a[left]) break;
            }
            for (r = 0; right + r < b.size(); ++r) {
                if (b[right + r] != b[right]) break;
            }

            left += l;
            right += r;
            cnt += l * r;
        }
    }

    cout << cnt << endl;

    return 0;
}
