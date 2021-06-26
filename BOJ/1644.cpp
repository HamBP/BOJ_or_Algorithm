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

int n;
ll arr[300000];

bool is_prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);

    // 소수 삽입
    int idx = 1;
    for (int i = 2; i <= n; ++i) {
        if (is_prime(i))
            arr[idx++] = i;
    }

    // 부분합
    for (int i = 1; i < 300000; ++i) {
        arr[i] += arr[i - 1];
    }

    int left = 0;
    int right = 1;
    int cnt = 0;

    while (right < 300000) {
        int sum = arr[right] - arr[left];
        
        if (sum == n)
            ++cnt;
        
        if (sum < n)
            ++right;
        else
            ++left;
    }

    cout << cnt << endl;

    return 0;
}
