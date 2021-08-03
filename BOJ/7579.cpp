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

int n, m;
int arr[105];
int cache[10005];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        int input;
        scanf("%d", &input);

        for (int j = 10000; j >= input; --j) {
            cache[j] = max(cache[j], cache[j - input] + arr[i]);
        }
    }

    for (int i = 0; i <= 10000; ++i) {
        if (cache[i] >= m) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
