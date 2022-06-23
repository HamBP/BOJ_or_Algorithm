#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING

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

int length;
bool visited[305][305];
int curRow, curColumn;
int targetRow, targetColumn;
int diffR[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int diffC[] = {1, 2, 2, 1, -1, -2, -2, -1};

int answer() {
	queue<pair<int, int>> q;

	memset(visited, 0, sizeof(visited));
	visited[curRow][curColumn] = true;

	int moveCount = 0;
	q.push(make_pair(curRow, curColumn));

	while (!q.empty()) {
		int len = q.size();

		for (int i = 0; i < len; ++i) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			if (r == targetRow && c == targetColumn) {
				return moveCount;
			}

			for (int j = 0; j < 8; ++j) {
				int nr = r + diffR[j];
				int nc = c + diffC[j];

				if (nr < 0 || nr >= length || nc < 0 || nc >= length || visited[nr][nc]) continue;

				q.push(make_pair(nr, nc));
				visited[nr][nc] = true;
			}
		}

		++moveCount;
	}

	return -1;
}

int main() {
	int testCases;

	cin >> testCases;

	for (int i = 0; i < testCases; ++i) {
		scanf("%d", &length);
		scanf("%d %d", &curRow, &curColumn);
		scanf("%d %d", &targetRow, &targetColumn);

		printf("%d\n", answer());
	}

	return 0;
}
