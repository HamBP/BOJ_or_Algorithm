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

#define INF 1987654321

int dr[] = { -1, 1, 0, 0, 0, 0 };
int dc[] = { 0, 0, -1, 1, 0, 0 };
int dh[] = { 0, 0, 0, 0, -1, 1 };

/* *** */

int row, column, height;
int grid[105][105][105];

class Point {
public:
	int h;
	int r;
	int c;

	Point(int h, int r, int c) {
		this->h = h;
		this->r = r;
		this->c = c;
	}
};

// 안 익은 토마토가 있는지 확인
bool isComplete() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < column; ++k) {
				if (grid[i][j][k] == 0) return false;
			}
		}
	}

	return true;
}

void initState(queue<Point>& q) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < column; ++k) {
				if (grid[i][j][k] == 1) q.push(Point(i, j, k));
			}
		}
	}
}

bool validate(int h, int r, int c) {
	if (h < 0 || r < 0 || c < 0) return false;
	if (h >= height || r >= row || c >= column) return false;
	if (grid[h][r][c] != 0) return false;

	return true;
}

int getDays() {
	int result = 0;

	queue<Point> q;
	initState(q);

	while (true) {
		int len = q.size();
		for (int j = 0; j < len; ++j) {
			Point p = q.front();
			q.pop();
			int r = p.r;
			int h = p.h;
			int c = p.c;
			for (int i = 0; i < 6; ++i) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				int nh = h + dh[i];

				if (validate(nh, nr, nc)) {
					grid[nh][nr][nc] = 1;
					q.push(Point(nh, nr, nc));
				}
			}
		}

		if (q.empty()) break;
		++result;
	}

	if (!isComplete()) return -1;
	else return result;
}

int main() {
	cin >> column >> row >> height;

	memset(grid, -1, sizeof(grid));
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < column; ++k) {
				scanf("%d", &grid[i][j][k]);
			}
		}
	}

	int result = getDays();
	cout << result << endl;

	return 0;
}
