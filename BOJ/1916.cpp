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
#include <assert.h>

using namespace std;

typedef long long ll;

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

const int INF = 987654321;

/* --- */

int cities, start, dest, buses;
vector<pair<int, int>> costs[1005];
int result[1005];

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (cost > result[node])
            continue;

        for (int i = 0; i < costs[node].size(); ++i) {
            int nextNode = costs[node][i].first;
            int nextCost = result[node] + costs[node][i].second;
            if (nextCost < result[nextNode]) {
                result[nextNode] = nextCost;
                pq.push(make_pair(-nextCost, nextNode));
            }
        }
    }
}

int main() {
    cin >> cities;
    cin >> buses;
    for (int i = 0; i < buses; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        costs[a].push_back(make_pair(b, c));
    }
    cin >> start >> dest;

    memset(result, 63, sizeof(result));
    result[start] = 0;
    dijkstra();
    cout << result[dest] << endl;

    return 0;
}
