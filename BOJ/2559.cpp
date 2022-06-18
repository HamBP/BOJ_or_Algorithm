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

int n, k;
int temp[100005];

int solve() {
	int res = -INF;

	for (int i = 0; i + k <= n; ++i) {
		res = max(res, temp[i + k] - temp[i]);
	}

	return res;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int input;
		scanf("%d", &input);

		temp[i + 1] = input + temp[i];
	}

	cout << solve() << endl;

	return 0;
}
