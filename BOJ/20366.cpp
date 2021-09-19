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
vector<int> arr;

int main() {
    cin >> n;

    arr = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());

    int dist = 2000000000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int left = i + 1;
            int right = j - 1;
            while (left < right) {
                int temp = arr[i] + arr[j] - arr[left] - arr[right];
                dist = min(dist, abs(temp));
                if (temp > 0) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
    }

    cout << dist << endl;

    return 0;
}
