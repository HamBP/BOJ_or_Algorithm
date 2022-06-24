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

int n; // 3 ~ 10000
int req[100005]; // 1 ~ 100000
int budget; // 10억 이하

int getTotal(int top) {

	int res = 0;

	for (int i = 0; i < n; ++i) {
		res += min(req[i], top);
	}

	return res;
}

int getMax() {

	int res = 0;

	for (int i = 0; i < n; ++i) {
		res = max(res, req[i]);
	}

	return res;
}

int answer() {

	int left = 0;
	int right = 100001;

	while (left + 1 != right) {
		int mid = (left + right) / 2;
		int res = getTotal(mid);

		if (res <= budget) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	if (left != 100000) return left;
	else return getMax();
}

void input() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &req[i]);
	}

	cin >> budget;
}

int main() {

	input();

	cout << answer() << endl;

	return 0;
}
