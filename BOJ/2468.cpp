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
#include <numeric>
#include <map>

using namespace std;

typedef long long ll;

#define INF 2100000000

int dr[] = { -1, 1, 0, 0, 0, 0 };
int dc[] = { 0, 0, -1, 1, 0, 0 };
int dh[] = { 0, 0, 0, 0, -1, 1 };

/* *** */

int n;
int grid[105][105];
bool visited[105][105];

bool dfs(int row, int column, int height) {
	if (grid[row][column] <= height || visited[row][column]) return false;
	visited[row][column] = true;

	for (int i = 0; i < 4; ++i) {
		int nr = row + dr[i];
		int nc = column + dc[i];

		if (nr >= n || nr < 0 || nc >= n || nc < 0) continue;

		dfs(nr, nc, height);
	}

	return true;
}

int answer() {
	int res = 0;

	for (int height = 0; height < 101; ++height) {
		int cnt = 0;

		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dfs(i, j, height)) ++cnt;
			}
		}

		res = max(res, cnt);
	}

	return res;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	cout << answer() << endl;

	return 0;
}
