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

using namespace std;

#define INF 987654321

typedef long long ll;

/* *** */

vector<int> v;
int cache[100005][5][5];

int dp(int cur, int left, int right) {
    if (cur && left == right)
        return INF;

    if (cur == v.size())
        return 0;

    int& ret = cache[cur][left][right];
    if (ret != -1)
        return ret;

    ret = INF;

    if(left == v[cur])
        ret = min(ret, 1 + dp(cur + 1, v[cur], right));
    else if(left == 0)
        ret = min(ret, 2 + dp(cur + 1, v[cur], right));
    else if(abs(left - v[cur]) % 2)
        ret = min(ret, 3 + dp(cur + 1, v[cur], right));
    else
        ret = min(ret, 4 + dp(cur + 1, v[cur], right));

    if(right == v[cur])
        ret = min(ret, 1 + dp(cur + 1, left, v[cur]));
    else if(right == 0)
        ret = min(ret, 2 + dp(cur + 1, left, v[cur]));
    else if(abs(right - v[cur]) % 2)
        ret = min(ret, 3 + dp(cur + 1, left, v[cur]));
    else
        ret = min(ret, 4 + dp(cur + 1, left, v[cur]));

    return ret;
}

int main() {
    int input;
    do {
        scanf("%d", &input);
        v.push_back(input);
    } while (input);

    memset(cache, -1, sizeof(cache));
    v.pop_back();
    cout << dp(0, 0, 0) << endl;

    return 0;
}
