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
    int cnt = 0;
    int time = 0;
    bool breakFlag = false;
    while (true) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            if (cur == y) {
                ++cnt;
                breakFlag = true;
            }
            else {
                if (cur > 0 && !visited[cur - 1]) q.push(cur - 1);
                if (cur < y && !visited[cur + 1]) q.push(cur + 1);
                if (cur < y && !visited[cur * 2]) q.push(cur * 2);
            }
        }
        if (breakFlag) break;
        ++time;
    }

    cout << time << endl;
    cout << cnt;

    return 0;
}
