#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <functional>

using namespace std;

typedef long long ll;

int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};


/* --- */

int arr[1005];
int n;

int asc(int start, int end) {
    vector<int> v;
    v.push_back(0);
    for (int i = start; i < end; ++i) {
        if (arr[i] >= arr[end]) continue;

        if (arr[i] > v.back()) v.push_back(arr[i]);
        else *lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
    }

    return v.size() - 1;
}

int desc(int start, int end) {
    vector<int> v;
    v.push_back(1001);
    for (int i = start; i < end; ++i) {
        if (arr[i] >= arr[start - 1]) continue;

        if (arr[i] < v.back()) v.push_back(arr[i]);
        else *(--upper_bound(v.rbegin(), v.rend(), arr[i])) = arr[i];
    }

    return v.size() - 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int maxV = 0;
    for (int i = 0; i < n; ++i) {
        maxV = max(maxV, 1 + asc(0, i) + desc(i + 1, n));
    }
    cout << maxV;

    return 0;
}
