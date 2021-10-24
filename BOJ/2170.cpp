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

int n;
vector<pair<int, int>> line;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        line.push_back(make_pair(a, -1));
        line.push_back(make_pair(b, 1));
    }

    sort(line.begin(), line.end());
    int cnt = 1;
    int pre = line[0].first;
    int total = 0;
    for (int i = 1; i < line.size(); ++i) {
        int length = line[i].first - pre;
        pre = line[i].first;
        if (cnt > 0) {
            total += length;
        }
        cnt -= line[i].second;
    }
    cout << total << endl;

    return 0;
}
