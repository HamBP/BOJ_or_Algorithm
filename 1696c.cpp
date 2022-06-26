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

int tc;
int n, m, k;
vector<pair<int, int>> a, b;

bool answer() {
	int l = 0, r = 0;

	while (l < n || r < k) {
		if (l == n || r == k) return false;
		if (a[l].first != b[r].first) return false;

		int sub = min(a[l].second, b[r].second);
		a[l].second -= sub;
		b[r].second -= sub;

		if (a[l].second == 0) ++l;
		if (b[r].second == 0) ++r;
	}

	return true;
}

pair<int, int> getPair(int number) {
	int cnt = 1;

	while (number % m == 0) {
		cnt *= m;
		number /= m;
	}

	return make_pair(number, cnt);
}

int main() {
	cin >> tc;

	for (int i = 0; i < tc; ++i) {
		scanf("%d %d", &n, &m);

		for (int j = 0; j < n; ++j) {
			int input;
			scanf("%d", &input);
			a.push_back(getPair(input));
		}

		scanf("%d", &k);

		for (int j = 0; j < k; ++j) {
			int input;
			scanf("%d", &input);
			b.push_back(getPair(input));
		}

		if (answer()) printf("Yes\n");
		else printf("No\n");
		a.clear();
		b.clear();
	}

	return 0;
}
