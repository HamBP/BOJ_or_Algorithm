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

int nodes, edges, X;
vector<pair<int, int>> costs[1005];

int dijkstra(int from, int dest) {
    vector<int> ret(1005, 10000000);
    ret[from] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, from));
    while (!pq.empty()) {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (cost > ret[node])
            continue;

        for (int i = 0; i < costs[node].size(); ++i) {
            int nextNode = costs[node][i].first;
            int nextCost = ret[node] + costs[node][i].second;
            if (nextCost < ret[nextNode]) {
                ret[nextNode] = nextCost;
                pq.push(make_pair(-nextCost, nextNode));
            }
        }
    }

    return ret[dest];
}

int main() {
    cin >> nodes >> edges >> X;
    for (int i = 0; i < edges; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        costs[a].push_back(make_pair(b, c));
    }

    int maxCost = 0;
    for (int i = 1; i <= nodes; ++i) {
        int dist = dijkstra(i, X) + dijkstra(X, i);
        maxCost = max(dist, maxCost);
    }
    cout << maxCost << endl;

    return 0;
}
