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
int n;
pair<int, int> arr[100005];

int answer() {
	int highest = 100001;
	int cnt = 0;

	sort(arr, arr + n);

	for (int i = 0; i < n; ++i) {
		if (arr[i].second < highest) {
			++cnt;
			highest = min(highest, arr[i].second);
		}
	}

	return cnt;
}

int main() {

	cin >> tc;

	for (int i = 0; i < tc; ++i) {
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[j] = make_pair(a, b);
		}

		printf("%d\n", answer());
	}

	return 0;
}
