#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define INF 987654321

/* *** */

int n;
int cache[3][1005];
const int DIV = 1000000009;

int dp(int row, int column) {
    int& ret = cache[row][column];
    if (ret != -1)
        return ret;
    ret = 0;

    ret += dp(0, column - 1);
    ret += dp(1, column - 1);
    ret %= DIV;
    ret += dp(2, column - 1);
    ret %= DIV;
    
    if (row == 0) {
        for (int i = 0; i < column - 1; ++i) {
            ret += dp(2, i);
            ret %= DIV;
        }
    }
    if (row == 2) {
        for (int i = 0; i < column - 1; ++i) {
            ret += dp(0, i);
            ret %= DIV;
        }
    }
    
    return ret;
}

int main() {
    cin >> n;
    
    memset(cache, -1, sizeof(cache));
    cache[0][0] = 1; cache[1][0] = 0; cache[2][0] = 0;

    cout << dp(2, n) << endl;

    return 0;
}
