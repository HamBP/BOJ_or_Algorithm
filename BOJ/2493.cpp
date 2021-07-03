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
int arr[500005];
stack<pair<int, int>> s;

int main() {
    cin >> n;

    s.push(make_pair(0, 100000001));
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);

        if (a < s.top().second) {
            arr[i] = s.top().first;
            s.push(make_pair(i + 1, a));
        }
        else {
            while (a > s.top().second) {
                s.pop();
            }
            if (a == s.top().second) {
                arr[i] = s.top().first;
                s.pop();
            }
            else 
                arr[i] = s.top().first;

            s.push(make_pair(i + 1, a));
        }
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
