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
int arr[200005];

int parse() {
    int flag = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) ++flag;
    }
    if (flag > 1 && arr[0] < arr[n - 1]) ++flag;

    return flag < 3 ? flag : 3;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    cout << parse() << endl;

    return 0;
}
