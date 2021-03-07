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

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

const int INF = 987654321;

/* --- */

#define MAX 20005

int v, e;
int p;
vector<pair<int, int>> graph[MAX];
bool visited[20005];

vector<int> dijkstra() {
    vector<int> ret(v+1, INF);
    ret[p] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, p));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int curVertex = pq.top().second;
        pq.pop();

        if (ret[curVertex] < cost) continue;

        for (int i = 0; i < graph[curVertex].size(); ++i) {
            int nextVertex = graph[curVertex][i].first;
            int nextCost = ret[curVertex] + graph[curVertex][i].second;
            if (nextCost < ret[nextVertex]) {
                ret[nextVertex] = nextCost;
                pq.push(make_pair(-nextCost, nextVertex));
            }
        }
    }

    return ret;
}

int main() {
    cin >> v >> e;
    cin >> p;
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
    }

    vector<int> res = dijkstra();


    for (int i = 1; i <= v; ++i) {
        if (res[i] != INF) printf("%d\n", res[i]);
        else printf("INF\n");
    }

    return 0;
}
