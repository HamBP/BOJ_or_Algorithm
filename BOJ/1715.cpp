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
priority_queue<int> pq;

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int input;
		scanf("%d", &input);
		pq.push(-input);
	}

	int total = 0;

	for (int i = 0; i < n - 1; ++i) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		int temp = a + b;
		total -= temp;
		pq.push(temp);
	}

	cout << total << endl;

	return 0;
}
