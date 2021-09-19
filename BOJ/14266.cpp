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
vector<pair<double, int>> v;

double getInclination(int x, int y) {
    return (double)y / (double)x;
}

bool comp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        double a = getInclination(x1, y1);
        double b = getInclination(x2, y2);
        v.push_back(make_pair(min(a, b), 1));
        v.push_back(make_pair(max(a, b), -1));
    }

    sort(v.begin(), v.end(), comp);

    int maxCnt = 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        cnt += v[i].second;
        maxCnt = max(cnt, maxCnt);
    }
    cout << maxCnt << endl;

    return 0;
}
