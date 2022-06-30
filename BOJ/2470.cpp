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
int arr[100005];

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	int l = 0, r = n - 1;
	int ansL = 0, ansR = 1;
	int minAbs = 2000000000;

	while (l < r) {
		int temp = abs(arr[l] + arr[r]);

		if (temp < minAbs) {
			minAbs = temp;
			ansL = l;
			ansR = r;
		}

		if (arr[l] + arr[r] < 0) {
			++l;
		} else {
			--r;
		}
	}

	cout << arr[ansL] << " " << arr[ansR] << endl;

	return 0;
}
