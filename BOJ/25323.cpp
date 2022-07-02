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
ll arr[500005], sorted[500005];

ll gcd(int a, int b) {
	return a % b == 0 ? b : gcd(b, a % b);
}

bool answer() {
	sort(sorted, sorted + n);

	for (int i = 0; i < n; ++i) {
		ll g = gcd(arr[i], sorted[i]);
		ll a = arr[i] / g;
		ll b = sorted[i] / g;
		if (sqrt(a) != (int)sqrt(a) || sqrt(b) != (int)sqrt(b)) return false;
	}

	return true;
}


int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		scanf("%lld", &arr[i]);
		sorted[i] = arr[i];
	}

	if (answer()) cout << "YES";
	else cout << "NO";

	return 0;
}
