#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};


/* --- */

bool visited[200005];

int main() {
    int x, y;
    cin >> x >> y;
    
    queue<int> q;
    q.push(x);

    int time = 0;
    bool breakFlag = false;

    while (true) {
        int len = q.size();

        for (int i = 0; i < len; ++i) {
            int cur = q.front();
            q.pop();

            if (visited[cur]) continue;
            visited[cur] = true;

            int temp = cur;
            while (temp < 200000) {
                if (temp == y) {
                    breakFlag = true;
                    break;
                }
                q.push(temp);
                if (temp > 0) q.push(temp - 1);
                if (temp < y) q.push(temp + 1);
                if (temp == 0) break;

                temp *= 2;

            }
            if (breakFlag) break;
        }
        if (breakFlag) break;
        ++time;
    }

    cout << time;

    return 0;
}
