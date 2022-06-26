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

int n;
int graph[25][25];
bool picked[50];

int getDiff() {
	int power1 = 0;
	int power2 = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (picked[i] && picked[j]) power1 += graph[i][j];
			if (!picked[i] && !picked[j]) power2 += graph[i][j];
		}
	}

	int res = abs(power1 - power2);
	return res;
}

int answer(int cur, int length) {
	if (cur == n, length == (n / 2)) return getDiff();
	if (cur >= n) return 1000000;

	int res = 1000000;

	picked[cur] = true;
	res = answer(cur + 1, length + 1);
	picked[cur] = false;

	res = min(res, answer(cur + 1, length));

	return res;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &graph[i][j]);
		}
	}

	cout << answer(0, 0) << endl;

	return 0;
}
