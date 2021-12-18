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

using namespace std;

typedef long long ll;

#define INF 1987654321

/* *** */

ll n;

int main() {
	cin >> n;

	for (int i = 2; i < 10000; ++i) {
		ll div = 0;
		for (ll j = 0; j < 50; ++j) {
			div += pow(i, j);
			if (j > 1 && n % div == 0) {
				printf("%d\n", j + 1);
				for (ll k = n / div; k < n; k *= i) {
					printf("%lld ", k);
				}
				return 0;
			}

			if (div > n) break;
		}
	}

	cout << -1 << endl;

	return 0;
}
