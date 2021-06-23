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

int rgb[3][3];
int n;

int main() {
    cin >> n;

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    rgb[0][0] = a;
    rgb[1][1] = b;
    rgb[2][2] = c;
    rgb[0][1] = rgb[0][2] = rgb[1][0] = rgb[1][2] = rgb[2][0] = rgb[2][1] = 1000;

    for (int i = 1; i < n - 1; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int aa, ab, ac, ba, bb, bc, ca, cb, cc;

        aa = a + min(rgb[0][1], rgb[0][2]);
        ab = b + min(rgb[0][0], rgb[0][2]);
        ac = c + min(rgb[0][0], rgb[0][1]);

        ba = a + min(rgb[1][1], rgb[1][2]);
        bb = b + min(rgb[1][0], rgb[1][2]);
        bc = c + min(rgb[1][0], rgb[1][1]);

        ca = a + min(rgb[2][1], rgb[2][2]);
        cb = b + min(rgb[2][0], rgb[2][2]);
        cc = c + min(rgb[2][0], rgb[2][1]);

        rgb[0][0] = aa;
        rgb[0][1] = ab;
        rgb[0][2] = ac;

        rgb[1][0] = ba;
        rgb[1][1] = bb;
        rgb[1][2] = bc;

        rgb[2][0] = ca;
        rgb[2][1] = cb;
        rgb[2][2] = cc;
    }

    scanf("%d %d %d", &a, &b, &c);
    a += min({ rgb[1][1], rgb[1][2], rgb[2][1], rgb[2][2] });
    b += min({ rgb[0][0], rgb[0][2], rgb[2][0], rgb[2][2] });
    c += min({ rgb[0][0], rgb[0][1], rgb[1][0], rgb[1][1] });

    cout << min({a, b, c});

    return 0;
}
