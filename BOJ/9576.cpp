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

int tc;
int n, m;
vector<pair<int, int>> person;
bool visited[1005];

int go() {
	sort(person.begin(), person.end());

	int cnt = 0;
	for(int i = 0; i < person.size(); ++i) {
		for (int j = person[i].second; j <= person[i].first; ++j) {
			if (!visited[j]) {
				visited[j] = true;
				++cnt;
				break;
			}
		}
	}

	person.clear();
	memset(visited, 0, sizeof(visited));

	return cnt;;
}

int main() {
	cin >> tc;

	for (int i = 0; i < tc; ++i) {
		scanf("%d %d", &n, &m);
		for (int j = 0; j < m; ++j) {
			int a, b;
			scanf("%d %d", &a, &b);
			person.push_back(make_pair(b, a));
		}
		printf("%d\n", go());
	}

	return 0;
}
