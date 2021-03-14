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

using namespace std;

typedef long long ll;

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

const int INF = 987654321;

/* --- */

int n;
vector<int> cache;
vector<pair<int, int>> arr(1000001);

int main() {
    cin >> n;
    cache.push_back(-1000000001);
    for (int i = 0; i < n; ++i) {
        int input;
        scanf("%d", &input);
        if (input > cache.back()) cache.push_back(input);
        auto low = lower_bound(cache.begin(), cache.end(), input);
        *low = input;
        int idx = low - cache.begin();
        arr[i].first = idx; arr[i].second = *low;
    }
    int len = cache.size() - 1;
    int cnt = len;

    printf("%d\n", len);

    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
        if (cnt == arr[i].first) {
            --cnt;
            s.push(arr[i].second);
        }
    }
    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    return 0;
}
