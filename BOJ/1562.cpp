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

int n;
int cache[101][10][2][2];
const int DIV = 1000000000;

int dp(int cur, int curNumber, int zero, int nine) {
    if (curNumber == 0)
        zero = 1;
    if (curNumber == 9)
        nine = 1;

    if (cur == n) {
        if (zero && nine)
            return 1;
        else
            return 0;
    }

    int& ret = cache[cur][curNumber][zero][nine];
    if (ret != -1)
        return ret;

    ret = 0;
    if (cur == 0) {
        for (int i = 1; i < 10; ++i) {
            ret += dp(1, i, 0, 0);
            ret %= DIV;
        }
        return ret;
    }
    
    if (curNumber > 0) {
        ret += dp(cur + 1, curNumber - 1, zero, nine);
        ret %= DIV;
    }

    if (curNumber < 9) {
        ret += dp(cur + 1, curNumber + 1, zero, nine);
        ret %= DIV;
    }

    return ret;
}

int main() {
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0, 0, 0);

    return 0;
}
