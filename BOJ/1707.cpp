#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int k, v, e;
vector<int> edges[20005];
int graph[20005];
bool visited[20005];

bool dfs(int cur) {
	if (visited[cur]) return true;
	if (graph[cur] == 0) graph[cur] = 1;
	visited[cur] = true;

	for (int i = 0; i < edges[cur].size(); ++i) {
		int next = edges[cur][i];

		if (graph[next] == graph[cur]) return false;

		if (graph[cur] == 1) graph[next] = 2;
		else graph[next] = 1;

		if(!dfs(edges[cur][i])) return false;
	}

	return true;
}

bool answer() {
	for (int i = 1; i <= v; ++i) {
		if (graph[i] == 0) {
			if (!dfs(i)) return false;
		}
	}

	return true;
}

void clear() {
	for (int i = 0; i <= v; ++i) {
		edges[i].clear();
	}
}

int main() {

	cin >> k;

	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &v, &e);

		clear();
		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));

		for (int j = 0; j < e; ++j) {
			int a, b;
			scanf("%d %d", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		if (answer()) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
